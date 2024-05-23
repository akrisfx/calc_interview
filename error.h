#ifndef SRC_ERROR_H
#define SRC_ERROR_H
#include <stdexcept>
#include <string>
enum err_type_t
{
	NO_ERROR = 0,
	INVALID_COUNT_BRACKETS = 1,
	INVALID_DOT = 2,
	EMPTY_BRACKETS = 3,
	INVALID_EXPRESSION = 4
};

class Error final : public std::runtime_error
{
public:
	Error() :  err_type(err_type_t::NO_ERROR), err_place(0), runtime_error(GetErrorStringInfo()) {}
	Error(err_type_t type, std::size_t place) :
		  err_type(type)
		, err_place(place)
		, runtime_error(GetErrorStringInfo()){}
	std::string GetErrorStringInfo();
	int GetErrorIndex() const;

	err_type_t err_type;
	int err_place;
};


#endif