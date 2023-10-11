//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
Conditions:
1. Valeriu in cycle OR
2. distance of intersectionPoint from val < marcel
*/

vector<int> adj[N];
vector<int> color(N), par(N);
vector<vector<int>> cycles;

void dfs(int node, int parent, int& cyclenumber) {
    if (color[node] == 2) {
        return;
    }

    if (color[node] == 1) {
        vector<int> v;
        cyclenumber++;

        int cur = parent;
        v.push_back(cur);
        while (cur != node) {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[node] = parent;

    color[node] = 1;

    for (int v : adj[node]) {

        if (v == par[node]) {
            continue;
        }
        dfs(v, node, cyclenumber);
    }

    // completely visited.
    color[node] = 2;
}

bool BFS(int src, int dest, int n, int pred[], int dist[])
{

    list<int> queue;
    bool visited[n + 1];

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);


    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

int getDistance(int u, int v, int n) {
    int pred[n + 1], dist[n + 1];
    if (BFS(u, v, n, pred, dist) == false) {

    }
    return dist[v];
}

void yash()
{
    int n, a, b;
    cin >> n >> a >> b;

    cycles.clear();
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        color[i] = 0;
        par[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int intersectionPoint = 0;

    if (a == b) {
        cout << "NO\n";
        return;
    }

    int cyclenumber = 0;
    dfs(1, 0, cyclenumber);

    for (auto it : cycles) {

        for (auto it1 : it) {
            if (adj[it1].size() == 3) {
                intersectionPoint = it1;
            }
            if (it1 == b) {
                cout << "YES\n";
                return;
            }
        }
    }

    // cout << a << " " << b << " " << intersectionPoint << "\n";

    int distaceMarcel = getDistance(a, intersectionPoint, n);
    int distanceVal = getDistance(b, intersectionPoint, n);

    // cout << distaceMarcel << " " << distanceVal << '\n';

    if (distanceVal < distaceMarcel) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

signed main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    test
    yash();
    return 0;
}