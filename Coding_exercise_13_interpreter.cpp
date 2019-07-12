#include<vector>
#include<string>
#include<map>

using namespace std;

struct ExpressionProcessor
{
  map<char,int> variables;

    int parse(const string& expression, vector<char>& symbols, vector<int>& nums)
    {
        string buffer;
        for (const auto& c : expression)
        {
            if (c >= '0' && c <= '9')
            {
                buffer += c;
            }
            else if (c == '+' || c == '-')
            {
                if (buffer.back() >= '0' && buffer.back() <= '9')
                {
                    nums.push_back(stoi(buffer));
                    buffer.clear();
                }
                else if (buffer.size() > 1)
                    return 0;
                else if (variables.find(buffer[0]) != variables.end())
                {
                    nums.push_back(variables[buffer[0]]);
                    buffer.clear();
                }
                else
                    return 0;
                symbols.push_back(c);
            }
            else if (c >= 'a' && c <= 'z')
            {
                if (variables.find(c) == variables.end())
                    return 0;
                else
                    buffer += c;
            }
            else
                return 0;
        }
        
        if (!buffer.empty())
        {
            if (buffer.front() >= '0' && buffer.front() <= '9')
                nums.push_back(stoi(buffer));
            else if (buffer.size() > 1)
                return 0;
            else if (variables.find(buffer[0]) == variables.end())
                return 0;
            else
                nums.push_back(variables[buffer[0]]);
        }
        
        return 1;
    }

  int calculate(const string& expression)
  {
    // TODO
    vector<char> symbols;
    vector<int> nums;
    
    int flag = parse(expression, symbols, nums);
    if (flag == 0)
        return 0;

    int res = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (symbols[i - 1] == '+')
            res += nums[i];
        else
            res -= nums[i];
    }
    return res;
  }
};
