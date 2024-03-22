#pragma once
#include "person.h"

class Young : public Person
{
public:
	Young(const std::string& name);
	~Young();
	
	void say() const;
	void act() const;

	void saySmthCool() const;
};

