#pragma once
#include <SFML/Graphics.hpp>
#include <atomic>
#include <iostream>

class Rectangle : public sf::Drawable
{
	public:
		Rectangle();
		Rectangle(int value, sf::Vector2f size, sf::Vector2f position, sf::Color activeColor, sf::Color inactiveColor, bool active, sf::Time transitionTime);
		void update();
		
		int getValue();
		sf::Color getActiveColor();
		sf::Color getInactiveColor();
		sf::Vector2f getSize();
		sf::Vector2f getPosition();
		
		void setValue(int value);
		void setSize(const sf::Vector2f& size);
		void setPosition(const sf::Vector2f& position);
		void setTransitionTime(const sf::Time& time);
		void setActive();
		void setInactive();
		void setActiveColor(const sf::Color& color);
		void setInactiveColor(const sf::Color& color);
		void setOrigin(const sf::Vector2f& coords);

		// Used for comparing value with other rectangles
		bool operator==(const Rectangle& rhs) const;
		bool operator!=(const Rectangle& rhs) const;
		bool operator<(const Rectangle& rhs) const;
		bool operator>(const Rectangle& rhs) const;
		bool operator<=(const Rectangle& rhs) const;
		bool operator>=(const Rectangle& rhs) const;

	private:
		int value;
		bool isActive;
		sf::Time transitionDuration;
		sf::Clock clock;
		sf::Color activeColor;
		sf::Color inactiveColor;
		sf::RectangleShape rectShape;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

