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
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

struct Node {
    int val;
    Node* left, *right;
    string res;
    Node(int x) {
        left = nullptr;
        right = nullptr;
        val = x;
        res = "";
    }
};

map<string, int> mp;
string dfs(Node* node) {
    if (node == nullptr) {
        return "";
    }

    string curr = to_string(node -> val);
    string s1 = dfs(node -> left);
    string s2 = dfs(node -> right);
    s1 += curr;
    s1 += s2;

    (node -> res) = s1;
    mp[s1]++;

    return s1;
}

void yash()
{
    int x;
    cin >> x;
    Node* root = new Node(1);
    // Node* leftChild = new Node(89);
    // Node* rightChild = new Node(69);
    // root -> right = rightChild;
    // cout << (root->right->val) << '\n';

    Node* n1 = new Node(2);
    Node* n2 = new Node(2);
    root -> left = n1;
    root -> right = n2;

    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    n1 -> left = n3;
    n1 -> right = n4;

    n3 = new Node(4);
    n4 = new Node(5);
    n2 -> left = n3;
    n2 -> right = n4;

    dfs(root);

    int ans = 0;
    for (auto it : mp) {
        ans += (it.second * (it.second - 1) / 2);
    }
    cout << ans << '\n';
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