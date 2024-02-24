#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <vector>
#include <utility>

// = の前までの文字列を取得
std::string extractLeftOfString(const std::string& input, const std::string& delimiter) {

    size_t pos = input.find(delimiter);

    if (pos != std::string::npos) {
        return input.substr(0, pos);
    } else {
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
// ストリング型が数のみから構成されているか判断する関数
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