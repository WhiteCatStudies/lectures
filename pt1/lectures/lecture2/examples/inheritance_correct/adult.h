#pragma once
#include "person.h"

class Adult : public Person
{
public:
	Adult(const std::string& name, const std::string& work);
	~Adult();
	void say() const;
	void goWork() const;

private:
	std::string _work;
};

