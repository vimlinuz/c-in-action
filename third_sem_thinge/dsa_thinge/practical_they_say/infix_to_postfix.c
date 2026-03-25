#include <assert.h>
#include <ctype.h>
#include <string.h>

int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

void to_postfix(char *infix, char postfix[], int length) {
  char stack[length];
  int top = -1;
  int j = 0;

  for (int i = 0; i < length; i++) {
    char c = infix[i];

    if (isalnum(c)) {
      postfix[j++] = c;
    } else if (c == '(') {
      stack[++top] = c;
    } else if (c == ')') {
      while (top != -1 && stack[top] != '(') {
        postfix[j++] = stack[top--];
      }
      top--; // remove '('
    } else { // operator
      while (top != -1 && precedence(stack[top]) >= precedence(c)) {
        postfix[j++] = stack[top--];
      }
      stack[++top] = c;
    }
  }

  while (top != -1) {
    postfix[j++] = stack[top--];
  }

  postfix[j] = '\0';
}

int main() {
  char infix[] = "A+B*C-D";
  int length = strlen(infix);
  char postfix[length + 1];

  to_postfix(infix, postfix, length);

  assert(strcmp(postfix, "ABC*+D-") == 0);

  return 0;
}
