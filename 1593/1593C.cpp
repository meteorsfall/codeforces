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
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        ll n, k;
        cin >> n >> k;
        // cout << "n: " << n << endl;
        vector<int> mice;
        ll cat_step = n;
        ll escaped_mice = 0;
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            mice.push_back(a);
        }
        sort(mice.begin(), mice.end());
        for(int i = mice.size() - 1; i >= 0; i--){
            if(n - cat_step >= mice[i]){
                break;
            }
            if(n - mice[i] <= cat_step){
                // cout << "n: " << n << endl;
                // cout << "n - mice[i]: " << n - mice[i] << endl;
                // cout << "catstep: " << cat_step << endl;
                escaped_mice++;
                cat_step -= n - mice[i];
                
            }
        }
        cout << escaped_mice << endl;
    }
    
    return 0;
}