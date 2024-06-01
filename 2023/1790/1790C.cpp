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
        cin >> n;
        vector<vector<int>> perms(n, vector<int>(n-1));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - 1; j++){
                int a;
                cin >> a;
                perms[i][j] = a;
            }
        }
        
        int index_one, index_two;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                if (perms[i][0] != perms[j][0] && perms[i][n-2] != perms[j][n-2]){
                    index_one = i;
                    index_two = j;
                }
            }
        }
        vector<int> final_perm;
        if (perms[index_one][1] == perms[index_two][0]) {
            final_perm = perms[index_one];
            final_perm.push_back(perms[index_two][n-2] );
        } else {
            final_perm = perms[index_two];
            final_perm.push_back(perms[index_one][n-2]);
        } 

        for (int i = 0; i < n; i++){
            cout << final_perm[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
