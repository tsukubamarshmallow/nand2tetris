#pragma once
#include <string>
#include <fstream>

class ParseModule {
public:
    std::ifstream file;
    std::string line;

    ParseModule(char *filename);

    int hasMoreCommands();

    void advance();

    void trimSpace();

    std::string commandType();

    std::string symbol();

    std::string dest();

    std::string comp();

    std::string jump();
};
