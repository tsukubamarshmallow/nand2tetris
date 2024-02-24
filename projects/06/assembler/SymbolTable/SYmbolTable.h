#pragma once

#include <string>
#include <vector>
#include <utility>

class SymbolTable {
public:
    std::vector<std::pair<std::string, int>> table;

    SymbolTable();

    void addEntry(std::string symbol, int address);

    bool contains(std::string symbol);

    std::string getAddress(std::string symbol);
};
