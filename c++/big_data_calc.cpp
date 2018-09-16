#include "big_data_calc.h"

big_data::big_data(INT_64 v)
    : _value(v)
    , _s_data()
{
}

big_data::big_data(const char *s)
    : _value(0)
    , _s_data(s)
{}
