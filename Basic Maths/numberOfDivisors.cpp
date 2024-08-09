#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i * i <= n; i++) // tc-> root(n)
    {
        if (n % i == 0)
        {
            count++;
            if (i != n / i)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

int countDivisorsTillN(int n)
{
    vector<int> numberOfDivisors(n + 1, 0); // tc->n*root(n)
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i * i <= n; i++) // tc-> root(n)
        {
            if (n % i == 0)
            {
                numberOfDivisors[i]++;
                if (i != n / i)
                {
                    numberOfDivisors[i]++;
                }
            }
        }
    }
}
int countDivisorsTillN2(int n)
{
    vector<int> numberOfDivisors(n + 1, n);
    for (int i = 1; i <= n; i++) // tc->n logn
    {
        for (int j = i; j <= n; j = j + i)
        {
            numberOfDivisors[j]++;
        }
    }
}

int sieveOfEratosthenese(int n)
{
    vector<int> sieve(n + 1, 1); 
    sieve[1] = 0;
    for (int i = 2; i <= n; i++) //tc-> nlog(log(n))
    {
        if (!sieve[i])
            continue;
        for (int j = i * i; j <= n; j++)
        {
            sieve[j] = 0;
        }
    }
}