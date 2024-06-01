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

bool valid_window(char window, char window_right, vector<string> valid_combos){
    for (ll i = 0; i < valid_combos.size(); i++){
        if ()
    }
}

pair<ll, ll> mark_two_beds(ll two_beds_left, vector<string>& min_windows, ll floor, bool need_light){
    ll two_bed = 0;
    ll occupied = 0;
    ll m = min_windows[floor].size();
    for (ll j = 0; j < m; j++){
        if (valid_window(min_windows[floor][j], need_light) ) {
                if (j < m-1 && valid_window(min_windows[floor][j+1], need_light) && two_bed < two_beds_left){
                    min_windows[floor][j] = '*';
                    min_windows[floor][j+1] = '*';
                    two_bed++;
                    occupied++;
                } 
        }
    }
    return {two_bed, occupied};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<string> windows;
    for (ll i = 0; i < n; i++){
        string a;
        cin >> a;
        windows.push_back(a);
    }

    vector<string> min_windows = windows;
    ll two_bed = 0;
    ll one_bed = 0;
    ll occupied = 0;
    for (ll i = 0; i < n; i++){
        ll two_bed_floor = 0;
        ll one_bed_floor = 0;
        ll occupied_floor;
        
    }

    return 0;
}
