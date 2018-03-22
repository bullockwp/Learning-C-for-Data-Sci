#include "FileNotOpenException.hpp"


FileNotOpenException::FileNotOpenException()
{
    SetmTag("none");
    SetmProblem("itsok");
}

FileNotOpenException::FileNotOpenException(std::string prob)
{
    SetmTag(prob);
    SetmProblem("File not open you fool!");
}

