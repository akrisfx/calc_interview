# CLI Calculator
## Build 
```sh
mkdir build
cd build
cmake ..
cmake --build .
```
## Usage 
`./calc "math expresshion"`

`./calc "math expr with variables (x) + (y)" --var x=4 --var y=PI` - if the name of var is not resolved it will turn to zero

The number of arguments is unlimited

## Expansion
If you wnat add new tokens put token name in enum [token.h](https://github.com/akrisfx/calc_interview/blob/main/src/token.h)
And add math logic to [calc.h](https://github.com/akrisfx/calc_interview/blob/main/src/calc.h) and string parser [calculatormodel.cpp](https://github.com/akrisfx/calc_interview/blob/f3bc4c599accfca8c6b52624a177add8c11b0922/src/calculatormodel.cpp#L169)

To add a new const value, enter the value in [calculatormodel.h](https://github.com/akrisfx/calc_interview/blob/059e99d612fb36a1659face8c172a927f84df65b/src/calculatormodel.h#L50)
