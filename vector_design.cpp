//YashS
#include <iostream>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

template<typename T>
class vector3 {
private:
	T* arr;
	int size, capacity;

public:
	vector3() {
		// default constructor;
		size = 0, capacity = 0;
	}
	vector3(int n) {
		size = capacity = 10;
		arr = new T[n];
	}

	void new_allocation() {
		T* temp = new T[size + 5];
		capacity = size + 5;

		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}

		arr = temp;
		delete [] temp;
	}

	// push
	// if size < capactity -> driectly push
	// if size == capacity -> alocate new array and copy the content
	void push_back(T num) {
		if (size == capacity) {
			new_allocation();
		}
		arr[size] = num;
		size++;
	}

	void pop_back() {
		if (size == 0) {
			T* temp;
			arr = temp;
			capacity = 0, size = 0;
			return;
		}
		size--;
	}

	// now how can v[i] give arr[i] as v is ab object of a class now
	// so overload an operator
	T operator[](int index) {
		return arr[index];
	}

	int siz() {
		return this->size;
	}

	~vector3() {
		cout << "Vector deleted\n";
	}
};

int main()
{
	init_code();

	vector3<int> v;
	v.push_back(0);
	cout << v[0] << "\n";
	return 0;
}