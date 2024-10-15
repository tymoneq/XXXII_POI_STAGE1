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
    else
        cout << "XD";

    cout << "\n";
    return 0;
}