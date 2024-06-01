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
        int m;
        cin >> m;
        vector<int> seq;
        for (ll i = 0; i < m; i++){
            int a;
            cin >> a;
            seq.push_back(a);
        }
    
        bool possible = true;
        ll opps = 0;
        for (int i = 1; (1 << i) <= m; i++){
            for (int j = 0; j < m; j += (1 << i) ){
                int range = 1 << i;
                int range_bottom;
                if (seq[j] % range == 0){
                    range_bottom = seq[j] - range + 1;
                } else {
                    range_bottom = (seq[j]/range) * range + 1;
                }
                int compare = seq[j + range/2];
                if (compare < range_bottom || compare >= range_bottom + range){
                    possible = false;
                }
                if (compare < seq[j]) {
                    opps++;
                }
            }
        }
        if (possible){
            cout << opps << endl;
        }  else {
            cout << -1 << endl;
        }
        
    }

    return 0;
}
