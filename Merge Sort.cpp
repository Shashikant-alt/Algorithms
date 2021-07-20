#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>&vec, vector<int>&left, vector<int>& right)
{
    int i=0, j=0, k=0;
    while((i < left.size()) && (j < right.size()))
    {
        if(left[i] <= right[j])
        {
            vec[k] = left[i];
            i++;
            k++;
        }
        else
        {
            vec[k] = right[j];
            j++;
            k++;
        }
    }
    while(i < left.size())
    {
        vec[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size())
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

void Mergesort(vector<int>&vec)
{
    if(vec.size() < 2)
        return;
    int mid = vec.size()/2;
    vector<int>left(mid);
    vector<int>right((vec.size()) - mid);
    for(int i=0; i<mid; i++)
        left[i] = vec[i];
    for(int i=mid; i<vec.size(); i++)
        right[i-mid] = vec[i];
    Mergesort(left);
    Mergesort(right);
    Merge(vec,left,right);
}

void solve() 
{
    vector<int>vec = {10,2,1,3,4,5,6,7,4,5,6,7,5,3,2,1,5,6,7,8,9,0,0};
    Mergesort(vec);
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
