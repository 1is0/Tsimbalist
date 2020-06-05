#pragma once
#include "clss\Scoreboard.h"
#include "clss\Millenium.h"

using namespace sf;
enum dirs { up = 0b0001, down = 0b0010, left = 0b0100, right = 0b1000, all = 0b1111 };

void take_screenshot(const sf::RenderWindow& window, const std::string& filename) {
	sf::Texture texture;
	texture.create(window.getSize().x, window.getSize().y);
	texture.update(window);
	texture.copyToImage().saveToFile(filename);
}

void Map_From_File(char level[17][17], int level_num) {
	int tmp = 0;
	int i = 0, j = 0;
	std::ifstream file_1("levels/level_" + std::to_string(level_num) + ".bin", std::ios_base::binary);
	while (file_1.read((char*)& tmp, sizeof(tmp))) {
		level[i][j] = tmp;
		j++;
		if (j == 17) {
			j = 0;
			i++;
		}
		if (i == 17) {
			break;
		}
	}
	file_1.close();
}

int entity_quantity(char map[17][17], std::string entity_type) {
	int type = 0;
	int type_count = 0;
	if (entity_type == "nothing") {
		type = 17;
	}
	if (entity_type == "easy_enemy") {
		type = 18;
	}
	if (entity_type == "emerald") {
		type = 19;
	}
	if (entity_type == "bag") {
		type = -1;
	}
	if (entity_type == "digger") {
		type = 20;
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == type) {
				type_count++;
			}
		}
	}
	return type_count;
}

void entity_getpos(char map[17][17], std::string entity_type, int num, int& x, int& y, std::vector<Bag>& bag) {
	int type = 19;
	int num_ = 0;
	if (entity_type == "easy_enemy") {
		type = 18;
	}
	if (entity_type == "emerald") {
		type = 19;
	}
	if (entity_type == "bag") {
		type = -1;
	}
	if (entity_type == "digger") {
		type = 20;
	}
	bool no_place = false;
	bool opportunity = true;
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == 16) {
				for (int f = 0; f < bag.size(); f++) {
					if (bag.at(f).GetLifes()) {
						if (bag.at(f).GetPosY() == i * 4 && bag.at(f).GetPosX() == j * 4) {
							map[i][j] = 16;
							no_place = true;
						}
						if (no_place) {
							opportunity = false;
							break;
						}
						else {
							opportunity = true;
						}
					}
				}
				if (opportunity) {
					map[i][j] = 15;
				}
			}
			no_place = false;
		}
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == 18 || map[i][j] == 20) {
				for (int f = 0; f < bag.size(); f++) {
					if (bag.at(f).GetLifes()) {
						if (bag.at(f).GetPosY() == i * 4 && bag.at(f).GetPosX() == j * 4) {
							map[i][j] = 16;
						}
					}
				}
			}
		}
	}
	int quantity = entity_quantity(map, "digger");
	if (!quantity) {
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 17; j++) {
				if (map[i][j] == 15) {
					map[i][j] = 20;
				}
			}
		}
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == 15) {
				map[i][j] = 18;
			}
		}
	}
	//сверху все ок
	if (type == 18 || type == 20) {
		quantity = entity_quantity(map, "easy_enemy");
		if (quantity) {
			int random = rand() % quantity;
			if (quantity == 0) {
				random = 0;
			}
			int next = 0;
			for (int i = 0; i < 17; i++) {
				for (int j = 0; j < 17; j++) {
					if (map[i][j] == type && next == random) {
						x = i; y = j;
						return;
					}
					if (map[i][j] == type) {
						next++;
					}
				}
			}
		}
		quantity = entity_quantity(map, "nothing") - 1;
		int random = rand() % quantity;
		int next = 0;
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 17; j++) {
				if (map[i][j] == 17 && next == random) {
					x = i; y = j;
					return;
				}
				if (map[i][j] == 17) {
					next++;
				}
			}
		}
	}
	if (type == 19 || type == -1) {
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 17; j++) {
				if (map[i][j] == type && num_ == num) {
					x = i; y = j;
					return;
				}
				if (map[i][j] == type) {
					num_++;
				}
			}
		}
	}
}

