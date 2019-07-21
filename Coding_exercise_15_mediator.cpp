#include<vector>

using namespace std;

struct IParticipant
{
    virtual void say(int value) = 0;
};

struct Participant;

struct Mediator
{
    vector<Participant*> participants;
    
    Mediator() {};
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void say(int value)
    {
        // todo
        for (auto p : mediator.participants)
        {
            if (p != this)
                p->value = value;
        }
    }
};

