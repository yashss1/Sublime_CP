//YashS
#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

#define TABLE_SIZE 100

struct HashKey
{
	int key;
	int value;
	HashKey* next = NULL;
};

class HashMap {
private:
	HashKey* table[TABLE_SIZE];

public:
	HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			this->table[i] = NULL;
		}
	}

	int calculateHash(int key) {
		return (key % TABLE_SIZE);
	}

	void insert(int key, int value) {
		int hash = this->calculateHash(key);
		HashKey* newPair = (HashKey*)malloc(sizeof(struct HashKey));
		newPair->key = key;
		newPair->value = value;

		if (this->table[hash] == NULL) {
			this->table[hash] = newPair;
		}
		else {
			HashKey* curr = this->table[hash];
			while (curr->next != NULL) {
				if (curr->key == key) {
					curr->value = newPair->value;
					return;
				}
				curr = curr->next;
			}
			if (curr->key == key) {
				curr->value = newPair->value;
				return;
			}
			curr->next = newPair;
		}
	}

	int get(int key)  {
		int hash = this->calculateHash(key);

		HashKey* curr = this->table[hash];
		if (curr == NULL) {
			return 0;
		}

		while (curr->next != NULL) {
			if (curr->key == key) {
				return curr->value;
			}
			curr = curr->next;
		}
		if (curr->key == key) {
			return curr->value;
		}

		return 0;
	}

	// not working
	int operator[](int key)
	{
		return this->get(key);
	}
};


int main()
{
	init_code();

	HashMap* hashmap = new HashMap();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int key, value;
		cin >> key >> value;
		hashmap->insert(key, value);
		cout << "Key " << key << " -> " << "Value " << value << " inserted\n";
	}

	cout << "\n";

	int q;
	cin >> q;
	while (q--) {
		int key;
		cin >> key;

		int value = hashmap->get(key);
		cout << "Value of " << key << " is " << value << '\n';
	}

	return 0;
}