#include "Rectangle.h"

Rectangle::Rectangle(int value, sf::Vector2f size, sf::Vector2f position, sf::Color activeColor, sf::Color inactiveColor, bool active) :
	value(value),
	activeColor(activeColor),
	inactiveColor(inactiveColor),
	isActive(active)
{
	rectShape.setSize(size);
	rectShape.setPosition(position);

	if (active) {
		rectShape.setFillColor(activeColor);
	}
	else {
		rectShape.setFillColor(inactiveColor);
	}
}

int Rectangle::getValue()
{
	return value;
}

sf::Vector2f Rectangle::getSize()
{
	return rectShape.getSize();
}

sf::Vector2f Rectangle::getPosition()
{
	return rectShape.getPosition();
}

sf::Color Rectangle::getActiveColor()
{
	return activeColor;
}

sf::Color Rectangle::getInactiveColor()
{
	return inactiveColor;
}

void Rectangle::drawSelf(sf::RenderWindow& mWindow)
{
	mWindow.draw(rectShape);
	//sf::Color sumexmaple;
	if (isActive) {
		// Instead of setting it to white, have it gradually change color from red to white every time the draw method is called.
		//rectShape.setFillColor(sf::Color(255, 255, 255));
		rectShape.setFillColor(rectShape.getFillColor() + inactiveColor);
		//isActive = false;
		if (rectShape.getFillColor() == inactiveColor) {
			isActive = false;
		}
	}
}

void Rectangle::setValue(int val)
{
	value = val;
}

void Rectangle::setSize(const sf::Vector2f& size)
{
	rectShape.setSize(size);
}

void Rectangle::setPosition(const sf::Vector2f& position)
{
	rectShape.setPosition(position);
}

void Rectangle::setActive()
{
	isActive = true;
	rectShape.setFillColor(activeColor);
}

void Rectangle::setInactive()
{
	isActive = false;
	rectShape.setFillColor(inactiveColor);
}

void Rectangle::setActiveColor(const sf::Color& color)
{
	activeColor = color;
}

void Rectangle::setInactiveColor(const sf::Color& color)
{
	inactiveColor = color;
}

bool Rectangle::operator==(const Rectangle& rhs) const
{
	return value == rhs.value;
}

bool Rectangle::operator!=(const Rectangle& rhs) const
{
	return !(*this == rhs);
}

bool Rectangle::operator<(const Rectangle& rhs) const
{
	return value < rhs.value;
}

bool Rectangle::operator>(const Rectangle& rhs) const
{
	return rhs < *this;
}

bool Rectangle::operator<=(const Rectangle& rhs) const
{
	return !(rhs < *this);
}

bool Rectangle::operator>=(const Rectangle& rhs) const
{
	return !(*this < rhs);
}
