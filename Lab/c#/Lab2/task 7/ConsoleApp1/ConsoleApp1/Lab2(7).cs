using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите строку :");
            string str = Console.ReadLine();
            int a = str.Length;
            Console.WriteLine("Вывод номеров символов в строке по порядку: ");
            for (int i = 1; i <= a; i++)
            {
                Console.Write("{0:X4} ", i);
            }
            Console.WriteLine();

            Console.WriteLine("Вывод кодов символов в шестнадцатеричной системе: ");
            foreach (var ch in str)
            {
                Console.Write("'{0}' ", Convert.ToUInt16(ch).ToString("X4"));
            }

            Console.WriteLine("\n\n");
        }
    }
}