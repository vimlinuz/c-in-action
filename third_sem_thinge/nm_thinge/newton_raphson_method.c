#include <math.h>
#include <stdio.h>
#define FUNCTION(x) (x * x + 4 * x - 9)
#define DERIVATIVE(x) (2 * x + 4)

float newton_raphson(float initial_guess, float tolerance) {
  float x0 = initial_guess;
  float x1;
  while (1) {
    x1 = x0 - FUNCTION(x0) / DERIVATIVE(x0);
    if (fabsf((x1 - x0) / x1) < tolerance) {
      break;
    }
    x0 = x1;
  }
  return x1;
}

int main() {
  // initializing the initial guess
  float initial_guess = 4.0;

  // initializing the tolerance
  float tolerance = 0.1;

  // calling the newton_raphson function
  // and storing the result in a variable
  float root = newton_raphson(initial_guess, tolerance);
  printf("The root is: %f\n", root);

  return 0;
}
