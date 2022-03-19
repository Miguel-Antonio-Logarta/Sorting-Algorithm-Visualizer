# Sorting Algorithm Visualizer With SFML
Welcome to my sorting algorithm visualizer! It utilizes SFML to render a vector of rectangles onto the screen.
## Currently supported sorting algorithms
* Bubble sort O(n^2)
* Insertion sort O(n^2)
* Selection sort O(n^2)
* Quick sort O(nlog(n))
* Merge sort O(nlog(n))
* Heap sort O(nlog(n))
* Counting sort O(n+k);
* Radix sort O(nk);
## Limitations
This visualizer does not have the ability to show multiple vectors at the same time. This is a drawback for sorting algorithms such as counting sort since counting sort builds a new vector after arithmetically calculating new positions of elements from the input vector.