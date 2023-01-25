//YashS
// TREE DIAMETER
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;
 
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
 
vector<int> adj[N];
vector<int> downPath(N);  // Length of longest path in subtree rooted at node u, such that parth starts at u
vector<int> diameter(N);
 
void dfs(int node, int par) {
    int bestChildDownPath = 0;
    int leaf = 1;
 
    for (auto it : adj[node]) {
        if (it != par) {
            leaf = 0;
            dfs(it, node);
            bestChildDownPath = max(bestChildDownPath, downPath[it]);
        }
    }
 
    if (leaf)downPath[node] = 0;
    else downPath[node] = 1 + bestChildDownPath;
}
 
int go(int node, int par) {
 
    // 2choices
    // Path goes through this node -> Then problem reduced to and of all subtrees of children of this node
    // Path does not go through this node  -> Then take the two longest downPath children
    int ans = 0;
    vector<int> childrenDownPaths;
 
    for (int it : adj[node]) {
        if (it != par) {
            go(it, node);
            childrenDownPaths.push_back(downPath[it]);
            ans = max(ans, diameter[it]);
        }
    }
 
    int numOfchildren = childrenDownPaths.size();
    sort(all(childrenDownPaths));
 
    if (numOfchildren == 0)diameter[node] = 0; //If leaf
    else if (numOfchildren == 1)diameter[node] = 1 + childrenDownPaths[0];  // No choice, go down from this path
    else diameter[node] = 2 + childrenDownPaths[numOfchildren - 1] + childrenDownPaths[numOfchildren - 2];  // Adding the two biggest subtrees to make a V like path.
 
    diameter[node] = max(diameter[node], ans);
}
 
void yash()
{
    int n;
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
 
    // for (int i = 1; i <= n; i++) {
    //     cout << downPath[i] << " ";
    // } cout << "\n";
 
    go(1, 0);
 
    cout << diameter[1] << '\n';
 
}
 
signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // test
    yash();
    return 0;
}