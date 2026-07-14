#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    /*
        IMPORTANT----
        Binary Search(lower bound, upper bound)also applicable in set, map, multiset and multimap remember this.
    */
    map<int, int> ticket_price; // Stores {price, frequency}
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        ticket_price[price]++;
    }

    for (int i = 0; i < m; i++)
    {
        int max_pay;
        cin >> max_pay;

        // upper_bound returns the first ticket strictly greater than max_pay
        auto it = ticket_price.upper_bound(max_pay);

        // If upper_bound points to begin(), all available tickets cost > max_pay
        if (it == ticket_price.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            // Decrement iterator to get the largest price <= max_pay
            --it;
            cout << it->first << "\n";

            // Decrement ticket count and erase if out of stock
            it->second--;
            if (it->second == 0)
            {
                ticket_price.erase(it);
            }
        }
    }

    return 0;
}