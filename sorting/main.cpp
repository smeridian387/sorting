// Sorting lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

// Import things we need from the standard library
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::steady_clock;
using std::cout;
using std::endl;
using std::list;
using std::ofstream;
using std::sort;
using std::vector;

// Put "count" random integers in the range (0, 99) into "collection".
// (This is templated so it'll work with any collection type that has push_back.)
template <typename T>
void MakeRandomValues(T& collection, int count) {
	for (int i = 0; i < count; i++) {
		collection.push_back(rand() % 100);
	}
}

// Print out all the items in "collection".
template <typename T>
void ShowValues(const T& collection) {
	for (auto item : collection) {
		cout << " " << item;
	}
	cout << "\n";
}

// Check that "collection" is in sorted order.
template <typename T>
void AssertSorted(const T& collection) {
	auto it = collection.begin();
	if (it == collection.end()) {
		// The collection is empty. So it's sorted!
		return;
	}

	auto prev = it;
	it++;
	while (it != collection.end()) {
		// Check that each pair of items is in order.
		assert(*it >= *prev);

		prev = it;
		it++;
	}

	// We've got to the end of the list. So it's sorted!
}

int main(int argc, char *argv[]) {
	srand((unsigned int) time(NULL));

	const int num_values = 20;

	cout << "Sorting " << num_values << " integers\n";

	list<int> input;
	MakeRandomValues(input, num_values);
	cout << "Before sorting:";
	ShowValues(input);

	// Sort the list.
	list<int> output = input;
	output.sort();

	cout << "After sorting:";
	ShowValues(output);
	AssertSorted(output);

	cout << "All OK!\n";

	return 0;
}