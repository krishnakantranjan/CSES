#include <iostream>
#include <vector>
#include <algorithm> // Required for std::lower_bound

using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    // Using vector instead of VLA (Variable-Length Array)
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            // Correct usage of std::lower_bound with iterators
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

            // Overwrite the existing element with the smaller value
            *it = arr[i];
        }
    }

    // The size of the 'lis' vector represents the length of the LIS
    cout << lis.size() << "\n";

    return 0;
}