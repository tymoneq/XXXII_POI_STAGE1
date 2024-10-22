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

    while (1)
    {

        ll N = DajN();
        ll curent_x = 1;
        ll tmp = 1;

        for (ll i = 2; (i <= (N / curent_x)); i++)
            if (prime(i))
            {
                if (tmp < (N / i))
                {
                    ll XD = Pytaj(tmp);
                    ll XD2 = i;
                    while (XD2 < N / i)
                        XD2 *= i;

                    curent_x *= Pytaj(XD2);
                    tmp = 1;
                    if (XD == 1)
                        continue;
                    ll x = XD;
                    while (x < N / XD)
                        x *= XD;
                    curent_x *= Pytaj(x);
                }
                else
                    tmp *= i;
            }

        Odpowiedz(curent_x);
    }
}