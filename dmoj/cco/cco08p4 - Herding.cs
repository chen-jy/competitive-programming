using System;

class Program
{
    static int[] input;
    static string[] grid;
    static int[,] vis;

    static bool DFS(int r, int c, int x)
    {
        if (vis[r, c] > 0 && vis[r, c] < x)
            return false;
        if (vis[r, c] == x)
            return true;
        vis[r, c] = x;

        bool loop = false;
        if (grid[r][c] == 'N')
            loop = DFS(r - 1, c, x);
        else if (grid[r][c] == 'S')
            loop = loop || DFS(r + 1, c, x);
        else if (grid[r][c] == 'W')
            loop = loop || DFS(r, c - 1, x);
        else loop = loop || DFS(r, c + 1, x);
        return loop;
    }

    static void Main()
    {
        input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        grid = new string[input[0]];
        vis = new int[input[0], input[1]];
        for (int i = 0; i < input[0]; i++)
            grid[i] = Console.ReadLine();
        int ans = 0, curr = 1;
        for (int i = 0; i < input[0]; i++)
        {
            for (int j = 0; j < input[1]; j++)
            {
                if (vis[i, j] == 0)
                {
                    if (DFS(i, j, curr++))
                        ans++;
                }
            }
        }
        Console.WriteLine(ans);
    }
}
