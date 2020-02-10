#include <iostream>
#include <stack>
#include <string>
#include "Expression.h"


int main()
{
    bool anyBrackets;
    std::string stringInput;


    do{

          std::cout << "Enter an expression: ";
          getline(std::cin, stringInput);

          Expression exp(stringInput);
          exp.removeWhitespace();

          anyBrackets = exp.anyBrackets();

          if (anyBrackets)
            exp.areBracketsMatching();

      }while(!anyBrackets);


    return 0;
}


