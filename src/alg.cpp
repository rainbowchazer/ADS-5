// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    TStack<char>  stack1;
    std::string str = "";
    for (int i = 0; i < inf.length(); i++) {
        if (num(inf[i])) {
            str += inf[i];
            str += ' ';
        }
        else if (op(inf[i])) {
            if (inf[i] == '(')
                stack1.push(inf[i]);
            else if (inf[i] == ')') {
                while (stack1.get() != '(') {
                    str += stack1.get();
                    str += ' ';
                    stack1.pop();
                }
                stack1.pop();
            }
            else if (stack1.isempty())
                stack1.push(inf[i]);
            else if (pr(inf[i]) > pr(stack1.get()))
                stack1.push(inf[i]);
            else if (pr(inf[i]) <= pr(stack1.get())) {
                str += stack1.get();
                str += ' ';
                stack1.pop();
            }
        }
    }
    while (stack1.isempty() != 1) {
        str += stack1.get();
        str += ' ';
        stack1.pop();
    }
    return str;
}

int eval(std::string pref) {
    TStack<int> stack2;
    for (int i = 0; i < pref.length(); i++) {
        if (num(pref[i]))
            stack2.push(conv(pref[i]));
        else if (op(pref[i])) {
            int a = stack2.get();
            stack2.pop();
            int b = stack2.get();
            stack2.pop();
            if (pref[i] == '+')
                stack2.push(a + b);
            else if (pref[i] == '-')
                stack2.push(a - b);
            else if (pref[i] == '*')
                stack2.push(a * b);
            else if (pref[i] == '/')
                stack2.push(a / b);
        }
    }
    return stack2.get();
}
