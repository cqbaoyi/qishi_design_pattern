#include <string>
#include <iostream>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const
    {
        return " as lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as() const
    {
        return " as pixels";
    }
};

struct Shape
{
protected:
    const Renderer& renderer;
    Shape(const Renderer& r) : renderer(r) {}
    string name;

    virtual string str() const = 0;
};

struct Triangle : Shape
{
    Triangle(const Renderer& r) : Shape(r)
    {
        name = "Triangle";
    }
    
    string str() const
    {
        return "Drawing " + name + renderer.what_to_render_as();
    }
};

struct Square : Shape
{
    Square(const Renderer& r) : Shape(r)
    {
        name = "Square";
    }
    
    string str() const
    {
        return "Drawing " + name + renderer.what_to_render_as();
    }
};
