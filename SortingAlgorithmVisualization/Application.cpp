#include "Application.h"

Application::Application() 
	: mWindow(sf::VideoMode(1280, 720), "Sorting Algorithm Visualizer")
	, sorter(sortingArray)
	, renderer(sortingArray, mWindow)
	, endProgram(false)
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

		for (auto& rectangle : sortingArray) {
			rectangle.update();
		}

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
			mWindow.close();
			break;
			// Keyboard events down here
		//case sf::Event::KeyPressed:
		//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		//	{
		//		// Pause the sort
		//		std::cout << "P is pressed\n";
		//	}
		//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		//	{
		//		// Lower the delay between each array action
		//		std::cout << "Left is pressed";
		//	}
		//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		//	{
		//		// Increase the delay between each array action
		//		std::cout << "Right is pressed";
		//	}
		//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		//	{
		//		// Just complete the array sort without delay
		//		std::cout << "Enter is pressed";
		//	}
		//	break;
		case sf::Event::Resized:
			std::cout << "I have been resized!";

			break;
		default:
			break;
		}

	}
}

void Application::getUserInput()
{
	// Find a way to clear the console so that the console is clean.
	std::cout << "Welcome to my sorting algorithm visualizer!" << "\n";
	renderer.setToRender(true);

	while (true) {
		sorter.setDelay(0);
		int amount{ 0 };
		int choice{ 0 };
		std::cout << "Enter the number of items to sort: ";
		std::cin >> amount;
		sorter.shuffleArray(amount);

		std::cout << "Enter the number corresponding to the sorting algorithm you want to use: \n";
		std::cout
			<< "0: Exit program"	<< "\n"
			<< "1: Bubble Sort"		<< "\n"
			<< "2: Insertion Sort"	<< "\n"
			<< "3: Selection Sort"	<< "\n"
			<< "4: Quick Sort"		<< "\n"
			<< "Your choice: ";
		std::cin >> choice;

		sorter.setDelay(5);
		if (!choice) {			// Exit the program
			endProgram = true;
			std::cout << "Exiting program";
			break;
		}
		
		renderer.setToRender(false);
		
		sorter.selectSortAlgo(choice);
		
		sorter.startSortAlgo();

		std::cout << "Sorting has finished \n";
		renderer.setToRender(true);

	}
}
