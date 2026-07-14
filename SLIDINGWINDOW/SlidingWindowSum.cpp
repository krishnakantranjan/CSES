#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k))
        return 0;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    // First window of size k (indices 0 to k-1)
    long long prevsum = 0;
    for (int i = 0; i < k; i++)
    {
        prevsum += arr[i];
    }

    long long ans = prevsum;

    // Slide window for remaining positions
    // Loop goes up to i = n - k inclusive
    for (int i = 1; i <= n - k; i++)
    {
        long long currsum = prevsum + arr[i + k - 1] - arr[i - 1];
        ans = ans ^ currsum;
        prevsum = currsum;
    }

    cout << ans << "\n";

    return 0;
}