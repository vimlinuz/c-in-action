#include <conio.h>
#include <graphics.h>
void flood_fill(int x, int y, int fill_color, int old_color) {
  int current_color = getpixel(x, y);
  if (current_color == old_color) {
    putpixel(x, y, fill_color);
    flood_fill(x + 1, y, fill_color, old_color); // Right
    flood_fill(x - 1, y, fill_color, old_color); // Left
    flood_fill(x, y + 1, fill_color, old_color); // Down
    flood_fill(x, y - 1, fill_color, old_color); // Up
  }
}

int main() {
  int gdriver = DETECT, gm;
  initgraph(&gdriver, &gm, "c:\\turboc3\\bgi");

  rectangle(100, 100, 300, 300);
  int x = 150, y = 150;
  int old_color = getpixel(x, y);
  flood_fill(x, y, GREEN, old_color);
  getch();
  closegraph();
  return 0;
}
