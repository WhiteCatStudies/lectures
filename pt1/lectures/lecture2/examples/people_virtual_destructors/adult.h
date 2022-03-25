#pragma once
#include "person.h"

class Adult : public Person
{
public:
	Adult(const std::string& name, const std::string& work);
	~Adult() override;
	void say() const override;
	void goWork() const;

private:
	std::string _work;
};

