#include "Coding_exercise_7_composite.h"

int sum(const vector<ContainsIntegers*> items)
{
    // TODO
    int result = 0;
    for (auto item : items)
        result += item->sum();
        
    return result;
}
