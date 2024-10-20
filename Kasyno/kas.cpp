#include <bits/stdc++.h>
#include "kaslib.h"

using namespace std;

typedef long long ll;

inline bool prime(ll n)
{
    for (ll i = 3; i * i <= n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{

    while (1)
    {

        ll N = DajN();
        ll Y = (1 << 29); // Wysoka potęga 2 576460752303423488
        ll curent_x = Pytaj(Y);
        if (curent_x <= (1 << 8))
        {
            Szturchnij();
            continue;
        }

        for (ll i = 3; (i <= (N / curent_x)); i += 2)
        {
            if (prime(i))
            {
                ll tmp = i;
                while (tmp < (N / i))
                    tmp *= i;

                curent_x *= Pytaj(tmp);
            }
        }
        Odpowiedz(curent_x);
    }
}