#include <vector>
#include <set>
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
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder
{
    friend void swap(Message& lhs, Message& rhs);
    friend class Message;
public:
    Folder(){};
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder(){};
    void PrintMessage()
    {
        for(auto i: messages)
            cout << i->contents << endl;
    }
private:
    set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*); //为毛不能用consgt
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
    remove_from_Folders();
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
    for(auto f: lhs.folders)
        f->remMsg(&lhs);
    for(auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}

void Folder::addMsg(Message* p)
{
    messages.insert(p);
}

void Folder::remMsg(Message* p)
{
    messages.erase(p);
}

int main()
{
    Folder Job; //工作相关邮件列表
    Folder CS;  //专业相关邮件列表
    Message m1("Tecent Internership");
    Message m2("GE Shanghai");
    Message m3("ALIBABA tianchi Mobile Competition");
    Message m4("Music Recommand");
    Message m5("IrDAStudy source code");

    Message m_1 = m1;

    m1.Save(Job);
    m2.Save(Job);
    m3.Save(CS);
    m4.Save(CS);
    m5.Save(CS);
    m_1.Save(CS);

    // Job.PrintMessage();
    CS.PrintMessage();
    
    return 0;
}
