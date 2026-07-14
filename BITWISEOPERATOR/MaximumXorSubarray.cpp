#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

int main()
{
    // Fast I/O
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

    vector<ll> left_bound(n), right_bound(n);
    stack<int> st;

    // 1. Previous Greater Element (STRICT: > arr[i])
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        left_bound[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop(); // Clear stack for next pass

    // 2. Next Greater or Equal Element (NON-STRICT: >= arr[i])
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        right_bound[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // 3. XOR Contribution Calculation
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        ll left_count = i - left_bound[i];
        ll right_count = right_bound[i] - i;

        // An element contributes to XOR sum only if it is the max
        // in an ODD number of subarrays (odd * odd = odd).
        if ((left_count & 1) && (right_count & 1))
        {
            result ^= arr[i];
        }
    }

    cout << result << "\n";
    return 0;
}