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
        vector<int> cycle;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            cycle.push_back(a);
        }
        vector<int> sorted = cycle;
        sort(sorted.begin(), sorted.end());
        vector<tuple<int, int, int>> answers;
        for(int i = 0; i < n; i++){
            if(cycle[i] != sorted[i]){
                int index = -1;
                for(int j = i; j < n; j++){
                    if(cycle[j] == sorted[i]){
                        index = j;
                    }
                }
                vector<int> working(index - i + 1);
                working[0] = cycle[index];
                for(int j = 1; j < working.size(); j++){
                    working[j] = cycle[i + j - 1];
                }
                for(int j = i; j <= index; j++){
                    cycle[j] = working[j - i];
                }
                answers.push_back({i + 1, index + 1, index - i});
                if(index == -1){
                    cout << "Didn't find next number.\n";
                };
            }
        }
        cout << answers.size() << endl;
        for(int i = 0; i < answers.size(); i++){
            cout << get<0>(answers[i]) << " " << get<1>(answers[i]) << " " << get<2>(answers[i]) << endl;
        }
    }
    
    return 0;
}