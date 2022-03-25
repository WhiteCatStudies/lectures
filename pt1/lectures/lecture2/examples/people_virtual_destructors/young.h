#pragma once
#include "person.h"

class Young : public Person
{
public:
	Young(const std::string& name);
	~Young() override;
	void say() const override;
	void saySmthCool() const;
	void goStudy() const;
};

