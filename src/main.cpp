#include "../include/Structures/Data.h"
#include "../include/Structures/DoublyLinkedList.h"
#include "../include/Common/MusicPlayer.h"

// basic utils
#include <iostream>
// tests

// Common
#include "Common/RPN.cpp"

/*
MAIN.CPP File for entire project.

Run project:
$: make all
$ : cd bin/
$: ./main_executable
$ : make clean

*/
void testRPN(){
    std::string userEquation = "";
    std::cout << "Enter Reverse Polish Notation you want evaluated:";
    getline(std::cin, userEquation);
    RPN eq(userEquation);
    std::cout << "\nInitialized Equation.\nResult is: " << eq.getResult() << " " << std::endl;

}

void testDLL(){
     int amt_items = 1e3;
    DoublyLinkedList<int> list;
    for (int i = 0; i < amt_items; i++)
    {
        Node<int> * nd = new Node<int>(i*5);
        list.add(nd);
    }
    int len = list.size();
    printf("size():%d Actual:%d\n",len,amt_items);
}

void testMusic(){
    MusicPlayer m;
    Song s = {"h","bob","--MAGICALBOB--",489};
    Song b = {"jilly","indigo","Fun Jilly Land Art **:)**",302};
    std::string hors_ac = R"(              .     :     .
            .  :    |    :  .
             .  |   |   |  ,
              \  |     |  /
          .     ,-'"""`-.     .
            "- /  __ __  \ -"
              |==|  I  |==|
        - --- | _`--^--'_ | --- -
              |'`.     ,'`|
            _- \  "---"  / -_
          .     `-.___,-'     .
              /  |     |  \
            .'  |   |   |  `.
               :    |    :
              .     :     .)";

    Song q = {"House of the Rising Sun","The Animals",hors_ac,269};
    m.addSong(s); m.addSong(b); m.addSong(q);
    m.display();
}
int main() {

    std::cout << "BEGIN MAIN()" << std::endl;
    
    // test RPN
   // testRPN();

    // test DLL
   // testDLL();

   //test music
   testMusic();
   
    std::cout << "END MAIN()" << std::endl;
    return 0;
}
