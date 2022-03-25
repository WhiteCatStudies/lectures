#pragma once
#include "person.h"

class Old : public Person
{
public:
	Old(const std::string& name);
	~Old();
	void say() const;
	void goFeedPegeons() const;
};

