#include <iostream>
#include <string>
using namespace std;
class Publication
{
public:
    string title;
    float price;
    int count = 0;
    void entry()
    {
        cout << "Enter Name of Book/Cassette ";
        cin >> title;
        cout << "Enter the price ";
        cin >> price;
    }
    void display()
    {
        try
        {
            if (price > 0)
            {
                cout << "Serial No.\tBook Name\tPrice\tPages/Reading   Time ";
                  
                cout<< "\n"<< count << "\t\t" << title << "\t" << price << "\t";
            }
            else
            {
                throw "Price Can't Be Negative";
            }
        }
        catch (const char *ex)
        {
            cout << ex;
        }
    }
};
class Book : public Publication
{
public:
    int pgcount;
    Book()
    {
        count++;
    }
    void entry()
    {
        Publication::entry();
        cout << "Enter number of pages ";
        cin >> pgcount;
    }
    void display()
    {
        try
        {
            if (pgcount <= 0 && price <= 0)
            {
                throw "Price & Pages Can't Be Zero or Negative\n ";
        
            }
            else if (price <= 0)
            {
                throw "Price Can't Be Negative\n";
            }
            else if (pgcount <= 0)
            {
                throw "Pages Can't Be Zero or Negative\n";
            }
            else
            {
                Publication::display();
                cout << pgcount << endl;
            }
        }
        catch (const char *ex)
        {
            cout << ex;
        }
    }
};
class Tape : public Publication
{
public:
    float rtime;
    Tape()
    {
        count++;
    }
    void entry()
    {
        Publication::entry();
        cout << "Enter Reading Time of Book ";
        cin >> rtime;
    }
    void display()
    {
        try
        {
            if (rtime <= 0 && price <= 0)
            {
                throw "Price & Pages Can't Be Zero or Negative\n ";
                  
            }
            else if (price <= 0)
            {
                throw "Price Can't Be Negative\n";
            }
            else if (rtime <= 0)
            {
                throw "Reading Time Can't Be Zero or Negative\n ";
                    
            }
            else
            {
                Publication::display();
                cout << rtime << endl;
            }
        }
        catch (const char *ex)
        {
            cout << ex;
        }
    }
};
int main()
{
    int ch;
    while (true)
    {
        cout << "Welcome\nPlease enter your  choice\n1.Book\t2.Cassette\n3.Exit\n ";
                
                cin >>
            ch;
        switch (ch)
        {
        case 1:
        {
            Book *b = new Book;
            b->entry();
            b->display();
            break;
        }
        case 2:
        {
            Tape *t = new Tape;
            t->entry();
            t->display();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid choice";
        }
        }
    }
    return 0;
}
