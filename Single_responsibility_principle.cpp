#include <iostream>
#include <string>

class book 
{
private:
    std::string title;
    std::string author;

public:
    void setTitle(std::string& t)
    {
        title = t;
    }
    
    void setAuthor(std::string& a)
    {
        author = a;
    }
    
    std::string getTitle() const {
        return title;
    }
 
    std::string getAuthor() const {
        return author;
    }
 
    std::string getContent() const {
        std::string content = "current page content";
        return content;
    }
};

class plainPrinter
{
public:
    void printCurrentPage(const book& b) const
    {
        std::cout << b.getContent() << std::endl;
    }
};

class fancyPrinter
{
public:
    void printCurrentPage(const book& b) const
    {
        std::cout << "Author: " << b.getAuthor() << std::endl;
        std::cout << "Title: " << b.getTitle() << std::endl;
        std::cout << "Content: " << b.getContent() << std::endl;
    }
};

int main()
{
    std::string title = "24 Hours in the Life of a Woman";
    std::string author = "Stefan Zweig";
    book novel;
    novel.setTitle(title);
    novel.setAuthor(author);
    
    plainPrinter pp;
    pp.printCurrentPage(novel);
    fancyPrinter fp;
    fp.printCurrentPage(novel);

    return 0;
}
