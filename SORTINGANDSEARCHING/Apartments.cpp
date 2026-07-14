#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <cmath>     // Required for std::abs

using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k))
        return 0;

    vector<int> applicants(n);
    for (int i = 0; i < n; i++)
    {
        cin >> applicants[i];
    }

    vector<int> apartments(m);
    for (int i = 0; i < m; i++)
    {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, ans = 0;

    while (i < n && j < m)
    {
        // Case 1: Apartment size is within acceptable range [a - k, a + k]
        if (abs(applicants[i] - apartments[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        // Case 2: Apartment is too small for applicant's desired size
        else if (apartments[j] < applicants[i] - k)
        {
            j++; // Move to a larger apartment
        }
        // Case 3: Apartment is too big for applicant's desired size
        else
        {
            i++; // Move to next applicant needing a larger apartment
        }
    }

    cout << ans << "\n";
    return 0;
}