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

ll segment_sum(int i, int j, vector<ll> seq_sum){
    ll a = i == 0 ? 0 : seq_sum[i-1];
    return seq_sum[j] - a;
}

void print_array(vector<ll> seq) {
    for (int i = 0; i < seq.size(); i++){
        cout << seq[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        int n;
        cin >> n;
        vector<ll> seq;
        vector<ll> seq_sum;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            seq.push_back(a);
            if (i == 0){
                seq_sum.push_back(a);
            } else {
                seq_sum.push_back(seq_sum[i-1] + a);
            }
        }
        ll min_thick = n;
        for (ll i = 0; i < n; i++){
            ll match_sum = segment_sum(0, i, seq_sum);
            vector<int> indices(1, i);
            for (ll j = i+1; j < n; j++){
                ll cur_sum = segment_sum(indices[indices.size() - 1] + 1, j, seq_sum);
                if (cur_sum == match_sum) {
                    indices.push_back(j);
                } if (cur_sum > match_sum) {
                    break;
                }
            }   
            if (indices[indices.size() - 1] == n - 1){
                int longest_segment = 1;
                for (ll j = 0; j < indices.size(); j++){
                    int a = j == 0 ? -1 : indices[j-1];
                    int seg_size = indices[j] - a;
                    if (seg_size > longest_segment){
                        longest_segment = seg_size;
                    }
                }
                if (longest_segment < min_thick){
                    min_thick = longest_segment;
                    //cout << "match: " << match_sum << endl;
                }
            }
        }
        cout << min_thick << endl;
    
    }

    return 0;
}
