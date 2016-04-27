#include "Geometric_vector.h"
#include <cstdarg>

template <typename type_t>
Vector<type_t>::Vector()
{
    this->pr_size = 1;
    this->data = new type_t[this->pr_size]();
    if (!this->data)
        throw er_Memory();
}

template <typename type_t>
Vector<type_t>::Vector(const Vector<type_t> &other)
{
    this->pr_size = other.pr_size;
    this->data = new type_t[this->pr_size];
    if (!this->data)
        throw er_Memory();
    for (size_t i = 0; i < this->pr_size; ++i)
        this->data[i] = other.data[i];
}

template <typename type_t>
Vector<type_t>::Vector(size_t size)
{
    if (!size)
        throw er_Size();

    this->pr_size = size;
    this->data = new type_t[size]();
}

template <typename type_t>
Vector<type_t>::Vector(size_t size, type_t first,...)
{
    if (!size)
        throw er_Size();

    this->pr_size = size;
    va_list arg;
    va_start(arg,first);
    this->data = new type_t[size]();
    if (!data)
        throw er_Memory();

    this->data[0] = first;
    for (size_t i = 1; i<size; ++i)
        this->data[i] = va_arg(arg, type_t);
    va_end(arg);
}

template <typename type_t>
Vector<type_t>::Vector(size_t size, type_t *data)
{
    if (!size)
        throw er_Size();

    this->pr_size = size;
    this->data = new type_t[size]();
    if (!data)
        throw er_Memory();

    for(size_t i = 0; i<size; ++i)
        this->data[i] = data[i];
}
template <typename type_t>
Vector<type_t>::Vector(Vector<type_t> &&vec)
{
    this->pr_size = vec.pr_size;
    this->data = vec.data;
}

template <typename type_t>
Vector<type_t>::~Vector()
{
    _delete_data();
}

template <typename type_t>
size_t Vector<type_t>::size() const
{
    return this->pr_size;
}

template <typename type_t>
const type_t &Vector<type_t>::get_data(size_t &i) const
{
    if (i>= this->pr_size)
        throw er_Index();

    else if(i>this->pr_size)
        return 0;
    return this->data[i];
}

template <typename type_t>
void Vector<type_t>::set_data(const size_t& i,const type_t& value)
{
    if (i>= this->pr_size)
        throw er_Index();

    this->data[i] = value;
}

template <typename type_t>
Vector<type_t> Vector<type_t>::get_min(const Vector &v1, const Vector &v2)
{
    return (v1.pr_size<v2.pr_size) ? (v1):(v2);
}

template <typename type_t>
void Vector<type_t>::resize_vector(size_t new_size)
{
    if(new_size == this->pr_size)
        return;
    if(!new_size)
        throw er_Size();

    type_t* new_data = new type_t[new_size]();
    if(!new_data)
        throw er_Memory();

    for(size_t i = 0; i< this->pr_size; ++i)
        new_data[i] = this->data[i];
    _delete_data();
    this->data = new_data;
    this->pr_size = new_size;
}
\
template <typename type_t>
const size_t Vector<type_t>::to_same_size(Vector<type_t> &vec1, Vector<type_t> &vec2)
{
    if(vec1.size()<vec2.size())
        vec1.resize_vector(vec2.size());
    else if(vec2.size()<vec1.size())
        vec2.resize_vector(vec1.size());
    return vec1.size();
}

template <typename type_t>
const type_t Vector<type_t>::length() const
{
    type_t res = 0;
    for(size_t i = 0; i<this->pr_size;++i)
        res += this->data[i]*this->data[i];
    return (type_t) sqrtl(res);
}

template <typename type_t>
const type_t& Vector<type_t>::operator[](const size_t& i) const
{
    if(i >= this->pr_size)
        throw er_Size();
    return this->data[i];
}

template <typename type_t>
type_t &Vector<type_t>::operator[](const size_t& i)
{
    if(i >= this->pr_size)
        throw er_Size();
    return this->data[i];
}

template <typename type_t>
Vector<type_t> &Vector<type_t>::operator =(const Vector<type_t> &vec)
{
    this->pr_size = vec.pr_size;
    _delete_data();
    this->data = new type_t[this->pr_size];
    if(!this->data)
        throw er_Memory();
    for(size_t i = 0; i<this->pr_size; ++i)
        this->data[i] = vec.data[i];
    return *this;
}

template <typename type_t>
Vector<type_t>& Vector<type_t>::operator =(Vector<type_t>&& vec)
{
    this->data = vec.data;
    this->pr_size = vec.pr_size;
    vec.data = 0;
    return *this;
}

template <typename type_t>
bool Vector<type_t>::operator==(const Vector<type_t> &vec) const
{
    Vector<type_t> max = get_max(*this,vec);
    Vector<type_t> min = get_min(*this,vec);

    size_t i = 0;
    bool er = true;
    for(; i<min.pr_size && er == true; ++i)
        if(this->data[i] != vec.data[i])
            er = false;
    for(; i<max.pr_size && er == true; ++i)
        if(vec.data[i] != 0)
            er = false;
    return er;
}

