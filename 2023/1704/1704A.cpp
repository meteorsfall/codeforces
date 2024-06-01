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

    int tt;
    cin >> tt;
    for (int i = 0; i < tt; i++){
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int b_index = m - 1;
        bool fail = false;
        for (int j = 0; j < m; j++) {
            if (a[n - j] != b[m - j]) {
                fail = true;
            }
        }
        if (a[n - m] != b[0] && !fail) {
            fail = true;
            if (n > m){
                for (int j = 0; j < n - m; j++) {
                    if (a[j] == b[0]) {
                        fail = false;
                    }
                }
            }
        }
        if (!fail) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}