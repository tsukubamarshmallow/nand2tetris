#include "ParseModule.h"
#include "../function.h"
#include <algorithm>
#include <sstream>
#include <bitset>

ParseModule::ParseModule(char *filename) {
    file.open(filename);
    std::getline(file, line);
}

int ParseModule::hasMoreCommands() {
    return file.eof();
}

void ParseModule::advance() {
    if (!file.eof()) {
        std::getline(file, line);
    }
}

void ParseModule::trimSpace() {
    int size = line.size();
    int i = 0;
    while (i < size) {
        if (line[0] == ' ') {
            line.erase(0, 1);
        } else {
            break;
        }
    }
}

std::string ParseModule::commandType() {
    if (line[0] == '@') {
        return "A_COMMAND";
    } else if (line[0] == '(') {
        return "L_COMMAND";
    } else {
        return "C_COMMAND";
    }
}

std::string ParseModule::symbol() {
    std::string commandTypeResult = commandType();

    commandTypeResult.pop_back();
    commandTypeResult.erase(commandTypeResult.begin());

    return commandTypeResult;
}

std::string ParseModule::dest() {
    std::string commandTypeResult = commandType();

    if (ContainsSubstring(line, ";")) {
        return "null";
    } else {
        std::string result = extractLeftOfString(line, "=");
        result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
        return result;
    }
}

std::string ParseModule::comp() {
    std::string commandTypeResult = commandType();

    std::string result = extractRightOfString(line, "=");
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

    if (ContainsSubstring(result, ";")) {
        size_t pos = result.find(";");
        if (pos != std::string::npos) {
            return result.substr(0, pos);
        }
    } else {
        return result;
    }
}

std::string ParseModule::jump() {
    std::string commandTypeResult = commandType();

    if (ContainsSubstring(line, "JGT")) {
        return "JGT";
    } else if (ContainsSubstring(line, "JEQ")) {
        return "JEQ";
    } else if (ContainsSubstring(line, "JGE")) {
        return "JGE";
    } else if (ContainsSubstring(line, "JLT")) {
        return "JlT";
    } else if (ContainsSubstring(line, "JNE")) {
        return "JNE";
    } else if (ContainsSubstring(line, "JLE")) {
        return "JLE";
    } else if (ContainsSubstring(line, "JMP")) {
        return "JMP";
    } else {
        return "null";
    }
}
