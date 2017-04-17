#include "heap.h"
#include <math.h>
#include <iostream>

Heap::Heap(int size)
{
	harry = new int[(int)pow(2, floor(log(size)/log(2)) + 1)];
	harry[0] = 0;
	_size = 0;
	//std::cout << (int)pow(2, floor(log(size) / log(2)) + 1) << std::endl;
}

Heap::~Heap()
{
	delete harry;
}

int Heap::size() const
{
	return _size;
}

bool Heap::empty() const
{
	return !_size;
}

void Heap::insert(const int & e)
{
	add_to_end(e); //size incremented
	heap_up();
}

const int & Heap::min()
{
	return harry[1];
}

void Heap::remove_min()
{
	swap_nodes(1, _size);
	remove(_size);
	_size -= 1;
	heap_down();
}

void Heap::heap_up()
{
	int parent = (_size) / 2;
	int child = _size;// size??!?!?
	while (harry[child] < harry[parent]) 
	{
		swap_nodes(parent, child);
		child = parent;
		parent /= 2;
	}
}

void Heap::heap_down()
{
	int min_index;
	int parent = 1;
	int lchild = parent * 2;
	int rchild = parent * 2 + 1;
	if (lchild > _size || rchild > _size)
		return;
	while ((harry[parent] > harry[lchild] || harry[parent] > harry[rchild]) && lchild <= _size && rchild <= _size)
	{
		if (harry[lchild] < harry[rchild])
		{
			min_index = lchild;
		}
		else
			min_index = rchild;
		swap_nodes(parent, min_index);
		parent = min_index;
		lchild = parent * 2;
		rchild = parent * 2 + 1;
		if (lchild > _size || rchild > _size)
			return;
		if (parent == _size)
			break;
	}
}

void Heap::add_to_end(int add) //check this later
{
	harry[_size+1] = add;
	_size += 1;
}

//Killer
void Heap::swap_nodes(int parent, int child)
{
	harry[parent] ^= harry[child];
	harry[child] ^= harry[parent];
	harry[parent] ^= harry[child];
}

void Heap::remove(int index)
{
	harry[index] = 0;
}

void Heap::reset()
{
	memset(harry, 0,(_size+1)*sizeof(int));
	_size = 0;
}
