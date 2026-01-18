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

/*
OUTPUT:

______________________________________________________________
Enter the size of the cache :
______________________________________________________________
4

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
2 6
-1 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
4 7
-1 -> 7 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
8 11
-1 -> 11 -> 7 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
7 10
-1 -> 10 -> 11 -> 7 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
2
Enter the key you want to get
2
The value of 2 is : 6
-1 -> 6 -> 10 -> 11 -> 7 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
2
Enter the key you want to get
8
The value of 8 is : 11
-1 -> 11 -> 6 -> 10 -> 7 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
5 6
-1 -> 6 -> 11 -> 6 -> 10 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
2
Enter the key you want to get
7
The value of 7 is : 10
-1 -> 10 -> 6 -> 11 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
1
Enter the number you want to put {key, value}
5 7
-1 -> 7 -> 10 -> 11 -> 6 -> -1 ->

______________________________________________________________
Enter the operation.
1. Put
2. Get
3. Exit program
______________________________________________________________
3

*/

class node {
public:
	int value, key;
	node* next;
	node* prev;

	node(int value, int key) {
		this->value = value;
		this->key = key;
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

void lruCache()
{
	node* first = new node(-1, 0);
	node *last = new node(-1, 10000000);

	first->next = last, first->prev = NULL;
	last->prev = first, last->next = NULL;

	int size;
	cout << "\n______________________________________________________________\n";
	cout << "Enter the size of the cache : ";
	cout << "\n______________________________________________________________\n";
	cin >> size;

	map<int, node*> cache;
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

			if (cache.find(key) != cache.end()) {
				node* newNode = new node(cache[key]->value, key);

				// delete it from the current position,
				node* currentNode = cache[key];
				node* front = currentNode->next;
				node* back = currentNode->prev;

				back->next = front;
				front->prev = back;

				cache.erase(cache.find(key));

				delete(currentNode);

				cache[key] = newNode;

				// put after first
				node* second = first->next;
				first->next = newNode;
				newNode->next = second;
				newNode->prev = first;
				second->prev = newNode;

				cout << "The value of " << key << " is : " << cache[key]->value << '\n';
			} else {
				cout << "No such key present\n";
			}

		} else if (input == 1) { // put
			int key, value;
			cout << "Enter the number you want to put {key, value}\n";
			cin >> key >> value;

			node* newNode = new node(value, key);

			// check if it already exits
			if (cache.find(key) != cache.end()) {
				// delete it from the current position,

				node* currentNode = cache[key];
				node* front = currentNode->next;
				node* back = currentNode->prev;

				back->next = front;
				front->prev = back;

				delete(currentNode);

				currentCapacity--;
			}

			else if (currentCapacity == size) { // if cache is full
				// remove last element

				node* secondLast = last->prev;
				node* thirdLast = secondLast->prev;

				// erase from map as well
				cache.erase(cache.find(secondLast->key));

				last->prev = thirdLast;
				thirdLast->next = last;

				delete(secondLast);

				currentCapacity--;
			}

			// put after first
			node* second = first->next;
			first->next = newNode;
			newNode->next = second;
			newNode->prev = first;
			second->prev = newNode;

			cache[key] = newNode;

			currentCapacity++;
		} else {
			break;
		}

		printDoublyLinkedList(first);
	}
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	lruCache();
	return 0;
}