#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <iostream>
using namespace std;

struct destination
{
    string ip;
    int port;
    destination(string _ip, int _port): ip(_ip), port(_port){};
};

struct connection
{
    string ip;
    int port;
    connection(string _ip, int _port): ip(_ip), port(_port){};
};

connection connect(destination *d)
{
    shared_ptr<connection> pConn(new connection(d->ip, d->port));
    cout << "creating connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

connection disconnect(connection& p)
{
    cout << "connection close(" << p.ip << ":" << p.port << ")" << endl;
}

void deleter(connection* p)
{
    disconnect(*p);
}

void f(destination &d)
{
    connection c = connect(&d);
    //shared_ptr<connection> p(&c, deleter);
    shared_ptr<connection> p(&c, [](connection* p)
                             {disconnect(*p);});
    cout << "Resource has been reaped\n";
}

int main()
{
    destination des("202.201.13.12", 8888);
    f(des);
}



