#ifndef __BIG_DATA_CALC_H__
#define __BIG_DATA_CALC_H__

#include <iostream>
#include <string>
using namespace std;

typedef long long INT_64;

class big_data{
public:
    big_data(INT_64 v);
    big_data(const char *s);
private:
    INT_64 _value;
    std::string _s_data;
};

#endif


