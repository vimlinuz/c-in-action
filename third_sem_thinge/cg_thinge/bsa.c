#include <conio.h>
#include <graphics.h>
#include <stdio.h>

int main() {

  int gd = DETECT, gm;

  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  int x1, y1, x2, y2;

  printf("Enter the coordinates of the first point (x1, y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Enter the coordinates of the second point (x2, y2): ");
  scanf("%d %d", &x2, &y2);

  int x = x1;
  int y = y1;
  int dx = x2 - x1;
  int dy = y2 - y1;

  putpixel(x, y, WHITE);
  int p = 2 * dy - dx;
  while (x < x2) {
    if (p < 0) {
      x = x + 1;
      p = p + 2 * dy;
    } else {
      x = x + 1;
      y = y + 1;
      p = p + 2 * (dy - dx);
    }
    putpixel(x, y, WHITE);
  }
  getch();
  closegraph();
  return 0;
}
