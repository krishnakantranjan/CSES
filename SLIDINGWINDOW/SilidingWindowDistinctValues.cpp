#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

// Custom hash function to prevent O(N^2) anti-hash test cases
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k))
        return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Use unordered_map with the custom hash
    unordered_map<long long, int, custom_hash> mp;

    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }

    vector<int> ans(n - k + 1);
    ans[0] = mp.size();

    for (int i = 1; i <= n - k; i++)
    {
        mp[arr[i - 1]]--;
        if (mp[arr[i - 1]] == 0)
        {
            mp.erase(arr[i - 1]);
        }
        mp[arr[i + k - 1]]++;
        ans[i] = mp.size();
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}