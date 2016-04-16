#include <iostream>
#include <string>

class Person
{
    std::string last_name;
    std::string first_name;
protected:
    unsigned int birth_year;
public:
    Person(std::string name, unsigned int year) :
        last_name(name), birth_year(year) {}
    unsigned int age() const { return 2016 - birth_year; }
};

class Student : public Person
{
    std::string group;
    std::string speciality;
public:
    Student(std::string name, unsigned int year, std::string gr) :
        Person(name, year), group(gr)  {}
    bool is_first_year() const { return group[0] == '1'; }
    unsigned int age() const { return Person::age() + 15; }
};

int main()
{
    Person a("Bcc", 1990);
    Student x("Abc", 1995, "101");
    Person *p;

    p = &x;
    std::cout << p->age() << std::endl;
    std::cout << x.age() << " " << x.is_first_year() << std::endl;
    return 0;
}
