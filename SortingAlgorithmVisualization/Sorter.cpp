#include "Sorter.h"
#include <thread>
#include <iostream>

Sorter::Sorter() 
	: delay{ 5 }
	, algoChoice{ -1 }
{
}

void Sorter::selectSortAlgo(int choice)
{
	algoChoice = choice;
}

void Sorter::setDelay(int timeInMs)
{
	delay = timeInMs;
}

void Sorter::shuffleArray(std::vector<Rectangle>& arr, int size)
{
	arr.clear();
	arr.reserve(size);

	// Generate array in order
	for (int i = 0; i < size; i++)
	{
		Rectangle rectangle(
			i + 1,
			sf::Vector2f(0.0, 0.0),
			sf::Vector2f(0.0, 0.0),
			sf::Color::Red,
			sf::Color::White,
			false,
			sf::milliseconds(30)
		);
		arr.push_back(rectangle);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}

	// Shuffle
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Rectangle temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void Sorter::startSortAlgo(std::vector<Rectangle>& arr)
{
	enum sortingAlgorithms {
		BubbleSort = 1,
		InsertionSort,
		SelectionSort,
		QuickSort,
		MergeSort,
		HeapSort,
		CountingSort,
		RadixSort
	};

	switch (algoChoice)
	{
	case BubbleSort:
		bubbleSort(arr);
		break;
	case InsertionSort:
		insertionSort(arr);
		break;
	case SelectionSort:
		selectionSort(arr);
		break;
	case QuickSort:
		quickSort(arr, 0, arr.size() - 1);
		break;
	case MergeSort:
		mergeSort(arr, 0, arr.size() - 1);
		break;
	case HeapSort:
		heapSort(arr, arr.size());
		break;
	case CountingSort:
		countingSort(arr);
		break;
	case RadixSort:
		radixSort(arr);
		break;
	default:
		std::cout << "An algorithm was not selected.\n";
		break;
	}
}

void Sorter::bubbleSort(std::vector<Rectangle>& arr)
{
	int n = arr.size();
	bool swapped = false;
	do {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1], delay, true);
				swapped = true;
			}
		}
	} while (swapped == true);
}

void Sorter::insertionSort(std::vector<Rectangle>& vec)
{
	for (unsigned int i = 1; i < vec.size(); i++) {
		int j = i;
		while (j > 0 && vec[j - 1] > vec[j]) {
			swap(vec[j], vec[j - 1], delay, true);
			j--;
		}
	}
}

void Sorter::quickSort(std::vector<Rectangle>& arr, int low, int hi)
{
	if (low < hi) {
		int pi = partition(arr, low, hi);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, hi);
	}
}

void Sorter::selectionSort(std::vector<Rectangle>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		int minimumIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minimumIndex]) {
				minimumIndex = j;
			}
		}

		swap(arr[i], arr[minimumIndex], delay);
	}
}

void Sorter::mergeSort(std::vector<Rectangle>& arr, int l, int r)
{
	// Divide the array into two subarrays, sort them, then merge them
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);			// Merge sorted subarrays
	}
}

void Sorter::heapSort(std::vector<Rectangle>& arr, int n)
{
	// Build a max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i], delay);
		// Heapify root element to get highest element to the root again
		heapify(arr, i, 0);
	}
}

void Sorter::countingSort(std::vector<Rectangle>& arr)
{
	std::vector<int> count{};
	std::vector<Rectangle> output{};
	int max = arr[0].getValue();

	// Find max in the vector
	for (std::size_t i = 0; i < arr.size(); i++) {
		if (arr[i].getValue() > max) {
			max = arr[i].getValue();

			arr[i].setActive();
			sleep(delay);
		}
	}

	// Create a vector of size max containing all zeroes
	count.resize(max+1, 0);
	output.resize(max+1);

	// Store the count of each element
	for (std::size_t i = 0; i < arr.size(); i++) {
		count[arr[i].getValue()]++;
		
		arr[i].setActive();
		sleep(delay);
	}

	// Store cumulative count of each element in array
	for (std::size_t i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = arr.size() - 1; i >= 0; i--) {
		sf::Vector2f newPosition = arr[arr[i].getValue() - 1].getPosition();			
		output[count[arr[i].getValue()] - 1] = arr[i];									
		output[count[arr[i].getValue()] - 1].setPosition(newPosition);
		count[arr[i].getValue()]--;
		
		arr[i].setActive();
		sleep(delay);
	}

	// Copy the sorted elements into original array
	for (std::size_t i = 0; i < arr.size(); i++) {
		arr[i] = output[i];
		
		arr[i].setActive();
		sleep(delay);
	}
}

