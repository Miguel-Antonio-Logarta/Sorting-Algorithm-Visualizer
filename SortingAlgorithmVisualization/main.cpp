// main.cpp: This is the entry point

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "SortClass.h"
#include <thread>							// Sorter and renderer operates on separate threads
#include "ArrClass.h"						// Objects that hold rect and a value
#include "SortingAlgorithms.h"				// Sorting algorithms for the array/vector
#include "Renderer.h"						// Renders the array as it is sorting
#include <functional>
#include "Visualizer.h"
#include <tuple>
#include "Application.h"
#include <exception>

// SortClass is not being used anymore. Delete sortClass header and cpp file. 
// ArrClass and sortingAlgorithms.cpp are the replacement

std::tuple<int, int> promptChoice() {
	int iAmount{ 0 };
	int iChoice{ 0 };
	std::cout << "Enter the number of items to sort: ";
	std::cin >> iAmount;
	std::cout << "Enter the number corresponding to the sorting algorithm you want to use: \n";
	std::cout
		<< "1: Bubble Sort" << "\n"
		<< "2: Insertion Sort" << "\n"
		<< "3: Selection Sort" << "\n"
		<< "> ";
	std::cin >> iChoice;

	return { iAmount, iChoice };
}

std::thread selectSortAlgo(std::vector<ArrClass> &arr, int choice) {
	enum sortingAlgorithms {
		BubbleSort = 1,
		InsertionSort,
		SelectionSort
	};

	switch (choice)
	{
	case BubbleSort:
	{
		// Dedicate a thread to bubble sorting
		return std::thread{ bubbleSort, std::ref(arr), 1 };
	}
	case InsertionSort:
		return std::thread{ insertionSort, std::ref(arr), 3000 };
	case SelectionSort:
		return std::thread{ selectionSort, std::ref(arr), 1 };
	default:
		break;
	}
}

int main()
{
	//auto [amount, choice] = promptChoice();

	//std::vector<ArrClass> arr;
	//generate_array(arr, amount);

	//std::thread t1 = selectSortAlgo(arr, choice);
	//
	////Visualizer visualizer(arr, sf::VideoMode(1280,720));
	//Renderer renderWindow(arr, sf::VideoMode(1280, 720));
	//

	//// Begin rendering the window
	//renderWindow.BeginLoop(arr);
	//t1.join();

	// Event handling is in the main thread
	// The rendering and the sorting is on another thread
	// User specifies the number of items to sort
	// User selects the sorting algorithm
	// The array is generated
	// Create a new thread for the renderer and the sorter
	// The main thread handles the event handling
	// The window is created
	// The array is generated visually 
	// Select the sorting algorithm
	// Start sorting
	// In the sort, for every swap, render the screen
	// Once done, exit the sort, but keep rendering until the user closes it.

	// The constructor has parameters: the window, and the array
	// Detach the window and then construct the renderWindow in a separate thread
	// 

	// Renderer and event handler in same thread
	// Sorter on another thread
	// Pass the renderer to the sorter
	// The sorter calls when to draw the frame
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception & e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}

	//return 0;
}

//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace sf;
//using namespace std;
//
//class Field
//{
//private:
//	vector<int> m_points;
//
//public:
//	void fill(const unsigned number_of_points) {
//		//Creating the points
//		for (unsigned i = 0; i < number_of_points; ++i)
//		{
//			m_points.push_back(i);
//		}
//		//Shuffling it
//		random_shuffle(m_points.begin(), m_points.end());
//	}
//
//	//bubble sort
//	void BubbleSort() {
//		for (size_t i = m_points.size() - 1; i > 0; --i) {
//			bool swapped = false;
//			for (size_t pos = 0; pos < i; ++pos) {
//				if (m_points[pos] < m_points[pos + 1]) {
//					swap(m_points[pos], m_points[pos + 1]);
//					swapped = true;
//				}
//			}if (swapped) break;
//		}
//	}
//
//	void show_points(RenderWindow& App)
//	{
//		RectangleShape rectangle(Vector2f(1, 178));
//		rectangle.setFillColor(Color(224, 18, 96));
//		for (size_t i = 0; i < m_points.size(); i++)
//		{
//			rectangle.setPosition(i, m_points[i]);
//			App.draw(rectangle);
//		}
//	}
//};
//
//int main()
//{
//	RenderWindow App(VideoMode(800, 600), "Bubble Sort");
//	Event ev;
//	Field fieldContext;
//	fieldContext.fill(1000);
//
//	//Let's start the app
//	while (App.isOpen())
//	{
//		//Verifying events
//		while (App.pollEvent(ev))
//		{
//			// Window closed
//			if (ev.type == Event::Closed) App.close();
//
//		}
//		fieldContext.BubbleSort();
//		//Clearing screen
//		App.clear(Color::Black);
//		fieldContext.show_points(App);
//
//		//Displaying 
//		App.display();
//	}
//	return 0;
//}