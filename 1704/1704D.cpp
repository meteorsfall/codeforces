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
    
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> c_arrays(n, vector<ll>(m));
        vector<vector<ll>> prefix_arrays(n, vector<ll>(m));
        vector<ll> sum_prefix(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll a;
                cin >> a;
                c_arrays[i][j] = a;
                if (j == 0) {
                    prefix_arrays[i][0] = a;
                    // cout << "prefix_array[" << i << "][0] = " << a << " ";
                } else {
                    prefix_arrays[i][j] = prefix_arrays[i][j-1] + a;
                    // cout << "prefix_array[" << i << "][" << j << "] = " << prefix_arrays[i][j] << endl; 
                }
            }
            for (int j = 0; j < m; j++) {
                sum_prefix[i] += prefix_arrays[i][j];
            }
        }
        ll same_sum;
        if (sum_prefix[0] == sum_prefix[1]){
            same_sum = sum_prefix[0];
        } else if (sum_prefix[0] == sum_prefix[2]) {
            same_sum = sum_prefix[0];
        } else {
            same_sum = sum_prefix[1];
        }
        for (int i = 0; i < n; i++) {
            if (sum_prefix[i] != same_sum) {
                cout << i + 1 << " " << same_sum - sum_prefix[i] << endl;
            }
        }
    }

    return 0;
}