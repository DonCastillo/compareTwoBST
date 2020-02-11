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
        void removeWhitespace();
        void print();
        bool areBracketsMatching();
        void compareTop(char c);
        bool anyBrackets();

    protected:

    private:
        std::string expression;
        std::stack<char> brackets;
};

#endif // EXPRESSION_H
