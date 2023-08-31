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
 
vector<ll> factorize(ll factor){
    vector<ll> factors;
    ll ntemp = factor;
    for (ll k = 2; k*k <= factor; k++){
        while (ntemp % k == 0){
            factors.push_back(k);
            ntemp /= k;
        }
        if (k > ntemp){
            break;
        }
    }
    if (ntemp != 1) {
        factors.push_back(ntemp);
    }
    sort(factors.begin(), factors.end());
    return factors;
}
 
void finish(ll j, ll n, vector<vector<ll>>& factors, vector<ll>& perm, vector<bool>& checked){
    ll factor = n/j;
    while (checked[j*factor] && factor >= 1){
        factor -= 1;
    }
    if (factor == 0){
        return;
    }
    if (factors.at(factor).size() == 0){
        factors[factor] = factorize(factor);
    }
    ll k = (ll)factors[factor].size() - 1;
    ///for (ll k = 0; k < (ll)factors[factor].size() - 1; k++){
        ll current = j*factors[factor][k];
        if (checked.at(current)){
            ///continue;
            return;
        }
        perm.push_back(current);
        checked.at(current) = true;
        finish(current, n, factors, perm, checked);
    ///}
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n;
        cin >> n;
 
        vector<bool> checked(n + 1, false);
        vector<ll> perm;
        vector<vector<ll>> factors(n+1, vector<ll>());
        perm.push_back(1);
        checked[1] = true;
        for (ll i = 2; i <= n; i++){
            if (checked[i]){
                continue;
            }
            perm.push_back(i);
            checked[i] = true;
            ll j = i;
            while(j*i <= n){
                if (checked[j*i]){
                    break;
                }
                perm.push_back(j*i);
                checked[j*i] = true;
                j *= i;
            }
            finish(j, n, factors, perm, checked);
        }
        //cout << "perm size: " << perm.size() << endl;
        for (ll i = 0; i < perm.size(); i++){
            cout << perm[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}