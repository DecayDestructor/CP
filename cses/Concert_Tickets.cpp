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
    ll n, m;
    cin >> n >> m;
    vll tickets(n);
    vll people(m);
    inputArray<ll>(tickets, n);
    inputArray<ll>(people, m);
    sort(tickets.begin(), tickets.end());
    map<ll, ll> mpp;
    for (int i = 0; i < m; i++)
    {
        ll answer = -1;
        ll left = 0;
        ll right = n - 1;
        ll target = people[i];
        while (left <= right)
        {
            ll middle = (left + right) / 2;
            if (tickets[middle] <= target && mpp[middle] == 0)
            {
                answer = max(answer, tickets[middle]);
                left = middle + 1;
                mpp[middle] = 1;
            }
            else if (tickets[middle] > target)
            {
                right = middle - 1;
            }
        }
        print(answer);
    }
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