#include <iostream>
#include <stack>
#include <string>
#include "Expression.h"


int main()
{

    std::string stringInput;

    std::cout << "Enter an expression: ";
    getline(std::cin, stringInput);

    Expression exp(stringInput);
    exp.removeWhitespace();
    exp.segChars();
    exp.printBrackets();
    exp.printNonBrackets();


    return 0;
}


