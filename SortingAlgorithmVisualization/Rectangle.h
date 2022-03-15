#pragma once
#include <SFML/Graphics.hpp>

class Rectangle
{
	public:
		Rectangle(int value, sf::Vector2f size, sf::Vector2f position, sf::Color activeColor, sf::Color inactiveColor, bool active);
		int getValue();
		sf::Vector2f getSize();
		sf::Vector2f getPosition();
		sf::Color getActiveColor();
		sf::Color getInactiveColor();
		void drawSelf(sf::RenderWindow& mWindow);
		
		void setValue(int value);
		void setSize(const sf::Vector2f& size);
		void setPosition(const sf::Vector2f& position);
		void setActive();
		void setInactive();
		void setActiveColor(const sf::Color& color);
		void setInactiveColor(const sf::Color& color);

		// Used for comparing value with other rectangles
		bool operator==(const Rectangle& rhs) const;
		bool operator!=(const Rectangle& rhs) const;
		bool operator<(const Rectangle& rhs) const;
		bool operator>(const Rectangle& rhs) const;
		bool operator<=(const Rectangle& rhs) const;
		bool operator>=(const Rectangle& rhs) const;

	private:
		int value;
		sf::RectangleShape rectShape;
		sf::Color activeColor;
		sf::Color inactiveColor;
		bool isActive;
};

