#include <conio.h>
#include <graphics.h>

int PolygonPoints[3][2] = {{50, 50}, {100, 50}, {75, 100}};

void PolyLine() {
  int i;
  cleardevice();
  line(0, 240, 640, 240); // x-axis
  line(320, 0, 320, 480); // y-axis
  for (i = 0; i < 3; i++) {
    line(PolygonPoints[i][0], PolygonPoints[i][1],
         PolygonPoints[(i + 1) % 3][0], PolygonPoints[(i + 1) % 3][1]);
  }
}

void Reflect() {
  int i;
  for (i = 0; i < 3; i++) {
    PolygonPoints[i][0] =
        2 * 320 - PolygonPoints[i][0]; // Reflect about y-axis (x=320)
  }
}

int main() {
  int gd = DETECT, gm, i;
  initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
  // Move polygon to center
  for (i = 0; i < 3; i++) {
    PolygonPoints[i][0] += 270; // Center horizontally (320 - 50)
    PolygonPoints[i][1] += 140; // Center vertically (240 - 100)
  }
  PolyLine();
  getch();
  Reflect();
  PolyLine();
  getch();
  closegraph();
  return 0;
}
