#include "iterator_random.h"

template <typename type_t>
iterator_vector<type_t>::iterator_vector(const Vector<type_t> &vec)
{
    this->vec = vec;
}

template <typename type_t>
iterator_vector::iterator_vector(const iterator_vector &it)
{
    this->vec = it.vec;
    this->_cur = it._cur;
}

template <typename type_t>
iterator_vector::~iterator_vector()
{
    this->vec = NULL;
    this->_cur = 0;
}

template <typename type_t>
size_t iterator_vector::cur()
{
    return this->_cur;
}

template <typename type_t>
typename iterator_vector& iterator_vector::operator =  (iterator_vector&& it)
{
    this->_cur = it._cur;
    this->vec = it.vec;
    it._NULL_vec();
    return *this;
}
template <typename type_t>
typename iterator_vector &iterator_vector::operator =(const iterator_vector &it)
{
    this->vec = it.vec;
    this->_cur = it._cur;

    return (*this);
}

template <typename type_t>
typename iterator_vector &iterator_vector::operator ++()
{
    if(this->isDone())
        throw er_iteration();

    this->next();
    return *this;
}

template <typename type_t>
typename iterator_vector iterator_vector::operator ++(type_t)
{
    iterator_vector copy(*this);
    ++(*this);
    return copy;
}

template <typename type_t>
typename iterator_vector &iterator_vector::operator --()
{
    if(this->isDone())
        throw er_iteration();

    this->prev();
    return *this;
}

template <typename type_t>
typename iterator_vector iterator_vector::operator --(type_t)
{
    iterator_vector copy(*this);
    --(*this);
    return copy;
}

template <typename type_t>
const type_t& iterator_vector::operator*()
{
    return this->value();
}

template <typename type_t>
typename iterator_vector &iterator_vector::operator +=(ssize_t n)
{
    if(n>=0)
    {
        if((n + this->_cur) > this->vec->size() - 1)
            throw er_iteration();
        while(n--)
            ++(*this);

    }
    else
    {
        if( this->vec->size() - 1 + n < 0)
            throw er_iteration();
        while(n++)
            --(*this);
    }
    return *this;
}

template <typename type_t>
typename iterator_vector &iterator_vector::operator -=(ssize_t n)
{
    return (*this) += -n;
}

template <typename type_t>
const type_t &iterator_vector::operator [](ssize_t n) const
{
    if(n < 0 || n >= this->vec->size() )
        throw er_iteration();
    return const_cast<const type_t&>(this->vec->get_data((size_t)n));
}

template <typename type_t>
bool iterator_vector::operator !=(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur >= it._cur;
}

template <typename type_t>
bool iterator_vector::operator ==(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur == it._cur;
}

template <typename type_t>
bool iterator_vector::operator <(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur < it._cur;
}

template <typename type_t>
bool iterator_vector::operator >(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur > it._cur;
}

template <typename type_t>
bool iterator_vector::operator <=(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur <= it._cur;
}

template <typename type_t>
bool iterator_vector::operator >=(const iterator_vector &it) const
{
    if(this->vec != it.vec)
        throw er_Compare_iter();
    return this->_cur >= it._cur;
}


template <typename type_t>
void iterator_vector::first()
{
    this->_cur = 0;
}

template <typename type_t>
void iterator_vector::prev()
{
    this->_cur--;
}

template <typename type_t>
void iterator_vector::next()
{
    this->_cur++;
}

template <typename type_t>
void iterator_vector::last()
{
    this->_cur = this->vec->size()-1;
}

template <typename type_t>
bool iterator_vector::isDone() const
{
    return this->_cur >= this->vec->size() || this->_cur == SIZE_MAX;
}

template <typename type_t>
const type_t &iterator_vector::value() const
{
    if(this->isDone())
        throw er_iteration();
    return this->vec->data[this->_cur];
}

template <typename type_t>
void iterator_vector::_NULL_vec()
{
    this->vec = NULL;
}

