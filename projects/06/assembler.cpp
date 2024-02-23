#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <sstream>

// = の前までの文字列を取得
std::string extractLeftOfString(const std::string& input, const std::string& delimiter) {

    size_t pos = input.find(delimiter);

    if (pos != std::string::npos) {
        return input.substr(0, pos);
    } else {
        // delimiterが見つからない場合は、そのままの文字列を返すか、適切な処理を行う
        return input;
    }
}
// = の後ろの文字列を取得
std::string extractRightOfString(const std::string& input, const std::string& delimiter) {

    size_t pos = input.find(delimiter);

    if (pos != std::string::npos) {
        return input.substr(pos + 1);
    } else {
        // delimiterが見つからない場合は、そのままの文字列を返すか、適切な処理を行う
        return input;
    }
}

bool isNumber(const std::string& str) {
  for (char const& c : str) {
    if (std::isdigit(c) == 0) return false;
  }
  return true;
}

//ある文字が文字列中に含まれるか判断
bool ContainsSubstring(const std::string& mainString, const std::string& subString) {
    return mainString.find(subString) != std::string::npos;
}

class ParseModule{
   
    public:
    std::ifstream file;
    std::string line;

    
    ParseModule(char *filename){
        file.open(filename);
        std::getline(file,line);
    }
    
    int hasMoreCommands(){
        return file.eof();
    }

    void advance(){
        if(!file.eof()){
            std::getline(file,line);
        }
    }

    std::string commandType(){
        if(line[0] == '@'){
            return "A_COMMAND";
        }else if(line[0] == '('){
            return "L_COMMAND";
        }else{
            return "C_COMMAND";
        }
    }
    // symbol dest compはそれぞれC_COMMANDの時だけ使用する
    std::string symbol(){

        std::string commandTypeResult = commandType();

        commandTypeResult.pop_back();
        commandTypeResult.erase(commandTypeResult.begin());
        
        return commandTypeResult;
    }

    std::string dest(){
        std::string commandTypeResult = commandType();

        if (ContainsSubstring(line, ";")) {
            return "null";
        }else{
            // lineの=前まで抽出し全ての空白行を削除する
            std::string result = extractLeftOfString(line, "=");
            result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
            return result;
        }
        
    }

    // =前の要素を取得する　1.~;~ 2.~ = ~のケースが存在するので両者に対応する
    std::string comp(){
        std::string commandTypeResult = commandType();

        // lineの=の後ろまで抽出し全ての空白行を削除する
        std::string result = extractRightOfString(line, "=");
        result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

        if (ContainsSubstring(result, ";")) {
            size_t pos = result.find(";");
            if (pos != std::string::npos) {
                return result.substr(0, pos);
            }
        }else{
            return result;
        }
    }

    std::string jump(){
        std::string commandTypeResult = commandType();

        if (ContainsSubstring(line, "JGT")) {
            return "JGT";
        }else if(ContainsSubstring(line, "JEQ")){
            return "JEQ";
        }else if(ContainsSubstring(line, "JGE")){
            return "JGE";
        }else if(ContainsSubstring(line, "JLT")){
            return "JlT";
        }else if(ContainsSubstring(line, "JNE")){
            return "JNE";
        }else if(ContainsSubstring(line, "JLE")){
            return "JLE";
        }else{
            return "null";
        }
    }
};

class CodeModule{
    public:

    static std::string dest(const std::string& mnemonic) {
        if (mnemonic == "M") {
            return "001";
        } else if (mnemonic == "D") {
            return "010";
        } else if (mnemonic == "MD") {
            return "011";
        } else if (mnemonic == "A") {
            return "100";
        } else if (mnemonic == "AM") {
            return "101";
        } else if (mnemonic == "AD") {
            return "110";
        } else if (mnemonic == "AMD") {
            return "111";
        } else {
            printf("Exeption Error Occurd in CodeModule-dest()function!");
            exit(EXIT_FAILURE);
        }
    }

