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
        int n;
        cin >> n;
        vector<vector<int>> students{n};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                int a;
                cin >> a;
                students[i].push_back(a);
            }
        }
        bool possible = false;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 5; j++){
                int only_i = 0;
                int only_j = 0;
                int both = 0;
                for(vector<int> student : students){
                    if(student[i] == 1 && student[j] == 1){
                        both++;
                    } else if (student[i] == 1){
                        only_i++;
                    } else if (student[j] == 1){
                        only_j++;
                    }
                }
                if(both >= abs(only_i - only_j) && both + only_i + only_j == n){
                    possible = true;
                }
            }
        }
        if (possible){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}