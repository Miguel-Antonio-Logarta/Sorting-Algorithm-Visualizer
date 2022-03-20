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
		Renderer();

		void drawRectangles(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow);
		void calculateRectSizes(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow);
		void setRecalculateRectSizes(bool condition);

	private:
		std::mutex mtx;
		bool recalculateRectSizes;
};

