#ifndef SRC_TOKEN_H
#define SRC_TOKEN_H
// Token types used to represent different elements of a mathematical
// expression.
enum TokenType {
    kNumber,         // Number
    kPlus,           // Addition operator
    kMinus,          // Subtraction operator
    kMultiply,       // Multiplication operator
    kDivide,         // Division operator
    kMod,            // Modulus operator
    kPow,            // Exponentiation operator
    kSqrt = 101,     // Square root function
    kCos,            // Cosine function
    kSin,            // Sine function
    kTan,            // Tangent function
    kAcos,           // Arccosine function
    kAsin,           // Arcsine function
    kAtan,           // Arctangent function
    kLn,             // Natural logarithm function
    kLog,            // Base-10 logarithm function
    kFactorial,      // Factorial function
    kOpenBrackets,   // Opening bracket
    kCloseBrackets   // Closing bracket
};

// Token priorities that determine their significance during calculations.
enum TokenPriority {
    kLow,     // Low priority
    kMiddle,  // Medium priority
    kUnary,   // Unary operators
    kHigh,    // High priority
    kBracket  // Brackets
};

// Structure representing a token in the mathematical expression.
struct Token {
    double value{};
    TokenType type{};
    TokenPriority priority{};

    Token(double value, TokenType type, TokenPriority priority)
        : value(value), priority(priority), type(type) {}
    ~Token() {}
};

#endif // !SRC_TOKEN_H
