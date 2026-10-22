#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int mult(int x, int y)
{
	return x * y;
}

int fold(vector<int> v, int (*f)(int, int))
{
	if (v.empty())
	{
		cout << "\n|ERROR - Cannot compute with an empty Vector.|" << endl;
		return -1; //Error case for an empty Vector input
	}
	if (v.size() == 1)
		return v[0]; //base case for one remaining/starting element in the Vector

	vector<int> remain(v.begin() + 1, v.end());
	return f(v[0], fold(remain, f));
}

int main()
{
	cout << "Beginning 'fold' Testing..." << endl;
	vector<int> vec = {2, 2, 11};

	assert(fold(vec, add) == 15);
	cout << "'fold' correctly returns 15 when adding in a vector comprised of: 2, 2, and 11" << endl;
	assert(fold(vec, mult) == 44);
	cout << "'fold' correctly returns 44 when multiplying in a vector comprised of: 2, 2, and 11" << endl;
	assert(fold(vector<int>{9}, add) == 9); //Note here - After a quick search, I believe this failed last
	// time because we were trying to create an assigned vector object, not just a vector object input.
	cout << "'fold' correctly returns 9 when attempting to add in a vector comprised of: 9" << endl;
	assert(fold(vector<int>{}, mult) == -1);
	cout << "\n'fold' correctly returns the Error when workwing with an empty vector" << endl;

	cout << "All 'fold' Tests Completed and Passed Successfully!" << endl;
}