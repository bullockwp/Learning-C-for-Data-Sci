#include "Student.hpp"
#include "math.h"


Student::Student()
{
    name = "noname";
    library_fines = 0;
    tuition_fees = 0;
}

Student::Student(std::string name, double fines, double fees)
{
    this -> name = name;
    library_fines = fines;
    tuition_fees = fees;
}

void Student::SetLibraryFines(double amount)
{
    library_fines = fabs(amount);
}

double Student::GetLibraryFines() const
{
    double amount = library_fines;
    return amount;
}

double Student::MoneyOwed() const
{
    double mo;
    double lf = GetLibraryFines();
    double tf = tuition_fees;
    mo = (lf +tf);
    return mo;
}