#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
vector<int> primes;
vector<bool> isPrime(N, true);

// Forms the sieve of Eratosthenes in O(n*log(log(n)))
void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (long long p = 2; p*p <= N; p++)
        if (isPrime[p])
            for (long long i = p * p; p <= N; p += p) isPrime[i] = false;
}

// Calculates the prime numbers up to N in O(n)
void calcPrimes()
{
    for (int i = 2; i <= N; i++)
        if (isPrime[i]) primes.push_back(i);
}

// Factorizes a number in O(sqrt(n))
vector<int> factorize(int n)
{
    vector<int> factors;
    for (int i = 2; i * 1LL * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// Factorizes a number in O(sqrt(n)/log(n)) using the sieve of Eratosthenes
vector<int> sieveFactorize(int n)
{
    vector<int> factors;
    for (auto i: primes)
    {
        if (i * 1LL * i > n) break;
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// Factorizes a number in the form of pairs (prime, exponent) in O(sqrt(n)/log(n))
vector< pair<int, int> > pairFactorize(int n)
{
    vector< pair<int, int> > factors;
    for (auto i: primes)
    {
        if (i * 1LL * i > n) break;
        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt > 0) factors.push_back({i, cnt});
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

int main()
{
    sieve(); // DONT FORGET TO CALL SIEVE :)
    calcPrimes(); // don't forget to call it too

    vector<int> factors1 = sieveFactorize(100);
    for (int factor : factors1)
        cout << factor << " ";
    cout << endl;

    vector< pair<int, int> > factors2 = pairFactorize(100);
    for (auto factor : factors2)
        cout << factor.first << " " << factor.second << endl;
    
}