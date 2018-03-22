#include "GraduateStudent.hpp"


GraduateStudent::GraduateStudent()
{
    name = "noname";
    SetLibraryFines(0);
    tuition_fees = 0;
    fullTime = 1;
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime)
{
    this -> name = name;
    SetLibraryFines(fines);
    tuition_fees = fees;
    this -> fullTime = fullTime;
}

double GraduateStudent::MoneyOwed() const
{
    return GetLibraryFines();
}