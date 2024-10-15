#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;
bool ANS[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n > 20)
    {
        vector<pair<int, int>> A(n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> A[j].first;
                A[j].second = j;
            }

        sort(A.begin(), A.end(), greater<pair<int, int>>());

        ll Bitek = 0, Bajtyna = 0;
        int mn_Bitek = numeric_limits<int>::max(), mn_Bajtyna = numeric_limits<int>::max();

        for (int i = 0; i < n; i++)
        {
            if (Bitek <= Bajtyna)
            {
                Bitek += A[i].first;
                mn_Bitek = min(A[i].first, mn_Bitek);
                ANS[A[i].second] = 1;
            }
            else
            {
                Bajtyna += A[i].first;
                mn_Bajtyna = min(A[i].first, mn_Bajtyna);
            }
        }

        if (Bitek >= Bajtyna - mn_Bajtyna && Bajtyna >= Bitek - mn_Bitek)
            for (int i = 0; i < n; i++)
                cout << ANS[i] << " ";
        vector<pair<int, int>> A(n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> A[j].first;
                A[j].second = j;
            }

        sort(A.begin(), A.end(), greater<pair<int, int>>());

        ll Bitek = 0, Bajtyna = 0;
        int mn_Bitek = numeric_limits<int>::max(), mn_Bajtyna = numeric_limits<int>::max();

        for (int i = 0; i < n; i++)
        {
            if (Bitek <= Bajtyna)
            {
                Bitek += A[i].first;
                mn_Bitek = min(A[i].first, mn_Bitek);
                ANS[A[i].second] = 1;
            }
            else
            {
                Bajtyna += A[i].first;
                mn_Bajtyna = min(A[i].first, mn_Bajtyna);
            }
        }

        if (Bitek >= Bajtyna - mn_Bajtyna && Bajtyna >= Bitek - mn_Bitek)
            for (int i = 0; i < n; i++)
                cout << ANS[i] << " ";
    }
    else
    {
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
                break;
            }
        }
    }

    return 0;
}