#include "Menu.h"

Menu::Menu()
{
  //ctor
}

Menu::~Menu()
{
  //dtor
}

char Menu::getCommandFlag(std::string stringInput)
{
  char c;
  if(stringInput.length() > 0)
    c = tolower(stringInput[0]);
  else
    c = '0';

  return c;
}

void Menu::displayTitle()
{
  std::cout << std::setfill('=') << std::setw(WIDTH) << "\n";
  std::cout << TITLE << "\n";
  std::cout << "by: " << AUTHOR << "\n";
  std::cout << std::setfill('=') << std::setw(WIDTH) << "\n";
  return;
}

void Menu::displayInstructions()
{
  std::cout << "\nInstruction:\n";
  std::cout << "This program checks if the bracketing operators\n"
            << "in a mathematical expression is properly nested\n"
            << "Bracketing operators include ( ), { }, [ ].\n"
            << "Example: (a+b) is properly nested\n"
            << "         (a+b  is NOT properly nested\n";
  return;

}


void Menu::displayCommands()
{
  std::cout << "\n\n";
  std::cout << std::setfill('.') << std::setw(WIDTH) << "\n";
  std::cout << "Commands:\n"
            << "Q -- to quit,  H -- for instruction\n";
  std::cout << std::setfill('.') << std::setw(WIDTH) << "\n\n";
  return;

}
