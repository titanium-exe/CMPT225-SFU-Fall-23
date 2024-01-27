/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Sandra Fawzy, EKAMLEEN MAAN
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;

int Perform_operation(int number1, char oprt, int number2) {
    switch (oprt) {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            if (number2 == 0) {
                cout << "ERROR" << endl;
                break;
            }
            return number1 / number2;
        default:
            cout << "Something went wrong" << endl;
    }
    return 0;
}

int main() {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

    t = S.getnext();
    while (t.tt != eof || !opstack.isEmpty()) {
        if (t.tt == integer) {
            numstack.push(t);
            t = S.getnext();
        } else if (t.tt == lptok) {  // if it's left parenthesis
            opstack.push(t);
            S.getnext();
        } else if (t.tt == rptok) {
            if (opstack.peek().tt == lptok) {
                opstack.pop(); // popping them out
                t = S.getnext();
            } else {
                Token oprt = opstack.pop();
                Token number2 = numstack.pop();
                Token number1 = numstack.pop();
                int output = Perform_operation(number1.val, oprt.text[0], number2.val);
                Token outputT;
                outputT.tt = integer;
                outputT.val = output;
                numstack.push(outputT);
            }
        }
        if (t.tt == pltok || t.tt == mitok || t.tt == eof) {
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                // Performing operation
                Token optr = opstack.pop();
                Token number2 = numstack.pop();
                Token number1 = numstack.pop();
                int output = Perform_operation(number1.val, optr.text[0], number2.val);
                Token outputT;
                outputT.tt = integer;
                outputT.val = output;
                numstack.push(outputT);
            } else {
                opstack.push(t);
                t = S.getnext();
            }
        } else if (t.tt == asttok || t.tt == slashtok) {
            if (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                // performing the operation 
                Token optr = opstack.pop();
                Token number2 = numstack.pop();
                Token number1 = numstack.pop();
                int output = Perform_operation(number1.val, optr.text[0], number2.val);
                Token outputT;
                outputT.tt = integer;
                outputT.val = output;
                numstack.push(outputT);
            } else {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    return 0;
}
