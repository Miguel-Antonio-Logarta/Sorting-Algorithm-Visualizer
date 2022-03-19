#pragma once
#include <SFML/Graphics.hpp>
#include "Sorter.h"
#include "Renderer.h"
#include <thread>
#include <iostream>
#include <atomic>

class Application
{
	public:
		Application();

		void run();
		void handleEvents();

	private:

		void getUserInput();
		void runRenderer();

		std::vector<Rectangle> sortingArray;
		Sorter sorter;
		Renderer renderer;

		std::thread appThread;
		sf::RenderWindow mWindow;
		std::atomic<bool> endProgram;
};

