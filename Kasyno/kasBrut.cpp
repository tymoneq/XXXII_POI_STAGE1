#include <bits/stdc++.h>
#include "kaslib.h"

using namespace std;

typedef long long ll;

inline bool prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{
    ll N = DajN();
    vector<ll> Primes;
    ll prime501 = 0;
    ll i = 2;
    while (i > 0)
    {
        if (Primes.size() == 3000 && prime(i))
        {
            prime501 = i;
            break;
        }

        if (prime(i))
            Primes.push_back(i);
        ++i;
    }

    vector<ll> TruePrimes;

    for (auto it = Primes.begin(); it != Primes.end(); it++)
    {
        ll b = *it;
        while (b < (N / *it))
            b *= *it;
        TruePrimes.push_back(b);
    }

    while (1)
    {
        ll curent_x = 1;

        int j = 0;
        for (ll y : TruePrimes)
        {
            curent_x *= Pytaj(y);
            if (j < Primes.size() - 1 && curent_x > (N / Primes[j + 1]))
                break;
            if (j == 0 && curent_x < 1024)
                break;
            if (j == 1000 && curent_x < (ll)1e11)
                break;
            j++;
        }

        if (curent_x <= (N / prime501))
        {
            Szturchnij();
            continue;
        }

        Odpowiedz(curent_x);
    }
}