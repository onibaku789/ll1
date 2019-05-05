//
// Created by Varga Attila on 2019. 05. 05..
//

#ifndef LL0_PARSER_H
#define LL0_PARSER_H

#include <utility>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>

class Parser {
public:
    std::string EPSILON = "!";
    std::string DOLLAR = "$";
    std::string inputStream;
    std::string startSymbol;
    std::vector<std::string> nonTerminals;
    std::vector<std::string> terminals;
    std::map<std::string, std::vector<std::string>> grammar;
    std::map<std::string, std::vector<std::string> >first;
    std::vector<std::string> follow;

    bool isTerminal( std::string rule);

    void test();

    void parseGrammar(std::string &inputFileName) ;

    void findFirsts();

    std::vector<std::string > findFirsHelper(std::vector<std::string> vector);

    const bool Contains(std::vector<std::string> &Vec, const std::string &Element);

    std::vector<std::string> getAlternatives (std::string a);

    std::vector<std::string> findFirsHelper2(
            std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>> vector);
};


#endif //LL0_PARSER_H
