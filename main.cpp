#include <iostream>
#include "Parser.h"

int main() {
    Parser parser;
    std::string input = "C:\\Users\\Varga Attila\\CLionProjects\\ll0\\input.txt";
    parser.parseGrammar(input);
    parser.findFirsts();
    parser.test();
    return 0;
}