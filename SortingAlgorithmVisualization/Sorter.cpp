#include "Sorter.h"
#include <thread>
#include <iostream>

Sorter::Sorter(std::vector<Rectangle>& arr) :
	sortingArray(arr),
	sortingThread{}
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
			false
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
			false
		);
		sortingArray.push_back(rectangle);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	// Shuffle
	srand(time(NULL));
	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Rectangle temp = sortingArray[i];
		sortingArray[i] = sortingArray[j];
		sortingArray[j] = temp;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	//std::cout << &sortingArray;
}

void Sorter::selectSortAlgo(int choice)
{
	algoChoice = choice;
	/*for (auto& elem : sortingArray) {
		std::cout << elem.getValue() << " ";
	}*/
}

void Sorter::startSortAlgo()
{
	enum sortingAlgorithms {
		BubbleSort = 1,
		InsertionSort,
		SelectionSort
	};

	isSorted = false;
	switch (algoChoice)
	{
	case BubbleSort:
	{
		// Dedicate a thread to bubble sorting
		//std::thread t1{ &Sorter::testfunc, this, 100 };
		//std::thread t1{ testfunc, std::ref(sortingArray), 1 };
		//sortingThread = std::thread{ &Sorter::bubbleSort, this, 100 };
		//t1.join();
		bubbleSort(5);
		break;
	}
	/*case InsertionSort:
		return std::thread{ insertionSort, std::ref(arr), 3000 };
	case SelectionSort:
		return std::thread{ selectionSort, std::ref(arr), 1 };*/
	default:
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
	//printArray();
	//std::cout << &sortingArray;
	do {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (sortingArray[i] < sortingArray[i - 1]) {
				sortingArray[i].setActive();
				sortingArray[i - 1].setActive();
				//std::cout << sortingArray[i].getValue() << " " << sortingArray[i - 1].getValue() << std::endl;
				// For some reason, swap is not swapping the array. 
				swap(&sortingArray[i], &sortingArray[i - 1]);
				swapped = true;
				std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			}
		}
	} while (swapped == true);

	//printArray();
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
	/*sf::Vector2f aCoords = a->getPosition();
	sf::Vector2f bCoords = b->getPosition();*/
	// Research how to swap pointers of elems in array
	// The param of a is of type Rectangle*, but when we are swapping a and b, we need to swap **a and **b. What does ** mean?
	*a = *b;
	*b = temp;

	// Swap coords of a and b
	sf::Vector2f tempCoords = a->getPosition();
	a->setPosition(b->getPosition());
	b->setPosition(tempCoords);
}

//bool bubbleSort(std::vector<Rectangle>& vecInput, int iWaitTime)
//{
//	int iSize = vecInput.size();
//	// Bubble sort has runtime of O(n^2)
//	bool bswapped = false;
//	// If it does a full pass through the array without swapping, end this loop
//	//ArrClass firstObject = vecInput[0];
//	//ArrClass secondObject = vecInput[0];
//	ArrClass* aPointer = &vecInput[0];
//	ArrClass* aPointer2 = &vecInput[0];
//	do
//	{
//		bswapped = false;
//		// Loop through the array
//		for (int i = 1; i < iSize; i++)
//		{
//			/*int* a = &arrInput[i];
//			int* b = &arrInput[i-1];*/
//
//			// Check if the pair is not in order.
//			if (vecInput[i].iValue < vecInput[i - 1].iValue)
//			{
//				std::this_thread::sleep_for(std::chrono::milliseconds(iWaitTime));
//				// Perform swap since they are not in order
//				// Save a pointer to both vecInputs so that we can turn them white when needed
//				/*setWhite(&firstObject, &secondObject);*/
//				/*std::cout << "Before the swap" << std::endl;
//				std::cout << &vecInput[i] << " " << aPointer << std::endl;
//				std::cout << &vecInput[i - 1] << " " << aPointer2 << std::endl;*/
//				/*aPointer->setActive(false);
//				aPointer2->setActive(false);*/
//				//setWhite(aPointer, aPointer2);
//				swap(&vecInput[i], &vecInput[i - 1]);
//				bswapped = true;
//				//std::cout << "After the swap" << std::endl;
//				aPointer = &vecInput[i];
//				aPointer2 = &vecInput[i - 1];
//				/*std::cout << &vecInput[i] << " " << aPointer << std::endl;
//				std::cout << &vecInput[i - 1] << " " << aPointer2 << std::endl;*/
//			}
//			//PrintContents(arrInput, 10, bswapped);
//		}
//
//	} while (bswapped == true);
//	//setWhite(aPointer, aPointer2);
//
//	std::cout << "successfully sorted\n";
//	return true;
//}