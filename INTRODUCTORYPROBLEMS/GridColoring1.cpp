#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 4-directional offsets
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
unordered_set<char> st = {'A', 'B', 'C', 'D'};

// Check if placing character 'ch' at (i, j) conflicts with adjacent cells
bool canPutChar(int i, int j, char ch, int n, int m, const vector<vector<char>> &grid)
{
    for (int d = 0; d < 4; d++)
    {
        int ni = i + di[d];
        int nj = j + dj[d];

        // Boundary check
        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        {
            // Compare neighbor directly against 'ch'
            if (grid[ni][nj] == ch)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int i, int j, int n, int m, vector<vector<char>> &grid)
{
    // Base Case: Processed all cells
    if (i == n)
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                cout << grid[r][c];
            }
            cout << "\n";
        }
        return true;
    }

    // Next cell coordinates
    int next_i = (j == m - 1) ? i + 1 : i;
    int next_j = (j == m - 1) ? 0 : j + 1;

    char original_ch = grid[i][j];

    // Try placing a DIFFERENT character from {'A', 'B', 'C', 'D'}
    for (char ch : st)
    {
        if (ch == original_ch)
            continue; // Must change from initial char

        // Validate directly against 'ch' without temporarily altering grid[i][j]
        if (canPutChar(i, j, ch, n, m, grid))
        {
            grid[i][j] = ch; // Make choice

            if (solve(next_i, next_j, n, m, grid))
            {
                return true; // Stop searching once first solution is found
            }
        }
    }

    // Backtrack to original state before returning false
    grid[i][j] = original_ch;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (!solve(0, 0, n, m, grid))
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}