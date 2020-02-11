#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

class Menu
{
  public:
    Menu();
    virtual ~Menu();
    void displayTitle();
    void displayInstructions();
    void displayCommands();
    char getCommandFlag(std::string stringInput);

  protected:

  private:
    const int WIDTH = 37;
    const std::string TITLE = "BRACKET CHECKER";
    const std::string AUTHOR = "Don Castillo";
};

#endif // MENU_H
