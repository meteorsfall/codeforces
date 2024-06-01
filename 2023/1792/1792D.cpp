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

struct Node {
    vector<Node*> children;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> perms(n, vector<int>(m));
        Node* root = new Node;
        root->children = vector<Node*>(m, nullptr) ;
        for (ll i = 0; i < n; i++) { 
            Node* tracker = root;
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                a--;
                perms[i][j] = a;
                if (tracker->children[a] == nullptr){
                    tracker->children[a] = new Node;
                    tracker->children[a]->children = vector<Node*>(m, nullptr);
                }
                tracker = tracker->children[a];
            }
            
        }

        vector<vector<int>> ideal_perms(n, vector<int>(m));
        for (ll i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                int p_j = perms[i][j];
                ideal_perms[i][p_j] = j;
            }
        }

        vector<int> answers(n, 0);
        for (ll i = 0; i < n; i++) {
            Node* tracker = root;
            for (int j = 0; j < m; j++){
                int a = ideal_perms[i][j];
                if (tracker->children[a] == nullptr){
                    break;
                } else {
                    answers[i]++;
                    tracker = tracker->children[a];
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            cout << answers[i] << " ";
        }
        cout << answers[n - 1] << endl;
    }

    return 0;
}
