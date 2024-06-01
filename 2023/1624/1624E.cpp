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

map<int, bool> memotable;
string s;

bool dp(int index, const map<string, tuple<int, int, int>>& segments) {
    if (memotable.count(index)) {
        return memotable[index];
    }

    bool ans;
    if (index == 0) {
        ans = false;
    } else if (index == 1 || index == 2) {
        ans = segments.count(s.substr(0, index + 1));
    } else {
        ans = dp(index - 2, segments) && segments.count(s.substr(index - 1, 2)) 
           || dp(index - 3, segments) && segments.count(s.substr(index - 2, 3));
    }

    return memotable[index] = ans;
}

int main() {
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        memotable.clear();

        int n, m;
        cin >> n >> m;
        vector<string> phonenumbers(n);
        for (int i = 0; i < n; i++) {
            cin >> phonenumbers[i];
        }
        cin >> s;
        
        map<string, tuple<int, int, int>> segments;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                string segment = phonenumbers[i].substr(j, 2);
                if (!segments.count(segment)){
                    segments[segment] = {j, j + 1, i};
                }
                if (j + 2 < m) {
                    segment = phonenumbers[i].substr(j, 3);
                    if (!segments.count(segment)){
                        segments[segment] = {j, j + 2, i};
                    }
                }
            }
        }

        vector<bool> works(m);
        works[0] = false;
        works[1] = segments.count(s.substr(0, 2));
        works[2] = segments.count(s.substr(0, 3));
        for(int i = 3; i < m; i++) {
            works[i] =
                segments.count(s.substr(i-1, 2)) && works[i-2]
             || segments.count(s.substr(i-2, 3)) && works[i-3];
        }

        if (!dp(m - 1, segments)) {
            cout << -1 << endl; 
        } else {
            vector<tuple<int, int, int>> ans_segments;
            int index = m-1;
            while (index > 0) {
                if (segments.count(s.substr(index-1, 2)) && (index - 2 < 0 || dp(index-2, segments))) {
                    ans_segments.push_back(segments[s.substr(index - 1, 2)]);
                    index -= 2;
                }
                else {
                    ans_segments.push_back(segments[s.substr(index - 2, 3)]);
                    index -= 3;
                }
            }
            reverse(ans_segments.begin(), ans_segments.end());

            cout << ans_segments.size() << endl;
            for(auto& as : ans_segments) {
                cout << get<0>(as) + 1 << " " << get<1>(as) + 1 << " " << get<2>(as) + 1 << endl;
            }
        }
    }
    return 0;
}