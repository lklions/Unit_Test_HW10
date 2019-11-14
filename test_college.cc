#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "college.h"
#include "course.h"
#include "node.h"


//Test gpa() methos in the College class
/*
double College::gpa(){
	node * ptr;
	ptr = head;
	double sum = 0;
	while(ptr != NULL){
	sum = sum + (ptr->data().get_number_grade() * ptr->data().get_hours());
	ptr = ptr->link();
	}
	return (sum / hours());
}
*/

/*
double course::get_number_grade()const{
    if(grade == "A") return 4.0;
    if(grade == "A-") return 3.667;
    if(grade == "B+") return 3.333;
    if(grade == "B") return 3.0;
    if(grade == "B-") return 2.667;
    if(grade == "C+") return 2.333;
    if(grade == "C") return 2.0;
    if(grade == "C-") return 1.667;
    if(grade == "D+") return 1.333;
    if(grade == "D") return 1.0;
    if(grade == "D-") return 0.667;
    if(grade == "F") return 0.0;
    else return 0;
}
*/

/*
void set_course(std::string num, std::string grad, double hrs);
*/
TEST_CASE( "All A's Should return 4.0" ) {
	College ohio("Laura");
	course a,b,c;
	a.set_course("cs2401","a",3);
	b.set_course("cs2400","a",4);
	c.set_course("ise3200","a",2);

	ohio.add(a);
	ohio.add(b);
	ohio.add(c);

	double result = ohio.gpa();

	REQUIRE(result == 4.0);
 }

TEST_CASE( "A, B, and C with same weight should 3.0" ) {
	College ohio("Laura");
	course a,b,c;
 	a.set_course("cs2401","a",3);
 	b.set_course("cs2400","b",3);
 	c.set_course("ise3200","c",3);

 	ohio.add(a);
 	ohio.add(b);
 	ohio.add(c);

	double result = ohio.gpa();

 	REQUIRE(result == 3.0);
}

TEST_CASE( "All D's should be 1.0" ) {
	College ohio("Laura");
	course a,b,c;
 	a.set_course("cs2401","d",7);
 	b.set_course("cs2400","d",4);
 	c.set_course("ise3200","d",2);

 	ohio.add(a);
 	ohio.add(b);
 	ohio.add(c);

	double result = ohio.gpa();

 	REQUIRE(result == 1.0);
}
