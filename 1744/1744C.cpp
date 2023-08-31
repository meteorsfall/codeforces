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
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s = s + s;
        
        if (c == 'g') {
            cout << 0 << endl;
            continue;
        }

        ll max_wait = 0;
        ll current_green = -1;
        for (ll i = 0; i < n; i++){
            if (s[i] == c) {
                if (i > current_green) {
                    for (ll j = i + 1; j < 2*n; j++) {
                        if (s[j] == 'g') {
                            current_green = j;
                            break;
                        }
                    }
                    
                }
                if (current_green - i > max_wait) {
                        max_wait = current_green - i;
                }
            }
        }
        cout << max_wait << endl;
    }

    return 0;
}
