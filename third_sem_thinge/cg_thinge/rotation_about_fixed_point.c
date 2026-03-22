#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  float x1, y1, x2, y2, x3, y3, x4, y4, a, t, h, k;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  printf("Enter the starting point of the line (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("Enter the ending point of the line (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  printf("Enter the angle of rotation (in degrees): ");
  scanf("%f", &a);

  printf("Enter the fixed point of rotation (h, k): ");
  scanf("%f %f", &h, &k);

  setcolor(WHITE);

  line(x1, y1, x2, y2); // Original line in white
  outtextxy(x2 + 5, y2, "Original Line");
  t = a * 3.14159 / 180; // Convert angle to radians
  x3 = h + (x1 - h) * cos(t) - (y1 - k) * sin(t);
  y3 = k + (x1 - h) * sin(t) + (y1 - k) * cos(t);
  x4 = h + (x2 - h) * cos(t) - (y2 - k) * sin(t);
  y4 = k + (x2 - h) * sin(t) + (y2 - k) * cos(t);

  line(x3, y3, x4, y4);
  outtextxy(x4 + 5, y4, "Rotated Line");

  getch();
}
