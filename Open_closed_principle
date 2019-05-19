#include <iostream>

class Measurable
{
public:
    virtual long getLength() = 0;
    virtual long getSent() = 0;
};

class File : public Measurable
{
private:
    long length;
    long sent;

public:
    void setLength(long l) { length = l; }
    void setSent(long s) { sent = s; }
    long getLength() { return length; }
    long getSent() { return sent; }
};

/*
class Music : public Measurable
{
    // ...
};
*/

class Progress
{
private:
    Measurable *measurable;

public:
    Progress(Measurable& m)
    {
        measurable = &m;    
    }
    
    double getPercent()
    {
        return static_cast<double>(measurable->getSent()) / 
               static_cast<double>(measurable->getLength());
    }
};

int main()
{
    File f1;
    f1.setLength(1000);
    f1.setSent(430);
    
    Progress p(f1);
    std::cout << p.getPercent() << std::endl;
    
    // Music m1;

    return 0;
}
