class Solution {
    struct ds {
        bool result;
        int index;
    };

    ds parseAnd(string &expr, int start) {
        int n = expr.length();
        ds res;
        res.result = true;
        for (int i = start; i < n; i++) {
            res.index = i;

            char ch = expr[i];
            if (ch == 't') { 
                res.result &= true;
            } else if (ch == 'f') { 
                res.result &= false;
            } else if (ch == '&') {
                ds temp = parseAnd(expr, i + 1);
                res.result &= temp.result;
                i = temp.index;
            } else if (ch == '|') {
                ds temp = parseOr(expr, i + 1);
                res.result &= temp.result;
                i = temp.index;
            } else if (ch == '!') {
                ds temp = parseNot(expr, i + 1);
                res.result &= temp.result;
                i = temp.index;
            } else if (ch == ')') return res;
        }
        return res;
    }

    ds parseOr(string &expr, int start) {
        int n = expr.length();
        ds res;
        res.result = false;
        for (int i = start; i < n; i++) {
            res.index = i;

            char ch = expr[i];
            if (ch == 't') { 
                res.result |= true;
            } else if (ch == 'f') { 
                res.result |= false;
            } else if (ch == '&') {
                ds temp = parseAnd(expr, i + 1);
                res.result |= temp.result;
                i = temp.index;
            } else if (ch == '|') {
                ds temp = parseOr(expr, i + 1);
                res.result |= temp.result;
                i = temp.index;
            } else if (ch == '!') {
                ds temp = parseNot(expr, i + 1);
                res.result |= temp.result;
                i = temp.index;
            } else if (ch == ')') return res;
        }
        return res;
    }

    ds parseNot(string &expr, int start) {
        int n = expr.length();
        ds res;
        res.result = true;
        for (int i = start; i < n; i++) {
            res.index = i;

            char ch = expr[i];
            if (ch == 't') { 
                res.result = false;
            } else if (ch == 'f') { 
                res.result = true;
            } else if (ch == '&') {
                ds temp = parseAnd(expr, i + 1);
                res.result = !temp.result;
                i = temp.index;
            } else if (ch == '|') {
                ds temp = parseOr(expr, i + 1);
                res.result = !temp.result;
                i = temp.index;
            } else if (ch == '!') {
                ds temp = parseNot(expr, i + 1);
                res.result = !temp.result;
                i = temp.index;
            } else if (ch == ')') return res; 
        }
        return res;
    }
public:
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        bool result;
        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == 't') { 
                result = true;
            } else if (ch == 'f') { 
                result = false;
            } else if (ch == '&') {
                ds temp = parseAnd(expression, i + 1);
                result = temp.result;
                i = temp.index;
            } else if (ch == '|') {
                ds temp = parseOr(expression, i + 1);
                result = temp.result;
                i = temp.index;
            } else if (ch == '!') {
                ds temp = parseNot(expression, i + 1);
                result = temp.result;
                i = temp.index;
            }
        }
        return result;
    }
};