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
#include <string>

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

    string pi = "3141592653589793238462643383279502884197169399375";
    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        string a;
        cin >> a;
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == pi[i]){
                count++;
            } else {
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}