void map_load(char map_s[17][17], MAP& s_map, Cube* stone, Cube* border, std::vector<EasyEnemy>& ens, std::vector<Emerald>& ems, std::vector<Bag>& bag, Digger& player) {
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			if (map_s[i][j] == 0) {
				for (int f = 0; f < 4; f++) {
					for (int k = 0; k < 4; k++) {
						s_map.map[i * 4 + f][j * 4 + k] = 0;
					}
				}
			}
			if (map_s[i][j] == 1 || map_s[i][j] == 19 || map_s[i][j] == -1) {
				int stone_id = 1;
				for (int f = 0; f < 4; f++) {
					for (int k = 0; k < 4; k++) {
						s_map.map[i * 4 + f][j * 4 + k] = stone_id++;
					}
				}
			}
			if (map_s[i][j] == 17 || map_s[i][j] == 18) {
				for (int f = 0; f < 4; f++) {
					for (int k = 0; k < 4; k++) {
						s_map.map[i * 4 + f][j * 4 + k] = 17;
					}
				}
			}
			if (map_s[i][j] == 20) {
				player.SetInfo(j * 4, i * 4, player.GetLifes(), "digger", 2);
				for (int f = 0; f < 4; f++) {
					for (int k = 0; k < 4; k++) {
						s_map.map[i * 4 + f][j * 4 + k] = 17;
					}
				}
			}
		}
	}
	//stone load//
	int usel = 0;
	stone[0].texture.loadFromFile("images/stone.png");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			stone[usel].sprite.setTexture(stone[0].texture);
			stone[usel].sprite.setTextureRect(IntRect(j * 8, i * 8, 8, 8));
			usel++;
		}
	}
	//borders load//
	border->texture.loadFromFile("images/borders.png");
	border->sprite.setTexture(border->texture);
	border->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	//entitys load//
	int bag_quantity = entity_quantity(map_s, "bag");
	int ens_quantity = entity_quantity(map_s, "easy_enemy");
	int ems_quantity = entity_quantity(map_s, "emerald");
	for (int i = 0; i < ems_quantity; i++) {
		int x = 0, y = 0;
		entity_getpos(map_s, "emerald", i, x, y, bag);
		ems.at(i).SetInfo(y * 4, x * 4, 1, "emerald", 0);
		if (i < bag_quantity) {
			entity_getpos(map_s, "bag", i, x, y, bag);
			bag.at(i).SetInfo(y * 4, x * 4, 1, "bag", 0);
			if (i < ens_quantity) {
				entity_getpos(map_s, "easy_enemy", i, x, y, bag);
				ens.at(i).SetInfo(y * 4, x * 4, 1, "easy_enemy", 0);
			}
		}
	}
}

void Delay(float delay_time) {
	Clock delay;
	float time_del = 0;
	while (time_del < delay_time) {
		time_del = delay.getElapsedTime().asSeconds();
	}
}

