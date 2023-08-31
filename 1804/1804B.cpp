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
        ll n, k, d, w;
        cin >> n >> k >> d >> w;
        vector<ll> seq;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            seq.push_back(a);
        }

        ll opened = 0;
        ll current_doses = 0;
        ll waiting_time = -1;
        for (ll i = 0; i < n; i++){
            
            if (current_doses <= 0 || seq[i] > waiting_time + d){
                waiting_time = seq[i] + w;
                current_doses = k - 1; 
                opened++;
            } else {
                current_doses--;
            } 
            //cout << "opened: " << opened << ", current_doses: " << current_doses << ", waiting_time: " << waiting_time << endl;
        }
        cout << opened << endl;
    }

    return 0;
}
