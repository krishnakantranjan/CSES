#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        int cbits = 0;
        long long n = i;
        while (n > 0)
        {
            n = n & (n - 1);
            cbits++;
        }
        ans += cbits;
    }
    cout << ans << endl;
    return 0;
}