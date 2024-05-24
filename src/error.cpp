#include "error.h"

std::string Error::GetErrorStringInfo()
{
	switch (err_type)
	{
	case NO_ERROR:
		return "Expression has no errors";
		break;
	case INVALID_COUNT_BRACKETS:
		return "Invalid count of brackets";
		break;
	case INVALID_DOT:
		return "Invalid dot position";
		break;
	case EMPTY_BRACKETS:
		return "Empty Brackets";
		break;
	case INVALID_EXPRESSION:
		return "Invalid expression";
		break;
	default: 
		return "";
	}
}

int Error::GetErrorIndex() const
{
	return err_place;
}
