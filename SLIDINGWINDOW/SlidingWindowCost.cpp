#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

multiset<ll> left_set, right_set;
ll leftsum = 0, rightsum = 0;

// Keep left_set size equal to (k + 1) / 2 and right_set size equal to k / 2
void rebalance()
{
    while (left_set.size() > right_set.size() + 1)
    {
        auto it = prev(left_set.end()); // largest in left
        ll val = *it;
        left_set.erase(it);
        leftsum -= val;

        right_set.insert(val);
        rightsum += val;
    }
    while (left_set.size() < right_set.size())
    {
        auto it = right_set.begin(); // smallest in right
        ll val = *it;
        right_set.erase(it);
        rightsum -= val;

        left_set.insert(val);
        leftsum += val;
    }
}

void addEle(ll num)
{
    if (left_set.empty() || num <= *left_set.rbegin())
    {
        left_set.insert(num);
        leftsum += num;
    }
    else
    {
        right_set.insert(num);
        rightsum += num;
    }
    rebalance();
}

void removeEle(ll num)
{
    auto it = left_set.find(num);
    if (it != left_set.end())
    {
        leftsum -= num;
        left_set.erase(it);
    }
    else
    {
        it = right_set.find(num);
        rightsum -= num;
        right_set.erase(it);
    }
    rebalance();
}

ll getCost()
{
    ll median = *left_set.rbegin();
    // Total steps to make all elements equal to median:
    // (median * size(left) - leftsum) + (rightsum - median * size(right))
    ll cost = (median * (ll)left_set.size() - leftsum) +
              (rightsum - median * (ll)right_set.size());
    return cost;
}

int main()
{
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

    // Process initial window
    for (int j = 0; j < k; j++)
    {
        addEle(arr[j]);
    }

    cout << getCost() << " ";

    // Slide window
    int i = 0;
    for (int j = k; j < n; j++)
    {
        addEle(arr[j]);
        removeEle(arr[i]);
        i++;
        cout << getCost() << " ";
    }

    cout << "\n";
    return 0;
}