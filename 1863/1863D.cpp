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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n, m;
        cin >> n >> m;
        vector<string> board(n, "");
        for (ll i = 0; i < n; i++){
            cin >> board[i];
        }

        vector<ll> num_u_per_row(n, 0);
        vector<ll> num_l_per_col(m, 0);
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                if (board[i][j] == 'U'){
                    num_u_per_row[i]++;
                }
                if (board[i][j] == 'L'){
                    num_l_per_col[j]++;
                }
            }
        }

        


        bool possible = true;
        for (ll i = 0; i < n; i++){
            if (num_u_per_row[i] % 2 != 0){
                possible = false;
                break;
            }
        }
        for (ll i = 0; i < m; i++){
            if (num_l_per_col[i] % 2 != 0){
                possible = false;
                break;
            }
        }

        if (!possible){
            cout << -1 << endl;
            continue;
        }

        vector<bool> set_l_col_black(m, true);
        vector<bool> set_u_row_black(n, true);
        vector<vector<char>> new_board(n, vector<char>(m, '*'));
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                if (board[i][j] == 'U'){
                    if (set_u_row_black[i]){
                        new_board[i][j] = 'B';
                        new_board[i+1][j] = 'W';
                        set_u_row_black[i] = false;
                    } else {
                        new_board[i][j] = 'W';
                        new_board[i+1][j] = 'B';
                        set_u_row_black[i] = true;
                    }
                }
                if (board[i][j] == 'L'){
                    if (set_l_col_black[j]){
                        new_board[i][j] = 'B';
                        new_board[i][j+1] = 'W';
                        set_l_col_black[j] = false;
                    } else {
                        new_board[i][j] = 'W';
                        new_board[i][j+1] = 'B';
                        set_l_col_black[j] = true;
                    }
                }
                if (board[i][j] == '.'){
                    new_board[i][j] = '.';
                }
            }
        }
        
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                cout << new_board[i][j];
            }
            cout << endl;
        }


    }

    return 0;
}
