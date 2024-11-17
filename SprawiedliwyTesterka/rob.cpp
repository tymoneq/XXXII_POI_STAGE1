#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);

    for (auto &el : A)
        cin >> el.first >> el.second;
    return 0;
}