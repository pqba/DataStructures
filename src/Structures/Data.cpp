#include "../../include/Structures/Data.h"
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

// Checks if the constant, id, and name of Data objects are equal.
bool Data::operator==(const Data& other){
    return this->description.constant == other.description.constant &&
    this->description.ID_NUMBER == other.description.ID_NUMBER &&
    this->description.name == other.description.name;
}
// Data objects are larger if int ID is larger, float constant is larger, or name length is longer
bool Data::operator>(const Data& other){
    if(this->description.ID_NUMBER > other.description.ID_NUMBER){
        return true;
    }
    else if(this->description.constant > other.description.constant){
        return true;
    }
    else if(this->description.name.length() > other.description.name.length()){
        return true;
    }
    return false;
}
// Data objects are smaller if int ID is smaller, float constant is smaller, or name length is shorter
bool Data::operator<(const Data& other){
    if(this->operator==(other)){
        return false;
    }
    return !(this->operator>(other));
}
// Access entire relevant struct
internal Data::getData()
{
    return description;
}

// Access ID of Data object.
int Data::getID()
{
    return description.ID_NUMBER;
}
// Access constant of Data object.
float Data::getConstant()
{
    return description.constant;
}
// Access name of Data object.
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
