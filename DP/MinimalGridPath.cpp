#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> grid;
vector<vector<string>> memo;

string solve(int i, int j)
{
    // Base Case: Reached lower-right corner
    if (i == n - 1 && j == n - 1)
    {
        return string(1, grid[i][j]);
    }

    // Return cached result if already calculated
    if (!memo[i][j].empty())
    {
        return memo[i][j];
    }

    string down = "";
    string right = "";

    // 1. Move Down (if within bounds)
    if (i + 1 < n)
    {
        down = solve(i + 1, j);
    }

    // 2. Move Right (if within bounds)
    if (j + 1 < n)
    {
        right = solve(i, j + 1);
    }

    // 3. Select lexicographically smaller path
    if (i + 1 < n && j + 1 < n)
    {
        memo[i][j] = grid[i][j] + min(down, right);
    }
    else if (i + 1 < n)
    {
        memo[i][j] = grid[i][j] + down;
    }
    else
    {
        memo[i][j] = grid[i][j] + right;
    }

    return memo[i][j];
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n))
        return 0;

    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    // Initialize memoization table with empty strings
    memo.assign(n, vector<string>(n, ""));

    // Start recursion from top-left (0, 0)
    cout << solve(0, 0) << "\n";

    return 0;
}