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
    for (int i = 0; i < tt; i++){
        int n, x;
        cin >> n >> x;
        vector<int> food;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            food.push_back(a);
        }
        int min = food[0];
        int max = food[0];
        int changes = 0;
        for (int j = 1; j < n; j++) {
            if (food[j] < min) {
                        min = food[j];
            } 
            if (food[j] > max) {
                        max = food[j];
            }
            if (max - min > 2*x ) {
                min = food[j];
                max = food[j];
                changes++;
            }
        }
        cout << changes << endl;
    }
    
    return 0;
}