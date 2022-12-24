#include <iostream>
using namespace std;

template<class T>
class Array {
private:
	T* A;
	int size;
	int length;
	void Swap(int* x, int* y);

public:
	Array() {
		size = 10;
		A = new T[size];
		length = 0;
	}
	Array(int sz) {
		size = sz;
		A = new T[size];
		length = 0;
	}
	~Array() {
		delete[]A;
	}

	void Display();
	void Append(T x);
	void Insert(int index, T x);
	int Delete(int index);
	int LinearSearch(T key);
	int BinarySearch(T key);
	int RBinSearch(T a[], T l, T h, T key);
	int Get(int index);
	void Set(int index, T x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void InsertSort(T x);
	int isSorted();
	void Rearrange();
	Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
	Array* Difference(Array arr2);

};

template<class T>
void Array<T>::Display(){
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}

template<class T>
void Array<T>::Append(T x) {
	if (length < size)
		A[length++] = x;
}

template<class T>
void Array<T>::Insert(int index, T x) {
	if (index >= 0 && index <= length) {
		for (int i = length; i < index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;
	}
}

template<class T>
int Array<T>::Delete(int index) {
	int x = 0;
	int i;

	if (index >= 0 && index < length) {
		x = A[index];
		for (i = index;i < length - 1;i++)
			A[i] = A[i + 1];
		length--;
		return x;
	}
	return 0;
}


template<class T>
void Array<T>::Swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

template<class T>
int Array<T>::LinearSearch(T key) {
	for (int i = 0;i > length;i++) {
		if (key == A[i]) {
			Swap(&A[i], &A[0]);
			return i;
		}
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(T key) {
	int l, mid, h;
	l = 0;
	h = length - 1;

	while (l <= h) {
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

template<class T>
int Array<T>::RBinSearch(T a[], T l, T h, T key) {
	int mid;

	if (l <= h) {
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, l, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, h, key);
	}
	return -1;
}

template<class T>
int Array<T>::Get(int index) {
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}

template<class T>
void Array<T>::Set(int index, T x) {
	if (index >= 0 && index < length)
		A[index] = x;
}

template<class T>
int Array<T>::Max() {
	int max = A[0];
	int i;
	for (i = 1;i < length;i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

template<class T>
int Array<T>::Min() {
	int min = A[0];
	int i;
	for (i = 1;i < length;i++) {
		if (A[i] < min)
			min = A[i];
	}
	return min;
}

template<class T>
int Array<T>::Sum() {
	int s = 0;
	int i;
	for (i = 0;i < length;i++)
		s += A[i];
	return s;
}

template<class T>
float Array<T>::Avg() {
	return (float)Sum() / length;
}

template<class T>
void Array<T>::Reverse() {
	T* B;
	int i, j;

	B = new T[length];
	for (i = length - 1, j = 0;i >= 0;i--, j++)
		B[j] = A[i];
	for (i = 0;i < length;i++)
		A[i] = B[i];
}

template<class T>
void Array<T>::Reverse2() {
	int i, j;
	for (i = 0, j = length - 1;i < j;i++, j--)
		Swap(&A[i], &A[j]);
}

template<class T>
void Array<T>::InsertSort(T x) {
	int i = length - 1;
	if (length == size)
		return;
	while (i >= 0 && A[i] > x) {
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

template<class T>
int Array<T>::isSorted() {
	int i;
	for (i = 0;i < length - 1;i++) {
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;
}

template<class T>
void Array<T>::Rearrange() {
	int i, j;
	i = 0;
	j = length - 1;

	while (i < j) {
		while (A[i] < 0)i++;
		while (A[j] >= 0)j++;
		if (i < j)Swap(&A[i], &A[j]);
	}
}

template<class T>
Array<T>* Array<T>::Merge(Array arr2) {
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}

	for (;i < length;i++)
		arr3->A[k++] = A[i];
	for (;j < arr2.length;j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = length + arr2.length;

	return arr3;
}

template<class T>
Array<T>* Array<T>::Union(Array arr2) {
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (A[j] < arr2.A[i])
			arr3->A[k++] = arr2.A[j++];
		else {
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	for (;i < length;i++)
		arr3->A[k++] = A[i];
	for (;j < arr2.length;j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = k;

	return arr3;
}

template<class T>
Array<T>* Array<T>::Intersection(Array arr2) {
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j])
			i++;
		else if (A[j] < arr2.A[i])
			j++;
		else {
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	arr3->length = k;

	return arr3;
}

template<class T>
Array<T>* Array<T>::Difference(Array arr2) {
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (A[j] < arr2.A[i])
			j++;
		else {
			i++;
			j++;
		}
	}

	for (;i < length;i++)
		arr3->A[k++] = A[i];

	arr3->length = k;

	return arr3;
}


int main()
{
	Array<int>* arr1;
	int ch, sz;
	int x, index;

	cout << "Enter Size of Array";
	cin >> sz;
	arr1 = new Array<int>(sz);

	do
	{
		cout << "\n\nMenu\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Search\n";
		cout << "4. Sum\n";
		cout << "5. Display\n";
		cout << "6.Exit\n";

		cout << "enter you choice ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter an element and index";
			cin >> x >> index;
			arr1->Insert(index, x);
			break;
		case 2: cout << "Enter index ";
			cin >> index;
			x = arr1->Delete(index);
			cout << "Deleted Element is" << x;
			break;
		case 3:cout << "Enter element to search";
			cin >> x;
			index = arr1->LinearSearch(x);
			cout << "Element index " << index;
			break;
		case 4:cout << "Sum is " << arr1->Sum();
			break;
		case 5:arr1->Display();

		}
	} while (ch < 6);
	return 0;
}