#include "Sorter.h"
#include <thread>
#include <iostream>

Sorter::Sorter(std::vector<Rectangle>& arr) 
	: sortingArray{ arr }
	, delay{ 0 }
	, algoChoice{ -1 }
	, sortingThread{}
{
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
	}

	// Shuffle
	srand(time(NULL));
	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Rectangle temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void Sorter::shuffleArray(int size)
{
	// Do not use clear(). It invalidates any references, pointers, or iterators to the elements within it.
	// Reserver() also invalidates references, pointers, and iterators to the elements if the parameter "size" is greater 
	// than its current capacity. SortingArray reallocates to a new location in memory.
	sortingArray.clear();
	sortingArray.reserve(size);

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
		sortingArray.push_back(rectangle);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}

	// Shuffle
	srand(time(NULL));
	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Rectangle temp = sortingArray[i];
		sortingArray[i] = sortingArray[j];
		sortingArray[j] = temp;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void Sorter::selectSortAlgo(int choice)
{
	algoChoice = choice;
}

void Sorter::startSortAlgo()
{
	enum sortingAlgorithms {
		BubbleSort = 1,
		InsertionSort,
		SelectionSort,
		QuickSort
	};

	isSorted = false;
	switch (algoChoice)
	{
	case BubbleSort:
	{
		bubbleSort(delay);
		break;
	}
	case InsertionSort:
		insertionSort(delay);
		break;
	case SelectionSort:
		selectionSort(delay);
		break;
	case QuickSort:
		quickSort(0, sortingArray.size() - 1, delay);
		break;
	default:
		std::cout << "An algorithm was not selected.\n";
		break;
	}
}

bool Sorter::checkIfSorted()
{
	if (sortingThread.joinable()) {
		sortingThread.join();
		return true;
	}
	else {
		return false;
	}
}

void Sorter::setDelay(int timeInMs)
{
	delay = timeInMs;
}

void Sorter::testfunc(int iWaitTime) {
	// sortingArray has 0 elements. I think the problem here is that the reference to the vector is not being updated.
	// Even if we shuffle the array, the application object has the updated vector with 100 elements, however, 
	// The vector sortingArray inside the sorter object has not been updated and thinks that we only have 0 elements.
	std::cout << "I am being ran\n";
	std::cout << 100;
	for (auto& elem : sortingArray) {
		std::this_thread::sleep_for(std::chrono::milliseconds(iWaitTime));
		std::cout << elem.getValue() << " ";
	}
}

void Sorter::bubbleSort(int delay)
{
	int n = sortingArray.size();
	bool swapped = false;
	do {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (sortingArray[i] < sortingArray[i - 1]) {
				swap(&sortingArray[i], &sortingArray[i - 1]);
				sortingArray[i].setActive();
				sortingArray[i - 1].setActive();
				swapped = true;
				std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			}
		}
	} while (swapped == true);
}

void Sorter::insertionSort(int delay)
{
}

void Sorter::quickSort(int low, int hi, int delay)
{
	if (low < hi) {
		int pi = partition(low, hi, delay);
		quickSort(low, pi - 1, delay);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		quickSort(pi + 1, hi, delay);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void Sorter::selectionSort(int delay)
{
	//int i, key, j;
	//for (i = 1; i < arr.size(); i++)
	//{
	//	key = arr[i].iValue;
	//	j = i - 1;

	//	/* Move elements of arr[0..i-1], that are
	//	greater than key, to one position ahead
	//	of their current position */
	//	while (j >= 0 && arr[j].iValue > key)
	//	{
	//		arr[j + 1].setActive(true);
	//		//arr[j + 1].iValue = arr[j].iValue;
	//		swap(&arr[j + 1], &arr[j]);
	//		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	//		//setWhite(arr[j + 1], arr[j]);
	//		setWhite(arr[j + 1]);
	//		setWhite(arr[j]);
	//		j = j - 1;
	//	}
	//	arr[j + 1].iValue = key;
	//}
}

int Sorter::partition(int low, int hi, int delay)
{
	Rectangle pivot = sortingArray[hi];					 // Select rightmost element as pivot
	int i = (low - 1);								// Pointer for greater element

	for (int j = low; j < hi; j++) {
		if (sortingArray[j] <= pivot) {
			i++;
			swap(&sortingArray[i], &sortingArray[j]);
			sortingArray[i].setActive();
			sortingArray[j].setActive();
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));

		}
	}

	swap(&sortingArray[i + 1], &sortingArray[hi]);
	sortingArray[i+1].setActive();
	sortingArray[hi].setActive();
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));

	
	return (i + 1);
}

void Sorter::printArray()
{
	for (Rectangle& elem : sortingArray) {
		std::cout << elem.getValue() << " ";
	}
	std::cout << std::endl;
}

void Sorter::swap(Rectangle* a, Rectangle* b)
{
	// Switch positions of a and b in array
	Rectangle temp = *a;
	*a = *b;
	*b = temp;

	sf::Vector2f tempCoords = a->getPosition();
	a->setPosition(b->getPosition());
	b->setPosition(tempCoords);
}
