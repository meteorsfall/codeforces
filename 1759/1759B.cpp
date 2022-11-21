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
        int m, s;
        cin >> m >> s;
        vector<int> elements;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            elements.push_back(a);
        }
        sort(elements.begin(), elements.end());
        int sum = 0;
        bool repeat = false;
        for (int i = 0; i < elements.size(); i++) {
            int prev = 0; 
            if (i != 0) {
                prev = elements[i-1];
            }
            if (prev == elements[i]) {
                repeat = true;
                //cout << "repeat prev: " << prev << " elements[i]: " << elements[i] << endl;
            }
            if (elements[i] - 1 != prev) {
                for (int j = prev + 1; j < elements[i]; j++) {
                    sum += j;
                    // cout << "append " << j << endl;
                }
            }
        }
        int biggest = elements[elements.size() - 1];
        while (sum < s){ 
            biggest++;
            sum += biggest;
            // cout << "append " << biggest << endl;
        }
        if (sum == s && !repeat) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}