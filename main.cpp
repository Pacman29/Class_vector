#include <iostream>
#include <cstddef>

using namespace std;
#include "Geometric_vector.h"
int main()
{
    std::size_t n = 5;
    Vector<int> a(n,1,2,3,4,5);
    Vector<int> b(n,1,2,3,4,5);
    a  = a * 5;
    b  = 5 * b;


    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}

