#pragma once
#include <SFML/Graphics.hpp>
#include "Sorter.h"
#include "Renderer.h"
#include <thread>
#include <iostream>
#include <atomic>

// Application keeps track of the window, game state, sorter, array, etc...
// Renderer draws and renders on the screen
// Sorter handles the sorting of the array
class Application
{
	public:
		Application();

		void run();
		void handleEvents();

	private:
		std::tuple<int, int> promptUser();
		int selectSortAlgorithm();

		static const sf::Time timePerFrame;
		sf::RenderWindow mWindow;

		Sorter sorter;
		std::vector<Rectangle> sortingArray;
		Renderer renderer;

		std::thread appThread;

		void getUserInput();

		std::atomic<bool> endProgram;
};

