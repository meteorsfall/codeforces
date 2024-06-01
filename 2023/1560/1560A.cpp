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

int threes[1001];

int main() {

    int t; 
    cin >> t;
    threes[1] = 1;
    for(int i = 2; i <= 1000; i++){
        threes[i] = threes[i-1] + 1;
        while( threes[i] % 10 == 3 || threes[i] % 3 == 0){
            threes[i]++;
        }
    }
    for(int tt = 0; tt < t; tt++){
        int a;
        cin >> a;
        cout << threes[a] << endl;
    }
    
    return 0;
}