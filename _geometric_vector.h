#include <cmath>
#include <ostream>
#include "_error.h"
#include <cstddef>

template <typename type_t>class iterator_vector;
#include "_base_g_vector.h"
#include "_error.h"

template <typename type_t>
class Vector : public Base_Vector
{
public:
    Vector ();
    Vector (size_t size);
    Vector (size_t size,type_t first,...);
    Vector (size_t size, type_t* data);
    Vector (const Vector<type_t>& other);
    Vector (Vector<type_t>&& vec);
    ~Vector ();

    Vector<type_t>& operator=  (const Vector<type_t>& vec);
    Vector<type_t>& operator=  (Vector<type_t> &&vec);

    size_t size() const;
    const type_t& get_data(size_t& i) const;
    void set_data(const size_t& i,const type_t& value);

    void resize_vector(size_t new_size);
    static const size_t  to_same_size(Vector<type_t> &vec1, Vector<type_t> &vec2);
    const type_t length() const;

    const type_t&   operator[] (const size_t& i) const;
    type_t&         operator[] (const size_t& i);

    bool            operator== (const Vector<type_t>& vec) const;
    Vector<type_t>  operator+  () const;
    Vector<type_t>  operator+  (const Vector<type_t>& vec) const;
    Vector<type_t>& operator+= (const Vector<type_t>& vec);
    Vector<type_t>  operator-  () const;
    Vector<type_t>  operator-  (const Vector<type_t>& vec) const;
    Vector<type_t>& operator-= (const Vector<type_t>& vec);

    Vector<type_t>  operator*  (const type_t& value) const;
    const type_t    operator*  (const Vector<type_t>& vec);  //скалярное произвдение
    Vector<type_t>  operator^  (const Vector<type_t>& vec) const;  //векторное произвдение (только для размерности 3)
    Vector<type_t>& operator*= (const type_t value);
    Vector<type_t>  operator/  (const type_t& value) const;
    Vector<type_t>& operator/= (const type_t value);

    bool            operator<  (const Vector<type_t>& vec) const;
    bool            operator<= (const Vector<type_t>& vec) const;
    bool            operator>  (const Vector<type_t>& vec) const;
    bool            operator>= (const Vector<type_t>& vec) const;
    bool            operator!= (const Vector<type_t>& vec) const;


    friend class iterator_vector<type_t>;
    template <typename t1>
    friend Vector<t1> operator*(const t1 &value,const Vector<t1> &vec);

private:
    type_t* data;
    void _delete_data();
    bool _check_type_t();
    Vector<type_t> get_max(const Vector &v1,const Vector &v2);
    Vector<type_t> get_min(const Vector &v1,const Vector &v2);
};

template<typename type_t>
Vector<type_t> operator*(const type_t &value,const Vector<type_t> &vec)
{
    return vec*value;
}

template<typename type_t>
std::ostream& operator<<(std::ostream& stream, const Vector<type_t>& vec)
{
    stream <<"( ";
    size_t i = 0;
    for(; i<vec.size()-1; ++i)
        stream << vec[i] << ", ";
    stream << vec[i] << " )";
    return stream;
}

#include "_Geometric_vector.cpp"