void Sorter::countingSort(std::vector<Rectangle>& arr, int place)
{
	// This version of counting sort is used by radix sort.
	const int max = 10;
	std::vector<int> count{};
	std::vector<Rectangle> output{};

	// Create a vector of size max containing all zeroes
	count.resize(max, 0);
	output.resize(arr.size());

	// Store the count of each element
	for (std::size_t i = 0; i < arr.size(); i++) {
		count[(arr[i].getValue() / place) % 10]++;
	}

	// Store cumulative count of each element in array
	for (int i = 1; i < max; i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = arr.size() - 1; i >= 0; i--) {
		sf::Vector2f newPosition = arr[count[(arr[i].getValue() / place) % 10] - 1].getPosition();
		output[count[(arr[i].getValue() / place) % 10] - 1] = arr[i];
		output[count[(arr[i].getValue() / place) % 10] - 1].setPosition(newPosition);						
		count[(arr[i].getValue() / place) % 10]--;
	}

	// Copy the sorted elements into original array
	for (std::size_t i = 0; i < arr.size(); i++) {
		arr[i] = output[i];
		arr[i].setActive();
		sleep(delay);
	}
}

void Sorter::radixSort(std::vector<Rectangle>& arr)
{
	// Get max element
	int max = arr[0].getValue();
	for (std::size_t i = 0; i < arr.size(); i++) {
		if (arr[i].getValue() > max) {
			max = arr[i].getValue();
		}
	}

	// Apply counting sort to sort elements using place value
	for (int place = 1; max / place > 0; place *= 10) {
		countingSort(arr, place);
	}
}

int Sorter::partition(std::vector<Rectangle>& vec, int low, int high)
{
	int pivot = high;
	int leftWall = low - 1;

	for (int i = low; i < high; i++) {
		if (vec[i] < vec[pivot]) {
			leftWall++;
			swap(vec[i], vec[leftWall], delay);
		}
	}

	swap(vec[leftWall + 1], vec[pivot], delay);

	return leftWall + 1; 
}

void Sorter::printVector(std::vector<Rectangle>& arr)
{
	for (Rectangle& elem : arr) {
		std::cout << elem.getValue() << " ";
	}
	std::cout << std::endl;
}

void Sorter::heapify(std::vector<Rectangle>& arr, int n, int i)
{
	// Find largest among root, left child, and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	
	// Swap and continue to heapify if root is not the largest
	if (largest != i) {
		swap(arr[i], arr[largest], delay, true);
		heapify(arr, n, largest);
	}
}

void Sorter::swap(Rectangle& a, Rectangle& b, unsigned int delay, bool setActive)
{
	Rectangle temp = a;
	a = b;
	b = temp;
	
	sf::Vector2f tempCoords = a.getPosition();
	a.setPosition(b.getPosition());
	b.setPosition(tempCoords);

	if (delay)
		sleep(delay);
	
	if (setActive) {
		a.setActive();
		b.setActive();
	}
}

void Sorter::merge(std::vector<Rectangle>& arr, int p, int q, int r)
{
	// Merge two subarrays L and R into arr
	// Create L=A[p..q] and R=A[q+1..r]
	const int n1 = q - p + 1;			// Length of subarray L
	const int n2 = r - q;				// Length of subarray R

	// Create new subarrays
	Rectangle* L = new Rectangle[n1];
	Rectangle* R = new Rectangle[n2];

	// Copy data to subarrays
	for (int i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[q + 1 + j];
	}

	// Maintain index of subarrays and main array
	int i = 0;		// Starting index of L
	int j = 0;		// Starting index of M
	int k = p;		// Starting index of main array

	// Pick larger elements out of arrays L and M until we reach the end. Swap their positions as well.
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			sf::Vector2f newPosition = arr[k].getPosition();
			arr[k] = L[i];
			arr[k].setPosition(newPosition);
			arr[k].setActive();
			i++;

			sleep(delay);
		}
		else {
			sf::Vector2f newPosition = arr[k].getPosition();
			arr[k] = R[j];
			arr[k].setPosition(newPosition);
			arr[k].setActive();
			j++;

			sleep(delay);
		}
		k++;
	}

	// Add remaining elements from either subarry and switch positions
	while (i < n1) {
		sf::Vector2f newPosition = arr[k].getPosition();
		arr[k] = L[i];
		arr[k].setPosition(newPosition);
		arr[k].setActive();
		i++;
		k++;

		sleep(delay);
	}
	while (j < n2) {
		sf::Vector2f newPosition = arr[k].getPosition();
		arr[k] = R[j];
		arr[k].setPosition(newPosition);
		arr[k].setActive();
		j++;
		k++;

		sleep(delay);
	}

	delete[] L;
	delete[] R;
}

void Sorter::sleep(unsigned int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
