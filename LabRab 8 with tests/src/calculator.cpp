#include <string>
#include "Stack.h"
#include "calculator.h"

using namespace std;

  int Calculator::operatorPriority (char operatorSymb) {
    if (operatorSymb == '(' || operatorSymb == ')') {
      return 0;
    }
    if (operatorSymb == '+' || operatorSymb == '-') {
      return 1;
    }
    if (operatorSymb == '*' || operatorSymb == '/') {
      return 2;
    }
  }
  string Calculator::rpn() {
    StackArray operatorStack;
    string expression, rpnExpression;
    /*cout << "Enter an expression:" << endl;
    getline(cin, expression);*/
    expression = "5+7/7";
    double number = 0;
    int i = 0, numRank1 = 0, numRank2 = 0, dotsCounter = 0;
    while (i < expression.size()) {
      if (expression[i] == ' ') {
        rpnExpression += expression[i];
        i++;
      }
      if (isdigit(expression[i])) {
        rpnExpression += expression[i];
        i++;
      }
      /*if (isdigit(expression[i])) {
        while ((isdigit(expression[i]) || expression[i] == '.')) {
          if (dotsCounter == 0 && isdigit(expression[i])) {
            //counter++;
            i++;
            numRank1++;
          }

          if (expression[i] == '.') {
            while (numRank1 != 0) {
              number += (int) expression[i - numRank1] * pow(10, numRank1 - 1);
              numRank1--;
            }
            i++;
            dotsCounter++;
          }
          if (dotsCounter == 1) {
            if (isdigit(expression[i])) {
              i++;
              numRank2--;
            } else {
              int a = 0;
              while (numRank2 != 0) {
                number += (int) expression[i - a] * pow(10, numRank2);
                numRank2++;
                a++;
              }
            }
          }
          if (dotsCounter > 1) {
            cout << "Incorrect data!" << endl;
            exit(0);
          }
        }
      }*/ //было бы уместно, если б данные заносились в контейнер, но я больше ничего не успеваю сделать...
      if (expression[i] == '(') {
        operatorStack << '(';
        i++;
      }
      if (expression[i] == ')' && !operatorStack.isEmpty()) {
        while (operatorStack.peek() != '(') {
          rpnExpression += (char)operatorStack.peek();
          operatorStack.pop();
        }
        if (operatorStack.peek() == '(') {
          operatorStack.pop();
          i++;
        }
      }
      if ((expression[i] == '*') ||
          (expression[i] == '/') ||
          (expression[i] == '-') ||
          (expression[i] == '+')) {
        if ((operatorPriority(expression[i])) == 1) {
          if (!operatorStack.isEmpty()) {
            while ((operatorPriority(expression[i])) <= operatorPriority(operatorStack.peek())) {
              rpnExpression += (char)operatorStack.peek();
              operatorStack.pop();
              if (operatorStack.isEmpty()) {
                break;
              }
            }
            operatorStack.push(expression[i]);
            i++;
          }
          operatorStack.push(expression[i]);
          i++;
        }
        if (operatorPriority(expression[i]) == 2) {
          if (!operatorStack.isEmpty()) {
            while (operatorPriority(operatorStack.peek()) >= (operatorPriority(expression[i]))) {
              if (!operatorStack.isEmpty()) {
                rpnExpression += (char)operatorStack.peek();
                operatorStack.pop();
              }
            }
            if (operatorPriority(operatorStack.peek()) < (operatorPriority(expression[i]))) {
              operatorStack.push(expression[i]);
              i++;
            }
          }
          operatorStack.push(expression[i]);
          i++;
        }
      }
    }
    while (!operatorStack.isEmpty())
    {
      rpnExpression += (char) operatorStack.peek();
      operatorStack.pop();
    }
    return rpnExpression;
  }

  int Calculator::count(string rpnExpression) {
    StackArray stack;
    int i = 0;
    while (i < rpnExpression.size()) {
      if (isdigit(rpnExpression[i])) {
        stack.push(rpnExpression[i]);
        i++;
        continue;
      }
      if ((rpnExpression[i] == '*') ||
          (rpnExpression[i] == '+') ||
          (rpnExpression[i] == '-') ||
          (rpnExpression[i] == '/')) {
        if (!stack.isEmpty()) {
          double a = stack.pop() - 48;
          double b = stack.pop() - 48;
          if (rpnExpression[i] == '*') {
            double c = a * b + 48;
            stack.push((char) c);
            i++;
            continue;
          }
          if (rpnExpression[i] == '+') {
            double c = a + b + 48;
            stack.push((char) c);
            i++;
            continue;
          }
          if (rpnExpression[i] == '/') {
            double c = a / b + 48;
            stack.push((char) c);
            i++;
            continue;
          }
          if (rpnExpression[i] == '-') {
            double c = b - a + 48;
            stack.push((char) c);
            i++;
            continue;
          }
        }
      }
    }
    return stack.peek() - 48;
  }