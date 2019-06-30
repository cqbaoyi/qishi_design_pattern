#include <vector>
#include <iostream>

using namespace std;

struct Creature;
struct Game
{
  vector<Creature*> creatures;
};

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;
  virtual bool is_king() = 0;
};

class Goblin : public Creature
{
    bool king;
public:
  Goblin(Game &game, int base_attack, int base_defense) 
  : Creature(game, base_attack, base_defense) 
  { 
      king = false;
  }

  Goblin(Game &game) : Creature(game, 1, 1) { king = false; }

  int get_attack() override {
    // todo
    bool kingPresent = false;
    for (auto c : game.creatures)
    {
        if (c->is_king())
        {
            kingPresent = true;
            break;
        }
    }
    return base_attack + (kingPresent ? 1 : 0);
  }

  int get_defense() override {
    // todo
    return base_defense + game.creatures.size() - 1;
  }
  
  bool is_king() override {
      return king;
  }
};

class GoblinKing : public Goblin
{
    bool king;
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) { 
      king = true; 
  }

  // todo
    int get_attack() override {
    // todo
    return base_attack;
  }

  int get_defense() override {
    // todo
    return base_defense + game.creatures.size() - 1;
  }
  
  bool is_king() override {
      return king;
  }
};
