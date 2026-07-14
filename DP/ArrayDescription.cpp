#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // dp[i][j] stores the number of valid prefixes of length i ending with value j
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    // Initialize the first element
    if (arr[0] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        dp[0][arr[0]] = 1;
    }

    // Fill the dp matrix
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j + 1 <= m) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        else
        {
            int j = arr[i];
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (j + 1 <= m) 
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
    }

    // Calculate the total number of valid full arrays
    int res = 0;
    if (arr[n - 1] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            res = (res + dp[n - 1][j]) % mod;
        }
    }
    else
    {
        res = dp[n - 1][arr[n - 1]];
    }

    cout << res << "\n";
    return 0;
}