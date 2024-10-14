#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, parzyste = 0, nieparzyste = 0;
    cin >> a >> b;

    for (ll i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            ++parzyste;
        else
            ++nieparzyste;
    }

    ll res = parzyste / 2 + nieparzyste / 2;
    res *= 2;

    cout << res << "\n";

    return 0;
}