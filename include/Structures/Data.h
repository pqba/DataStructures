#ifndef DATA_H
#define DATA_H
#include <string>
/*
Abstract Data header file. Used to test the basic implementations of data structures. Any relevant storage of integers types, floats, and/or strings can be inputted into this data type.
*/

// Struct for basic data fields: id, constant, and name
struct internal {
    int ID_NUMBER;
    float constant;
    std::string name;
};

// Abstract class for sample data in structure implementations
class Data {
   public:
    internal description;
    double TOLERANCE = 1e-6;
    Data();
    Data(int i, float f, std::string N);
    ~Data();

    bool operator==(const Data&);
    bool operator>(const Data&);
    bool operator<(const Data&);

    internal getData() const;
    int getID() const;
    float getConstant() const;
    std::string getName() const;

    void setData(internal);
    void setID(int);
    void setConstant(float);
    void setName(std::string);

    const std::string print() const;
};

#endif
