using System;

namespace ConsoleApp1
{
    class Program
    {
        public static String ReverseString(String str)
        {
            int word_length = 0;
            String result = "";
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == ' ')
                {
                    result = " " + result;
                    word_length = 0;
                }
                else
                {
                    result = result.Insert(word_length, str[i].ToString());
                    word_length++;
                }
            }
            return result;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            string str;
            str = Console.ReadLine();
            ReverseString(str);

            Console.WriteLine("{0}", ReverseString(str));

        }
    }
}
