#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;

    vector<ll> Bajtyna(n), Bitek(n);
    for (ll &a : Bajtyna)
        cin >> a;
    for (ll &a : Bitek)
        cin >> a;

    int MAXMASK = (1 << n) - 1;

    for (int mask = 0; mask <= MAXMASK; mask++)
    {
        ll bitekBitek = 0, bajtynaBitek = 0;
        ll mnbajtynaBitek = numeric_limits<int>::max();
        ll bitekBajtyna = 0, bajtynaBajtyna = 0;
        ll mnbitekBajtyna = numeric_limits<int>::max();

        for (int m = 0; m < n; m++)
        {
            if ((mask >> m) & 1)
            {
                bitekBitek += Bitek[m];

                bitekBajtyna += Bajtyna[m];
                mnbitekBajtyna = min(mnbitekBajtyna, Bajtyna[m]);
            }
            else
            {
                bajtynaBitek += Bitek[m];
                mnbajtynaBitek = min(mnbajtynaBitek, Bitek[m]);

                bajtynaBajtyna += Bajtyna[m];
            }
        }

        if ((bajtynaBitek - mnbajtynaBitek) <= bitekBitek && (bitekBajtyna - mnbitekBajtyna <= bajtynaBajtyna))
        {
            for (int m = 0; m < n; m++)
                cout << ((mask >> m) & 1) << " ";
            cout << "\n";
            // break;
        }
    }
}