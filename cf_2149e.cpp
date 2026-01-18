//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
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

// SOURCE -> https://www.geeksforgeeks.org/dsa/count-of-distinct-numbers-in-an-array-in-a-range-for-online-queries-using-merge-sort-tree/
// Function to merge the right
// and the left tree
void merge(vector<int> tree[], int treeNode)
{
	int len1 = tree[2 * treeNode].size();
	int len2 = tree[2 * treeNode + 1].size();
	int index1 = 0, index2 = 0;

	// Fill this array in such a
	// way such that values
	// remain sorted similar to mergesort
	while (index1 < len1 && index2 < len2) {

		// If the element on the left part
		// is greater than the right part
		if (tree[2 * treeNode][index1]
		        > tree[2 * treeNode + 1][index2]) {

			tree[treeNode].push_back(
			    tree[2 * treeNode + 1][index2]);
			index2++;
		}
		else {
			tree[treeNode].push_back(
			    tree[2 * treeNode][index1]);
			index1++;
		}
	}

	// Insert the leftover elements
	// from the left part
	while (index1 < len1) {
		tree[treeNode].push_back(
		    tree[2 * treeNode][index1]);
		index1++;
	}

	// Insert the leftover elements
	// from the right part
	while (index2 < len2) {
		tree[treeNode].push_back(
		    tree[2 * treeNode + 1][index2]);
		index2++;
	}
	return;
}

// Recursive function to build
// segment tree by merging the
// sorted segments in sorted way
void build(vector<int> tree[], int* arr, int start, int end,
           int treeNode)
{
	// Base case
	if (start == end) {
		tree[treeNode].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;

	// Building the left tree
	build(tree, arr, start, mid, 2 * treeNode);

	// Building the right tree
	build(tree, arr, mid + 1, end, 2 * treeNode + 1);

	// Merges the right tree
	// and left tree
	merge(tree, treeNode);
	return;
}

// Function similar to query() method
// as in segment tree
int query(vector<int> tree[], int treeNode, int start,
          int end, int left, int right)
{

	// Current segment is out of the range
	if (start > right || end < left) {
		return 0;
	}
	// Current segment completely
	// lies inside the range
	if (start >= left && end <= right) {

		// as the elements are in sorted order
		// so number of elements greater than R
		// can be find using binary
		// search or upper_bound
		return tree[treeNode].end()
		       - upper_bound(tree[treeNode].begin(),
		                     tree[treeNode].end(), right);
	}

	int mid = (start + end) / 2;

	// Query on the left tree
	int op1 = query(tree, 2 * treeNode, start, mid, left,
	                right);
	// Query on the Right tree
	int op2 = query(tree, 2 * treeNode + 1, mid + 1, end,
	                left, right);
	return op1 + op2;
}


void yash()
{
	int n, k, L, R;
	cin >> n >> k >> L >> R;
	vector<int> v(n);
	for (int i = 0; i < n; i++ ) {
		cin >> v[i];
	}


	int next_right[n + 1];
	// Initialising the tree
	vector<int> tree[4 * n];

	map<int, int> ump;

	// Construction of next_right
	// array to store the
	// next index of occurrence
	// of elements
	for (int i = n - 1; i >= 0; i--) {
		if (ump[v[i]] == 0) {
			next_right[i] = n;
			ump[v[i]] = i;
		}
		else {
			next_right[i] = ump[v[i]];
			ump[v[i]] = i;
		}
	}
	// building the mergesort tree
	// by using next_right array
	build(tree, next_right, 0, n - 1, 1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = L, r = min(n - i + 1, R), temp = -1;
		if (r < l) continue;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (i + mid - 1 >= n) {
				r = mid - 1;
				continue;
			}
			int dist = query(tree, 1, 0, n - 1, i, (i + mid - 1));
// 			cout << i << " " << (i + mid - 1) << " ___ " << dist << " " << mid<< '\n';

			if (dist <= k) {
				l = mid + 1;
				if (dist == k) {
					temp = mid;
				}
			} else {
				r = mid - 1;
			}
		}

		l = L, r = min(n - i + 1, R);
		int temp1 = -1;
		if (r < l) continue;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (i + mid - 1 >= n) {
				r = mid - 1;
				continue;
			}
			int dist = query(tree, 1, 0, n - 1, i, (i + mid - 1));
// 			cout << i << " " << (i + mid - 1) << " ___ " << dist << " " << mid<< '\n';

			if (dist < k) {
				l = mid + 1;
				if (dist == k) {
					temp1 = mid;
				}
			} else {
				if (dist == k) {
					temp1 = mid;
				}
				r = mid - 1;
			}
		}
		if (temp == -1 || temp1 == -1) {
			continue;
		}
// 		cout << i << " -> " << temp << " " << temp1 << '\n';
		ans += (temp - temp1 + 1);
	}

	cout << ans << '\n';

}

signed main()
{
// 	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}