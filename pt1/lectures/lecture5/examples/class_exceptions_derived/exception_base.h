#pragma once
#include <string>


class StudentExceptionBase
{
public:
	StudentExceptionBase(const std::string& reason);
	StudentExceptionBase(const StudentExceptionBase& other);

	std::string getReason() const;

private:
	// Можно передать обработчику исключений информацию о случившемся,
	// используя сообщения или коды
	// Применяется, когда возможны различные исключительные ситуации, 
	// но при обработке исключения выполняются одни и те же действия 
	std::string _reason;
};

class LateException : public StudentExceptionBase
{
public:
	LateException();
};

class BadLuckException : public StudentExceptionBase
{
public:
	BadLuckException();
};