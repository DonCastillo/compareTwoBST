#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <iostream>
#include <stack>
class Expression
{
    public:
        Expression(std::string e);
        virtual ~Expression();
        void segChars();
        void removeWhitespace();
        void print();
        void printBrackets();
        void printNonBrackets();

    protected:

    private:
        std::string expression;
        std::stack<char> brackets;
        std::stack<char> nonBrackets;

};

#endif // EXPRESSION_H
