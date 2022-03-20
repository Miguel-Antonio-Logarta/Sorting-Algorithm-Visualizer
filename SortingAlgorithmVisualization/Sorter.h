#pragma once
#include "Rectangle.h"
#include <vector>
#include <cstddef>
#include <chrono>
#include <mutex>

class Sorter
{
	public:
		Sorter();

		void shuffleArray(std::vector<Rectangle>& arr, int size);
		void selectSortAlgo(int choice);
		void startSortAlgo(std::vector<Rectangle>& arr);
		void setDelay(int timeInMs);


	private:
		int algoChoice;
		int delay;
		std::mutex mtx;

		// Sorts
		void bubbleSort(std::vector<Rectangle>& arr);
		void insertionSort(std::vector<Rectangle>& arr);
		void selectionSort(std::vector<Rectangle>& arr);					
		void quickSort(std::vector<Rectangle>& arr, int low, int hi);		
		void mergeSort(std::vector<Rectangle>& arr, int l, int r);
		void heapSort(std::vector<Rectangle>& arr, int n);
		void countingSort(std::vector<Rectangle>& arr);
		void countingSort(std::vector<Rectangle>& arr, int place);	
		void radixSort(std::vector<Rectangle>& arr);

		// Utils
		void printVector(std::vector<Rectangle>& arr);
		void heapify(std::vector<Rectangle>& arr, int n, int i);
		void swap(Rectangle* a, Rectangle* b);
		void merge(std::vector<Rectangle>& arr, int p, int q, int r);				
		int partition(std::vector<Rectangle>& arr, int low, int hi);
};

