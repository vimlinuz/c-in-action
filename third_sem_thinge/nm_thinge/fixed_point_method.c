#include <math.h>
#include <stdio.h>
// f(x) = 0 form
// f(x) = x^2 - 6x + 8
#define FUNCTION(x) (x * x - 6 * x + 8)

// x = g(x) form
// x = x^2 - 5x + 8
#define CONVERSION_FORM(x) (x * x - 5 * x + 8)

float fixed_point_method(float initial_guess, float precision) {
  float x0 = initial_guess;
  float x1;
  while (1) {
    x1 = CONVERSION_FORM(x0);
    if (fabsf((x1 - x0) / x1) < precision) {
      break;
    }
    x0 = x1;
  }
  return x1;
}

int main() {
  // initializing the initial guess
  float initial_guess = 1.0;

  // initializing the precision
  float precision = 0.01;

  // calling the newton_raphson function
  // and storing the result in a variable
  float root = fixed_point_method(initial_guess, precision);
  printf("The root is: %f\n", root);

  return 0;
}
