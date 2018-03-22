#ifndef SUBMISSION_EXERCISE82_HPP_
#define SUBMISSION_EXERCISE82_HPP_
#include "math.h"

template<typename T>
T CalcAbs(T val) {
    if (val < 0)
        return val * -1;
    else
        return val;
}

#endif /* SUBMISSION_EXERCISE82_HPP_ */
