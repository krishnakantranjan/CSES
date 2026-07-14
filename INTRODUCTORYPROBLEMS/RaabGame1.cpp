#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        // 1. Invalid conditions check
        if ((a == 0 && b > 0) || (b == 0 && a > 0))
        {
            cout << "NO\n";
            continue;
        }

        if ((a + b) > n)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // 2. Player 1 ALWAYS plays 1 to n in order
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";

        // 3. Player 2 Output (Both are zero case)
        if (a == 0 && b == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }

        // 4. Player 2 Output (a != 0 and b != 0)
        int tie = n - (a + b);

        // Loop 1: Tied games at the start (1 to tie)
        for (int i = 1; i <= tie; i++)
        {
            cout << i << " ";
        }

        // Loop 2: Cards that give Player 2 'b' wins
        for (int i = n - b + 1; i <= n; i++)
        {
            cout << i << " ";
        }

        // Loop 3: Cards that give Player 1 'a' wins
        for (int i = tie + 1; i <= n - b; i++)
        {
            cout << i << " ";
        }

        cout << "\n";
    }
    return 0;
}