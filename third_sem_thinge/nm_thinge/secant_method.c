#include <math.h>
#include <stdio.h>
// f(x ) = 2x^2 + 4x - 10
#define FUNCTION(x) (2 * x * x + 4 * x - 10)

typedef struct {
  float first_initial_guess;
  float second_initial_geuss;
  float precision;
} parms;

float secant_method(parms parms) {

  float x0 = parms.first_initial_guess;
  float x1 = parms.second_initial_geuss;
  float x2;

  while (1) {
    x2 = x1 - FUNCTION(x1) * (x1 - x0) / (FUNCTION(x1) - FUNCTION(x0));

    if (fabsf((x2 - x1) / x1) < parms.precision) {
      break;
    }
    x1 = x2;
  }
  return x2;
}

int main() {
  parms parms = {
      .first_initial_guess = 2, .second_initial_geuss = 6, .precision = 0.05};

  float root = secant_method(parms);

  printf("The root is: %f\n", root);

  return 0;
}
