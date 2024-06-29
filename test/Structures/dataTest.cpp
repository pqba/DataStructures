#include "../../include/Structures/Data.h"
#include <iostream>

namespace testData {
    void testD(){
        Data make = Data();
        make.setName("hello");
        if(make.getName() != "hello"){
            std::cout << "Failed changing name. " << "\n";
        }
        float expect = 8.8f;
        make.setConstant(expect);
        if(abs(make.getConstant()-expect) > make.TOLERANCE){
            std::cout << "Failed changing float" << "\n";
        }
        make.setID(2);
        if(make.getID() != 2){
            std::cout << "Failed changing integer" << "\n";
        } 
        for(int i = 0; i < 10; i++){
            Data less = Data(i, 1.5, "z");
            Data more = Data(i+1, 0.5, "a");
            if(less > more){
                std::cout << "Incorrect < operator for integers." << "\n";
            }
            less.setID(more.getID());
            more.setConstant(3.0);
            less.setConstant(1.0);
            if(less > more || more < less) {
                std::cout << "Incorrect < operator for floats." << "\n";
            }
            less.setConstant(more.getConstant());
            more.setName("Z");
            less.setName("A");
            if(less > more || more < less) {
                std::cout << "Incorrect < operator for strings." << "\n";
            }
        }
        Data a = Data();
        Data b = Data();
        if(!(a == b)){
            std::cout << "Incorrect equality operator for same inputs." << "\n";
        }
        a.setID(7);
        b.setID(3);
        if(a == b){
            std::cout << "Incorrect equality operator for different inputs." << "\n";
        }
    }
}