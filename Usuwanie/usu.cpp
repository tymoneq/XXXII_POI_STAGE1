#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, x1, x2, x3, x4;
    cin >> a >> b;

    x1 = b / 2;
    x2 = (a - 1) / 2;
    x3 = (b + 1) / 2;
    x4 = a / 2;

    ll res = ((x1 - x2) / 2 + (x3 - x4) / 2) * 2;

    cout << res << "\n";
    return 0;
}