#ifndef ERROR_H
#define ERROR_H
#include <exception>
using namespace std;

class Base_Error : public std::exception
{
public:
    virtual const char* what()
    {
        return "my base exception";
    }
};

class er_Memory : public Base_Error
{
public:
    const char* what()
    {
        return "memory is not allocated";
    }
};

class er_Size : public Base_Error
{
public:
    const char* what()
    {
        return "size is set incorrectly";
    }
};

class er_Index : public Base_Error
{
public:
    const char* what()
    {
        return "incorrectly specified index";
    }
};

class er_Unsigned_type : public Base_Error
{
public:
    const char* what()
    {
        return "work this unsigned type";
    }
};

class er_Zero : public Base_Error
{
public:
    const char* what()
    {
        return "devided by zero";
    }
};
#endif // ERROR_H
