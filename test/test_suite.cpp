#include "Common/lexTest.h"
#include "Common/musTest.h"

#include "Structures/dataTest.h"
#include "Structures/dllTest.h"
#include "Structures/llTest.h"
#include "Structures/qTest.h"
#include "Structures/btTest.h"

void test_Lex() {
    LexTest::test();
}

void test_Mus() {
    MusTest::test();
}

void test_Data() {
    DataTest::test();
}
void test_DLL() {
    DLLTest::test();
}

void test_LL() {
    LLTest::test();
}


void test_Q() {
    QTest::test();
}

void test_BT() {
    BTTest::test();
}

void full_suite() {
    test_Lex();
    test_Mus();
    test_Data();
    test_DLL();
    test_LL();
    test_Q();
}
