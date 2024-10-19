#include <bits/stdc++.h>

using namespace std;

constexpr int B = 1e9;
int main()
{

    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int n = rand() % 20;
    n++;
    cout << n << "\n";

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int a = rand() % B;
            ++a;
            cout << a << " ";
        }

        cout << "\n";
    }
    return 0;
}