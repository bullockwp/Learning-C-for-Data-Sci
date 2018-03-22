#include "Exception.hpp"
#include <iostream>

//Constructor

Exception::Exception()
{
    mTag = "none";
    mProblem ="itsok";
}

Exception::Exception(std::string tagString,
                     std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}
void Exception::PrintDebug() const
{
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}

void Exception::SetmTag(std::string tagString)
{
    mTag = tagString;
}

void Exception::SetmProblem(std::string problemString)
{
    mProblem = problemString;
}
