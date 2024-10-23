#include <bits/stdc++.h>

using namespace std;

constexpr int BASE = 1 << 18;

struct wal
{
    int szybkosc, zwinnosc;
};

inline bool sorto(wal &lhs, wal &rhs) { return lhs.szybkosc < rhs.szybkosc; }
inline bool sortBSzybkosc(wal &lhs, wal &rhs) { return lhs.szybkosc > rhs.szybkosc; }
inline bool sortBZwinnosc(wal &lhs, wal &rhs) { return lhs.zwinnosc > rhs.zwinnosc; }

int Tree[BASE << 1];

inline int querry(int r)
{
    int l = BASE;
    r += BASE;
    int suma = 0;

    while (l / 2 != r / 2)
    {
        if (l % 2 == 0)
            suma += Tree[l + 1];
        if (r % 2 == 1)
            suma += Tree[r - 1];
        r /= 2, l /= 2;
    }

    return suma;
}

inline void upt(int v)
{
    v += BASE;
    Tree[v] = 1;
    v /= 2;
    while (v > 0)
    {
        Tree[v] = Tree[v * 2] + Tree[v * 2 + 1];
        v /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<wal> Roboty(n), B;
    vector<int> A;
    for (int i = 0; i < n; i++)
        cin >> Roboty[i].szybkosc >> Roboty[i].zwinnosc;

    sort(Roboty.begin(), Roboty.end(), sorto);

    for (int i = 0; i < n; i++)
    {

        int ile_pokona = (Roboty[i].szybkosc - 1) + (Roboty[i].zwinnosc - 1) - querry(Roboty[i].zwinnosc);
        if (ile_pokona == n - 1)
            A.push_back(i);
        else
            B.push_back(Roboty[i]);
        upt(Roboty[i].zwinnosc);
    }

    // liczenie wyniku
    bool T = 0;
    if (A.size() % 2 == 1 && B.size() > 0)
    {
        sort(B.begin(), B.end(), sortBSzybkosc);

        for (int w : A)
            if (B[0].szybkosc > Roboty[w].szybkosc || B[0].zwinnosc > Roboty[w].zwinnosc)
            {
                T = 1;
                break;
            }

        sort(B.begin(), B.end(), sortBZwinnosc);
        for (int w : A)
            if (B[0].szybkosc > Roboty[w].szybkosc || B[0].zwinnosc > Roboty[w].zwinnosc)
            {
                T = 1;
                break;
            }
    }

    if (A.size() % 2 == 1 && !T)
        cout << "NIE\n";
    else
        cout << "TAK\n";
    return 0;
}