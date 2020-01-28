// gcd, fermat, modulo
#include <iostream>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else b -= a;
    }
    return a;
}
ll modulo(ll x, ll y, ll p) {
    if (y == 0)
        return 1;
    ll temp = modulo(x, y/2, p);
    if (y % 2 == 0)
        return (temp * temp) % p;
    else return (temp * temp % p) * x % p;
}

bool fermat(ll m) {
    if (m == 1)
        return false;
    for (int i = 1; i <= 70; ++i) {
        ll a = 1 + rand() % (m - 1);
        if (gcd(a, m) != 1)
            return false;
        else {
            if (modulo(a, m - 1, m) != 1)
                return false;
        }
    }
    return true;
}

ll modulo1(ll base, ll e, ll mod) {
    ll a = 1;
    ll b = base;
    while (e > 0) {
        if (e % 2 == 1)
            a = (a * b) % mod;
        b = (b * b) % mod;
        e = e / 2;
    }
    return a % mod;
}
bool Fermat(ll m, int iterations) {
    if (m == 1) {
        return false;
    }
    for (int i = 0; i < iterations; i++) {
        ll x = rand() % (m - 1) + 1;
        if (modulo(x, m - 1, m) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int dem = 0;
    for (ll i = 1; i <= 10000000; ++i)
        if (fermat(i))
            ++dem;
    cout << dem;
    return 0;
}
