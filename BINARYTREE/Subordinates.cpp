#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> adj;

void tree(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 2; i < n; i++)
    {
        adj[arr[i]].push_back(i);
    }
}

int count(int u, vector<int> &subordinates)
{
    int c = 0;
    for (int v : adj[u])
    {
        c += 1 + count(v, subordinates);
    }

    return subordinates[u] = c;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> arr[i];
    }

    tree(arr);

    vector<int> subordinates(n + 1, 0);
    count(1, subordinates);

    for (int i = 1; i <= n; i++)
    {
        cout <<subordinates[i] <<" ";
    }

    return 0;
}