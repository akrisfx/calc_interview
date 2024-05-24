#ifndef SRC_VAR_RESOLVER_H
#define SRC_VAR_RESOLVER_H
#include "CLI11.hpp"
#include <string>
#include <unordered_map>


class VarResolver
{
public:
	VarResolver() = default;
	std::string GetRes() { return expression_; };
	int SetCliArgs(int argc, char** argv);
	void Resolve();


private:
	CLI::App app_{ "Simple CLI Calculator" };
	std::string expression_;
	std::unordered_map<std::string, std::string> vars_ = {};
	void ReplaceBrackets(std::string& str_expr);
	void ReplaceSubstring(const std::string& from, const std::string& to);


	const std::unordered_map<std::string, std::string> const_vals = {
		std::make_pair("PI", "3.14")
	};
};
#endif