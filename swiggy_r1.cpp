//YashS
#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*

array -> 1 2 3 1 3 2

A  1  1  1
B     2  2
C        3


query -> empId, cmpId
*/



// void lru(vector<EmpQuery*> queries, int frames) {
//     int querySize = queries.size();

//     // {empId, cmpId}

//     EmpQuery* obj = new EmpQuery(123, "ABC");
//     // map<EmpQuery*, int> mp; // EmpQuery, Timestamp

//     priority_queue<int, vector<int>, greater<int>> pq;

// }


class EmpQuery {
public:
	int empId;
	string cmpId;
	EmpQuery(int eId, string cId) {
		empId = eId;
		cmpId = cId;
	}
};

class LRUCache {
	// store keys of cache
	// list<EmpQuery> dq;

	list<EmpQuery> cacheKeys;
	// store references of key in cache
	map<EmpQuery, string> cache;

	int cacheSize; // maximum capacity of cache

public:
	LRUCache(int n) { cacheSize = n; }
	void put(EmpQuery);
	string get(EmpQuery);
};

// Refers key x with in the LRU cache
void LRUCache::put(EmpQuery query)
{
	// not present in cache
	if (cache.find(query) == cache.end()) {
		// cache is full
		if (cacheKeys.size() == cacheSize) {
			// delete least recently used element
			EmpQuery last = cacheKeys.back();

			// Pops the last element
			cacheKeys.pop_back();

			// Erase the last
			cache.erase(last);
		}
	}
	// present in cache
	else
		cacheKeys.erase(query);

	// update reference
	cacheKeys.push_front(query);
	cache[query] = loadDB(query);
}

// Function to display contents of cache
string LRUCache::get(EmpQuery query)
{

	// Iterate in the deque and print
	// all the elements in it
	if (cache.find(query) == cache.end()) {
		return "404 Not Found";
	}
	string EmpName = cache[query];
	// have to update the order
	return EmpName;
}

signed main()
{
	int n, m;
	cin >> n >> m;
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}