using System;
using System.Collections.Generic;

class Program
{
    static int index = 0;

    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        for (int test = 0; test < N; test++)
        {
            string input = Console.ReadLine();
            string nomod = input;
            List<char> first = Read(input);
            input = input.Substring(index);
            List<char> second = Read(input);
            int a = Sum(first);
            int b = Sum(second);
            int c = a + b;
            Console.Write(nomod);
            if (c > 1000) Console.WriteLine("CONCORDIA CUM VERITATE");
            else
            {
                List<char> third = Convert(c);
                foreach (char letter in third)
                    Console.Write(letter);
                Console.WriteLine();
            }
        }
    }

    static List<char> Read(string input)
    {
        List<char> temp = new List<char>();
        char a;
        for (int i = 0; i < input.Length; i++)
        {
            a = input[i];
            if (a == '+' || a == '=')
            {
                index = i + 1;
                break;
            }
            else if (a == 13 || a == 10) continue;
            else temp.Add(a);
        }
        return temp;
    }

    static int Sum(List<char> temp)
    {
        char a, b = ' ';
        int sum = 0;
        for (int i = 0; i < temp.Count; i++)
        {
            a = temp[i];
            if ((a == 'V' || a == 'X') && b == 'I') sum += Convert(a) - 2;
            else if ((a == 'L' || a == 'C') && b == 'X') sum += Convert(a) - 20;
            else if ((a == 'D' || a == 'M') && b == 'C') sum += Convert(a) - 200;
            else sum += Convert(a);
            b = a;
        }
        return sum;
    }

    static int Convert(char numeral)
    {
        switch (numeral)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
    }

    /// <summary>
    /// Warning: lazy ugly code ahead
    /// </summary>
    /// <param name="integer"></param>
    /// <returns></returns>
    static List<char> Convert(int integer)
    {
        List<char> temp = new List<char>();
        while (integer > 0)
        {
            if (integer >= 900)
            {
                temp.Add('C');
                temp.Add('M');
                integer -= 900;
            }
            else if (integer >= 800)
            {
                temp.Add('D');
                for (int i = 0; i < 3; i++)
                    temp.Add('C');
                integer -= 800;
            }
            else if (integer >= 700)
            {
                temp.Add('D');
                temp.Add('C');
                temp.Add('C');
                integer -= 700;
            }
            else if (integer >= 600)
            {
                temp.Add('D');
                temp.Add('C');
                integer -= 600;
            }
            else if (integer >= 500)
            {
                temp.Add('D');
                integer -= 500;
            }
            else if (integer >= 400)
            {
                temp.Add('C');
                temp.Add('D');
                integer -= 400;
            }
            else if (integer >= 300)
            {
                for (int i = 0; i < 3; i++)
                    temp.Add('C');
                integer -= 300;
            }
            else if (integer >= 200)
            {
                temp.Add('C');
                temp.Add('C');
                integer -= 200;
            }
            else if (integer >= 100)
            {
                temp.Add('C');
                integer -= 100;
            }
            else if (integer >= 90)
            {
                temp.Add('X');
                temp.Add('C');
                integer -= 90;
            }
            else if (integer >= 80)
            {
                temp.Add('L');
                for (int i = 0; i < 3; i++)
                    temp.Add('X');
                integer -= 80;
            }
            else if (integer >= 70)
            {
                temp.Add('L');
                temp.Add('X');
                temp.Add('X');
                integer -= 70;
            }
            else if (integer >= 60)
            {
                temp.Add('L');
                temp.Add('X');
                integer -= 60;
            }
            else if (integer >= 50)
            {
                temp.Add('L');
                integer -= 50;
            }
            else if (integer >= 40)
            {
                temp.Add('X');
                temp.Add('L');
                integer -= 40;
            }
            else if (integer >= 30)
            {
                for (int i = 0; i < 3; i++)
                    temp.Add('X');
                integer -= 30;
            }
            else if (integer >= 20)
            {
                temp.Add('X');
                temp.Add('X');
                integer -= 20;
            }
            else if (integer >= 10)
            {
                temp.Add('X');
                integer -= 10;
            }
            else if (integer == 9)
            {
                temp.Add('I');
                temp.Add('X');
                return temp;
            }
            else if (integer == 8)
            {
                temp.Add('V');
                for (int i = 0; i < 3; i++)
                    temp.Add('I');
                return temp;
            }
            else if (integer == 7)
            {
                temp.Add('V');
                temp.Add('I');
                temp.Add('I');
                return temp;
            }
            else if (integer == 6)
            {
                temp.Add('V');
                temp.Add('I');
                return temp;
            }
            else if (integer == 5)
            {
                temp.Add('V');
                return temp;
            }
            else if (integer == 4)
            {
                temp.Add('I');
                temp.Add('V');
                return temp;
            }
            else if (integer == 3)
            {
                for (int i = 0; i < 3; i++)
                    temp.Add('I');
                return temp;
            }
            else if (integer == 2)
            {
                temp.Add('I');
                temp.Add('I');
                return temp;
            }
            else
            {
                temp.Add('I');
                return temp;
            }
        }
        return temp;
    }
}
