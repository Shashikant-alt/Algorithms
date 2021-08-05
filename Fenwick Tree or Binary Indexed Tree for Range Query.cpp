#include <iostream>
using namespace std;

#define int long long

int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
    BITree[index] += val;
    index += index & (-index);
    }
}

int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int* BITree = constructBITree(a,n);
    for(int i=1; i<=q; i++)
    {
        int x,l,r;
        cin >> x >> l >> r;
        if(x == 0)
        {
            a[l] = r;
            updateBIT(BITree,n,l,r);
        }
        else if(x == 1)
        {
            int p1 = getSum(BITree,r-1);
            int p2 = getSum(BITree,l-1);
            cout << p1 - p2 << "\n";
        }
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