template <typename type_t>
Vector<type_t> Vector<type_t>::operator+() const{ return *this; }

template <typename type_t>
Vector<type_t> Vector<type_t>::operator+(const Vector<type_t> &vec) const
{
    Vector<type_t> res(*this);
    Vector<type_t> copy(vec);
    to_same_size(res,copy);
    for(size_t i = 0; i<res.pr_size; ++i)
        res.data[i] += copy.data[i];
    return res;
}

template <typename type_t>
Vector<type_t> &Vector<type_t>::operator +=(const Vector<type_t> &vec)
{
    if(this->pr_size < vec.pr_size)
    {
        this->resize_vector(vec.pr_size);
        for(size_t i = 0; i<this->pr_size; ++i)
            this->data[i] += vec.data[i];
        return *this;
    }
    else
    {
        for(size_t i = 0; i<vec.pr_size; ++i)
            this->data[i] += vec.data[i];
        return *this;
    }
}

template <typename type_t>
Vector<type_t> Vector<type_t>::operator -(const Vector<type_t> &vec) const
{
    Vector<type_t> res(*this);
    Vector<type_t> copy(vec);
    to_same_size(res,copy);
    for(size_t i = 0; i<res.pr_size; ++i)
        res.data[i] -= vec.data[i];
    return res;
}

template <typename type_t>
Vector<type_t> Vector<type_t>::operator -() const
{
    Vector<type_t> res(*this);
    return res*(-1);
}

template<typename type_t>
Vector<type_t> &Vector<type_t>::operator -=(const Vector<type_t> &vec)
{
    if(this->pr_size < vec.pr_size)
    {
        this->resize_vector(vec.pr_size);
        for(size_t i = 0; i<this->pr_size; ++i)
            this->data[i] -= vec.data[i];
    }
    else
    {
        for(size_t i = 0; i<vec.pr_size; ++i)
            this->data[i] -= vec.data[i];
    }
    return *this;
}

template<typename type_t>
Vector<type_t> Vector<type_t>::operator*(const type_t& value) const
{
    Vector<type_t> res(*this);
    for(size_t i = 0; i<res.pr_size; ++i)
        res.data[i] *= value;
    return res;
}

template<typename type_t>
const type_t Vector<type_t>::operator*(const Vector<type_t> &vec)
{
    Vector<type_t> copy(vec);
    to_same_size(*this,copy);
    type_t res = 0;
    for(size_t i = 0; i<this->pr_size; ++i)
        res += this->data[i]*vec.data[i];
    return res;
}

template<typename type_t>
Vector<type_t> Vector<type_t>::operator^(const Vector<type_t> &vec) const
{
    Vector<type_t> copy(vec);
    to_same_size(*this,copy);
    if(this->size() != 3)
    {
        er_Size er;
        throw er;
    }
    Vector<type_t> res(3,(this->data[1]*copy.data[2] - this->data[2]*copy.data[1]),
                         (this->data[0]*copy.data[2] - this->data[2]*copy.data[0]),
                         (this->data[0]*copy.data[1] - this->data[1]*copy.data[0]));
    return res;
}

template <typename type_t>
Vector<type_t> &Vector<type_t>::operator*=(const type_t value)
{
    for(size_t i = 0; i<this->pr_size; ++i)
        this->data[i] *= value;
    return *this;
}

template<typename type_t>
Vector<type_t> Vector<type_t>::operator/(const type_t& value) const
{
    Vector<type_t> res(*this);
    for(size_t i = 0; i<res.pr_size; ++i)
        res.data[i] /= value;
    return res;
}

template <typename type_t>
Vector<type_t> &Vector<type_t>::operator/=(const type_t value)
{
    for(size_t i = 0; i<this->pr_size; ++i)
        this->data[i] /= value;
    return *this;
}

template <typename type_t>
bool Vector<type_t>::operator<(const Vector<type_t> &vec) const
{
    return this->length()<vec.length();
}

template <typename type_t>
bool Vector<type_t>::operator>(const Vector<type_t> &vec) const
{
    return this->length()>vec.length();
}

template <typename type_t>
bool Vector<type_t>::operator>=(const Vector<type_t> &vec) const
{
    return this->length()>=vec.length();
}

template <typename type_t>
bool Vector<type_t>::operator!=(const Vector<type_t> &vec) const
{
    return !(this==vec);
}

template <typename type_t>
bool Vector<type_t>::operator<=(const Vector<type_t> &vec) const
{
    return this->length()<=vec.length();
}

template <typename type_t>
void Vector<type_t>::_delete_data()
{
    if (this->data)
        delete [] this->data;
}

template <typename type_t>
bool Vector<type_t>::_check_type_t()
{
    type_t ch = 0;
    ch -= 1;
    if(ch < 0)
        return true;
    else
        return false;
}

template <typename type_t>
Vector<type_t> Vector<type_t>::get_max(const Vector<type_t> &v1, const Vector<type_t> &v2)
{
    return (v1.pr_size >= v2.pr_size) ? (v1):(v2);
}
