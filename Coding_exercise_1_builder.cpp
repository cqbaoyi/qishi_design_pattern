#include <string>
#include <ostream>
using namespace std;

class CodeBuilder
{
private:
    string m_str;
public:
  CodeBuilder(const string& class_name)
  {
      m_str += "class " + class_name + "\n";
      m_str += "{\n";
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
      m_str += "  " + type + " " + name + ";\n";
      return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
      os << obj.m_str << "};\n";
      return os;
  }
};
