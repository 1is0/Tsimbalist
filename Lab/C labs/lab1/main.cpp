#include<iostream>
#include<math.h>

using namespace std;

int main()
{
int a, c1, c2, c3,b;
cout << "Enter number: \n";
cin >> a;
c1=a/100;
c2=(a%100)/10;
c3=(a%100)%10;

cout<<""<<c1<<c2<<c3<<'\n';


        return 0;
}
