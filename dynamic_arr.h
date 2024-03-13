#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class dynamic_arr {
private:
	void realocate();
public:
	int size;
	int size_max;
	T* arr;
	bool reached_max();
	void push(T obj);
	//void return_elem(int i);
	T& operator[](int);
	friend ostream& operator<<(ostream& os, const dynamic_arr& tabliczka)
	{
		for (int i = 0; i < (tabliczka.size - 1); i++)
			os << tabliczka.arr[i] << endl;
		//os << *tabliczka->arr[i] << endl;
		return os;
	}
	void clear();
	void bsort();
	void swap(T& elem1, T& elem2);
	dynamic_arr()
	{
		size = 1;
		size_max = 1;
		arr = (T*)calloc(size, sizeof(T));
	}
	~dynamic_arr()
	{
		clear();
	}
};
template <typename T> T& dynamic_arr<T>::operator[](int i)
{
	return arr[i];
}

template <typename T> bool dynamic_arr<T>::reached_max()
{
	if (size + 1 > size_max)
		return 1;
	return 0;
}

template <typename T> void dynamic_arr<T>::realocate()
{
	arr = (T*)realloc(arr, size_max * 2 * sizeof(T));
	size_max *= 2;
}

template <typename T> void dynamic_arr<T>::push(T obj)//add object at the end of the array
{
	if (reached_max())
		realocate();
	arr[size-1] = obj;
	size += 1;
}

template <typename T> void dynamic_arr<T>::clear()//clear array of objects
{
	free(arr);
	size = 1;
	size_max = 1;
	arr = (T*)calloc(size, sizeof(T));//no bo musi zaalokowaæ pamiec na cokolowiek

}
template <typename T> void dynamic_arr<T>::swap(T& elem1, T& elem2)
{
	T pom = elem1;
	elem1 = elem2;
	elem2 = pom;
}
template <typename T> void dynamic_arr<T>::bsort()
{
	for (int i = 0; i < size - 1; i++)
	{//nie dziala jeszcze bo cos pokickalem
		for (int j = 0; j < size - 2; j++)//-2 by nie wyszedl poza index
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/*
int main()
{
	dynamic_arr<int> tablica;
	for (int i = 0; i < 10; i++)
		tablica.push(i,i);
	cout << tablica << endl;
	tablica.clear();
	auto j = 10;
	for (int i = 0; i < 10; i++)
		tablica.push(j--, i);
	auto test = tablica[2];
	tablica.bsort();
	cout << tablica << endl;
	test = tablica[2];
	tablica.~dynamic_arr();
	//delete tablica;
	return 0;
}*/