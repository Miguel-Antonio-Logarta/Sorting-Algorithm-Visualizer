#include "Application.h"

Application::Application() 
	: mWindow{ sf::VideoMode(1280, 720), "Sorting Algorithm Visualizer" }
	, sorter{ sortingArray }
	, renderer{ sortingArray, mWindow }
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
		renderer.drawRectangles();
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
				renderer.calculateRectSizes();
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

	while (true) {
		renderer.setRecalculateRectSizes(true);

		int amount{ 0 };
		int choice{ 0 };
		std::cout << "Enter the number of items to sort: ";
		std::cin >> amount;
		sorter.setDelay(5);
		sorter.shuffleArray(amount);

		std::cout << "Enter the number corresponding to the sorting algorithm you want to use: \n";
		std::cout
			<< "0: Exit program"				<< "\n"
			<< "1: Bubble Sort	   O(n^2)"		<< "\n"
			<< "2: Insertion Sort  O(n^2)"		<< "\n"
			<< "3: Selection Sort  O(n^2)"		<< "\n"
			<< "4: Quick Sort      O(nlog(n))"	<< "\n"
			<< "5: Merge Sort      O(nlog(n))"	<< "\n"
			<< "6: Heap Sort       O(nlog(n))"	<< "\n"
			<< "7: Counting Sort   O(n+k)"		<< "\n"
			<< "8: Radix Sort      O(nk)"		<< "\n"
			<< "Your choice: ";
		std::cin >> choice;

		if (!choice) {			// Exit the program
			endProgram = true;
			std::cout << "Exiting program";
			break;
		}
		
		sorter.setDelay(30);
		renderer.setRecalculateRectSizes(false);
		sorter.selectSortAlgo(choice);
		sorter.startSortAlgo();

		std::cout << "Sorting has finished \n";

	}

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
		renderer.drawRectangles();
		mWindow.display();
	}
}
