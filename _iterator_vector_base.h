#ifndef ITERATOR_VECTOR_BASE_H
#define ITERATOR_VECTOR_BASE_H
#include <cstddef>

class iterator_vector_base
{
public:
    virtual void first()             = 0;
    virtual void prev()              = 0;
    virtual void next()              = 0;
    virtual void last()              = 0;
    virtual bool isDone() const      = 0;
protected:
    size_t _cur;
};

#endif // ITERATOR_VECTOR_BASE_H
