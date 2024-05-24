#include "error.h"

#include <iomanip>
#include <iostream>

void Error::PrintErrorStringInfo(const std::string& str) const
{
	std::cout << "Error: ";
	switch (err_type)
	{
	case NO_ERROR:
		std::cout << "Expression has no errors\n";
		break;
	case INVALID_COUNT_BRACKETS:
		std::cout << "Invalid count of brackets\n";
		break;
	case INVALID_DOT:
		std::cout << "Invalid dot position\n"
				  << str << "\n";
		
		PrintPointerToErr(str);
		break;
	case EMPTY_BRACKETS:
		std::cout << "Empty Brackets"
			<< str << "\n";
		PrintPointerToErr(str);
		break;
	case INVALID_EXPRESSION:
		std::cout << "Invalid expression"
			<< str << "\n";
		PrintPointerToErr(str);
		break;
	default:;
	}
}

int Error::GetErrorIndex() const
{
	return err_place;
}

void Error::PrintPointerToErr(const std::string& str) const
{
	std::cout << std::setfill('_') << std::setw(err_place + 1) << "^" << std::setfill('_')
		<< std::setw(str.size() - err_place) << "\n";
}
