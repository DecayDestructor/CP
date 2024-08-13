#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;

template <typename T1, typename T2>
using vpp = std::vector<std::pair<T1, T2>>;

// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << nl;
    }
}
void solve()
{
    ll n;
    cin >> n;
    vpp<ll, ll> time;
    for (int i = 0; i < n; i++)
    {
        ll start, end;
        cin >> start >> end;
        time.push_back({start, 1});
        time.push_back({end, -1});
    }
    sort(time.begin(), time.end());
    ll maxi = 0;
    ll count = 0;
    for (auto it : time)
    {
        count = count + it.second;
        maxi = max(maxi, count);
    }
    print(maxi);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}