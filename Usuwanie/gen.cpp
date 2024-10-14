#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    int ziarno;
    cin >> ziarno;

    srand(ziarno);

    int a = rand() % N;
    int b = rand() % N;

    cout << min(a, b) << " " << max(a, b) << "\n";

    return 0;
}