#ifndef SRC_MODEL_CALCULATORMODEL_H
#define SRC_MODEL_CALCULATORMODEL_H

#include <math.h>

#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_map>

#include "token.h"
#include "calc.h"
#include "error.h"

class CalculatorModel
{
public:
	CalculatorModel() = default;
	~CalculatorModel() = default;

	double GetResult() const { return result_; }
	Error GetError() const { return error_; }

	void SetError(Error number) { error_ = number; }

	Error RunModelCalculation(std::string problem, std::string value);

private:
	Error error_;
	double result_{};
	std::stack<Token> stack_{};

	void MainCalculation();
	// Parsing and Tokenizing Functions
	int IsUnar(const std::string& problem, const int step);
	int HandleExponentPrefix(const std::string& problem, int startIndex);
	void ParseNumber(const std::string& problem, int& step);
	void PasteValue(std::string& problem, const std::string& number);
	void ParseOperators(std::string& problem, int& step);
	void ValidateString(const std::string& problem);
	void PasteValue(std::string& problem, std::string& number);
	void ParseString(std::string& problem);
	// Stack and Calculation Functions
	void ReverseStack();
	int IsFunctionOrBracket();
	int IsDoublePow(std::stack<Token>& operands);
	int IsBracket(std::stack<Token>& numbers);
	void Calculate(std::stack<Token>& numbers, int operation);
	void ReplaceBrackets(std::string& problem);
	std::unordered_map<std::string, std::string> constants_ = {std::make_pair("PI", "3.14")};
};

#endif  // SRC_MODEL_CALCULATORMODEL_H
