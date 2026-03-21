#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

  int gd = DETECT, gm;

  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  int x1, y1, x2, y2;

  printf("Enter the coordinates of the first point (x1, y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Enter the coordinates of the second point (x2, y2): ");
  scanf("%d %d", &x2, &y2);

  int dx = x2 - x1;
  int dy = y2 - y1;

  int step_lenght = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  float xIncrement = dx / (float)step_lenght;
  float yIncrement = dy / (float)step_lenght;

  float x = x1;
  float y = y1;

  for (int k = 0; k <= step_lenght; k++) {
    // round method might not be available in some compilers, so we can use
    // (int)(x + 0.5) to round to the nearest integer
    //
    // - Example: If x = 2.3, x + 0.5 = 2.8 → (int)2.8 = 2
    // - Example: If x = 2.7, x + 0.5 = 3.2 → (int)3.2 = 3

    // putpixel(round(x), round(y), WHITE);
    putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    x += xIncrement;
    y += yIncrement;
  }

  getch();
  closegraph();
  return 0;
}