void Game_lvl(RenderWindow& window, char level[17][17], Digger& player, bool difficulty, bool with_bullet, int& chose, int& level_num, int& Score) {
	//level loading//
	MAP* s_map = new MAP;
	Cube* stone = new Cube[16];
	Cube* border = new Cube;
	Bullet bullet;
	int bag_quantity = entity_quantity(level, "bag");
	int ens_quantity = entity_quantity(level, "easy_enemy");
	int ems_quantity = entity_quantity(level, "emerald");
	std::vector<EasyEnemy> ens(ens_quantity);
	std::vector<Emerald> ems(ems_quantity);
	std::vector<Bag> bag(bag_quantity);
	map_load(level, *s_map, stone, border, ens, ems, bag, player);
	player.SetEmCount(0);
	player.SetTime(1);
	for (int i = 0; i < ens.size(); i++) {
		ens.at(i).SetTime(-(i + 1.f) * 0.6f);
		ens.at(i).SetLifes(0);
	}
	//level loading//
	srand(static_cast<unsigned int>(time(0)));
	//needable elements//
	int dir = 0;
	Clock bags_clock, en_clock, bull_clock, digger_clock;
	Font font;
	font.loadFromFile("trajan.ttf");
	Text text, Died;
	text.setFont(font);text.setFillColor(Color(255, 140, 0));text.setString("Score: " + std::to_string(Score));text.setCharacterSize(28);
	Died.setFont(font); Died.setFillColor(Color(125, 2, 2)); Died.setString("YOU DIED"); Died.setCharacterSize(46); Died.setPosition(150, 275);
	//main loop//
	while (window.isOpen()) {
		float digger_t = digger_clock.getElapsedTime().asSeconds();
		player.SetTime(player.GetTime() + digger_t);
		bags_clock.restart();
		en_clock.restart();
		bull_clock.restart();
		digger_clock.restart();
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				chose = 5;
				return;
			}
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					chose = 4;
					return;
				}
				if (e.key.code == Keyboard::Up) {
					dir |= dirs::up;
				}
				if (e.key.code == Keyboard::Left) {
					dir |= dirs::left;
					//player.sprite().setTextureRect(IntRect(0, 0, 32, 32));
				}
				if (e.key.code == Keyboard::Right) {
					dir |= dirs::right;
					//player.sprite().setTextureRect(IntRect(32, 0, -32, 32));
				}
				if (e.key.code == Keyboard::Down) {
					dir |= dirs::down;
				}
				if (e.key.code == Keyboard::Space) {
					if (!bullet.GetLifes() && with_bullet) {
						bullet.SetInfo(player.GetPosX(), player.GetPosY(), 1, "bullet", player.GetDir());
						with_bullet = false;
						bullet.SetLifes(1);
					}
				}
			}
			else if (e.type == Event::KeyReleased) {
				if (e.key.code == Keyboard::Up) {
					dir &= dirs::up ^ dirs::all;
				}
				if (e.key.code == Keyboard::Left) {
					dir &= dirs::left ^ dirs::all;
				}
				if (e.key.code == Keyboard::Right) {
					dir &= dirs::right ^ dirs::all;
				}
				if (e.key.code == Keyboard::Down) {
					dir &= dirs::down ^ dirs::all;
				}
			}
		}
		player.Move(dir, *s_map, bag, ens);
		window.clear(Color(70, 70, 70));
		for (int i = 0; i < 17 * 4; i++) {
			for (int j = 0; j < 17 * 4; j++) {
				if (s_map->map[i][j] > 0 && s_map->map[i][j] < 17) {
					stone[s_map->map[i][j] - 1].setPosition(static_cast<float>(j) * 8, static_cast<float>(i) * 8 + 32);
					window.draw(stone[s_map->map[i][j] - 1].sprite);
				}
				if (s_map->map[i][j] == 0 && i % 4 == 0 && j % 4 == 0) {
					border->setPosition(static_cast<float>(j) * 8, static_cast<float>(i) * 8 + 32);
					window.draw(border->sprite);
				}
			}
		}
		float bag_t = bags_clock.getElapsedTime().asSeconds(), ens_t = en_clock.getElapsedTime().asSeconds();
		for (int i = 0; i < ems_quantity; i++) {
			if (ems.at(i).GetLifes()) {
				window.draw(ems.at(i).sprite());
			}
			if (i < bag_quantity) {
				if (bag.at(i).GetLifes()) {
					bag.at(i).Move(*s_map, bag_t, bag, ens, player);
					window.draw(bag.at(i).sprite());
				}
				if (i < ens_quantity) {
					if (ens.at(i).GetLifes() && ens.at(i).GetTime() >= 0) {
						ens.at(i).Move(*s_map, ens_t, bag, difficulty);
						window.draw(ens.at(i).sprite());
					}
					if (!ens.at(i).GetLifes()) {
						int x = 0, y = 0;
						entity_getpos(level, "easy_enemy", i, x, y, bag);
						ens.at(i).Respawn(x * 4, y * 4, ens_t);
					}
				}
			}
		}
		if (bullet.GetLifes()) {
			bullet.SetTime(bullet.GetTime() + bull_clock.getElapsedTime().asSeconds());
			bullet.Move(*s_map);
			window.draw(bullet.sprite());
		}
		char trash_dir = player.GetDir();
		char dir = player.toChar(trash_dir);
		window.draw(player.sprite());
		int lifes = player.GetLifes();
		player.Entity_Collision(bullet, ens, ems, bag, Score);
		if (player.GetLifes() <= 0) {
			take_screenshot(window, "Screen.png");
			level_num = 1;
			chose = 4;
			RectangleShape shape(Vector2f(544, 576));
			shape.setFillColor(Color(0, 0, 0, 150));
			window.draw(shape);
			window.draw(Died);
			text.setString("Score: " + std::to_string(Score) + "  Lifes: " + std::to_string(player.GetLifes()));
			window.draw(text);
			window.display();
			Delay(3);
			return;
		}
		if (player.GetLifes() + 1 == lifes) {
			int x, y;
			for (size_t i = 0; i < bag.size(); i++) {
				window.draw(bag.at(i).sprite());
			}
			for (size_t i = 0; i < ens.size(); i++) {
				window.draw(ens.at(i).sprite());
			}
			Delay(1);
			entity_getpos(level, "digger", 0, x, y, bag);
			player.Respawn(x * 4, y * 4, 0);
		}
		if (player.GetEmCount() == ems_quantity) {
			chose = 1;
			player.SetTime(5);
			player.SetEmCount(0);
			level_num++;
			take_screenshot(window, "Screen.png");
			return;
		}
		text.setString("Score: " + std::to_string(Score) + "  Lifes: " + std::to_string(player.GetLifes()));
		window.draw(text);
		window.display();
	}
}

