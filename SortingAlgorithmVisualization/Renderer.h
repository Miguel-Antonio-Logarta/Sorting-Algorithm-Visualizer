#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include "Rectangle.h"
#include <mutex>

class Renderer
{
	public:
		Renderer(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow);
		void drawRectangles();
		void setRecalculateRectSizes(bool condition);
		void calculateRectSizes();

	private:
		void Resize();

		std::vector<Rectangle>& arrRef;
		sf::RenderWindow& windowRef;
		std::mutex mtx;

		bool calculatetherect;
		bool recalculateRectSizes;
};

