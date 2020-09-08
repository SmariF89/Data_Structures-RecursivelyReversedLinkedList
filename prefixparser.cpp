#include <iostream>
#include <stdlib.h>
#include "prefixparser.h"

using namespace std;

int parseExpression(istream& ins)
{
    string strInput;
    ins >> strInput;

    int number = 0;

    if(strInput == "+")                                         //RECURSION
    {
        return parseExpression(ins) + parseExpression(ins);
    }
    else if(strInput == "-")
    {
        return parseExpression(ins) - parseExpression(ins);
    }
    else if(strInput == "*")
    {
        return parseExpression(ins) * parseExpression(ins);
    }
    else if(strInput == "/")
    {
        int lhs = parseExpression(ins);
        int rhs = parseExpression(ins);

        if(rhs == 0)
        {
            throw DivideByZeroException();
        }
        else
        {
            return lhs / rhs;
        }
    }
    else
    {
        number = atoi(strInput.c_str());                              //BASE CASE
        return number;
    }

}
