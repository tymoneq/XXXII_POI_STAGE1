#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ziarno;
    cin >> ziarno;
    srand(ziarno);

    int n = (rand() % 5) + 1;
    vector<int> A;
    int b = (rand() % 8) + 1;
    A.push_back(b);
    for (int i = 0; i < n; i++)
    {
        b = (rand() % 10);
        A.push_back(b);
    }

    for (int &w : A)
        cout << w;
    return 0;
}
