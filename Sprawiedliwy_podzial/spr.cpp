#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;

bool ANS[N];

struct podzial
{
    ll Bajtyna, Bitek;
    int indx;
};

struct Bitekcomp
{
    bool operator()(const podzial &lhs, const podzial &rhs) const
    {
        if (lhs.Bitek == rhs.Bitek)
            return lhs.Bajtyna < rhs.Bajtyna;
        return lhs.Bitek > rhs.Bitek;
    }
};

struct Bajtynacomp
{
    bool operator()(const podzial &lhs, const podzial &rhs) const
    {
        if (lhs.Bajtyna == rhs.Bajtyna)
            return lhs.Bitek < rhs.Bitek;
        return lhs.Bajtyna > rhs.Bajtyna;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;
    vector<podzial> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i].Bajtyna;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i].Bitek;
        A[i].indx = i;
    }

    multiset<podzial, Bajtynacomp> Bajtyna;
    multiset<podzial, Bitekcomp> Bitek;
    ll Bajtyna_Bajtyna = 0, Bajtyna_Bitek = 0, mnBajtyna = numeric_limits<ll>::max(), Bitek_Bitek = 0, Bitek_Bajtyna = 0, mnBitek = numeric_limits<ll>::max();

    for (int i = 0; i < n; i++)
    {
        Bajtyna.insert(A[i]);
        Bitek.insert(A[i]);
    }

    for (int k = 0; k < n; k++)
    {
        if (Bajtyna_Bitek + Bajtyna.begin()->Bitek - min(mnBajtyna, Bajtyna.begin()->Bitek) <= Bitek_Bitek)
        {
            Bajtyna_Bajtyna += Bajtyna.begin()->Bajtyna;
            Bajtyna_Bitek += Bajtyna.begin()->Bitek;
            mnBajtyna = min(mnBajtyna, Bajtyna.begin()->Bitek);

            podzial a = *Bajtyna.begin();
            auto it = Bitek.find(a);
            Bitek.erase(it);
            Bajtyna.erase(Bajtyna.begin());
        }
        else
        {
            Bitek_Bitek += Bitek.begin()->Bitek;
            Bitek_Bajtyna += Bitek.begin()->Bajtyna;
            ANS[Bitek.begin()->indx] = 1;
            mnBitek = min(mnBitek, Bitek.begin()->Bajtyna);

            podzial a = *Bitek.begin();
            auto it = Bajtyna.find(a);
            Bajtyna.erase(it);
            Bitek.erase(Bitek.begin());
        }
    }

    if ((Bajtyna_Bitek - mnBajtyna) <= Bitek_Bitek && (Bitek_Bajtyna - mnBitek <= Bajtyna_Bajtyna))
    {
        for (int i = 0; i < n; i++)
            cout << ANS[i] << " ";
        cout << "\n";

        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        Bajtyna.insert(A[i]);
        Bitek.insert(A[i]);
        ANS[i] = 0;
    }
    Bajtyna_Bajtyna = 0, Bajtyna_Bitek = 0, mnBajtyna = numeric_limits<ll>::max(), Bitek_Bitek = 0, Bitek_Bajtyna = 0, mnBitek = numeric_limits<ll>::max();

    for (int k = 0; k < n; k++)
    {
        if (Bitek_Bajtyna + Bitek.begin()->Bajtyna - min(mnBitek, Bitek.begin()->Bajtyna) <= Bajtyna_Bajtyna)
        {
            Bitek_Bitek += Bitek.begin()->Bitek;
            Bitek_Bajtyna += Bitek.begin()->Bajtyna;
            ANS[Bitek.begin()->indx] = 1;
            mnBitek = min(mnBitek, Bitek.begin()->Bajtyna);

            podzial a = *Bitek.begin();
            auto it = Bajtyna.find(a);
            Bajtyna.erase(it);
            Bitek.erase(Bitek.begin());
        }

        else
        {
            Bajtyna_Bajtyna += Bajtyna.begin()->Bajtyna;
            Bajtyna_Bitek += Bajtyna.begin()->Bitek;
            mnBajtyna = min(mnBajtyna, Bajtyna.begin()->Bitek);

            podzial a = *Bajtyna.begin();
            auto it = Bitek.find(a);
            Bitek.erase(it);
            Bajtyna.erase(Bajtyna.begin());
        }
    }
    for (int i = 0; i < n; i++)
        cout << ANS[i] << " ";
    cout << "\n";

    return 0;
}