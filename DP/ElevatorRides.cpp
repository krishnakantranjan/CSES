#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 20;
int n;
ll W;
vector<ll> arr;

// memo[mask] stores {min_rides, weight_of_last_ride}
pair<int, ll> memo[1 << MAXN];
bool visited[1 << MAXN];

pair<int, ll> solve(int mask)
{
    // Base Case: All people processed
    if (mask == (1 << n) - 1)
    {
        return {1, 0}; // 1 ride needed, starting with 0 accumulated weight
    }

    if (visited[mask])
    {
        return memo[mask];
    }

    pair<int, ll> best = {n + 1, W + 1}; // Initialize with worst case

    for (int i = 0; i < n; i++)
    {
        // Pick an unchosen person
        if (!(mask & (1 << i)))
        {
            int next_mask = mask | (1 << i);
            auto [rides, weight] = solve(next_mask);

            // Check if person 'i' fits into the current ride coming back from sub-problem
            if (weight + arr[i] <= W)
            {
                weight += arr[i];
            }
            else
            {
                rides++;
                weight = arr[i];
            }

            best = min(best, {rides, weight});
        }
    }

    visited[mask] = true;
    return memo[mask] = best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> W))
        return 0;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    // Solve from starting mask 0
    pair<int, ll> ans = solve(0);
    cout << ans.first << "\n";

    return 0;
}