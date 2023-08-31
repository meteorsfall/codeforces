#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include <queue>

#ifdef SHOW_DEBUG
#define dbg(a, ...) printf("DEBUG: " a "\n", ##__VA_ARGS__)
#else
#define dbg(...) ((void*)(0))
#endif

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

bool is_prime(ll a){
    for (ll i = 2; i*i <= a; i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}



ll dp(ll remaining, ll index, vector<ll>& seq){
    if (remaining + index >= seq.size()){
        return 0;
    }
    if (remaining <= 0){
        return 0;
    }
    if (index >= seq.size()){
        return 0;
    }
    return seq[index] + dp(remaining - 1, index + 1, seq) + dp(remaining, index + 1, seq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*ll n;
    cin >> n;
    vector<ll> seq;
    for (ll i = 0; i < 2*n; i++){
        ll a;
        cin >> a;
        seq.push_back(a);
    }

    sort(seq.begin(), seq.end());
    vector<ll> prime;
    for (ll i = 0; i < seq.size(); i++){
        prime[i] = is_prime(seq[i]);
    }

    for (ll i = 0; i < seq.size(); i++){

    }*/

    vector<ll> seq;
    for (ll i = 0; i < 10; i++){
        seq.push_back(i);
    }

    cout << dp(5, 0, seq) << endl; 

    return 0;
}
