#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
int max_diameter = 0; 

int dfs(int u, int p)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int v : adj[u])
    {
        if (v == p)
            continue; 

        int child_depth = dfs(v, u);
        pq.push(child_depth);

        if (pq.size() > 2)
        {
            pq.pop();
        }
    }

    int firstmx = 0;
    int secondmx = 0;

    if (!pq.empty())
    {
        firstmx = pq.top();
        pq.pop();
    }
    if (!pq.empty())
    {
        secondmx = pq.top();
        pq.pop();
    }

    
    max_diameter = max(max_diameter, firstmx + secondmx);

    return 1 + max(firstmx, secondmx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << max_diameter << "\n";

    return 0;
}