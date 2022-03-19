#include "Renderer.h"

Renderer::Renderer(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow) 
	: arrRef(arr)
	, windowRef(mWindow)
	, calculatetherect(true)
	, recalculateRectSizes(false)
{
}

void Renderer::calculateRectSizes()
{
	int iSize = arrRef.size();
	int iArrayMax = iSize;
	int iMargins = 5;

	for (int i = 0; i < iSize; i++)
	{
		sf::Vector2u windowSize = windowRef.getSize();

		float windowWidth = (float)windowSize.x;
		float windowHeight = (float)windowSize.y;

		// (max window size w/ margins) / (MaxVal*elementVal)
		float fHeight = ((windowHeight - 2 * iMargins) / (float)iArrayMax) * ((float)arrRef[i].getValue());		
		float fWidth = (windowWidth - 2 * iMargins) / (float)iSize;
		float fXPos = i * fWidth + iMargins;
		float fYPos = windowHeight - iMargins;

		arrRef[i].setOrigin(sf::Vector2f(0, fHeight));
		arrRef[i].setSize(sf::Vector2f(fWidth, fHeight));
		arrRef[i].setPosition(sf::Vector2f(fXPos, fYPos));
	}
}

void Renderer::drawRectangles()
{
	if (recalculateRectSizes) {
		calculateRectSizes();
	}

	for (auto& rectangle : arrRef) {
		mtx.lock();
		rectangle.update();
		mtx.unlock();

		windowRef.draw(rectangle);
	}
}

void Renderer::setRecalculateRectSizes(bool condition)
{
	recalculateRectSizes = condition;
}

void Renderer::Resize()
{
	calculateRectSizes();
}
