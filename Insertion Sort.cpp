#include <bits/stdc++.h>
using namespace std;

void Insertionsort(vector<int>&vec)
{
    for(int i=1; i<vec.size(); i++)
    {
        int key = vec[i];
        int hole = i;
        while(hole > 0 && vec[hole-1] > key)
        {
            vec[hole] = vec[hole-1];
            hole--;
        }
        vec[hole] = key;
    }
}

void solve() 
{
    vector<int>vec = {4,2,5,6,1,3,1,2,3,4,5,6,7,8,9,0};
    Insertionsort(vec);
    for(auto it : vec)
        cout << it << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
