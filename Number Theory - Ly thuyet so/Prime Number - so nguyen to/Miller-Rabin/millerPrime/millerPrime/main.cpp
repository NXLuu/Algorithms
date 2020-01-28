// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 23, 13, 1662803, 31, 73

#include <iostream>
#define ll long long int
using namespace std;
int check[4] = {2, 7, 61, 13};

ll modulo(ll x, ll y, ll p) {
    if (y == 0)
        return 1;
    ll temp = modulo(x, y/2, p);
    if (y % 2 == 0)
        return temp * temp % p;
    else return (temp * temp % p) * x % p;
}

bool millerTest(ll d, ll n, int a) {
    ll x = modulo(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool isPrime(ll n) {
    for (int i = 0; i < 4; ++i) {
        if (n == check[i])
            return true;
    }
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    ll d = n - 1;
    while(d % 2 == 0) { // n - 1 = d * 2^m;
        d /= 2;
    }
    for (int i = 0; i < 4; ++i) {
        if (millerTest(d, n, check[i]) == false)
            return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    
    cout << cnt;
    return 0;
}
