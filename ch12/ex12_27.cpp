#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
using namespace std;

class QueryResult
{
public:
    QueryResult(){};
    ~QueryResult(){};
    int ShowCount;
    set<int> ShowLine;
    map<int, string> LineContent;
};


class TextQuery
{
public:
    TextQuery(ifstream& input): infile(input)
    {
        int lineid = 1;
        string line, word;
        while(getline(input, line))
        {
           TextInfo.push_back(line);
           istringstream record(line);
           while(record >> word)
           {
                WordInfo[word].insert(lineid);
           }
           lineid++;
        }   
    }
    ~TextQuery(){}; 

    bool query(string s);
    void print();

private:
    ifstream &infile;
    vector<string> TextInfo;
    map<string, set<int> > WordInfo;
    QueryResult result;
};

bool TextQuery::query(string s)
{
    auto it = WordInfo.find(s);
    if(it == WordInfo.end()){
        cout << "Ooops, not find " << s << endl;
        return false;
    }
    else {
        result.ShowCount = it->second.size();
        result.ShowLine = it->second;
        for(auto i: result.ShowLine){
            result.LineContent.insert({i, TextInfo[i-1]});
        }
        return true;
    }          
}

void TextQuery::print()
{
    cout << "element occurs " << result.ShowCount << " times" << endl;
    for(auto i: result.ShowLine)
    cout << "  (line " << i << ") " << result.LineContent[i] << endl;
}


void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        bool flag = tq.query(s);
        if(flag)
            tq.print();
    }
}

int main()
{
    ifstream file("Pride-and-Prejudice.txt");
    runQueries(file);
    return 0;
}