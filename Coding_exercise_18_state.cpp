#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class CombinationLock
{
    vector<int> combination;
    vector<int> buffer;
public:
    string status;

    CombinationLock(const vector<int> &combination) : combination(combination) {
        status = "LOCKED";
    }

    void enter_digit(int digit)
    {
      // TODO
      buffer.push_back(digit);
      if (buffer == combination)
      {
          status = "OPEN";
          buffer.clear();
      }
      else if (buffer.size() == combination.size())
      {
          status = "ERROR";
          buffer.clear();
      }
      else
      {
          ostringstream oss;
          for (auto d : buffer)
            oss << d;
          status = oss.str();
      }
    }
};
