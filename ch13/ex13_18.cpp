#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <random>
using namespace std;

class Employee
{
public:
    Employee(): id(id_generator++){};
    Employee(string _name): name(_name), id(id_generator++){};
    void Print() { cout << "name: " << name << " id: " << id << endl; }
    void Setname(string _name) { name = _name; }
private: 
    string name;
    int id;
    static int id_generator; 
};

int Employee::id_generator = 100;

int main()
{
    Employee e1;
    e1.Setname("tuzhi");
    e1.Print();
    Employee e2("ituzhi");
    e2.Print();

}