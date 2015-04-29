#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class TreeNode
{
public:
    TreeNode(const string& s = string()): value(s), count(new int(1)), left(nullptr), right(nullptr) { };
    //const string& s = string()加了默认参数，实例化可以直接TreeNode a,string为空。
    TreeNode(const TreeNode&p): value(p.value), count(p.count), left(p.left), right(p.right) { ++*p.count; }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
    void Print() { cout << value << " : " << *count << endl; }
private:
    string value;
    int* count;
    TreeNode* left;
    TreeNode* right;
};

TreeNode::~TreeNode()
{
    if(--*count == 0)
    {
        if(left){
            delete left;
            left = nullptr;
        }

        if(right){
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
}

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
    ++*rhs.count;
    if(--*count == 0)
    {
        delete count;
        delete left;
        delete right;
    }
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

class BinStrTree
{
public:
    BinStrTree(): root(new TreeNode()) { }
    BinStrTree(const BinStrTree& p): root(new TreeNode(*p.root)) { }
    BinStrTree& operator=(const BinStrTree& p);
    ~BinStrTree(){ delete root; }

private:
    TreeNode* root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& p)
{
    auto new_root = new TreeNode(*p.root);
    delete root;
    root = new_root;
    return *this;  
}

int main()
{
    TreeNode a;
    a.Print();
    TreeNode b("tuzhi");
    b.Print();
    TreeNode c = b;
    b.Print();
    c.Print();

    return 0;
}
