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
    map<ll, ll> TruePrimes;
    vector<ll> Combinations;
    ll tmp = 1;
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

    for (ll it : Primes)
    {
        ll b = it;
        while (b < (N / it))
            b *= it;
        TruePrimes[it] = b;
    }

    i = 0;
    while (i < Primes.size())
    {
        if (tmp > (N / Primes[i]))
        {
            Combinations.push_back(tmp);
            tmp = 1;
        }
        else
        {
            tmp *= Primes[i];
            ++i;
        }
    }

    while (1)
    {
        ll curent_x = 1;
        auto it = TruePrimes.begin();
        for (int j = 0; j < Combinations.size(); j++)
        {
            tmp = Pytaj(Combinations[j]);
            curent_x *= tmp;
            while (tmp > 1)
            {
                if (tmp % (it->first) == 0)
                {
                    ll XD = Pytaj(it->second);
                    curent_x *= XD / it->first;
                    tmp /= it->first;
                }
                it++;
            }
            if (j == 0 && curent_x < 100'000)
                break;

            auto itr = it;
            itr++;

            if (itr != TruePrimes.end() && tmp > (N / (itr->first)))
                break;

            if (j == 125 && curent_x < 1'000'000'000'000)
                break;
        }

        if (curent_x <= (N / prime501))
        {
            Szturchnij();
            continue;
        }

        Odpowiedz(curent_x);
    }
}