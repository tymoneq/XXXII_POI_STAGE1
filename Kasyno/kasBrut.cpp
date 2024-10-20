#include <bits/stdc++.h>
#include "kaslib.h"

using namespace std;

typedef long long ll;

inline bool bin_search(vector<ll> &used, ll X)
{

    int lo = 0, hi = used.size() - 1, mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (used[mid] == X)
            return 1;

        if (used[mid] < X)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return 0;
}

inline bool prime(ll n, vector<ll> &used)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0 && bin_search(used, i))
            return 0;

    return 1;
}

int main()
{

    while (1)
    {

        ll N = DajN();
        vector<ll> checked;
        ll curent_x = 1;

        for (ll i = 2; i <= (N / curent_x); i++)
            if (prime(i, checked))
            {
                ll tmp = Pytaj(i);
                checked.push_back(i);
                if (tmp == i)
                {
                    curent_x *= i;
                    ll next_X = i;
                    while (next_X <= (N / i))
                    {
                        next_X *= i;
                        tmp = Pytaj(next_X);
                        if (next_X != tmp)
                            break;

                        curent_x *= i;
                    }
                }
            }

        Odpowiedz(curent_x);
    }
}#include <bits/stdc++.h>
#include "kaslib.h"

using namespace std;

typedef long long ll;

inline bool bin_search(vector<ll> &used, ll X)
{

    int lo = 0, hi = used.size() - 1, mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (used[mid] == X)
            return 1;

        if (used[mid] < X)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return 0;
}

inline bool prime(ll n, vector<ll> &used)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0 && bin_search(used, i))
            return 0;

    return 1;
}

int main()
{

    while (1)
    {

        ll N = DajN();
        vector<ll> checked;
        ll curent_x = 1;

        for (ll i = 2; i <= (N / curent_x); i++)
            if (prime(i, checked))
            {
                ll tmp = Pytaj(i);
                checked.push_back(i);
                if (tmp == i)
                {
                    curent_x *= i;
                    ll next_X = i;
                    while (next_X <= (N / i))
                    {
                        next_X *= i;
                        tmp = Pytaj(next_X);
                        if (next_X != tmp)
                            break;

                        curent_x *= i;
                    }
                }
            }

        Odpowiedz(curent_x);
    }
}