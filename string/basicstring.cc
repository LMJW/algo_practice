
#include <cstring>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
// string split
// common way of doing this

// 1. using c library `strtok` method
//
// you need to import `cstring`
// this can split multiple deliminters

void c_str_split(string& s, vector<string>& r) {
    char str[s.size() + 1];
    strcpy(str, s.c_str());
    char* cc;
    cc = strtok(str, ",");
    while (cc != NULL) {
        r.push_back(string(cc));
        cc = strtok(NULL, ",");
    }
}

// 2. using c++ standard library
// getline function, need to import library `sstream`
// only can split the single deliminator case
void split(string& s, char deli, vector<string>& r) {
    std::stringstream ss(s);
    string token;
    while (getline(ss, token, deli)) {
        r.push_back(token);
    }
}

// 3. using the regular expression
// need to import regex
// very similar to the first approach

// reg = "[,]+" for space(\s) or comma(,)
void reg_split(string& s, string reg, vector<string>& r) {
    std::regex re(reg);
    std::sregex_token_iterator it(s.begin(), s.end(), re, -1);
    std::sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
        r.push_back(it->str());
    }
}

int main() {
    string s = "1A 3b,2b 3a,3b 4c,5d 6h";
    vector<string> want;
    c_str_split(s, want);
    for (auto e : want) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

    want.resize(0);
    split(s, ',', want);
    for (auto e : want) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

    want.resize(0);
    reg_split(s, "[,]+", want);
    for (auto e : want) {
        std::cout << e << std::endl;
    }
}