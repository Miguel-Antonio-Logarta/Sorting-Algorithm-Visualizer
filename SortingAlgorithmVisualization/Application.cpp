#include "Application.h"

Application::Application() 
	: mWindow{ sf::VideoMode(1280, 720), "Sorting Algorithm Visualizer" }
	, sorter{}
	, renderer{}
	, endProgram{ false }
{
	mWindow.setFramerateLimit(60);
}

void Application::run()
{
	appThread = std::thread{ &Application::getUserInput, this };

	while (mWindow.isOpen() && !endProgram.load())
	{
		handleEvents();
		mWindow.clear();
		renderer.drawRectangles(sortingArray, mWindow);
		mWindow.display();
	}
	appThread.join();
}

void Application::handleEvents()
{
	sf::Event evnt;
	while (mWindow.pollEvent(evnt))
	{
		switch (evnt.type)
		{

			case sf::Event::Closed:
			{
				mWindow.close();
				break;
			}
			case sf::Event::Resized:
			{
				sf::FloatRect visibleArea(
					0.0f,
					0.0f,
					static_cast<float>(evnt.size.width),
					static_cast<float>(evnt.size.height)
				);
				mWindow.setView(sf::View(visibleArea));
				renderer.calculateRectSizes(sortingArray, mWindow);
				break;
			}
			default:
			{
				break;
			}
		}

	}
}

void Application::getUserInput()
{
	std::cout << "Welcome to my sorting algorithm visualizer!" << "\n";
	renderer.setRecalculateRectSizes(true);

	int amount{ 0 };
	int choice{ 0 };
	std::cout << "Enter the number of items to sort: ";
	std::cin >> amount;
	sorter.setDelay(5);
	sorter.shuffleArray(sortingArray, amount);

	std::cout << "Enter the number corresponding to the sorting algorithm you want to use: \n";
	std::cout
		<< "0: Exit program" << "\n"
		<< "1: Bubble Sort	   O(n^2)" << "\n"
		<< "2: Insertion Sort  O(n^2)" << "\n"
		<< "3: Selection Sort  O(n^2)" << "\n"
		<< "4: Quick Sort      O(nlog(n))" << "\n"
		<< "5: Merge Sort      O(nlog(n))" << "\n"
		<< "6: Heap Sort       O(nlog(n))" << "\n"
		<< "7: Counting Sort   O(n+k)" << "\n"
		<< "8: Radix Sort      O(nk)" << "\n"
		<< "Your choice: ";
	std::cin >> choice;

	if (!choice) {			// Exit the program
		endProgram = true;
		std::cout << "Exiting program";
		return;
	}

	sorter.setDelay(5);
	renderer.setRecalculateRectSizes(false);
	sorter.selectSortAlgo(choice);
	sorter.startSortAlgo(sortingArray);

	std::cout << "Sorting has finished \n";

	// I wanted it to be a loop, but the program would crash every time the vector was reallocated.
	// The renderer would run in the middle of reallocation and end up reading an invalid reference to an element.
	// Mutexes did not help in solving the problem, so I just ditched this idea.

	//while (true) {
	//	renderer.setRecalculateRectSizes(true);

	//	int amount{ 0 };
	//	int choice{ 0 };
	//	std::cout << "Enter the number of items to sort: ";
	//	std::cin >> amount;
	//	sorter.setDelay(5);
	//	sorter.shuffleArray(sortingArray, amount);

	//	std::cout << "Enter the number corresponding to the sorting algorithm you want to use: \n";
	//	std::cout
	//		<< "0: Exit program"				<< "\n"
	//		<< "1: Bubble Sort	   O(n^2)"		<< "\n"
	//		<< "2: Insertion Sort  O(n^2)"		<< "\n"
	//		<< "3: Selection Sort  O(n^2)"		<< "\n"
	//		<< "4: Quick Sort      O(nlog(n))"	<< "\n"
	//		<< "5: Merge Sort      O(nlog(n))"	<< "\n"
	//		<< "6: Heap Sort       O(nlog(n))"	<< "\n"
	//		<< "7: Counting Sort   O(n+k)"		<< "\n"
	//		<< "8: Radix Sort      O(nk)"		<< "\n"
	//		<< "Your choice: ";
	//	std::cin >> choice;

	//	if (!choice) {			// Exit the program
	//		endProgram = true;
	//		std::cout << "Exiting program";
	//		break;
	//	}
	//	
	//	sorter.setDelay(5);
	//	renderer.setRecalculateRectSizes(false);
	//	sorter.selectSortAlgo(choice);
	//	sorter.startSortAlgo(sortingArray);

	//	std::cout << "Sorting has finished \n";

	//}

	/*std::cout << "Welcome to my sorting algorithm visualizer!" << "\n";
	std::cout << "Sorting Algorithm: " << "Array length: " << ", Delay: ";
	std::cout << "Select an option:\n";
	std::cout
		<< "0: Exit program"		<< "\n"
		<< "1: Adjust array length" << "\n"
		<< "2: Adjust delay"		<< "\n"
		<< "3: Bubble Sort"			<< "\n"
		<< "4: Insertion Sort"		<< "\n"
		<< "5: Selection Sort"		<< "\n"
		<< "6: Quick Sort"			<< "\n"
		<< "Your choice: ";*/
}

void Application::runRenderer()
{
	mWindow.setActive(true);
	while (mWindow.isOpen() && !endProgram.load())
	{
		handleEvents();
		mWindow.clear();
		renderer.drawRectangles(sortingArray, mWindow);
		mWindow.display();
	}
}
