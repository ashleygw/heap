#include <iostream>
#include <cstdlib>
#include <chrono>
#include "heap.h"
#include <assert.h>
using namespace std;
using namespace std::chrono;

bool isHeap(int arr[], int i, int n)
{
	if (i > n)
		return true;
	if (arr[i] >= arr[2 * i] && arr[i] >= arr[2 * i + 1] &&
		isHeap(arr, 2 * i, n) && isHeap(arr, 2 * i + 1, n))
		return true;
	return false;
}
int main()
{
	Heap h(90);
	srand(time(0));
	int v;
	int n;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	t1 = high_resolution_clock::now();
	t2 = high_resolution_clock::now();
	double total = 0;
	duration<double> time_span = duration_cast<duration<double>>(t2-t1);
	for (int j = 0; j < 1; j++) // number of trials
	{
		//n = rand() % 30000; // number of elements
		n = 90;
		for (int i = 0; i < n; i++)
		{
			v = rand() % 1000; // number to be inserted
			h.insert(v);
		}
		for (int k = 0; k < n; k++)
		{
			t1 = high_resolution_clock::now();
			h.remove_min();
			t2 = high_resolution_clock::now();
			time_span = duration_cast<duration<double>>(t2 - t1);
			total = time_span.count();
			if (k % 1001 == 0) {
				for (int z = 0; z < 20;z++)
					cout << h.harry[z] << ", ";
				assert(isHeap(h.harry, 1, 20));
				cout << n - k << ", " << total << endl;
			}
		}
		h.reset();
	}
}