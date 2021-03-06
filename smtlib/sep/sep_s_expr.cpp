#include "sep_s_expr.h"

#include <sstream>

using namespace std;
using namespace smtlib::sep;

CompSExpression::CompSExpression(const vector<SExpressionPtr>& exprs) {
    this->expressions.insert(this->expressions.end(), exprs.begin(), exprs.end());
}

void CompSExpression::accept(Visitor0* visitor) {
    visitor->visit(shared_from_this());
}

string CompSExpression::toString() {
    stringstream ss;
    ss << "(";

    for (size_t i = 0, sz = expressions.size(); i < sz; i++) {
        if (i != 0)
            ss << " ";

        ss << expressions[i];
    }

    ss << ")";
    return ss.str();
}
