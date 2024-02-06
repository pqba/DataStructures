#ifndef DATA_H
#define DATA_H
#include <string>
/*
Abstract Data header file to be possibly switched out for relevant data. Make a print() function to visualize.
*/

// Struct for basic data
struct internal
{
    int ID_NUMBER;
    float constant;
    std::string name;
};

// Class for data in structure implementations
class Data
{
    public:
        internal description;
        Data();
        Data( int i, float f, std::string N);
        ~Data();

        internal getData();

        int getID();

        float getConstant();

        std::string getName();

        const std::string print();
};
#endif
