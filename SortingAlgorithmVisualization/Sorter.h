#pragma once
#include "Rectangle.h"
#include <vector>
#include <thread>

class Sorter
{
public:
	Sorter(std::vector<Rectangle>& arr);

	void shuffleArray(std::vector<Rectangle>& arr, int size);
	void shuffleArray(int size);
	void selectSortAlgo(int choice);
	void startSortAlgo();
	bool checkIfSorted();

private:
	//bool bubbleSort(std::vector<Rectangle>& vecInput, int iWaitTime);
	void testfunc(int iWaitTime);

	//std::thread sortingThread;
	std::vector<Rectangle>& sortingArray;
	bool isSorted{ false }; // At the beginning it is false, but after we finish running the sorting thread, it will be set to true.
	int algoChoice;
	std::thread sortingThread;

	void bubbleSort(int delay);
	void printArray();
	void swap(Rectangle* a, Rectangle* b);
};

