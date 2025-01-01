#include "SimpleVector.h"
#include <iostream>

using namespace std;

int main()
{
	SimpleVector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	int size = v1.size();

	cout << "- push_back\n";

	for (int i = 0; i < size; i++)
	{
		cout << v1[i] << " ";
	}

	cout << "\n\n- pop_back\n";

	while (v1.size() > 0)
	{
		v1.pop_back();
		cout << "size: " << v1.size() << ", capacity: " << v1.capacity() << "\n";
	}

	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(0);
	v1.push_back(3);
	v1.push_back(1);

	v1.sortData(); //±âº» std::less<T>

	cout << "\n- lessSortData\n";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << "\n";
	}


	v1.sortData(greater<int>());

	cout << "\n- greaterSortData\n";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << "\n";
	}
}