#include <iostream>
#include <vector>
#include <deque>
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

    long long xor_sum = 0;
    deque<int> dq; // Stores indices

    for (int i = 0; i < n; i++)
    {
        // 1. Remove elements outside the current window
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // 2. Remove larger elements from the back (they can't be minimums)
        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }

        // 3. Add current element index
        dq.push_back(i);

        // 4. Accumulate minimum for every completed window
        if (i >= k - 1)
        {
            xor_sum ^= arr[dq.front()];
        }
    }

    cout << xor_sum << "\n";

    return 0;
}