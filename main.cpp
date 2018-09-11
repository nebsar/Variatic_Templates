/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 10, 2018, 10:34 PM
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
string toString_impl(const T& t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

////////////WE DO NOT HAVE TO WRITE ALL BELOW LINE OF CODES //////////////////
/*vector<string> toString() {
    return {};
}

template <typename P1, typename... Params>
vector<string> toString(const P1& param1, const Params&... params) {
    vector<string> sVector;
    sVector.push_back(toString_impl(param1));

    const auto remainder = toString(params...);
    sVector.insert(sVector.end(), remainder.begin(), remainder.end());
    return sVector;
}*/
//////////////////////////////////////////////////////////////////////////////


////////////////// WE SIMPLY WRITE THE CODE BELOW /////////////////////////////

template <typename... Params>
vector<string> toString(const Params&... params) {
    return {toString_impl(params)...};

}
///////////////////////////////////////////////////////////////////////////////

/////////// AND ALSO WE CAN WRITE A LAMBDA FUNCTION, BUT SLOWER ////////////////

template <typename... Params>
vector<string> tostring(const Params&... params) {

    auto toString_impl = [](const auto& t) {
        stringstream ss;
        ss << t;
        return ss.str();
    };

    return {toString_impl(params)...};

}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {

    auto v = toString(1, "Hello World", 5.67);

    for (auto c : v) {
        cout << c << '\n';
    }

    return 0;
}

