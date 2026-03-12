#include <math.h>
#include <stdio.h>
// f(x ) =  3x^2 - 6x + 2 = 0
#define FUNCTION(x) (3 * x * x - 6 * x + 2)

typedef struct {
  float first_initial_guess;
  float second_initial_geuss;
  float precision;
} parms;

float bisection_method(parms parms) {

  float xl = parms.first_initial_guess;
  float xu = parms.second_initial_geuss;
  float xm;

  float fxl;
  float fxu;
  float fxm;

  while (1) {
    fxl = FUNCTION(xl);
    fxu = FUNCTION(xu);

    xm = (xl + xu) / 2;

    fxm = FUNCTION(xm);

    if ((fxl * fxm) == 0) {
      break;
    } else if ((fxl * fxm) < 0) {
      xu = xm;
    } else {
      xl = xm;
    }

    if (fabsf((xl - xu) / xu) < parms.precision) {
      break;
    }
  }
  return xm;
}

int main() {
  parms parms = {
      .first_initial_guess = 1, .second_initial_geuss = 2, .precision = 0.05};

  if (!((FUNCTION(parms.first_initial_guess) *
         FUNCTION(parms.second_initial_geuss)) < 0)) {
    printf("The function does not change signs in the given interval. Please "
           "choose different initial guesses.\n");
    return 1;
  }

  float root = bisection_method(parms);

  printf("The root is: %f\n", root);

  return 0;
}
