/*
Abstract Data header file to be possibly switched out for relevant data 
*/

// Struct for basic data
struct internal {
    unsigned int ID_NUMBER;
    float constant;
    const char * name;
};

//Class for data in structure implementations
class Data {
    public:
        internal description;
        Data();
        Data(unsigned int i, float f, char * N);

    void setData();

    void setData(unsigned int i, float f, char * N);

    internal getData();

    unsigned int getID();

    float getConstant();

    const char * getName();
};

