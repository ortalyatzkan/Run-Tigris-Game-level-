#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class MovingObject:public Object
{
public:

	virtual void moveFrame(const int& firstNum, const int& secondNum,
		 bool& isRight, sf::Time time) = 0;
	virtual void locOfFrame( const bool&) =0;


private:

};