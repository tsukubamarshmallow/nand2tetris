#include <iostream>
#include <fstream>
#include "ParseModule/ParseModule.h"
#include "CodeModule/CodeModule.h"
#include "SymbolTable/SymbolTable.h"
#include "function.h"

int main(int argc, char *argv[]) {
    int rom_integer = 0;

    ParseModule testModule1(argv[1]);

    SymbolTable RAMTable;

    RAMTable.addEntry("SP", 0);
    // ... (initialize RAMTable with other entries)

    SymbolTable ROMTable;

    std::ofstream ofs("test.hack");

    // 1st pass to create symbol table for (Xxx) labels

    do {
        testModule1.trimSpace();
        if (!testModule1.line.empty() && testModule1.line[testModule1.line.length() - 1] != '\n' && !ContainsSubstring(testModule1.line, "//")) {
            if (testModule1.commandType() == "L_COMMAND") {
                std::string result = testModule1.line.erase(0, 1);
                result.erase(result.size() - 1, 1);
                ROMTable.addEntry(result, rom_integer);
            } else {
                rom_integer++;
            }
        }
    } while (std::getline(testModule1.file, testModule1.line));

    printf("toriaezuok");

    // 2nd pass to generate binary code using the symbol table

    int ram_integer = 16;

    ParseModule testModule2(argv[1]);

    do {
        testModule2.trimSpace();
        if (!testModule2.line.empty() && testModule2.line[testModule2.line.length() - 1] != '\n' && !ContainsSubstring(testModule2.line, "//")) {
            if (testModule2.commandType() == "C_COMMAND") {
                std::string result;
                std::string jump = testModule2.jump();
                std::string dest = testModule2.dest();
                std::string comp = testModule2.comp();

                jump = CodeModule::jump(jump);
                dest = CodeModule::dest(dest);
                comp = CodeModule::comp(comp);

                result = "111" + comp + dest + jump;

                ofs << result << std::endl;

            } else if (testModule2.commandType() == "A_COMMAND") {
                std::string content = testModule2.line.erase(0, 1);
                if (isNumber(content)) {
                    int intValue;
                    std::istringstream(content) >> intValue;
                    std::string binary = std::bitset<15>(intValue).to_string();

                    ofs << "0" + binary << std::endl;
                } else {
                    if (RAMTable.contains(content)) {
                        ofs << RAMTable.getAddress(content) << std::endl;
                    } else if (ROMTable.contains(content)) {
                        ofs << ROMTable.getAddress(content) << std::endl;
                    } else {
                        RAMTable.addEntry(content, ram_integer);
                        std::string binary = std::bitset<15>(ram_integer).to_string();
                        ofs << "0" + binary << std::endl;
                        ram_integer++;
                    }
                }
            }
        }
    } while (std::getline(testModule2.file, testModule2.line));

    return 0;
}