void Options(RenderWindow& window, bool& difficulty, bool& bullets, int& chose) {
	chose = 1;
	std::string complexity_txt("Easy"), bullets_txt("on");
	if (!difficulty) {
		complexity_txt = "Hard";
	}
	if (!bullets) {
		bullets_txt = "off";
	}
	Cube menu_bg("menu_bg");
	Font font;
	font.loadFromFile("trajan.ttf");
	Text complexity_, bullets_, back_;
	complexity_.setFont(font);						bullets_.setFont(font);						back_.setFont(font);
	complexity_.setFillColor(Color(15, 141, 0));	bullets_.setFillColor(Color(15, 141, 0));	back_.setFillColor(Color(15, 141, 0));
	complexity_.setPosition(70, 115 * 1);			bullets_.setPosition(130, 115 * 2);			back_.setPosition(210, 115 * 3);
	complexity_.setOutlineThickness(2);	complexity_.setOutlineColor(Color(0, 0, 0));
	bullets_.setOutlineThickness(2);	bullets_.setOutlineColor(Color(0, 0, 0));
	back_.setOutlineThickness(2);	back_.setOutlineColor(Color(0, 0, 0));
	complexity_.setString("Difficulty : " + complexity_txt);
	bullets_.setString("Bullets : " + bullets_txt);
	back_.setString("Exit");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				chose = 5;
				return;
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					chose = 4;
					return;
				}
				if (event.key.code == Keyboard::Up) {
					chose--;
					if (chose < 1) {
						chose = 1;
					}
				}
				if (event.key.code == Keyboard::Down) {
					chose++;
					if (chose > 3) {
						chose = 3;
					}
				}
				if (event.key.code == Keyboard::Left) {
					switch (chose) {
					case 1:
						if (difficulty) {
							difficulty = false;
							complexity_txt = "Hard";
						}
						else {
							difficulty = true;
							complexity_txt = "Easy";
						}
						break;
					case 2:
						if (bullets) {
							bullets = false;
							bullets_txt = "off";
						}
						else {
							bullets = true;
							bullets_txt = "on";
						}
						break;
					}
				}
				if (event.key.code == Keyboard::Right) {
					switch (chose) {
					case 1:
						if (difficulty) {
							difficulty = false;
							complexity_txt = "Hard";
						}
						else {
							difficulty = true;
							complexity_txt = "Easy";
						}
						break;
					case 2:
						if (bullets) {
							bullets = false;
							bullets_txt = "off";
						}
						else {
							bullets = true;
							bullets_txt = "on";
						}
						break;
					}
				}
				if (event.key.code == Keyboard::Enter) {
					if (chose == 3) {
						chose = 4;
						return;
					}
				}
			}
		}
		switch (chose) {
		case 1:
			complexity_.setStyle(Text::Bold);		bullets_.setStyle(Text::Regular);		back_.setStyle(Text::Regular);
			complexity_.setCharacterSize(46);		bullets_.setCharacterSize(38);			back_.setCharacterSize(38);
			break;
		case 2:
			complexity_.setStyle(Text::Regular);	bullets_.setStyle(Text::Bold);			back_.setStyle(Text::Regular);
			complexity_.setCharacterSize(38);		bullets_.setCharacterSize(46);			back_.setCharacterSize(38);
			break;
		case 3:
			complexity_.setStyle(Text::Regular);	bullets_.setStyle(Text::Regular);		back_.setStyle(Text::Bold);
			complexity_.setCharacterSize(38);		bullets_.setCharacterSize(38);			back_.setCharacterSize(46);
			break;
		}
		complexity_.setString("Difficulty : " + complexity_txt);
		bullets_.setString("Bullets : " + bullets_txt);
		back_.setString("Back");
		window.clear(Color::White);
		window.draw(menu_bg.sprite);
		window.draw(complexity_);
		window.draw(bullets_);
		window.draw(back_);
		window.display();
	}
}

