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

void set_blue(int loc, int n, vector<int>& a, vector<int>& is_red, set<int>& twos, set<int>& ones, set<int>& zeroes, int& coins){
    is_red[loc] = true;
    coins++;
    if (a[loc] == 2){
        twos.erase(loc);
    } else if (a[loc] == 1){
        ones.erase(loc);
    } else {
        zeroes.erase(loc);
    }
}

void left_iterate(int loc, int n, vector<int>& a, vector<int>& is_red, set<int>& twos, set<int>& ones, set<int>& zeroes, int& coins) {
    
    int cur = loc - 1;
    while (cur >= 0) {
        if (is_red[cur] == true){
            break;
        }
        is_red[cur] = true;
        if (a[cur] == 2){
            twos.erase(cur);
        } else if (a[cur] == 1){
            ones.erase(cur);
        } else {
            zeroes.erase(cur);
        }
        if (cur > 0 && is_red[cur-1] == false && a[cur] > 0){
            cur--;
        } else {
            break;
        }
    }
    
}

void right_iterate(int loc, int n, vector<int>& a, vector<int>& is_red, set<int>& twos, set<int>& ones, set<int>& zeroes, int& coins){
    int rightcur = loc + 1;
    while (rightcur < n) {
        if (is_red[rightcur] == true){
            break;
        }
        is_red[rightcur] = true;
        if (a[rightcur] == 2){
            twos.erase(rightcur);
        } else if (a[rightcur] == 1){
            ones.erase(rightcur);
        } else {
            zeroes.erase(rightcur);
        }
        if (rightcur < n-1 && is_red[rightcur+1] == false && a[rightcur] > 0){
            rightcur++;
        } else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<int> a(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> is_red(n, false);
    set<int> twos;
    set<int> ones;
    set<int> zeroes;
    for (ll i = 0; i < n; i++){
        if (a[i] == 2) {
            twos.insert(i);
        } else if (a[i] == 1) {
            ones.insert(i);
        } else {
            zeroes.insert(i);
        }
    }

    int coins = 0;
    while(twos.size() > 0){
        int smallest = *twos.begin();
        cout << smallest << 
        set_blue(smallest, n, a, is_red, twos, ones, zeroes, coins);
        left_iterate(smallest, n, a, is_red, twos, ones, zeroes, coins);
        right_iterate(smallest, n, a, is_red, twos, ones, zeroes, coins);
    }
    while (ones.size() > 0){
        int smallest = *ones.begin();
        set_blue(smallest, n, a, is_red, twos, ones, zeroes, coins);
        if (smallest > 0 && is_red[smallest-1] == true){
            left_iterate(smallest, n, a, is_red, twos, ones, zeroes, coins);
        } else {
            right_iterate(smallest, n, a, is_red, twos, ones, zeroes, coins);
        }
    }
    coins += zeroes.size();

    cout << coins << endl; 

    return 0;
}
