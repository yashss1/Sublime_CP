//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

// TRIE
// Solved on 27-01-23
struct node{
    map<int, node*> mp;
    bool isWord;
    node(){
        isWord = false;
    }
};
node* root;

void insert(vector<pair<int,int>> &s){
    node* curr = root;

    for(auto x : s){
        int ch = x.second;
        if(curr->mp[ch] == nullptr){
            curr->mp[ch] = new node();
        }

        curr = curr->mp[ch];
    }
    curr->isWord = true;
}

void yash()
{
	int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    root = new node();

    for(auto &i : v){
        vector<pair<int,int>> temp;
        for(int idx = 0; idx < m; idx++){
            temp.push_back({i[idx], idx + 1});
        }
        sort(temp.begin(), temp.end());

        insert(temp);
    }

    for(auto &x : v){
        node* curr = root;
        int cnt = 0;
        for(int i=0; i<m; i++){
            
            if(curr->mp[x[i]] == nullptr){
                break;
            }

            cnt++;
            curr = curr->mp[x[i]];
        }
        cout << cnt << " ";
    }
    cout << '\n';
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