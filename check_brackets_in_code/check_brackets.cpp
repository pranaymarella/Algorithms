#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using std::cin;
using std::cout;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket obj = Bracket(next, position + 1);
            // Process opening bracket, write your code here
            opening_brackets_stack.push(obj);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (!opening_brackets_stack.empty()) {
                Bracket top = opening_brackets_stack.top();
                // Process closing bracket, write your code here
                if (top.Matchc(next))
                    opening_brackets_stack.pop();
                else {
                    std::cout << position + 1 << std::endl;
                    return 0;
                }
            } else {
                std::cout << position + 1 << std::endl;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty())
        std::cout << "Success" << std::endl;
    else {
        Bracket obj = opening_brackets_stack.top();
        std::cout << obj.position << std::endl;
    }
    return 0;
}
