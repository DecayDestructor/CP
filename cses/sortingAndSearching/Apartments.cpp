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

// Template aliases for other containers
template <typename T>
using vec = vector<T>;

template <typename T>
using un_set = unordered_set<T>;

template <typename T>
using sset = set<T>;

template <typename T>
using mp = map<T, T>;

template <typename T>
using ump = unordered_map<T, T>;

template <typename T>
using stk = stack<T>;

template <typename T>
using que = queue<T>;

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
    ll n, m, k;
    cin >> n >> m >> k;
    vll apartment(n);
    inputArray<ll>(apartment, n);
    vll appartmentSize(m);
    inputArray<ll>(appartmentSize, m);
    sort(apartment.begin(), apartment.end());
    sort(appartmentSize.begin(), appartmentSize.end());
    ll person = 0;
    ll app = 0;
    ll count = 0;

    while (person < n)
    {
        while (app < m && apartment[person] < appartmentSize[app] - k)
        {
            app++;
        }
        if (app < m && apartment[person] >= appartmentSize[app] - k && apartment[person] <= appartmentSize[person] + k)
        {
            count++;
            person++;
            app++;
        }
        else
        {
            person++;
        }
    }
    print(count);
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