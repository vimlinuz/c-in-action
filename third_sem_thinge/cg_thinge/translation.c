#include <conio.h>
#include <graphics.h>
#include <stdio.h>

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
  int x1, y1, x2, y2, tx, ty, x3, y3, x4, y4;
  printf("Enter the  starting point of the line (x1, y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter the ending point of the line (x2, y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Enter the translation factors (tx, ty): ");
  scanf("%d %d", &tx, &ty);

  setcolor(WHITE);
  line(x1, y1, x2, y2); // Original line in white
  outtextxy(x2 + 5, y2, "Original Line");

  x3 = x1 + tx;
  y3 = y1 + ty;
  x4 = x2 + tx;
  y4 = y2 + ty;

  line(x3, y3, x4, y4);
  outtextxy(x4 + 5, y4, "Translated Line");
  getch();
  closegraph();
  return 0;
}
