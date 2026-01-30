#ifndef __BOUNDCHECKARRAY_H__
#define __BOUNDCHECKARRAY_H__

#include <iostream>
using namespace std;

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int len;

public:
	BoundCheckArray();
	BoundCheckArray(int length);
	int getLen() const;
	T& operator[](int idx);
	T operator[](int idx) const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray() :len(100) {
	arr = new T[100];
}

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int length) : len(length) {
	arr = new T[length];
}

template <typename T>
int BoundCheckArray<T>::getLen() const {
	return len;
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= len) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= len) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	cout << "arr 객체 소멸" << endl;
	delete[] arr;
}

#endif // !__BOUNDCHECKARRAY_H__
