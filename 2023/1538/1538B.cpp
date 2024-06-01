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
    int t, n, a, sum, k;
    cin >> t;
    vector<int> candies;
    for(int tt = 0; tt < t; tt++) {
        candies = {};
        cin >> n;
        sum = 0;
        k = 0;
        for(int i = 0; i < n; i++){
            cin >> a;
            dbg("%d", a);
            candies.push_back(a);
            sum += a;
        }

        if(sum % n != 0){
            cout << -1 << endl;
            continue;
        } 
        for(int i = 0; i < n; i++){
            if(candies[i] > sum/n){
                k++;
            }
        }
        cout << k << endl;
    }
    return 0;
}