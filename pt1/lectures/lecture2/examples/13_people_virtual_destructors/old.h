#pragma once
#include "person.h"

class Old : public Person
{
public:
	Old(const std::string& name);
	~Old() override;
	void say() const override;
	void goFeedPegeons() const;
};

