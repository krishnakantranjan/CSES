#include <iostream>
#include <vector>

// PBDS headers for GCC
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

// Define PBDS ordered set storing pair<ll, int> to safely support duplicate elements
typedef tree<
    pair<ll, int>,
    null_type,
    less<pair<ll, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

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

    ordered_multiset st;

    // Lower median index calculation
    int m = (k - 1) / 2;

    // Process initial window of size k
    for (int j = 0; j < k; j++)
    {
        st.insert({arr[j], j});
    }

    // Output median for 1st window
    cout << st.find_by_order(m)->first << " ";

    // Slide window across remaining array
    int i = 0;
    for (int j = k; j < n; j++)
    {
        // Remove left element
        st.erase({arr[i], i});
        i++; // Slide left pointer

        // Add right element
        st.insert({arr[j], j});

        // Output lower median for current window
        cout << st.find_by_order(m)->first << " ";
    }
    cout << "\n";

    return 0;
}