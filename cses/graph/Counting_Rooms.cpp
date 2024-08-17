#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(i, n) for (i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
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

bool isValid(int row, int column, int n, int m)
{
    if (row < 0 || column < 0 || row >= n || column >= m)
    {
        return false;
    }
    return true;
}
void dfs(vector<vi> &visited, vector<vch> &graph, int row, int column, int n, int m)
{
    int rowDir[] = {1, 0, -1, 0};
    int colDir[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int rowTrav = rowDir[i] + row;
        int colTrav = colDir[i] + column;
        if (isValid(rowTrav, colTrav, n, m) && graph[rowTrav][colTrav] == '.' && !visited[rowTrav][colTrav])
        {
            // visited.insert({rowTrav, colTrav});
            visited[rowTrav][colTrav] = 1;
            dfs(visited, graph, rowTrav, colTrav, n, m);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vch> graph(n, vch(m));
    // int i = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    // set<pair<int, int>> visited;
    vector<vi> visited(n, vi(m, 0));
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' && !visited[i][j])
            {
                count++;
                // visited.insert({i, j});
                visited[i][j] = 1;
                dfs(visited, graph, i, j, n, m);
            }
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