#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void plot_ellipse_points(int xc, int yc, int x, int y) {
  putpixel(xc + x, yc + y, WHITE);
  putpixel(xc - x, yc + y, WHITE);
  putpixel(xc + x, yc - y, WHITE);
  putpixel(xc - x, yc - y, WHITE);
}

int main() {
  int gd = DETECT, gm;
  int xc, yc, rx, ry;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

  printf("Enter center (xc, yc): ");
  scanf("%d %d", &xc, &yc);
  printf("Enter radii (rx, ry): ");
  scanf("%d %d", &rx, &ry);

  long rx2 = rx * rx, ry2 = ry * ry;

  int x = 0, y = ry;
  float dx = 0;
  float dy = 2.0f * rx2 * y;
  float p1 = ry2 - rx2 * ry + 0.25f * rx2;

  plot_ellipse_points(xc, yc, x, y);

  while (dx < dy) {
    x++;
    dx += 2.0f * ry2;
    if (p1 < 0) {
      p1 += ry2 * (2 * x - 1);
    } else {
      y--;
      dy -= 2.0f * rx2;
      p1 += ry2 * (2 * x - 1) - 2 * rx2 * y;
    }
    plot_ellipse_points(xc, yc, x, y);
  }

  x = rx;
  y = 0;
  dx = 2.0f * ry2 * x;
  dy = 0;
  float p2 = rx2 - ry2 * rx + 0.25f * ry2;

  plot_ellipse_points(xc, yc, x, y);

  while (x > 0) {
    y++;
    dy += 2.0f * rx2;
    if (p2 < 0) {
      p2 += rx2 * (2 * y + 1);
    } else {
      x--;
      dx -= 2.0f * ry2;
      p2 += rx2 * (2 * y + 1) - 2 * ry2 * x;
    }
    plot_ellipse_points(xc, yc, x, y);
  }

  getch();
  closegraph();
  return 0;
}
