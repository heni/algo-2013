/*
 * See http://www.boost.org/doc/libs/1_41_0/libs/test/doc/html/utf.html for more information
 */
#include "interface.h"
#include <string>
#include <cmath>

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

BOOST_AUTO_TEST_CASE(testJournal) {
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
    BOOST_CHECK_EQUAL(journal.GetStudentScore(BJARNE), 10.0);
    BOOST_CHECK_EQUAL(journal.GetStudentScore(DENNIS), 9.0);
    BOOST_CHECK_EQUAL(journal.GetStudentScore(BRIAN), 9.0);
    BOOST_CHECK_CLOSE(journal.GetStudentScore(EUGENE), exp(log(3.0)), 1e-6);
    journal.DropStudent(EUGENE);
    BOOST_CHECK_THROW(journal.DropStudent(EUGENE), std::out_of_range);
}

/*typedef boost::mpl::list<int> test_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(testJournalTmpl, CType, test_types) {
    TJournal<std::string, std::less<std::string>, CType> journal;
}*/
