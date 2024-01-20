#include "Data.h"
#include <string>
#include <cstring>

Data::Data()
{
    setData();
}
Data::Data(unsigned int i, float f, const char *N)
{
    setData(i, f, N);
}
Data::~Data(){
    
}

void Data::setData()
{
    description.ID_NUMBER = 0;
    description.constant = 0;
    description.name = "";
}

void Data::setData(unsigned int i, float f, const char *N)
{
    description.ID_NUMBER = i;
    description.constant = f;
    description.name = N;
}
// Access entire relevant struct
internal Data::getData()
{
    return description;
}

// Access members of struct
unsigned int Data::getID()
{
    return description.ID_NUMBER;
}
float Data::getConstant()
{
    return description.constant;
}
const char * Data::getName()
{
    return description.name + '\0';
}

// Return ch array of id, constant, and name
const char * Data::print()
{
    std::string id = std::to_string(getID());
    std::string c = std::to_string(getConstant());
    std::string name = getName();
    
    std::string result = id + "-" + c + "-" + name;

    // Convert the std::string to a C-style string (const char*)
    return result.c_str();
}
