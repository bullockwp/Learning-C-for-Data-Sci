#include "PhdStudent.hpp"


PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime)
{
    this -> name = name;
    SetLibraryFines(fines);
    tuition_fees = fees;
    this -> fullTime = fullTime;
}

double PhdStudent::MoneyOwed() const
{
    return 0;
}