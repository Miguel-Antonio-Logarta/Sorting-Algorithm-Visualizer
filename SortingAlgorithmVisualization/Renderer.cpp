#include "Renderer.h"

//Renderer::Renderer()
//{
//}

Renderer::Renderer(std::vector<Rectangle>& arr, sf::RenderWindow& mWindow) :
	arrRef(arr),
	windowRef(mWindow)
{
}

//Renderer::Renderer(std::vector<ArrClass>& arrVector, sf::VideoMode vmResolution)
//	: window(vmResolution, "My Window"),
//{
//	//sf::RenderWindow window(vmResolution, "My Window");
//	window.setFramerateLimit(60);
//
//	// Set rect position and size
//	CalculateRectSize(arrVector);
//	//window.setActive(false); // We need to deactive this window to move it to a new thread
//}

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

		float fHeight = ((windowHeight - 2 * iMargins) / (float)iArrayMax) * ((float)arrRef[i].getValue());		// (max window size w/ margins) / (MaxVal*elementVal)
		float fWidth = (windowWidth - 2 * iMargins) / (float)iSize;
		float fXPos = i * fWidth + iMargins;
		float fYPos = windowHeight - iMargins - fHeight;

		arrRef[i].setSize(sf::Vector2f(fWidth, fHeight));
		arrRef[i].setPosition(sf::Vector2f(fXPos, fYPos));
	}
}

void Renderer::DrawRectangles(std::vector<ArrClass>& arr, sf::RenderWindow& mWindow)
{
}

void Renderer::CalculateRectSize(std::vector<ArrClass>& arrVector) //  , sf::RenderWindow& window
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

	// Issue: Both size and position is not mapping right. When the window is smaller, the rectangles end up being too small. When the window is bigger, the rectangles end up being too big
}

void Renderer::drawRectangles()
{
	calculateRectSizes();

	for (auto& elem : arrRef) {
		/*windowRef.draw(elem.rect)*/
		elem.drawSelf(windowRef);
	}
}

//void Renderer::DrawRectangles(std::vector<ArrClass>& arrVector)
//{
//	CalculateRectSize(arrVector);
//	/*std::cout << "The rectangle is being drawn";*/
//	int iSize = arrVector.size();
//	for (int i = 0; i < iSize; i++)
//	{
//		//if (arrVector[i].isActive())
//		//{
//		//	arrVector[i].rectShape.setFillColor(sf::Color::Red);
//		//	// If it is red, set isActive back to false so that next time it renders as white
//		//	arrVector[i].setActive(false);
//		//}
//		//else
//		//	arrVector[i].rectShape.setFillColor(sf::Color::White);
//
//		if (arrVector[i].isActive())
//		{
//			arrVector[i].rectShape.setFillColor(sf::Color::Red);
//		}
//		else
//			arrVector[i].rectShape.setFillColor(sf::Color::White);
//		window.draw(arrVector[i].rectShape);
//	}
//
//	//std::cout << &arrVector;
//}

void Renderer::Resize()
{

}

//void Renderer::BeginLoop(std::vector<ArrClass>& arrVector)
//{
//	// Begin the main game loop
//	while (window.isOpen())
//	{
//		
//		// Start the rendering thread
//
//		sf::Event evnt;
//		while (window.pollEvent(evnt))
//		{
//			//std::cout << "ha";
//			switch (evnt.type)
//			{
//
//			case sf::Event::Closed:
//				window.close();
//				break;
//				// Keyboard events down here
//			case sf::Event::KeyPressed:
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
//				{
//					// Pause the sort
//					std::cout << "P is pressed\n";
//				}
//				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//				{
//					// Lower the delay between each array action
//					std::cout << "Left is pressed";
//				}
//				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//				{
//					// Increase the delay between each array action
//					std::cout << "Right is pressed";
//				}
//				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
//				{
//					// Just complete the array sort without delay
//					std::cout << "Enter is pressed";
//				}
//				break;
//			case sf::Event::Resized:
//				std::cout << "I have been resized!";
//				break;
//			default:
//				break;
//			}
//			
//		}
//
//		window.clear();
//		DrawRectangles(arrVector);
//		window.display();
//	}
//}