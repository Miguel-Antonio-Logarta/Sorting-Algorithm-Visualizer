#include "Renderer.h"

Renderer::Renderer()
	: recalculateRectSizes(false)
{
}

void Renderer::calculateRectSizes(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow)
{
	int iSize = arr.size();
	int iArrayMax = iSize;
	int iMargins = 5;
	
	for (int i = 0; i < iSize; i++)
	{
		sf::Vector2u windowSize = mWindow.getSize();

		float windowWidth = (float)windowSize.x;
		float windowHeight = (float)windowSize.y;

		// (max window size w/ margins) / (MaxVal*elementVal)
		float fHeight = ((windowHeight - 2 * iMargins) / (float)iArrayMax) * ((float)arr[i].getValue());
		float fWidth = (windowWidth - 2 * iMargins) / (float)iSize;
		float fXPos = i * fWidth + iMargins;
		float fYPos = windowHeight - iMargins;

		arr[i].setOrigin(sf::Vector2f(0, fHeight));
		arr[i].setSize(sf::Vector2f(fWidth, fHeight));
		arr[i].setPosition(sf::Vector2f(fXPos, fYPos));
	}
}

void Renderer::drawRectangles(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow)
{
	if (recalculateRectSizes) {
		calculateRectSizes(arr, mWindow);
	}

	for (auto& rectangle : arr) {
		mtx.lock();
		rectangle.update();
		mtx.unlock();

		mWindow.draw(rectangle);
	}
}

void Renderer::setRecalculateRectSizes(bool condition)
{
	recalculateRectSizes = condition;
}