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


/**
  @brief  determine if expression has any bracket operator
  @param  none
  @return TRUE if there's a bracket operator, otherwise FALSE
*/

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




/**
  @brief  remove object on top of stack if it is c's match
  @param  char c
  @return none
*/
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



/**
  @brief  push all bracket operators into the stack
  @param  none
  @return TRUE if brackets are properly nested, otherwise FALSE
*/
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



/**
  @brief  removes whitespace characters in the expression
  @param  none
  @return none
*/
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


/**
  @brief  prints the expression
  @param  none
  @return none
*/
void Expression::print()
{
    std::cout << expression << std::endl;
}


