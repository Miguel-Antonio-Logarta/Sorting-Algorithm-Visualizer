#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//#include <time.h>
//#include <iostream>
#include "ArrClass.h"
#include <thread>
//#include <thread>

class Visualizer
{
public:
	Visualizer(std::vector<ArrClass>&, sf::VideoMode);
	Visualizer(unsigned int resHeight, unsigned int resWidth, int sortChoice, std::string windowTitle);
	void BeginLoop(std::vector<ArrClass>&);
private:
	void CalculateRectSize(std::vector<ArrClass>& arrVector); // , sf::RenderWindow&
	void DrawRectangles(std::vector<ArrClass>& arrVector);
	void Resize();
	std::thread selectSort(std::vector<ArrClass>&);
	sf::RenderWindow window;

	enum sortingAlgorithms {
		BubbleSort = 1,
		InsertionSort,
		SelectionSort
	};
};

