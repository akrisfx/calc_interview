#include <iostream>
#include "calculatormodel.h"
#include "var_resolver.h"
#include <regex>

int main(int argc, char** argv)
{
	auto resolver = VarResolver();
	if(resolver.SetCliArgs(argc, argv) != 0)
	{
		return 1;
	}
	resolver.Resolve();
	const auto str = resolver.GetRes();
	if(!str.empty())
	{
		auto calc = CalculatorModel();
		auto result = calc.RunModelCalculation(str);
		if(result.err_type == NO_ERROR)
		{
			std::cout << calc.GetResult();
		}
		else
		{
			result.PrintErrorStringInfo(str);
		}
	}
	return 0;
}