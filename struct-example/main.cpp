#include "interface.h"
#include <string>
#include <iostream>

int main() {
    TJournal<std::string> journal; 
    const std::string 
        BJARNE = "Bjarne Stroustrup", 
        DENNIS = "Dennis Ritchie",
        BRIAN = "Brian Kernigan",
        EUGENE = "Eugene Krokhalev";
    journal.AddStudent(BJARNE);
    journal.AddStudent(DENNIS);
    journal.AddStudent(BRIAN);
    journal.AddStudent(EUGENE);
    journal.SetStudentScore(BJARNE, 10.0);
    journal.SetStudentScore(DENNIS, 9.0);
    journal.SetStudentScore(BRIAN, 9.0);
    journal.SetStudentScore(EUGENE, 3.0);
    std::cout << BJARNE << " " << journal.GetStudentScore(BJARNE) << std::endl;
    std::cout << DENNIS << " " << journal.GetStudentScore(DENNIS) << std::endl;
    std::cout << BRIAN << " " << journal.GetStudentScore(BRIAN) << std::endl;
    std::cout << EUGENE << " " << journal.GetStudentScore(EUGENE) << std::endl;
    journal.DropStudent(EUGENE);
    journal.DropStudent(EUGENE);
    return 0;
}
