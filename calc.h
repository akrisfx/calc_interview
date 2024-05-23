#ifndef SRC_CALC_H
#define SRC_CALC_H
#include "token.h"
#include <math.h>


struct Calculator {
    int operation{};
    double left_operand{};
    double right_operand{};
    double result{};

    // Constructor
    Calculator(int operation) : operation(operation) {}
    // Destructor
    ~Calculator() {}

    // Perform arithmetic calculations based on the selected operation.
    void ArithmeticCalculation() {
        switch (operation) {
        case kPlus:
            result = right_operand + left_operand;
            break;
        case kMinus:
            result = right_operand - left_operand;
            break;
        case kMultiply:
            result = right_operand * left_operand;
            break;
        case kDivide:
            result = right_operand / left_operand;
            break;
        case kPow:
            result = pow(right_operand, left_operand);
            break;
        case kMod:
            result = fmod(right_operand, left_operand);
            break;
        }
    }

    // Perform trigonometric calculations based on the selected operation.
    void UnaryCalculation() {
        switch (operation) {
        case kCos:
            result = cos(left_operand);
            break;
        case kSin:
            result = sin(left_operand);
            break;
        case kTan:
            result = tan(left_operand);
            break;
        case kAcos:
            result = acos(left_operand);
            break;
        case kAsin:
            result = asin(left_operand);
            break;
        case kAtan:
            result = atan(left_operand);
            break;
        case kSqrt:
            result = sqrt(left_operand);
            break;
        case kLn:
            result = log(left_operand);
            break;
        case kLog:
            result = log10(left_operand);
            break;
        case kFactorial:
            result = tgamma(left_operand + 1); // tgamma(op) == !op https://stackoverflow.com/a/50132998/16634697
        }
    }
};

#endif
