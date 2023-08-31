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
        ll n, k;
        cin >> n >> k;
        string s, curse;
        cin >> s >> curse;


        bool success = true;
        /* if (n == 5 && s[2] != curse[2]){
                success = false;
        }
        if (n == 4 && (s[1] != curse[1] || s[2] != curse[2]) ){
            success = false;
        }
        if (n == 1 || n == 2 || n == 3){
            if (s != curse){
                success = false;
            }
        } */
        
        if (n <= 2*k - 1 && n >= k){
            for(int i = k - 1 + n - (2*k - 1); i <= k - 1; i++){
                if (s[i] != curse[i]){
                    success = false;
                    break;
                }
            }
        }
        if (n <= k){
            for (int i = 0; i < n; i++){
                if (s[i] != curse[i]){
                    success = false;
                    break;
                }
            }
        }

        sort(s.begin(), s.end());
        sort(curse.begin(), curse.end());

        if (success && s == curse ){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
