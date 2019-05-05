//
// Created by Varga Attila on 2019. 05. 05..
//

#include "Parser.h"

void Parser::parseGrammar(std::string &inputFileName) {
    std::ifstream inputStream(inputFileName);
    std::string line, tempString, prod;

    getline(inputStream, line);
    startSymbol = line;


    getline(inputStream, line);
    std::istringstream iss(line);
    nonTerminals.clear();
    while (iss >> tempString) {
        nonTerminals.emplace_back(tempString);
    }

    getline(inputStream, line);
    std::istringstream iss2(line);
    terminals.clear();
    while (iss2 >> tempString) {
        terminals.emplace_back(tempString);
    }
    grammar.clear();
    while (getline(inputStream, line)) {
        std::istringstream iss3(line);
        iss3 >> prod;
        while (iss3 >> tempString) {
            grammar[prod].emplace_back(tempString);
        }
    }
    inputStream.close();

}

void Parser::test() {
    std::cout << "STARTSYMBOL" << std::endl << startSymbol << std::endl;

    std::cout << "NONTERMINALS" << std::endl;
    for (const auto &i:nonTerminals) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "TERMINALS" << std::endl;
    for (const auto &i:terminals) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "GRAMMAR" << std::endl;
    for (const auto &map:grammar) {
        std::cout << map.first << " ";
        for (const auto &i:map.second) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "FIRST" << std::endl;
    for (const auto &map:first) {
        std::cout << map.first << " ";
        for (const auto &i:map.second) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }


}

void Parser::findFirsts() {

    for (auto map:grammar) {
        first[map.first] = findFirsHelper(map.second);
    }

    for (auto map:grammar) {
        if (map.second.empty())
            first[map.first] = findFirsHelper2(map.second);
    }

}

std::vector<std::string> Parser::findFirsHelper(std::vector<std::string> vector) {

    std::vector<std::string> tempStringVec;
    std::string temp;


    for (const auto &string :vector) {

        for (char letter :string) {
            std::cout << letter << std::endl;
            temp.push_back(letter);
            std::cout << temp << std::endl;
            if (isTerminal(temp) || temp == EPSILON) {
                tempStringVec.push_back(temp);

            } else {


            }

            temp = "";
        }


    }
    return tempStringVec;
}

bool Parser::isTerminal(std::string rule) {
    return Contains(terminals, rule);
}


const bool Parser::Contains(std::vector<std::string> &Vec, const std::string &Element) {
    return std::find(Vec.begin(), Vec.end(), Element) != Vec.end();
}

std::vector<std::string> Parser::getAlternatives(std::string a) {
    return grammar[a];
}

std::vector<std::string> Parser::findFirsHelper2(
        std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>> vector) {

    std::vector<std::string> tempStringVec,resultVec;
    std::string temp;

    for (const auto &string :vector) {

        for (char letter :string) {
            std::cout << letter << std::endl;
            temp.push_back(letter);
            std::cout << temp << std::endl;
            tempStringVec = first[temp];
            if(!isTerminal(temp)){
                
            }

        }

        temp = "";
    }


    return tempStringVec;
}
