#include <conio.h>
#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  float x1, y1, x2, y2, sx, sy, xf, yf, x3, y3, x4, y4;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  printf("\nEnter the coordinates of the first point (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("\nEnter the coordinates of the second point (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  printf("\nEnter the scaling factors (sx, sy): ");
  scanf("%f %f", &sx, &sy);

  printf("\nEnter the fixed point for scaling (xf, yf): ");
  scanf("%f %f", &xf, &yf);

  setcolor(WHITE);

  line(x1, y1, x2, y2); // Original line
  outtextxy(x2 + 5, y2, "Original Line");

  x3 = xf + sx * (x1 - xf);
  y3 = yf + sy * (y1 - yf);
  x4 = xf + sx * (x2 - xf);
  y4 = yf + sy * (y2 - yf);

  line(x3, y3, x4, y4); // Scaled line
  outtextxy(x4 + 5, y4, "Scaled Line");
  getch();
  closegraph();
  return 0;
}
