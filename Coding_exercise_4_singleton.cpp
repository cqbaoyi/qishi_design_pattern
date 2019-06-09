#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    // TODO
    return factory() == factory();
  }
};
