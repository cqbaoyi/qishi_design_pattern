#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct IRat
{
    virtual void enters(size_t num) = 0;
    virtual void dies() = 0;
};

struct Game
{
    // todo
    vector<IRat*> rats;
    
    void broadcast_enters()
    {
        for(auto r : rats)
            r->enters(rats.size());
    }
    void broadcast_dies()
    {
        for(auto r : rats)
            r->dies();
    }
};

struct Rat : IRat
{
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
      // todo, obviously
      game.rats.push_back(this);
      game.broadcast_enters();
    }

    ~Rat() 
    { 
        // rat dies here!
        game.rats.erase(std::remove(game.rats.begin(),game.rats.end(),this));
        game.broadcast_dies();
    }
    
    void enters(size_t num)
    {
        attack = num;
    }
    
    void dies()
    {
        --attack;
    }
};
