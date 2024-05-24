#include "var_resolver.h"
#include <regex>
#include <unordered_map>

std::pair<std::string, std::string> ParseVar(const std::string& input)
{
	auto pos = input.find('=');
	if (pos == std::string::npos) {
		throw CLI::ValidationError("Invalid format for variable: " + input);
	}
	std::string name = input.substr(0, pos);
	std::string value = input.substr(pos + 1);
	return std::make_pair(name, value);
}

int VarResolver::SetCliArgs(int argc, char** argv)
{
	//std::unordered_map<std::string, std::string> variables = {};

	app_.add_option("expression_", expression_, "Math expression, if you want to put vars, you must use () for vars. (x) * 2 + (y)")
		->required();

	std::vector<std::string> var_strings;
	app_.add_option("--var", var_strings, "Variable in the format 'name=value'")->take_all();

	CLI11_PARSE(app_, argc, argv);
	for (const auto& var_string : var_strings) {
		auto var = ParseVar(var_string);
		vars_[var.first] = var.second;
	}
	//vars_ = (variables);

	return 0;

}

void VarResolver::Resolve()
{
	ReplaceBrackets(expression_);
	for (const auto& [name, val] : vars_)
	{
		const auto str_to_replace = "[(]" + name + "[)]";
		if (auto it = const_vals.find(val); it != const_vals.end())
			ReplaceSubstring(str_to_replace, "(" + it->second + ")");
		else
			ReplaceSubstring(str_to_replace, "(" + val + ")");
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
