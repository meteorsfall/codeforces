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
        string a, b;
        cin >> a >> b;

        string the_template;
        //shared string
        bool shared = false;
        for (ll i = 0; i < a.size() - 1; i++){
            for (ll j = 0; j < b.size() - 1; j++) {
                if (a[i] == b[j] && a[i+1] == b[j+1]) {
                    shared = true;
                    the_template = "*";
                    the_template += a[i];
                    the_template += a[i+1];
                    the_template += "*";
                }
            }
        }
        bool end = false;
        if ( a[0] == b[0]){
            end = true;
            the_template = a[0];
            the_template += "*";
        }
        if (a[a.size() - 1] == b[b.size() - 1] ) {
            end = true;
            the_template = "*";
            the_template += a[a.size() - 1];
        }

        if (shared || end) {
            cout << "YES" << endl;
            cout << the_template << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }

    return 0;
}
