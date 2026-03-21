#include <conio.h>
#include <graphics.h>

void boundary_fill(int x, int y, int fill_color, int boundary_color) {
  int current_color = getpixel(x, y);
  if (current_color != boundary_color && current_color != fill_color) {
    putpixel(x, y, fill_color);
    boundary_fill(x + 1, y, fill_color, boundary_color); // Right
    boundary_fill(x - 1, y, fill_color, boundary_color); // Left
    boundary_fill(x, y + 1, fill_color, boundary_color); // Down
    boundary_fill(x, y - 1, fill_color, boundary_color); // Up
  }
}
int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
  rectangle(100, 100, 300, 300);
  boundary_fill(150, 150, RED, WHITE);
  getch();
  closegraph();
  return 0;
}
