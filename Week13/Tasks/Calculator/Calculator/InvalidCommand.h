#pragma once
#include <exception>
#include <string>
#include <iostream>
class InvalidCommand : public std::exception
{
private:
	std::string message;
public:
	InvalidCommand() : message("Invalid Command"){}
	InvalidCommand(const std::string& m): message(m){}

	const char* what() const noexcept override { return message.c_str(); }
};

