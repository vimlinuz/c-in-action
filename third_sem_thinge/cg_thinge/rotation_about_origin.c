#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  float x1, y1, x2, y2, x3, y3, x4, y4, a, t;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  printf("Enter the starting point of the line (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("Enter the ending point of the line (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  printf("Enter the angle of rotation (in degrees): ");
  scanf("%f", &a);

  setcolor(WHITE);

  line(x1, y1, x2, y2); // Original line in white
  outtextxy(x2 + 5, y2, "Original Line");
  t = a * 3.14159 / 180; // Convert angle to radians
  x3 = x1 * cos(t) - y1 * sin(t);
  y3 = x1 * sin(t) + y1 * cos(t);
  x4 = x2 * cos(t) - y2 * sin(t);
  y4 = x2 * sin(t) + y2 * cos(t);

  line(x3, y3, x4, y4);
  outtextxy(x4 + 5, y4, "Rotated Line");

  getch();
}
