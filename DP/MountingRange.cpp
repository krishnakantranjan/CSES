#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Example: Pop elements from heap while they violate your condition
    priority_queue<pair<ll, int>> pq; // Max heap storing {value, index}
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        // Remove elements from top if they break the rules for index i
        while (!pq.empty() && pq.top().first < arr[i])
        {
            pq.pop();
        }

        if (!pq.empty())
        {
            ans = max(ans, i - pq.top().second + 1);
        }

        pq.push({arr[i], i});
    }

    cout << ans << "\n";
    return 0;
}