#ifndef PREFIXPARSER_H_INCLUDED
#define PREFIXPARSER_H_INCLUDED

#include <iostream>
#include <string>

class DivideByZeroException { };

using namespace std;

int parseExpression(istream& ins);

#endif // PREFIXPARSER_H_INCLUDED
