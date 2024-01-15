#ifndef DATA_H
#define DATA_H
/*
Abstract Data header file to be possibly switched out for relevant data. Make a print() function to visualize.
*/

// Struct for basic data
struct internal
{
    unsigned int ID_NUMBER;
    float constant;
    const char *name;
};

// Class for data in structure implementations
class Data
{
public:
    internal description;
    Data();
    Data(unsigned int i, float f, const char *N);
    ~Data();

    void setData();

    void setData(unsigned int i, float f, const char *N);

    internal getData();

    unsigned int getID();

    float getConstant();

    const char *getName();

    const char *print();
};
#endif
