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
    
    ll t;
    cin >> t;
    vector<vector<ll> > coord(t);
    for(ll i = 0; i < t; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        coord[i].push_back(x1);
        coord[i].push_back(y1);
        coord[i].push_back(x2);
        coord[i].push_back(y2);
    }

    for(ll i = 0; i < t; i++){
        ll x1 = coord[i][0];
        ll y1 = coord[i][1];
        ll x2 = coord[i][2];
        ll y2 = coord[i][3];
        vector<tuple<int, int, int>> top(y2 - y1 + 1);
        ll startsum = 1;
        for(ll j = 2; j <= x1; j++){
            startsum += j; 
        }
        for(ll j = 2; j <= y1; j++){
            startsum += x1 + j - 2;
        }
        top[0] = {x1, y1, startsum};
        for(ll j = 1; j < top.size(); j++){
            top[j] = {x1, y1 + x1 + j - 2}
        }
    }

    return 0;
}