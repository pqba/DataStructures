// basic utils
#include <iostream>
#include <random>
// tests
#include "../test/test_suite.cpp"

// Common
#include "../include/Common/Event.h"
#include "../include/Common/EventHandler.h"
#include "../include/Common/Lexicon.h"
#include "../include/Common/MusicPlayer.h"
#include "Common/RPN.cpp"



void play_RPN() {
    std::string userEquation = "";
    std::cout << "Enter Reverse Polish Notation you want evaluated: ";
    getline(std::cin, userEquation);
    RPN eq(userEquation);
    std::cout << "Initialized Equation.\nResult is: " << eq.getResult() << "\n";
    std::cout << "Algebraic: " << eq.describeAlgebraic(userEquation) << " = " << eq.getResult() << "\n";
}

void test_EventHandler() {
    EH::runEventHandle();
}

int main() {
    std::cout << "BEGIN MAIN()" << std::endl;

    test_Lex();

    std::cout << "END MAIN()" << std::endl;

    return 0;
}
