#ifndef _MY_REALLOC_H_
#define _MY_REALLOC_H_

template <typename T>
T min(const T a, const T b) {
	return ((a > b) ? b : a);
}

template <typename T>
T* realloc(T* ptr, int size, int n_size) {
	int i;
	int n = min(size, n_size);
	T* n_ptr = new T[n_size];
	for (i = 0; i < n; ++i)
		n_ptr[i] = ptr[i];
	delete[] ptr;
	return n_ptr;
}

#endif