#include <conio.h>
#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  float x1, y1, x2, y2, sx, sy, x3, y3, x4, y4;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  printf("\nEnter the coordinates of the first point (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  printf("\nEnter the coordinates of the second point (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  printf("\nScaling factor in x direction (sx, sy): ");
  scanf("%f %f", &sx, &sy);

  setcolor(WHITE);

  line(x1, y1, x2, y2); // Original line
  outtextxy(x2 + 5, y2, "Original Line");

  x3 = x1 * sx;
  y3 = y1 * sy;
  x4 = x2 * sx;
  y4 = x2 * sy;

  line(x3, y3, x4, y4); // Scaled line
  outtextxy(x4 + 5, y4, "Scaled Line");
  getch();
  closegraph();
  return 0;
}
