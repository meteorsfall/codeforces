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
    for (int t = 0; t < tt; t++) {
        int n, l;
        cin >> n >> l;
        vector<int> wordforms(n);
        for (int i = 0; i < n; i++) {
            cin >> wordforms[i];
        }
        int average = 0;
        for (int bit = l - 1; bit >= 0; bit--) {
            int bitsum = 0;
            for (int word : wordforms) {
                bitsum += ( (word & (1 << bit)) >> bit); 
            }
            int averagebit = bitsum > n/2;
            average |= (averagebit << bit);
        }
        cout << average << endl;
    }
    return 0;
}