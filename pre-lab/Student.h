#ifndef STUDENT
#define STUDENT

#include <string>

class Student {
    public:
        Student();
        void setData(std::string nameValue, int idValue);
        std::string getName();
        int getId() const;
        void print() const;
    private:
        std::string name;
        int id;
};

#endif