#include "ArrClass.h"

ArrClass::ArrClass()
{
}

ArrClass::ArrClass(int val = 0, sf::Color activeColor = sf::Color::Red, sf::Color inactiveColor = sf::Color::White) :
	value(val),
	activeColor(activeColor),
	inactiveColor(inactiveColor)
{
}

void ArrClass::setActive(bool bValue)
{
	activeRect = bValue;
}

bool ArrClass::isActive()
{
	return activeRect;
}

int ArrClass::getValue()
{
	return value;
}

void ArrClass::setActive()
{
	activeRect = true;
	rectShape.setFillColor(activeColor);
}

void ArrClass::setInactive()
{
	activeRect = false;
	rectShape.setFillColor(inactiveColor);
}

void ArrClass::setActiveColor(sf::Color& color)
{
	activeColor = color;
}

void ArrClass::setInactiveColor(sf::Color& color)
{
	inactiveColor = color;
}

void ArrClass::setValue(int x)
{
	value = x;
}
