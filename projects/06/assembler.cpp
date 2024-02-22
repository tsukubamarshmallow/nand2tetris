#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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

class ParseModule{
    private:
        std::ifstream file;
        std::string line;

    public:
    //コンストラクタ
    ParseModule(char *filename){
        file.open(filename);
        std::getline(file,line);
    }
    
    int hasMoreCommands(){
        return file.eof();
    }

    void advance(){
        if(!file.eof){
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

    std::string symbol(){
        std::string commandTypeResult = commandType();
        if(commandTypeResult == "C_COMMAnD"){
            commandTypeResult.pop_back();
            commandTypeResult.erase(str.begin());
        }
    }

    std::sring dest(){
        std::string commandTypeResult = commandType();

        if(commandTypeResult == "C_COMMAND"){
            if (containsSubstring(line, ";")) {
                return "null"
            }else{
                // lineの=前まで抽出し全ての空白行を削除する
                std::string result = extractLeftOfString(line, "=");
                result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
                return result;
            }
        }
    }

    std::string comp(){
        std::string commandTypeResult = commandType();

        // lineの=より後ろまで抽出し全ての空白行を削除する
        std::string result = extractLeftOfString(line, "=");
        result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

        if(commandTypeResult == "C_COMMAND"){
            if (containsSubstring(line, ";")) {
                return "null"
            }else{
                return result;
            }
        }
    }

    std::string jump(){
        std::string commandTypeResult = commandType();

        if (containsSubstring(line, "JGT")) {
            return "JGT";
        }else if(containsSubstring(line, "JEQ")){
            return "JEQ";
        }else if(containsSubstring(line, "JGE")){
            return "JGE";
        }else if(containsSubstring(line, "JLT")){
            return "JlT";
        }else if(containsSubstring(line, "JNE")){
            return "JNE";
        }else if(containsSubstring(line, "JLE")){
            return "JLE";
        }else{
            return "null";
        }
    }
}

class CodeModule{
    static std::string dest(std::string nimonic){
        switch(nimonic){
            case "M":
                return "001";
            case "D":
                return "010";
            case "MD":
                return "011";
            case "A":
                return "100"
            case "AM":
                return "101";
            case "AD":
                return "110";
            case "AMD":
                return "111";
            default:
                return "000";
        } 
    } 
}

int main(void){

}