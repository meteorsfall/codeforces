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
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        ll a,b,c;
        cin >> a >> b >> c;
        vector<ll> nums = {a,b,c};
        // dbg("A B C %d %d %d", a, b, c);
        ll biggest = 0;
        for(int i = 0; i < 3; i++){
            if (nums[i] > biggest){
                biggest = nums[i];
            }
        }
        vector<ll> bignums = {biggest, biggest, biggest};
        for(int i = 0; i < 3; i++){
            for(int j = (i+1) % 3; j != i; j = (j + 1) % 3){
                if (nums[j] >= bignums[i]){
                    bignums[i]++;
                }
            }
        }
        cout << bignums[0] - nums[0] << " " << bignums[1] - nums[1] << " " << bignums[2] - nums[2] << endl;
    }
    cout << endl;
    
    return 0;
}