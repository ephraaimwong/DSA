/**
 * @author iampo
 * 
 */
#include <iostream>
using namespace std;
/**
 * @brief Vector Class based on array, pointer and dynamic memory allocation
 * 
 */
class MyVector
{

public:
/**
 * @brief Construct a new My Vector object
 * 
 */
	MyVector() : p(NULL), size(0) {}
	/**
	 * @brief Getter method for private field size
	 * 
	 * @return int size
	 */
	int vsize()
	{
		return size;
	}
	/**
	 * @brief returns 1 if empty, 0 if not
	 * 
	 * @return int 
	 */
	int empty()
	{
		if (vsize() == 0)
		{
			return 1;
		}
		return 0;
	}
	/**
	 * @brief returns element at p[idx], -1 if idx out of array range 
	 * 
	 * @param idx index 
	 * @return int value of p[idx]
	 */
	int at(int idx)
	{
		if (idx < 0 || idx >= vsize())
		{
			return -1;
		}
		return p[idx];
	}
	/**
	 * @brief resize array to specified size
	 * 
	 * @param n new size of array
	 */
	void resize(int n)
	{
		int *x = new int[n];
		for (int i = 0; i < min(vsize(), n); i++)
		{
			x[i] = p[i];
		}
		delete[] p;
		p = x;
		size = n;
	}
	/**
	 * @brief Adds element to the end of array
	 * 
	 * @param x Element to append
	 */
	void push_back(int x)
	{
		resize(vsize() + 1);
		p[vsize() - 1] = x;
	}
	/**
	 * @brief Removes last element of array
	 * Does nothing if array is empty
	 */
	void pop_back()
	{
		if (size > 0)
		{
			resize(size - 1);
		}
	}
	/**
	 * @brief Insert element X at index idx, resizing array to compensate
	 * 
	 * @param idx Index of insertion
	 * @param x Element to insert
	 */
	void insert(int idx, int x)
	{
		if (idx < 0 || idx >= size)
		{
			return;
		}
		resize(size + 1);
		for (int i = size - 1; i > idx; i--)
		{
			p[i] = p[i - 1];
		}
		p[idx] = x;
	}
	/**
	 * @brief Removes element at index idx, resizing array to compensate
	 * 
	 * @param idx Index of removal
	 */
	void erase(int idx)
	{
		if (idx < 0 || idx >= size)
		{
			return;
		}
		for (int i = idx; i < size - 1; i++)
		{
			p[i] = p[i + 1];
		}
		resize(size - 1);
	}
/**
 * @brief Private fields 
 * Pointer P
 * Size of Array
 */
private:
	int *p;
	int size;
};

// The main function has been completed for you.
// It is used to test your implmentation.
// You should not modify it (unless there is typo).
int main()
{
	MyVector x;

	int mode;
	int new_size, idx, data;
	int temp;

	cin >> mode; // This decides which function to test.
	cin >> new_size >> idx >> data;

	// Mode 0: test push_back(), vsize() and at()
	if (mode == 0)
	{

		while (cin >> temp)
		{
			x.push_back(temp);
		}

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++)
		{
			cout << x.at(i) << '\n';
		}
	}
	// Mode 1: test resize()
	else if (mode == 1)
	{
		while (cin >> temp)
		{
			x.push_back(temp);
		}

		x.resize(new_size);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++)
		{
			cout << x.at(i) << '\n';
		}
	}
	// Mode 2: test pop_back()
	else if (mode == 2)
	{

		while (cin >> temp)
		{
			x.push_back(temp);
		}

		x.pop_back();

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++)
		{
			cout << x.at(i) << '\n';
		}
	}
	// Mode 3: test insert()
	else if (mode == 3)
	{

		while (cin >> temp)
		{
			x.push_back(temp);
		}

		x.insert(idx, data);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++)
		{
			cout << x.at(i) << '\n';
		}
	}
	// Mode 4: test erase()
	else if (mode == 4)
	{

		while (cin >> temp)
		{
			x.push_back(temp);
		}

		x.erase(idx);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++)
		{
			cout << x.at(i) << '\n';
		}
	}
	else
	{
		cout << "Wrong Mode Input!";
	}

	return 0;
}
