#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// 8 possible moves for a Knight
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int main()
{
    int n;
    if (!(cin >> n) || n <= 0)
        return 0;

    // Use vector for dynamic 2D array allocation
    vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    queue<pair<int, int>> qu;

    // Start BFS from (0, 0)
    qu.push({0, 0});
    grid[0][0] = 0;
    vis[0][0] = true;

    while (!qu.empty())
    {
        auto curr = qu.front();
        int i = curr.first, j = curr.second;
        qu.pop();

        for (int m = 0; m < 8; m++)
        {
            int ni = i + dx[m];
            int nj = j + dy[m];

            // Boundary and visited check
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && !vis[ni][nj])
            {
                vis[ni][nj] = true;
                grid[ni][nj] = grid[i][j] + 1;
                qu.push({ni, nj});
            }
        }
    }

    // Print final shortest path distances from (0, 0)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}