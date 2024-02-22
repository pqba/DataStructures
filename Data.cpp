#include "Data.h"
#include <string>
#include <cstring>
#include <cstdlib>

Data::Data() : description{0,0,""}
{

}
Data::Data(int id, float c, std::string n) : description{ id, c, n } {
    
}
Data::~Data(){
    description.constant = 0;
    description.ID_NUMBER = 0;
    description.name = "";
}
bool Data::operator==(const Data& other){
    return this->description.constant == other.description.constant &&
    this->description.ID_NUMBER == other.description.ID_NUMBER &&
    this->description.name == other.description.name;
}

// Access entire relevant struct
internal Data::getData()
{
    return description;
}

// Access members of struct
int Data::getID()
{
    return description.ID_NUMBER;
}
float Data::getConstant()
{
    return description.constant;
}
std::string Data::getName()
{
    std::string res(description.name);
    return res;
}
// Return ch array of id, constant, and name
const std::string Data::print() 
{
    std::string idStr = std::to_string(getID()) + "-";
    std::string constantStr = std::to_string(getConstant()) + "-";
    std::string nameStr(getName());

    return idStr + constantStr + nameStr;
}
