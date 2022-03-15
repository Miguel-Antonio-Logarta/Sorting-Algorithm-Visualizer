#include "Visualizer.h"

Visualizer::Visualizer(std::vector<ArrClass>& arrVector, sf::VideoMode vmResolution)
	: window(vmResolution, "My Window")
{
	//sf::RenderWindow window(vmResolution, "My Window");
	window.setFramerateLimit(60);

	// Set rect position and size
	CalculateRectSize(arrVector);
}

Visualizer::Visualizer(unsigned int resHeight, unsigned int resWidth, int sortChoice, std::string windowTitle)
	: window(sf::VideoMode(resWidth, resHeight), windowTitle)
{
	window.setFramerateLimit(60);

	switch (sortChoice) {
	case 1:
		break;
	default:
		break;
	}
}

void Visualizer::BeginLoop(std::vector<ArrClass>&)
{
}

void Visualizer::CalculateRectSize(std::vector<ArrClass>& arrVector)
{
	int iSize = arrVector.size();
	int iArrayMax = iSize;
	int iMargins = 5;

	for (int i = 0; i < iSize; i++)
	{
		sf::Vector2u windowSize = window.getSize();

		float windowWidth = (float)windowSize.x;
		float windowHeight = (float)windowSize.y;

		float fHeight = ((windowHeight - 2 * iMargins) / (float)iArrayMax) * ((float)arrVector[i].iValue);		// (max window size w/ margins) / (MaxVal*elementVal)
		float fWidth = (windowWidth - 2 * iMargins) / (float)arrVector.size();
		float fXPos = i * fWidth + iMargins;
		float fYPos = windowHeight - iMargins - fHeight;

		arrVector[i].rectShape.setSize(sf::Vector2f(fWidth, fHeight));
		arrVector[i].rectShape.setPosition(sf::Vector2f(fXPos, fYPos));
	}
}

void Visualizer::DrawRectangles(std::vector<ArrClass>& arrVector)
{
	CalculateRectSize(arrVector);
	int iSize = arrVector.size();
	for (int i = 0; i < iSize; i++)
	{
		//if (arrVector[i].isActive())
		//{
		//	arrVector[i].rectShape.setFillColor(sf::Color::Red);
		//	// If it is red, set isActive back to false so that next time it renders as white
		//	arrVector[i].setActive(false);
		//}
		//else
		//	arrVector[i].rectShape.setFillColor(sf::Color::White);

		if (arrVector[i].isActive())
		{
			arrVector[i].rectShape.setFillColor(sf::Color::Red);
		}
		else
			arrVector[i].rectShape.setFillColor(sf::Color::White);
		window.draw(arrVector[i].rectShape);
	}
}

void Visualizer::Resize()
{
}

std::thread Visualizer::selectSort(std::vector<ArrClass>&)
{
	return std::thread();
}
