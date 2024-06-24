// basic utils
#include <iostream>
// tests
#include "../test/Structures/qTest.cpp"
#include "../test/Structures/llTest.cpp"
#include "../test/Structures/dllTest.cpp"
#include "../test/Common/mTest.cpp"

// Common
#include "Common/RPN.cpp" //technically bad practice.
#include "../include/Common/MusicPlayer.h"
#include "../include/Common/Event.h"
#include "../include/Common/EventHandler.h"

// Structures
#include "../include/Structures/Queue.h"
#include "../include/Structures/Data.h"
#include "../include/Structures/DoublyLinkedList.h"
#include "../include/Structures/LinkedList.h"
#include "../include/Structures/BinTree.h"

void play_RPN(){
    std::string userEquation = "";
    std::cout << "Enter Reverse Polish Notation you want evaluated: ";
    getline(std::cin, userEquation);
    RPN eq(userEquation);
    std::cout << "Initialized Equation.\nResult is: " << eq.getResult() << "\n";
    std::cout << "Algebraic: " << eq.describeAlgebraic(userEquation) <<  " = " << eq.getResult() << "\n";
}

void test_DLL(){
    TestDLL::testDLL();
}

void test_LL(){
    TestLL::testLL();
}
void test_Music(){
    testM::testM();
}

void test_Q(){
    TestQ::testQ();
}

void test_EventHandler(){
    EH::runEventHandle();
}

int main() {
    std::cout << "BEGIN MAIN()" << std::endl;

    BinTree<Data> bt;
    bt.insert(Data(5,1,"bruh"));
    bt.insert(Data(6,7,"fjsdfhlsdkfjh"));
    bt.insert(Data(1,0,"e"));
    std::cout << bt.inOrder() <<"\n";
    std::cout << bt.size() << "\n";

    std::cout << "END MAIN()" << std::endl;
    return 0;
}
