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
        ll n, m;
        cin >> n >> m;
        vector<int> infected;
        for (int j = 0; j < m; j++) {
            ll a;
            cin >> a;
            infected.push_back(a);
        }
        sort(infected.begin(), infected.end());
        vector<ll> intervals;
        for (int j = 1; j < m; j++) {
            intervals.push_back(infected[j] - infected[j-1] - 1);
        }
        intervals.push_back(infected[0] + n - infected[m-1] - 1);
        sort(intervals.begin(), intervals.end());
        int day = 0;
        int protect = 0;
        // cout << "interval length : " << intervals.size() << ", m : " << m << endl;
        for (int j = m - 1; j >= 0; j--) {
            if (intervals[j] > 2*day) {
                if (intervals[j] == 2*day + 1) {
                    protect++;
                    day++;
                }    
                else {
                    protect += intervals[j] - 2*day - 1;
                    day += 2;
                }
            } else {
                break;
            }
        }
        cout << n - protect << endl;
    }

    return 0;
}