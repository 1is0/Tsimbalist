using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                Console.WriteLine("Input culture(example ru, en, fr, de): ");
                string cultureSymbol = Console.ReadLine();
                try
                {
                    CultureInfo culture = new CultureInfo(cultureSymbol);
                    if (!CultureInfo.GetCultures(CultureTypes.AllCultures).Contains(culture))
                        throw new Exception();
                    foreach (var month in culture.DateTimeFormat.MonthNames)
                    {
                        Console.WriteLine(month);
                    }
                }
                catch (Exception)
                {
                    Console.WriteLine("Incorrect culture");
                }
            }
        }
    }
}
