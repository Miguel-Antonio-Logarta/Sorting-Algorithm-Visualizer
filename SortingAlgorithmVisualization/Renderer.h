#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include <iostream>
#include "ArrClass.h"
#include <thread>
#include "Rectangle.h"

// Renderer creates a window in its own thread
// Takes in an array and draws it to the window
// Has a main loop that polls for events
// Handles a resize event as well


class Renderer
{
public:
	Renderer(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow);
	//Renderer(std::vector<ArrClass>&, sf::VideoMode);
	//void BeginLoop(std::vector<ArrClass>&);
	void drawRectangles();
private:
	void calculateRectSizes();
	void DrawRectangles(std::vector<ArrClass>& arr, sf::RenderWindow& mWindow);
	void CalculateRectSize(std::vector<ArrClass>&); // , sf::RenderWindow&
	void Resize();
	sf::RenderWindow window;

	// V2
	std::vector<Rectangle>& arrRef;
	sf::RenderWindow& windowRef;
};

