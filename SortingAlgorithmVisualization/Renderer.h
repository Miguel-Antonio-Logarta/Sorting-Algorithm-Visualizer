#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include "Rectangle.h"

class Renderer
{
	public:
		Renderer(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow);
		void drawRectangles();
		void setToRender(bool condition);

	private:
		void calculateRectSizes();
		void Resize();

		std::vector<Rectangle>& arrRef;
		sf::RenderWindow& windowRef;

		bool calculatetherect;
};

