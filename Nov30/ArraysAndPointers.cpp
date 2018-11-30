#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void printNumbers(const char* text, /*const*/ int arr[], int size) {
	cout << text << ":";
	for (int i = 0; i < size; ++i)
		cout << " " << arr[i];
	cout << endl;
	//arr[0] = 9; // not possible if it is const array in the parameter
}

// search function returns index of element with the value
int linearSearch(int value, int arr[], int size) {
	for (int index = 0; index < size; ++index) {
		if (arr[index] == value)
			return index;
	}
	return -1; // value not found
}

int linearSearchSortedArray(int value, int arr[], int size) {
	for (int index = 0; index < size; ++index) {
		if (value < arr[index]) // if we got to greater element 
			return -1;          // - no reason to continue
		if (arr[index] == value)
			return index;
	}
	return -1; // value not found
}

int binarySearchSortedArray(int value, int arr[], int size) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (value < arr[mid]) {
			right = mid - 1;
		}
		else if (value > arr[mid]) {
			left = mid + 1;
		}
		else // value == arr[mid] - Eurica!!! I've found it!!!
			return mid;
	}
	return -1; // value not found
}

//const int NUMBERS_SIZE = 10;
const int NUMBERS_SIZE = 12;

int binarySearchSortedArrayRecursive(int value, int arr[], int size);

void sortSelection(int[], int);
void sortSelectionRecursive(int[], int);
void sortInsertion(int[], int);
void sortBubble1(int[], int);
void sortBubble2(int[], int);
void sortBubble3(int[], int);

int main() {
	//// Array declaration and initialization
	//int numbers1[NUMBERS_SIZE];
	//printNumbers("numbers1", numbers1, NUMBERS_SIZE);
	//int numbers2[NUMBERS_SIZE] = { 1, 2, 3 };
	//printNumbers("numbers2", numbers2, NUMBERS_SIZE);
	//int numbers3[] = { 1, 2, 3, 4, 5 };
	//printNumbers("numbers3", numbers3, 5);
	//// int numbers4[]; // fails - C++ must now how much memory to allocate

	//// Set array values
	//// numbers1[12] = 8; // C++ does not check the index boundary limit
	//					 // This line (if not commented) will change some
	//					 // memory slot beyond array location
	//numbers1[0] = 1;
	//numbers1[1] = 2;
	//// ... etc
	//int index = 2;
	//numbers1[index * 2 + 1] = 7; // goes to location 5 in array

	//for (int i = 6; i < NUMBERS_SIZE; ++i)
	//	numbers1[i] = i;
	//printNumbers("numbers1", numbers1, NUMBERS_SIZE);

	//int size;
	//cout << "Enter array size: ";
	//cin >> size;
	//// int numbers5[size]; // Compiler does not know what will be the input!

	//const int numbers6[] = { 1 };
	//// Function call won't work if the array parameter is not declared as const
	//// printNumbers("numbers6", numbers6, 1);

	//const int MAX_STUDENTS = 40;
	//int studentAges[MAX_STUDENTS];
	//int actualStudents = 20;
	//for (int i = 0; i < actualStudents; ++i)
	//	studentAges[i] = 15;
	//printNumbers("Ages", studentAges, actualStudents);

	//cout << binarySearchSortedArrayRecursive(8, numbers2, NUMBERS_SIZE) << endl;

	int numbers[NUMBERS_SIZE];
	srand(time(nullptr));
	for (int i = 0; i < NUMBERS_SIZE; ++i)
		numbers[i] = rand() % 100;
	printNumbers("Before sort", numbers, NUMBERS_SIZE);
	sortBubble2(numbers, NUMBERS_SIZE);
	printNumbers("After sort", numbers, NUMBERS_SIZE);
	return 0;
}

int binarySearchSortedArrayRecursive(int value, int arr[], int left, int right) {
	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (value = arr[mid]) return mid;

	if (value < arr[mid])
		return binarySearchSortedArrayRecursive(value, arr, left, mid - 1);
	else // value > arr[mid]
		return binarySearchSortedArrayRecursive(value, arr, mid + 1, right);
}
int binarySearchSortedArrayRecursive(int value, int arr[], int size) {
	return binarySearchSortedArrayRecursive(value, arr, 0, size - 1);
}

void sortSelection(int arr[], int size) {
	for (int j = 0; j < size - 1; j++) {
		// find the min element in the unsorted a[j .. n-1]
		// assume the min is the first element
		int iMin = j;
		// test against elements after j to find the smallest
		for (int i = j + 1; i < size; i++) {
			// if this element is less, then it is the new minimum
			if (arr[i] < arr[iMin]) {
				//* found new minimum; remember its index
				iMin = i;
			}
		}
		if (iMin != j) { // if other is smaller than j's element - swap them
			swap(arr[j], arr[iMin]);
		}
	}
}

void sortSelectionRecursive(int arr[], int size, int j) {
	if (j == size - 1) return;
	int iMin = j;
	for (int i = j + 1; i < size; i++) {
		if (arr[i] < arr[iMin]) {
			iMin = i;
		}
	}
	if (iMin != j) { // if other is smaller than j's element - swap them
		swap(arr[j], arr[iMin]);
	}
	sortSelectionRecursive(arr, size, j + 1);
}
void sortSelectionRecursive(int arr[], int size) {
	sortSelectionRecursive(arr, size, 0);
}

void sortInsertion(int arr[], int size) {
	for (int i = 1; i < size; ++i) {
		// arr[0..i-1] is already sorted
		// insert arr[i] to its correct place
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
			swap(arr[j], arr[j - 1]);
	}
}

void sortBubble1(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size; ++j) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}
void sortBubble2(int arr[], int size) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int j = 1; j < size; ++j) {
			if (arr[j - 1] > arr[j]) {
				swapped = true;
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}
void sortBubble3(int arr[], int size) {
	int limit = size;
	bool swapped = true;
	while(swapped) {
		swapped = false;
		for (int j = 1; j < limit; ++j) {
			if (arr[j - 1] > arr[j]) {
				swapped = true;
				swap(arr[j - 1], arr[j]);
			}
		}
		--limit;
	}
}