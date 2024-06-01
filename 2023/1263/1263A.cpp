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

    ll t, r, g, b;

    cin >> t;

    vector<ll> candies(3);

    for(int i = 0; i < t; i++){

        cin >> r >> g >> b;
        candies[0] = r;
        candies[1] = g;
        candies[2] = b;

        sort(candies.begin(), candies.end() );

        ll days = 0;

        ll diff = candies[1] - candies[0];
        days += diff;
        candies[1] -= diff;
        candies[2] -= diff;

        
        days += min(candies[2] /2, candies[0]) + candies[0];

        cout << days << endl;

    }    
    
    return 0;
}