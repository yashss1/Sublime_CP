class UnionFind {
	vector<int> id;
public:
	UnionFind(int n) : id(n) {
		iota(begin(id), end(id), 0);
	}
	void connect(int a, int b) {
		id[find(a)] = find(b);
	}
	int find(int a) {
		return id[a] == a ? a : (id[a] = find(id[a]));
	}
	int connected(int a, int b) {
		return find(a) == find(b);
	}
};