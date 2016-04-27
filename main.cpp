#include <iostream>
#include <cstddef>

using namespace std;
#include "Geometric_vector.h"
int main()
{
    std::size_t n = 5;
    Vector<int> a(n,1,2,3,4,5);
    Vector<int> b(n,1,2,3,4,5);
    a -= b;


    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}

