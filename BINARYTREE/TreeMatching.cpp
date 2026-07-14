#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> adj;
int dp[200005][2];

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = 0;

    int sum_children = 0;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        sum_children += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = sum_children;

    for (int v : adj[u])
    {
        if (v == p)
            continue;

        int cand = 1 + dp[v][0] + (sum_children - max(dp[v][0], dp[v][1]));
        dp[u][1] = max(dp[u][1], cand);
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}