#include <iostream>
#include <cstddef>

using namespace std;
#include "Geometric_vector.h"
#include "iterator_random.h"
int main()
{
    try
    {
        std::size_t n = 5;
        Vector<int> a(n,1,2,3,4,5);
        Vector<int> b(n,1,2,3,4,5);
        Vector<int> c(n,1,2,3,4,5);


        a  = a * 5;
        b  = 5 * b;

        c = a^b;

        cout<<a<<endl;
        cout<<b<<endl;
    }
    catch(error_iter_base& er)
    {
        cout<<er.what()<<endl;
    }
    catch(Base_Error& er)
    {
        cout<<er.what()<<endl;
    }

    return 0;
}