void Menu(RenderWindow& window, int& chose) {
	chose = 1;
	Cube menu_bg("menu_bg");
	Font font;
	font.loadFromFile("trajan.ttf");
	Text Play, Options, Exit, Score;
	Play.setString("   Play  ");
	Options.setString(" Options");
	Exit.setString("     Exit  ");
	Score.setString("Show scoreboard");
	Score.setFont(font);						Score.setFillColor(Color(15, 141, 0));			Score.setPosition(70, 115 * 3);
	Play.setFont(font);							Options.setFont(font);							Exit.setFont(font);
	Play.setFillColor(Color(15, 141, 0));		Options.setFillColor(Color(15, 141, 0));		Exit.setFillColor(Color(15, 141, 0));
	Play.setPosition(180, 115 * 1);				Options.setPosition(160, 115 * 2);				Exit.setPosition(160, 115 * 4);

	Play.setOutlineThickness(2);	Play.setOutlineColor(Color(0, 0, 0));
	Options.setOutlineThickness(2);	Options.setOutlineColor(Color(0, 0, 0));
	Score.setOutlineThickness(2);	Score.setOutlineColor(Color(0, 0, 0));
	Exit.setOutlineThickness(2);	Exit.setOutlineColor(Color(0, 0, 0));
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				chose = 5;
				return;
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					chose = 5;
					return;
				}
				if (event.key.code == Keyboard::Up) {
					chose--;
					if (chose < 1) {
						chose = 1;
					}
				}
				if (event.key.code == Keyboard::Down) {
					chose++;
					if (chose > 4) {
						chose = 4;
					}
				}
				if (event.key.code == Keyboard::Enter) {
					if (chose == 4) {
						chose = 5;
					}
					return;
				}
			}
		}
		switch (chose) {
		case 1:
			Play.setStyle(Text::Bold);		Options.setStyle(Text::Regular);	Score.setStyle(Text::Regular);	Exit.setStyle(Text::Regular);
			Play.setCharacterSize(46);		Options.setCharacterSize(38);		Score.setCharacterSize(38);		Exit.setCharacterSize(38);
			Score.setPosition(70, 115 * 3);
			break;
		case 2:
			Play.setStyle(Text::Regular);	Options.setStyle(Text::Bold);		Score.setStyle(Text::Regular);	Exit.setStyle(Text::Regular);
			Play.setCharacterSize(38);		Options.setCharacterSize(46);		Score.setCharacterSize(38);		Exit.setCharacterSize(38);
			Score.setPosition(70, 115 * 3);
			break;
		case 3:
			Play.setStyle(Text::Regular);	Options.setStyle(Text::Regular);	Score.setStyle(Text::Bold);		Exit.setStyle(Text::Regular);
			Play.setCharacterSize(38);		Options.setCharacterSize(38);		Score.setCharacterSize(46);		Exit.setCharacterSize(38);
			Score.setPosition(40, 115 * 3);
			break;
		case 4:
			Play.setStyle(Text::Regular);	Options.setStyle(Text::Regular);	Score.setStyle(Text::Regular);	Exit.setStyle(Text::Bold);
			Play.setCharacterSize(38);		Options.setCharacterSize(38);		Score.setCharacterSize(38);		Exit.setCharacterSize(46);
			Score.setPosition(70, 115 * 3);
			//Play.setPosition(150, 100 * 1);	Options.setPosition(160, 100 * 2);	Exit.setPosition(160, 100 * 3);	Exit.setPosition(160, 100 * 4);
			break;
		}
		window.clear();
		window.draw(menu_bg.sprite);
		window.draw(Play);
		window.draw(Options);
		window.draw(Exit);
		window.draw(Score);
		window.display();
	}
}

