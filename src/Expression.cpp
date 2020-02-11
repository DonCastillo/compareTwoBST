#include "Expression.h"
#include <string>

Expression::Expression(std::string e)
{
    expression = e;
    //ctor
}

Expression::~Expression()
{
    //dtor
}



// segregrate brackets and non brackets
// and put them to their stacks
bool Expression::anyBrackets()
{
    for(char c : expression)
    {
       switch(c)
       {
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
                return true;
            default:
                break;
       }
    }
    std::cout << "No brackets in the expression\n\n";
    return false;
}





void Expression::compareTop(char c)
{
  char openingBracket;
  switch(c)
  {
      // get corresponding opening bracket if c is closing bracket
      case ')':
        openingBracket = '(';
        break;
      case ']':
        openingBracket = '[';
        break;
      case '}':
        openingBracket = '{';
        break;
      // return if c is a opening bracket
      default:
        brackets.push(c);
        return;
  }
  // compare top stack to the opening bracket
  if(brackets.top() == openingBracket)
    brackets.pop();
  else
    brackets.push(c);
  return;
}






bool Expression::areBracketsMatching()
{
  // check if the brackets are properly matched
  for(char c : expression)
  {
     switch(c)
     {
          case '(':
          case ')':
          case '[':
          case ']':
          case '{':
          case '}':
              if(brackets.empty())
                brackets.push(c);
              else
                compareTop(c);
              break;
          default:
              break;
     }
  }

  // if brackets is empty, then all brackets are matching
  if(brackets.empty())
  {
    std::cout << "Brackets are properly nested.\n\n";
    return true;
  }
  else
  {
    std::cout << "Brackets are NOT properly nested.\n\n";
    return false;
  }

}







// segregrate brackets and non brackets
// and put them to their stacks
void Expression::segChars()
{
    for(char c : expression)
    {
       switch(c)
       {
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
                brackets.push(c);
                break;
            default:
                nonBrackets.push(c);
                break;
       }
    }
}




// remove whitespaces
void Expression::removeWhitespace()
{
    std::string sanitzedString;
    for(char c : expression)
    {
        if( c != ' ')
            sanitzedString += c;
    }
    expression = sanitzedString;
    return;
}


// print original expression
void Expression::print()
{
    std::cout << expression << std::endl;
}



// print bracket characters
void Expression::printBrackets()
{
    std::stack<char>copyBrackets = brackets;
    while(!copyBrackets.empty())
    {
        char c = copyBrackets.top();
        copyBrackets.pop();
        std::cout << c << std::endl;
    }
}


// print non bracket characters
void Expression::printNonBrackets()
{
    std::stack<char>copyNonBrackets = nonBrackets;
    while(!copyNonBrackets.empty())
    {
        char c = copyNonBrackets.top();
        copyNonBrackets.pop();
        std::cout << c << std::endl;
    }
}

