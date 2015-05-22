#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
using namespace std;

class QueryResult
{
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<int>> p, shared_ptr<vector<string>> t):
    sought(s), lines(p), TextInfo(t){}
    ~QueryResult(){};

    set<int>::iterator begin() 
    { return lines->begin(); }

    set<int>::iterator end()   
    { return lines->end();   }

    const shared_ptr<vector<string>> get_file() const
    { return TextInfo; }
private:
    string sought;
    shared_ptr<set<int>> lines;
    shared_ptr<vector<string>> TextInfo;
};

class TextQuery
{
public:
    TextQuery(ifstream& input);
    ~TextQuery(){}; 

    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> TextInfo;
    map<string, shared_ptr<set<int>> > WordInfo; //指针好处是用的时候才分配内存
};


TextQuery::TextQuery(ifstream& input): TextInfo(new vector<string>)
{ 
    int lineid = 1;
    string line, word;
    while(getline(input, line))
    {
       TextInfo->push_back(line);
       istringstream record(line);
       while(record >> word)
       {
            auto& lines = WordInfo[word];
            if(!lines)
                lines.reset(new set<int>);
            lines->insert(lineid);
       }
       lineid++;
    }  
}

QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<int>> nodata(new set<int>);
    auto it = WordInfo.find(sought);
    if(it == WordInfo.end()){
        cout << "Ooops, not find " << sought << endl;
        return QueryResult(sought, nodata, TextInfo);
    }
    else
        return QueryResult(sought, it->second, TextInfo);
}

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << "element occurs " << qr.lines->size() << " times" << endl;
    for(auto i: *qr.lines)
        os << "  (line " << i << ") " << *(qr.TextInfo->begin() + i - 1) << endl;
    return os;
}

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}
