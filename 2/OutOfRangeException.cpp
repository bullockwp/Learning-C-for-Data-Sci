#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException()
{
    SetmTag("none");
    SetmProblem("itsok");
}

OutOfRangeException::OutOfRangeException(std::string prob)
{
    SetmTag(prob);
    SetmProblem("it's out of range idiot!");
}
