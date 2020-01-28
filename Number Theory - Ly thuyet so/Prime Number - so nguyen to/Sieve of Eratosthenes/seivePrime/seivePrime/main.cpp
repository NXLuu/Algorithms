#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
const long long int MAX = 1e1 + 10;

vector<ll> calc_prime() {
    vector<ll> sievePrime(MAX, true);
    sievePrime[0] = sievePrime[1] = false;
    for (ll i = 2; i * i < MAX; ++i) {
        if (sievePrime[i]) {
            for (ll j = i * i; j < MAX; j+=i) {
                sievePrime[j] = false;
            }
        }
    }
    return sievePrime;
}
vector<ll> calc_prime2() {
    vector<ll> sievePrime(MAX, true);
    sievePrime[0] = sievePrime[1] = false;
    for (ll i = 3; i * i < MAX; i+= 2) {
        if (sievePrime[i/2]) {
            for (ll j = i * i; j < MAX; j+=i*2) {
                sievePrime[j/2] = false;
            }
        }
    }
    return sievePrime;
}

int main() {
    vector<ll> prime = calc_prime2();
    for (int i = 1; i <= 10; ++i)
        if (prime[i])
            cout << i << endl;
    return 0;
}
