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

int wormhelper(vector<vector<bool>>& grid, int y, int x, pair<int, int> first_move, pair<int, int> second_move){
    int ans = 0;
    bool is_first = true;
    while(true) {
        pair<int, int> move = is_first ? first_move : second_move;
        if(y < 0 || grid.size() <= y || x < 0 || grid[0].size() <= x || grid[y][x]){
            break;
        }
        y += move.first;
        x += move.second;
        ans++;
        is_first = !is_first;
    }
    return ans;
}

int worm(vector<vector<bool>>& grid, int y, int x, bool is_top_left, bool is_starting_horizontal){
    if(!is_top_left && is_starting_horizontal){
        return wormhelper(grid, y, x, {0, 1}, {1, 0});
    } else if (!is_top_left && !is_starting_horizontal){
        return wormhelper(grid, y, x, {1, 0}, {0, 1});
    } else if (is_top_left && is_starting_horizontal){
        return wormhelper(grid, y, x, {-1, 0}, {0, -1});
    } else {
        return wormhelper(grid, y, x, {0, -1}, {-1, 0});
    }
}

int main() {
    int n,m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    ll paths = 0;
    //todo
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            int diffy = n - 1 - y;
            int diffx = m - 1 - x;
            if(diffy > diffx){
                diffy = diffx + 1;
            } else if (diffx > diffy) {
                diffx = diffy + 1;
            }
            paths += diffx + diffy + (diffx < diffy ? 2*diffx : 2*diffy) + 1;
            dbg("x: %d\ny: %d\ndiffx, diffy: %d,%d", x, y, diffx, diffy);
        }
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        bool orig = grid[y][x];
        grid[y][x] = false;
        int wormthere = worm(grid, y, x, true, true)*worm(grid, y, x, false, true) + 
            worm(grid, y, x, true, false)*worm(grid, y, x, false, false) - 1;
        grid[y][x] = !orig;
        //dbg("newgrid: %d\nwormthere: %d", grid[y][x], wormthere);
        paths += grid[y][x] ? -wormthere : wormthere; 
        cout << paths << endl;
    }   
    return 0;
}