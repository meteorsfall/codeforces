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

int assign_rank (string a) {
    int x_count_a = 0;
        for (int i = 0; i < a.size(); i++){
            if (a[i] == 'X'){
                x_count_a++;
            } else {
                break;
            }
        }
    if (a == "M"){
        return 100;
    }
    if (a[a.size() - 1] == 'S'){
        return 99 - x_count_a;
    } else if (a[a.size() - 1] == 'L'){
        return 101 + x_count_a;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        string a, b;
        cin >> a >> b;
        int a_rank = assign_rank(a);
        int b_rank = assign_rank(b);
        if (a_rank < b_rank){
            cout << "<" << endl;
        } else if (a_rank > b_rank){
            cout << ">" << endl;
        } else {
            cout << "=" << endl;
        }
    }

    return 0;
}
