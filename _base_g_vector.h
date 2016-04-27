#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H
#include <cstddef>

class Base_Vector
{
public:
    virtual size_t size() const = 0;
protected:
    size_t pr_size;
};

#endif // BASE_VECTOR_H
