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
const char *Data::getName()
{
    return description.name;
}
// TODO: Fix this messy function... 
// Return ch array of id, constant, and name
const char * Data::print()
{
    std::string id = std::to_string(getID());
   // std::string c = std::to_string(getConstant());
   // std::string separator = "-";  // Corrected the spelling of "separator"
  //  std::string name(getName());
  //  size_t totLen = id.length() + c.length() + name.length();
  //  char *result = new char[totLen + 1];

   // strcpy(result, id.c_str());
   // strcat(result, separator.c_str());
   // strcat(result, c.c_str());
   // strcat(result, separator.c_str());
   // strcat(result, name.c_str());

    return id.c_str(); 
}
