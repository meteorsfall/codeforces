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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n, a, q;
        cin >> n >> a >> q;
        string s;
        cin >> s;
        ll certain = false;
        ll possible = false;
        ll num_active = a;
        ll ever_active = a;
        if (a == n){
            certain = true;
        }
        for (ll i = 0; i < q; i++){
            
            if (s[i] == '+'){
                num_active++;
                ever_active++;
            } else {
                num_active--;
            }
            if (num_active == n){
                certain = true;
            }
            //cout << "ever_active: " << ever_active << endl;
            if (ever_active == n){
                possible = true;
            }
        }
        if (certain){
            cout << "YES";
        } else if (possible){
            cout << "MAYBE";
        } else {
            cout << "NO";
        }
        cout << endl;   

    }

    return 0;
}
