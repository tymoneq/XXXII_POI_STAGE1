#include <bits/stdc++.h>

using namespace std;
int main()
{
    ifstream plik, plik_2;
    string test, test_2;

    cin >> test;
    test_2 = "w.out";
    test += ".out";
    plik.open(test);
    plik_2.open(test_2);
    int a, b, counter = 1;
    bool error = false;
    while (plik >> a && plik_2 >> b)
    {
        if (!(a == b))
        {
            cout << "Error in line " << counter << "\n";
            error = true;
        }
        counter += 1;
    }
    if (!error)
        cout << "\n1000% ";
    if (error)
        cout << "\nERROR";
    return 0;
}