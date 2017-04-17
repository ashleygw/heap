class Heap {

public:

	//Allocates heap big enough to hold tree of size int
	Heap(int);

	~Heap();

	int size() const; // number of elements

	bool empty() const; // is the queue empty?

	void insert(const int& e); // insert element

	const int& min(); // minimum element

	void remove_min(); // remove minimum
	
	void heap_up();

	void heap_down();

	void add_to_end(int);

	void swap_nodes(int parent, int child);

	void remove(int index);

	void reset();

	//int pointer for our array
	int *harry;
	int _size;
};