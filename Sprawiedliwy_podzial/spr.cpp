#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;
bool ANS[N];
struct bitek
{
    ll Bajtyna, Bitek, indx = 0;
};

inline bool sorto(bitek &lhs, bitek &rhs) { return lhs.Bajtyna >= rhs.Bajtyna; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<bitek> Bohaterowie(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Bohaterowie[i].Bajtyna;
        Bohaterowie[i].indx = i;
    }
    for (int i = 0; i < n; i++)
        cin >> Bohaterowie[i].Bitek;

    sort(Bohaterowie.begin(), Bohaterowie.end(), sorto);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ANS[j] = 0;

        ll Bajtyna_Bajtyna = Bohaterowie[i].Bajtyna;
        ll Bajtyna_Bitek = Bohaterowie[i].Bitek;
        ll mnBajtyna = Bohaterowie[i].Bitek;

        ll Bitek_Bajtyna = 0;
        ll Bitek_Bitek = 0;
        ll mnBitek = numeric_limits<ll>::max();
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (Bajtyna_Bajtyna <= Bitek_Bajtyna)
            {
                mnBajtyna = min(mnBajtyna, Bohaterowie[j].Bitek);
                Bajtyna_Bajtyna += Bohaterowie[j].Bajtyna;
                Bajtyna_Bitek += Bohaterowie[j].Bitek;
            }
            else
            {
                mnBitek = min(mnBitek, Bohaterowie[j].Bajtyna);
                ANS[Bohaterowie[j].indx] = 1;
                Bitek_Bajtyna += Bohaterowie[j].Bajtyna;
                Bitek_Bitek += Bohaterowie[j].Bitek;
            }
        }

        if (Bajtyna_Bajtyna >= (Bitek_Bajtyna - mnBitek) && Bitek_Bitek >= (Bajtyna_Bitek - mnBajtyna))
        {
            for (int j = 0; j < n; j++)
                cout << ANS[j] << " ";
            cout << "\n";
            break;
        }
    }

    return 0;
}