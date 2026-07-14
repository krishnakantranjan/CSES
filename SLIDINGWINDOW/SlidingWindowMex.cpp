#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    // Fast I/O
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

    set<int> unseen;
    map<ll, int> seen;

    // The MEX for a window of size k can never exceed k.
    for (int i = 0; i <= k; i++)
    {
        unseen.insert(i);
    }

    // Process initial window of size k
    for (int j = 0; j < k; j++)
    {
        seen[arr[j]]++;
        unseen.erase(arr[j]);
    }

    // Print MEX for the first window
    cout << *unseen.begin() << " ";

    // Slide the window
    int i = 0;
    for (int j = k; j < n; j++)
    {
        // 1. Remove outgoing element arr[i]
        seen[arr[i]]--;
        if (seen[arr[i]] == 0)
        {
            seen.erase(arr[i]);
            // If the removed element is <= k, it becomes a candidate MEX again
            if (arr[i] <= k)
            {
                unseen.insert(arr[i]);
            }
        }

        // 2. Add incoming element arr[j]
        seen[arr[j]]++;
        unseen.erase(arr[j]);

        // 3. Move left pointer forward
        i++;

        // 4. Output current MEX
        cout << *unseen.begin() << " ";
    }

    cout << "\n";
    return 0;
}