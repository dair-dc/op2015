#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct XMLHandler {
    virtual void on_element_start(const string &name) = 0;
    virtual void on_element_end(const string &name) = 0;
    virtual void on_attribute(const string &name, const string &value)=0;
};

struct DummyHandler : public XMLHandler
{
    void on_element_start(const string &name)
    {
        cout << "Element start: " << name << endl;
    }

    void on_element_end(const string &name)
    {
        cout << "Element end: " << name << endl;
    }

    void on_attribute(const string &name, const string &value)
    {
    }
};

class XMLValidator : public XMLHandler
{
    void on_element_start(const string &name)
    {
    }

    void on_element_end(const string &name)
    {
    }

    void on_attribute(const string &name, const string &value)
    {
    }
};

class XMLParser {
    bool is_space(char c)
    {
        return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
    }


    bool is_letter(char c)
    {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_');
    }
public:
void parse(istream &in, XMLHandler *h)
{
    int state = 0;
    char c;
    string name;
    bool err = false;

    while (!err && in.get(c))
    {
        switch (state)
        {
            case 0:
                if (c == '<')
                {
                    state = 1;
                    name = "";
                }
                break;

            case 1:
                if (is_letter(c))
                {
                    name += c;
                    state = 5;
                }
                else if (c == '/')
                    state = 4;
                else
                    err = true;
                break;

            case 4:
                if (is_letter(c))
                    name += c;
                else if (c == '>')
                {
                    h->on_element_end(name);
                    state = 0;
                }
                break;

            case 5:
                if (is_letter(c))
                    name += c;
                else
                {
                    h->on_element_start(name);
                    if (is_space(c))
                        state = 2;
                    else if (c == '/')
                        state = 3;
                    else if (c == '>')
                        state = 0;
                    else
                        err = true;
                }
                break;

            case 2:
                if (c == '/')
                    state = 3;
                else if (c == '>')
                    state = 0;
                break;

            case 3:
                if (c == '>')
                {
                    h->on_element_end(name);
                    state = 0;
                }
                else
                    err = true;
                break;
        }
    }
    if (err) cout << "Error, state " << state << "\n";
}
};

int main()
{
    XMLValidator d;
    XMLParser p;
    ifstream f("test.xml");
    p.parse(f, &d);
}
