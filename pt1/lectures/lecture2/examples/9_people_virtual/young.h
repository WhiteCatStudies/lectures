#pragma once
#include "person.h"

class Young : public Person
{
public:
	Young(const std::string& name);
	~Young();
	void say() const override;
	void act() const override;
	
	void saySmthCool() const;
};

