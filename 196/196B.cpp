#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

namespace std {
    template <class T1, class T2>
    struct hash<std::pair<T1, T2>> {
        inline size_t operator()(const std::pair<T1, T2> &v) const {
            return std::hash<T1>()(v.first) ^ std::hash<T2>()(v.second);
        }
    };
};

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

int place_on_maze(int a, int dimension) {
    int ret = a % dimension;
    if (ret < 0) {
        ret += dimension;
    }
    return ret;
}

bool explore_maze(const vector<vector<bool>>& maze, pair<int, int> S) {
    int n = maze.size();
    int m = maze[0].size();
    
    unordered_set<pair<int, int>> visited;
    visited.reserve(1500*1500+10);
    visited.insert(S);
    vector<pair<int, int>> Q = {S};
    int qsize = 1;
    Q.resize(1500*1500+10);
    while (qsize > 0) {
        pair<int, int> curpos = Q[--qsize];
        int y = curpos.first;
        int x = curpos.second;
        if ((int)visited.size() > 1500*1500 + 1) {
            return true;
        }
        pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(pair<int, int>& dir : dirs) {
            int newy = y + dir.first;
            int newx = x + dir.second;
            /*
            cout << "y: " << newy << ", x: " << newx << ", ";
            cout << "place_on_maze: (" << place_on_maze(newy, n) << ", " << place_on_maze(newx, m) << "), ";
            cout << "maze: " << maze[place_on_maze(newy, n)][place_on_maze(newx, m)] << ", ";
            cout << "visited: " << visited[{newy, newx}] << endl;
            */
            if (maze[place_on_maze(newy, n)][place_on_maze(newx, m)] && visited.count({newy, newx}) == 0) {
                visited.insert({newy, newx});
                Q[qsize++] = {newy, newx};
                //cout << "newy: " << newy << ", newx: " << newx << endl;
            }
        }
    }
    //cout << "possible: " << possible << ", S: {" << S.first << ", " << S.second << "}" << endl;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> S;
    vector<vector<bool>> maze(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            maze[i][j] = s[j] != '#';
            if (s[j] == 'S') {
                S = {i, j};
            }
        }
    }

    bool possible = explore_maze(maze, S);

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}