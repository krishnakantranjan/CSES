#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k))
        return 0;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<ll, int> freq;
    map<int, set<ll>> inv_freq;

    // Process first window of size k
    for (int j = 0; j < k; j++)
    {
        int prevfreq = freq[arr[j]]++;
        int currfreq = freq[arr[j]];

        if (prevfreq >= 1)
        {
            inv_freq[prevfreq].erase(arr[j]);
            if (inv_freq[prevfreq].empty())
            {
                inv_freq.erase(prevfreq);
            }
        }
        inv_freq[currfreq].insert(arr[j]);
    }

    auto last_entry = inv_freq.rbegin();
    ll ele = *(last_entry->second.begin());
    cout << ele << " ";

    int i = 0;
    for (int j = k; j < n; j++)
    {
        // Remove left element arr[i] from window
        int out_prev_freq = freq[arr[i]]--;
        inv_freq[out_prev_freq].erase(arr[i]);
        if (inv_freq[out_prev_freq].empty())
        {
            inv_freq.erase(out_prev_freq);
        }
        if (freq[arr[i]] > 0)
        {
            inv_freq[freq[arr[i]]].insert(arr[i]);
        }
        i++; // Slide left pointer forward

        // Add incoming element arr[j] to window
        int prevfreq = freq[arr[j]]++;
        int currfreq = freq[arr[j]];

        if (prevfreq >= 1)
        {
            inv_freq[prevfreq].erase(arr[j]);
            if (inv_freq[prevfreq].empty())
            {
                inv_freq.erase(prevfreq);
            }
        }
        inv_freq[currfreq].insert(arr[j]);

        last_entry = inv_freq.rbegin();
        ele = *(last_entry->second.begin());
        cout << ele << " ";
    }
    cout<<endl;
    return 0;
}