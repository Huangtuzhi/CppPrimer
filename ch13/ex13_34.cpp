#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class Folder;
class Message
{
    friend void swap(Message& lhs, Message& rhs);
    friend class Folder;
public:
    explicit Message(const string &str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void Save(Folder&);
    void Remove(Folder&);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message*);
    void remove_from_Folders();
};

void Message::Save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::Remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message &m)
{
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders;
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message& lhs, Message& rhs)
{
    for(auto f： lhs.folders)
        f->remMsg(&lhs);
    for(auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, ths.contents);

    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}