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

vector<int> elements;
vector<vector<short>> memotable;

int dp(int index, int xor_bit) {
    if (memotable[index][xor_bit] != -1){
        return memotable[index][xor_bit];
    }
    int ans;
    if (index == 0) {
        if ( (elements[0] ^ xor_bit) == 0) {
            ans = 0;
        } else {
            ans = 1;
        }
    } else {
        if ( (elements[index] ^ xor_bit) == 0) {
            ans = dp(index - 1, 0);
        } else {
            int a = dp(index - 1, elements[index] ^ xor_bit);
            int b = dp(index - 1, 0);
            if (a < b) {
                ans = a + 1;
            } else {
                ans = b + 1;
            }
        }
    }
    return memotable[index][xor_bit] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++){
        int n;
        cin >> n;
        elements.clear();
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            elements.push_back(a);
        }
        memotable = vector<vector<short>>(n, vector<short>(1<<13, -1));
        cout << dp(n - 1, 0) << endl;
    }

    return 0;
}