    static std::string comp(const std::string& mnemonic) {
        if (mnemonic == "0") {
            return "0101010";
        } else if (mnemonic == "1") {
            return "0111111";
        } else if (mnemonic == "-1") {
            return "0111010";
        } else if (mnemonic == "D") {
            return "0001100";
        } else if (mnemonic == "A") {
            return "0110000";
        } else if (mnemonic == "!D") {
            return "0001101";
        } else if (mnemonic == "!A") {
            return "0110001";
        } else if (mnemonic == "-D") {
            return "0001111";
        } else if (mnemonic == "-A") {
            return "0110011";
        } else if (mnemonic == "D+1") {
            return "0011111";
        } else if (mnemonic == "A+1") {
            return "0110111";
        } else if (mnemonic == "D-1") {
            return "0001110";
        } else if (mnemonic == "A-1") {
            return "0110010";
        } else if (mnemonic == "D+A") {
            return "0000010";
        } else if (mnemonic == "D-A") {
            return "0010011";
        } else if (mnemonic == "A-D") {
            return "0000111";
        } else if (mnemonic == "D&A") {
            return "0000000";
        } else if (mnemonic == "D|A") {
            return "0010101";
        } else if (mnemonic == "M") {
            return "1110000";
        } else if (mnemonic == "!M") {
            return "1110001";
        } else if (mnemonic == "-M") {
            return "1110011";
        } else if (mnemonic == "M+1") {
            return "1110111";
        } else if (mnemonic == "M-1") {
            return "1110010";
        } else if (mnemonic == "D+M") {
            return "1000010";
        } else if (mnemonic == "D-M") {
            return "1010011";
        } else if (mnemonic == "M-D") {
            return "1000111";
        } else if (mnemonic == "D&M") {
            return "1000000";
        } else if (mnemonic == "D|M") {
            return "1010101";
        } else {
            printf("Exeption Error Occurd in CodeModule-comp()function!");
            exit(EXIT_FAILURE);
        }
    }

    static std::string jump(const std::string& mnemonic) {
        if (mnemonic == "null") {
                return "000";
        } else if (mnemonic == "JGT") {
            return "001";
        } else if (mnemonic == "JEQ") {
            return "010";
        } else if (mnemonic == "JGE") {
            return "011";
        } else if (mnemonic == "JLT") {
            return "100";
        } else if (mnemonic == "JNE") {
            return "101";
        } else if (mnemonic == "JLE") {
            return "110";
        } else if (mnemonic == "JMP") {
            return "111";
        } else {
            printf("Exeption Error Occurd in CodeModule-jump()function!");
            exit(EXIT_FAILURE);
        }  
    }
};

int main(int argc, char *argv[]){
    
    class ParseModule testModule(argv[1]);

    std::ofstream ofs("output.txt");

    do{
        if(testModule.commandType() == "C_COMMAND"){
            //Parse-section
            std::string result;
            std::string jump = testModule.jump();
            std::string dest = testModule.dest();
            std::string comp = testModule.comp();
            //decode-section
            jump = CodeModule::jump(jump);
            dest = CodeModule::dest(dest);
            comp = CodeModule::comp(comp);
            result = "111" + comp + dest + jump;

            ofs << result << std::endl;

        }else if(testModule.commandType() == "A_COMMAND"){
            std::string content = testModule.line.erase(0,1);
            if(isNumber(content)){
                int intValue;
                std::istringstream(content) >> intValue;
                std::string binary = std::bitset<15>(intValue).to_string();
                std::cout << binary << std::endl;
                ofs << "1" + binary << std::endl;
            }else{
                ofs << "@" + content << std::endl;
            }
        }else if(testModule.commandType() == "L_COMMAND"){
            ofs << testModule.line << std::endl;
        }
        std::cout << testModule.commandType() << std::endl;
        std::cout << testModule.line << std::endl;
    }
    while(std::getline(testModule.file,testModule.line));

    return 0;
}