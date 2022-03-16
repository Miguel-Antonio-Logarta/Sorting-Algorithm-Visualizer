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
		void setDelay(int timeInMs);

	private:
		std::vector<Rectangle>& sortingArray;
		bool isSorted{ false }; // At the beginning it is false, but after we finish running the sorting thread, it will be set to true.
		int algoChoice;
		std::thread sortingThread;
		int delay;

		// Sorts
		void bubbleSort(int delay);
		void insertionSort(int delay);
		void quickSort(int low, int hi, int delay);
		void selectionSort(int delay);

		// Utils
		void testfunc(int iWaitTime);
		void printArray();
		void swap(Rectangle* a, Rectangle* b);
		int partition(int low, int hi, int delay);
};

