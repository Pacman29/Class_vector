#ifndef ITERATION_ER
#define ITERATION_ER

class error_iter_base
{
public:
    virtual const char* what() = 0;
};

class er_iteration : public error_iter_base
{
public:
    const char* what() {
        return "Index out of range";
    }
};

class er_Compare_iter : public error_iter_base
{
public:
    const char* what() {
        return "Different iterators was compared";
    }
};

#endif // ITERATION_ER

