#include "Intern.hpp"
#include "../ex02/Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern intern;
    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "Home");
    AForm* f3 = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* f4 = intern.makeForm("unknown form", "Nobody");

    Bureaucrat boss("Boss", 1);
    if (f1) { f1->beSigned(boss); boss.executeForm(*f1); delete f1; }
    if (f2) { f2->beSigned(boss); boss.executeForm(*f2); delete f2; }
    if (f3) { f3->beSigned(boss); boss.executeForm(*f3); delete f3; }
    if (f4) { delete f4; }

    return 0;
}
