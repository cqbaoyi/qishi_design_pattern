#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int id = 0;
public:
  Person create_person(const string& name)
  {
    // todo
    Person p;
    p.name = name;
    p.id = id++;
    return p;
    // return {id++, name};
  }
};