std::string GetStand() {
	std::string date;
	struct tm itm;
	time_t now = time(0);
	localtime_s(&itm, &now);
	int month = 1 + itm.tm_mon;
	int day = itm.tm_mday;
	int year = itm.tm_year - 100;
	std::string day_str, mon_str, year_str;
	day_str = std::to_string(day);
	mon_str = std::to_string(month);
	if (day < 10)
		day_str = "0" + std::to_string(day);
	if (month < 10)
		mon_str = "0" + std::to_string(month);
	year_str = std::to_string(year);
	date = "Digger" + day_str + mon_str + year_str;
	return date;
}

void SortScores(std::vector<std::string>& lines, int& chose, int& Score, std::vector<int>& ScoreBoard) {
	std::string tmp;
	for (int i = 0; i < 5; i++) {
		tmp = "";
		for (int j = lines.at(i).size() - 5; j < lines.at(i).size(); j++) {
			tmp += lines.at(i).at(j);
		}
		ScoreBoard.at(i) = stoi(tmp);
	}
	for (size_t i = 0; i < ScoreBoard.size() - 1; i++) {
		for (size_t j = 0; j < ScoreBoard.size() - i - 1; j++) {
			if (ScoreBoard.at(j) < ScoreBoard.at(j + 1)) {
				std::swap(ScoreBoard.at(j), ScoreBoard.at(j + 1));
				std::swap(lines.at(j), lines.at(j + 1));
			}
		}
	}
}

std::string GetScoreStr(int& Score) {
	std::string Score_str;
	Score < 10000 ? Score_str += "0" : Score_str = Score_str;
	Score < 1000 ? Score_str += "0" : Score_str = Score_str;
	Score < 100 ? Score_str += "0" : Score_str = Score_str;
	Score_str += std::to_string(Score);
	return Score_str;
}

