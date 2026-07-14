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

    // prefix ors
    vector<long long> pre_ors(n);
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
            pre_ors[i] = arr[i];
        else
            pre_ors[i] = pre_ors[i - 1] | arr[i];
    }

    // suffix ors
    vector<long long> suf_ors(n);
    suf_ors[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (i % k == k - 1)
            suf_ors[i] = arr[i];
        else
            suf_ors[i] = arr[i] | suf_ors[i + 1];
    }

    long long ans = 0;
    for (int j = k - 1; j < n; j++)
    {
        long long cur = pre_ors[j] | suf_ors[j - k + 1];
        ans = ans ^ cur;
    }

    cout << ans << "\n";

    return 0;
}