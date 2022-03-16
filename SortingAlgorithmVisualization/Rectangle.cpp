#include "Rectangle.h"

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
	if (!isActive && rectShape.getFillColor() == activeColor) {
		// For catching bugs
		std::cout << "This rect is not active, but it is red\n";
	}

	if (isActive) {
		//if (clock.getElapsedTime().asMilliseconds() >= transitionDuration.asMilliseconds()) {
		if (clock.getElapsedTime() >= transitionDuration) {
			setInactive();
		}
	}

	//if (isActive) {
	//	if (clock.getElapsedTime() >= transitionDuration) {
	//		setInactive();
	//		/*const float ratio{ (currentTime - fadeStart) / (length - fadeStart) };
	//		const sf::Color color(255, 255, 255, static_cast<sf::Uint8>(255.f * (1.f - ratio)));
	//		rectShape.setFillColor(color);*/
	//	}
	//	else {
	//		// Equation for linear color transition: f(t)=255*(t)/(d) where t is the current elapsed time and d is the transition duration
	//		const sf::Int32 ratio{ (clock.getElapsedTime().asMilliseconds() / transitionDuration.asMilliseconds()) };
	//		const sf::Uint8 colorValue = static_cast<sf::Uint8>(255.f * static_cast<float>(ratio));
	//		rectShape.setFillColor(sf::Color(255, colorValue, colorValue));
	//	}
	//}
	//if (isActive) {
	//	// Instead of setting it to white, have it gradually change color from red to white every time the draw method is called.
	//	//rectShape.setFillColor(sf::Color(255, 255, 255));
	//	sf::Uint8 currentGreen = rectShape.getFillColor().g;
	//	sf::Uint8 currentBlue = rectShape.getFillColor().b;
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
