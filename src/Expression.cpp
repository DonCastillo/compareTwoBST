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
            case '<':
            case '>':
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