void AddToScoreBoard(RenderWindow& window, int& Score, std::vector<std::string>& lines, int& chose) {
	int min_score = 99999;
	chose = 3;
	std::string Name = GetStand();
	std::ifstream Score_file("Score_board.txt");
	std::vector<int>ScoreBoard(5);
	SortScores(lines, chose, Score, ScoreBoard);
	for (size_t i = 0; i < ScoreBoard.size(); i++) {
		if (min_score > ScoreBoard.at(i)) {
			min_score = ScoreBoard.at(i);
		}
	}
	if (Score <= min_score)
		return;
	std::string Score_str = GetScoreStr(Score);
	Texture texture;
	texture.loadFromFile("Screen.png");
	Sprite bg(texture);
	
	Font font;	font.loadFromFile("trajan.ttf");

	Text txt, Enter_name;
	txt.setPosition(25, 270);	txt.setFont(font);	txt.setString(Name);	txt.setFillColor(Color(15, 141, 0));//15, 141, 0//255, 140, 0
	txt.setCharacterSize(36);
	txt.setOutlineColor(Color(0, 0, 0)); txt.setOutlineThickness(2);

	Enter_name.setPosition(60, 200); Enter_name.setFont(font); Enter_name.setString("Enter your nickname");
	Enter_name.setFillColor(Color(15, 141, 0)); Enter_name.setCharacterSize(36);
	Enter_name.setOutlineColor(Color(0, 0, 0)); Enter_name.setOutlineThickness(2);

	FocusController fc;		TextBox tb(txt);	fc.SetFocusObject(&tb);		bool close = false;
	RectangleShape text_rect(Vector2f(510, 50));
	text_rect.setFillColor(Color(250, 250, 250, 0)); text_rect.setOutlineColor(Color(0, 0, 0));
	text_rect.setOutlineThickness(4);	text_rect.setPosition(20, 265);

	Texture black; black.loadFromFile("images/rect.png");
	Sprite sprite; sprite.setTexture(black); sprite.setColor(Color(255, 255, 255, 170));

	while (window.isOpen()) {
		Event event;
		if (close) { break; }
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { close = true; break; }
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					chose = 5;
					return;
				}
				if (event.key.code == Keyboard::Return) {
					close = true;
					chose = 4;
					break;
				}
			}
			FocusObject* fo = fc.GetFocusObject();
			if (fo != 0)  fo->Event(event, chose);
		}
		window.clear();
		window.draw(bg);	window.draw(sprite);	 window.draw(Enter_name); window.draw(tb); window.draw(text_rect); window.display();
	}
	lines.at(4) = tb.GetText() + " - " + Score_str;
	SortScores(lines, chose, Score, ScoreBoard);
	Score_file.close();
	std::ofstream file("Score_board.txt");
	for (int i = 0; i < 5; i++) {
		file << lines.at(i) << "\n";
	}
	Score_file.close();
}

void ShowScoreBoard(RenderWindow& window, int& chose,std::vector<std::string>& StrScores) {
	chose = 1;
	Texture bg;
	bg.loadFromFile("images/menu_bg.png");
	Sprite sprite(bg);
	Cube menu_bg("menu_bg");
	Font font; font.loadFromFile("trajan.ttf");
	Text back;
	back.setString("Press 'Enter' to return");
	back.setFont(font);
	back.setFillColor(Color(15, 141, 0));
	back.setOutlineThickness(2);
	back.setOutlineColor(Color(0, 0, 0));
	std::vector<Text>TxtScores(5);
	for (int i = 0; i < 5; i++) {
		TxtScores[i].setString(StrScores[i]);
		TxtScores[i].setFont(font);
		TxtScores[i].setFillColor(Color(15, 141, 0));
		TxtScores[i].setPosition(static_cast<float>(15), static_cast<float>(100 * (i + 1)));
		TxtScores[i].setOutlineThickness(2);
		TxtScores[i].setOutlineColor(Color(0, 0, 0));
	}
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				chose = 5;
				return;
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					chose = 4;
					return;
				}
				if (event.key.code == Keyboard::Enter) {
					chose = 4;
					return;
				}
			}
		}
		window.clear();
		window.draw(sprite);
		for (int i = 0; i < 5; i++) {
			window.draw(TxtScores[i]);
		}
		window.draw(back);
		window.display();
	}
}