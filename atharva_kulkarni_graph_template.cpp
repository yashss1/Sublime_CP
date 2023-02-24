//Written by : Atharva Kulkarni (Naruto_cm)
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef std::vector<ll> vll;
typedef map<ll,ll>mll;
const ll mod = 1e9 + 7,inf = 1e18;//998244353
#define in(n)          ll n;cin>>n;
#define inp(a,n)        vll a(n);for(ll i = 0;i<n;i++) cin>>a[i];
#define rep(i,s,e)  for(__typeof(e) i = s;i<e;i++) 
#define sz(a)           ll(a.size())
#define nl              cout<<endl;
#define pb              push_back
#define vec(a)          (a).begin(),(a).end()
const int N = 5e5 + 100;
void print(ll a){cout<<a;nl;}
void print(vll a){for(auto i : a)cout<<i<<" ";nl;}
void print(string s){cout<<s<<endl;}


ll sizeset[100001];
ll arr2[100001];
ll pts[100001];
void make_set(ll i)
{
    arr2[i] = i;
    sizeset[i] = 1;
    pts[i] = 1;
}

ll find_set(ll i)
{
    if(i == arr2[i]) return i;

    return arr2[i] = find_set(arr2[i]);

}

void set_union(ll i, ll j)
{
    ll a = find_set(i);
    ll b = find_set(j);
    pts[a]++;
    if(a != b)
    {
        if(sizeset[a] < sizeset[b]) swap(a,b);
        arr2[b] = a;
        sizeset[a] += sizeset[b];
    }
}
class Graph
{
    int V;
    vll *adj;

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new vll[V + 1];
    }

    void addEdge(ll u,ll v)
    {
        adj[u].pb(v);
    }
    bool cycle_helper(int i,bool *visited,bool *rec)
    {
        visited[i] = true;
        rec[i] = true;
    
        for(auto j : adj[i])
        {
            if(!visited[j] && cycle_helper(j,visited,rec))
            {
                return true;
            }
            else if(rec[j])
            {
                return true;
            }
        }
        rec[i] = false;
        return false;
    }
    int isCycle()
    {
        bool *visited = new bool[V+1];
        bool *rec = new bool[V+1];
        rep(i,1,V+1)
        {
            visited[i] = false;
            rec[i] = false;
        }
        int ans = 0;
        rep(i,1,V+1)
        {
            if(visited[i] == 0)
            {
                ans+=cycle_helper(i,visited,rec);
            }
        }
        return ans;
    }
    void topo(ll i,vector<ll>&ans,bool *visited)
    {
        visited[i] = true;
        for(auto j : adj[i])
        {
            if(visited[j] == false)
            {
                topo(j,ans,visited);
            }
        }
        ans.pb(i);
    }
    vector<ll> topologicalSort()
    {
        bool *visited = new bool[V+1];
        rep(i,1,V+1)
        {
            visited[i] = false;
        }
        vector<ll>ans;
        rep(i,1,V+1)
        {
            if(visited[i] == 0)
            {
                topo(i,ans,visited);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
void solve()
{
    // in(n);inp(a,n);
    in(n);in(m);

    Graph g(n);

    vll x(m),y(m);

    for(int i = 1;i<=n;i++)make_set(i);

    set<ll> st;
    int steps = m;

    for(int i = 0;i<m;i++)
    {
        cin >> x[i] >> y[i];
        if(x[i] == y[i])steps--;
        else g.addEdge(x[i],y[i]);          
    }


    //connected components + steps

    int ans = g.isCycle();
    print(steps + ans);
}



signed main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    // cout<<fixed<<setprecision(x)<<endl;
    for(ll i = 1;i<=t;i++)
    {
        //cout << "Case #"<<i<<": ";
        solve();
    }
}