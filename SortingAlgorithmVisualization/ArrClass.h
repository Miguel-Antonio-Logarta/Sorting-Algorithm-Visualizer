#pragma once
#include <SFML/Graphics.hpp>

// Maybe have arrclass inherit sf::rectangleshape and have its own variable called iValue;
class ArrClass
{
public:
	ArrClass();
	ArrClass(int, sf::Color, sf::Color);
	sf::RectangleShape rectShape;

	// v Delete these
	int iValue;
	void setActive(bool);
	bool isActive();
	// ^ Delete these

	int getValue();
	void setActive();
	void setInactive();
	void setActiveColor(sf::Color&);
	void setInactiveColor(sf::Color&);
	void setValue(int);

	// Add overload operators to compare values
	/*ArrClass operator>(const ArrClass& rhs) {
		return this->value > rhs.value;
	}*/
private:
	int value;
	sf::Color activeColor;
	sf::Color inactiveColor;
	bool activeRect{ false };
};

