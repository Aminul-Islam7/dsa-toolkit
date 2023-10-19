#include <bits/stdc++.h>

using namespace std;

// Calculates a^b in O(log(b))
int binPow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) // if b is odd
            res = res * a;
        a = a * a;
        b >>= 1; // b = b/2
    }
    return res;
}

// Calculates a^b (mod m) in O(log(b))
int binPowMod(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b)
    {
        if (b & 1) // if b is odd
            res = res * a % m;
        a = a * a % m;
        b >>= 1; // b = b/2
    }
    return res;
}

/*
    Explanations of the algorithm:
    https://youtu.be/K8mJ27S72v0 (Luv - Hindi)
*/

int main()
{
    cout << binPow(2, 10) << endl; // 1024
    cout << binPowMod(2, 10, 100) << endl; // 24
}