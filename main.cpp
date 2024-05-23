#include <iostream>
#include "calculatormodel.h"

int main()
{
	auto calc = CalculatorModel();
	auto result = calc.RunModelCalculation("!(1 + 2)", "3.145");
	if(result.err_type == NO_ERROR)
	{
		std::cout << calc.GetResult();
	}
	else
	{
		std::cout << result.GetErrorStringInfo();
	}

}