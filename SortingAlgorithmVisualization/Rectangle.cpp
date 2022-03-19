#include "Rectangle.h"

Rectangle::Rectangle()
	: value(0)
	, activeColor(sf::Color::Red)
	, inactiveColor(sf::Color::White)
	, isActive(false)
	, transitionDuration(sf::milliseconds(30))
	, clock()
{
}

Rectangle::Rectangle(int value, sf::Vector2f size, sf::Vector2f position, sf::Color activeColor, sf::Color inactiveColor, bool active, sf::Time transitionTime)
	: value(value)
	, activeColor(activeColor)
	, inactiveColor(inactiveColor)
	, isActive(active) 
	, transitionDuration(transitionTime)
	, clock()
{
	rectShape.setSize(size);
	setPosition(position);
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

void Rectangle::update()
{
	if (isActive) {
		// After some time, the rectangle changes to an inactive color
		if (clock.getElapsedTime() >= transitionDuration) {
			setInactive();
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

void Rectangle::setTransitionTime(const sf::Time& time)
{
	transitionDuration = time;
}

void Rectangle::setActive()
{
	isActive = true;
	rectShape.setFillColor(activeColor);
	clock.restart();
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

void Rectangle::setOrigin(const sf::Vector2f& coords)
{
	rectShape.setOrigin(coords);
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

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectShape, states);
}
