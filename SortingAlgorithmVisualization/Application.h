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

		void getUserInput();

		std::vector<Rectangle> sortingArray;
		Sorter sorter;
		Renderer renderer;

		std::thread appThread;
		sf::RenderWindow mWindow;
		std::atomic<bool> endProgram;
};

