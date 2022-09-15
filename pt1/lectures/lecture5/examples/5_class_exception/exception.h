#pragma once
#include <string>


class StudentException
{
public:
	StudentException(const std::string& reason);
	StudentException(const StudentException& other);

	std::string getReason() const;

private:
	// Можно передать обработчику исключений информацию о случившемся,
	// используя сообщения или коды
	// Применяется, когда возможны различные исключительные ситуации, 
	// но при обработке исключения выполняются одни и те же действия 
	std::string _reason;
};