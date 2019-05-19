#include <iostream>
#include <string>

class Book
{
public:
    virtual std::string read() = 0;
};

class PDFBook : public Book
{
public:
    std::string read() 
    {
        return "reading a pdf book.";
    }
};

class MOBIBook : public Book
{
public:
    std::string read()
    {
        return "reading a mobi book.";
    }
};

class EBookReader 
{
private:
    Book *book;

public:
    EBookReader(Book& b)
    {
        book = &b;
    }
    
    void read()
    {
        std::cout << book->read() << std::endl;
    }
};

int main()
{
    PDFBook book1;
    EBookReader reader1(book1);
    reader1.read();
    
    MOBIBook book2;
    EBookReader reader2(book2);
    reader2.read();
    
    return 0;
}
