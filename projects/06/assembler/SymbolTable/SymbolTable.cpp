#include "SymbolTable.h"
#include "../function.h"

SymbolTable::SymbolTable() {
    // Constructor implementation if needed
}

void SymbolTable::addEntry(std::string symbol, int address) {
    table.push_back(std::make_pair(symbol, address));
}

bool SymbolTable::contains(std::string symbol) {
    for (auto &[c, n] : table) {
        if (c == symbol) {
            return true;
        }
    }
    return false;
}

std::string SymbolTable::getAddress(std::string symbol) {
    for (auto &[c, n] : table) {
        if (c == symbol) {
            std::string binary = std::bitset<15>(n).to_string();
            return "0" + binary;
        }
    }
    // Handle the case when the symbol is not found (may need to return an appropriate value)
    return "";
}
