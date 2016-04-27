#include "_iterator_vector_base.h"
#include "_iteration_er.h"
#include "_geometric_vector.h"

template <typename type_t>
class iterator_vector : public iterator_vector_base
{
public:
    iterator_vector(const Vector<type_t>& vec);
    iterator_vector(const iterator_vector<type_t>& it);

    ~iterator_vector();

    size_t cur();

    iterator_vector<type_t>& operator =  (const iterator_vector<type_t>& it);
    iterator_vector<type_t>& operator ++ ();
    iterator_vector<type_t>  operator ++ (type_t);
    iterator_vector<type_t>& operator -- ();
    iterator_vector<type_t>  operator -- (type_t);
    const type_t&            operator *  ();
    iterator_vector<type_t>& operator += (const ssize_t n);
    iterator_vector<type_t>& operator -= (const ssize_t n);
    const type_t&            operator [] (const ssize_t n);

    bool operator != (const iterator_vector<type_t>& it);
    bool operator == (const iterator_vector<type_t>& it);
    bool operator <  (const iterator_vector<type_t>& it);
    bool operator >  (const iterator_vector<type_t>& it);
    bool operator <= (const iterator_vector<type_t>& it);
    bool operator >= (const iterator_vector<type_t>& it);

    void first();
    void prev();
    void next();
    void last();
    bool isDone() const;

    const type_t& value() const;
private:
    const Vector<type_t>* vec;
    void _NULL_vec();
};

#include "_iterator_vector.cpp"

