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


class node {
public:
	int key, value;
	node* next, *prev;

	node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

void printDoublyLinkedList(node* first) {
	node* curr = first;
	while (curr != NULL) {
		cout << curr->value << " -> ";
		curr = curr->next;
	}
	cout << '\n';
}

class dll {
public:
	node* front, *back;
	dll() {
		front = new node(0, -1);
		back = new node(100000, -1);
	}
};


void lfu_cache()
{
	int size;
	cout << "\n______________________________________________________________\n";
	cout << "Enter the size of the cache : ";
	cout << "\n______________________________________________________________\n";
	cin >> size;

	map<int, dll*> cache;
	map<int, node*> frequency;
	int currentCapacity = 0;

	while (1) {
		cout << "\n______________________________________________________________\n";
		cout << "Enter the operation.\n1. Put\n2. Get\n3. Exit program\n";
		cout << "______________________________________________________________\n";
		int input;
		cin >> input;

		if (input == 2) { // get
			int key;
			cout << "Enter the key you want to get\n";
			cin >> key;


		} else if (input == 1) { // put
			int key, value;
			cout << "Enter the number you want to put {key, value}\n";
			cin >> key >> value;

			if (cache.find(key) != cache.end()) {
				//
			}



		} else {
			break;
		}
	}
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	lfu_cache();
	return 0;
}