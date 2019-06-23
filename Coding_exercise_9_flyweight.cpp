#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };

  Sentence(const string& text)
  {
    // todo
    string buf;
    stringstream ss(text);
    
    while (ss >> buf)
    {
        v.emplace_back(buf);
    }
  }

  WordToken& operator[](size_t index)
  {
    // todo
    if (m.find(index) == m.end())
        m[index] = WordToken{};
    return m[index];
  }

  string str() const
  {
    // todo
    string res;
    for (size_t i = 0; i < v.size(); ++i)
    {
        auto token = v[i];
        auto it = m.find(i);
        if (it != m.end() && it->second.capitalize)
        {
            for (auto c : token)
                res += toupper(c);
        }
        else
            res += token;
        if (i < v.size() - 1)
            res += " ";
    }
    return res;
  }
  
private: 
    unordered_map<int, WordToken> m;
    vector<string> v;
    
};
