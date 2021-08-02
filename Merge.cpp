#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>&vec, int start, int end)
{
    int pivot = vec[end];
    int PartitionIndex = start;
    for(int i=start; i<end; i++)
    {
        if(vec[i] <= pivot)
        {
            swap(vec[i],vec[PartitionIndex]);
            PartitionIndex++;
        }
    }
    swap(vec[PartitionIndex],vec[end]);
    return PartitionIndex;
}

void Quicksort(vector<int>&vec, int start, int end)
{
    if(start >= end)
        return;
    int Pindex = Partition(vec,start,end);
    Quicksort(vec,start,Pindex-1);
    Quicksort(vec,Pindex+1,end);
}

void solve() 
{
    int n;
    //cout << "\n Enter the number of elements : ";
    cin >> n;
    //vector<int>vec = {10,2,1,3,4,5,6,7,4,5,6,7,5,3,2,1,5,6,7,8,9,0,0};
    vector<int>vec(n);
    for(int i=0; i<n; i++)
        cin >> vec[i];
    Quicksort(vec,0,n-1);
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
