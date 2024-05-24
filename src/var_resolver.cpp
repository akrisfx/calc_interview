#include "var_resolver.h"
#include <regex>
#include <unordered_map>


int VarResolver::SetCliArgs(int argc, char** argv)
{
	std::unordered_map<std::string, std::string> variables = {};

	app_.add_option("expression_", expression_, "Math expression_")
		->required();

	// Опция для передачи переменных в формате "имя=значение"
	auto varOption = app_.add_option_function<std::pair<std::string, std::string>>(
		"--var",
		[&variables](const std::pair < std::string, std::string >& var) {
			variables[var.first] = var.second;
		},
		"Variable on format 'name=value'"
	)->expected(-1); // -1 означает, что опция может быть указана неограниченное число раз

	CLI11_PARSE(app_, argc, argv);
	vars_ = (variables);

	return 0;

}

void VarResolver::Resolve()
{
	ReplaceBrackets(expression_);
	for (const auto& [name, val] : vars_)
	{
		if (auto it = const_vals.find(val); it != const_vals.end())
			ReplaceSubstring("(" + name + ")", "(" + it->second + ")");
		else
			ReplaceSubstring("(" + name + ")", "(" + val + ")");
	}
}

void VarResolver::ReplaceBrackets(std::string& str_expr)
{
	std::ranges::replace(str_expr, '[', '(');
	std::ranges::replace(str_expr, ']', ')'); // ranges
	std::replace(str_expr.begin(), str_expr.end(), '{', '('); //classic. Why not ^_^
	std::replace(str_expr.begin(), str_expr.end(), '}', ')');
}

void VarResolver::ReplaceSubstring(const std::string& from, const std::string& to)
{
	expression_ = std::regex_replace(expression_, std::regex(from), to);
}
