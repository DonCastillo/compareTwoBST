#include <iostream>
#include <stack>
#include <string>
#include "Expression.h"
#include "Menu.h"

int main()
{
    bool loop=true;
    char commandKey;
    std::string stringInput;



    Menu menu;
    menu.displayTitle();
    menu.displayInstructions();

    do{
          menu.displayCommands();
          std::cout << "Enter an expression: ";
          getline(std::cin, stringInput);

          commandKey = menu.getCommandFlag(stringInput);

          if(commandKey == 'h')
            menu.displayInstructions();
          else if (commandKey == 'q')
            loop=false;
          else
          {
              Expression exp(stringInput);
              exp.removeWhitespace();

              if (exp.anyBrackets())
                exp.areBracketsMatching();
          }
      }while(loop);


    return 0;
}


