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
    for (int i = 0; i < tt; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> unhappiness;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            unhappiness.push_back(a);
        }
        vector<int> friends(n);
        int friendsum = 0;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            friends[a-1]++;
            friends[b-1]++;
            friendsum++;
        }
        if (friendsum % 2 == 0){
            cout << 0 << endl;
        } else {
            int least_unhappy = 1000;
            int least_unhappy_index = 0;
            for (int j = 0; j < n; j++) {
                if (friends[j] % 2 == 1 && unhappiness[j] < least_unhappy) {
                    least_unhappy = unhappiness[j];
                    least_unhappy_index = j;
                }
            }
            cout << least_unhappy << endl;
            // cout << "index: " << least_unhappy_index << endl;
        }
    }

    return 0;
}