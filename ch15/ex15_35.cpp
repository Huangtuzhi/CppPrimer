class Query_base
{
    friend class Query; //接口类
public:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&);
    friend Query operator&(const Query&);
public:
    Query(const string &s): q(new WordQuery(s)) { }
    QueryResult eval(const TextQuery& t) const
    { return q->eval(t); }
    string rep() const
    { return q->rep(); }
    ostream& operator<<(ostream& os, const Query& query)
    {
        return os << query.rep();
    }
private:
    Query(shared_ptr<Query_base> query): q(query) {}
    shared_ptr<Query_base> q;
};