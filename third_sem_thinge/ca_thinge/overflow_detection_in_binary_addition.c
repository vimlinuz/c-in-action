#include <stdio.h>

int to_binary4(int v) {
  v &= 0xF;
  return ((v >> 3) & 1) * 1000 + ((v >> 2) & 1) * 100 + ((v >> 1) & 1) * 10 +
         (v & 1);
}

int to_signed4(int val) {
  val = val & 0xF;
  if (val & 0x8)
    val = val - 16;
  return val;
}

int detect_overflow(int a, int b, int result) {
  int sign_a = (a >> 3) & 1;
  int sign_b = (b >> 3) & 1;
  int sign_res = (result >> 3) & 1;
  return (sign_a == sign_b) && (sign_res != sign_a);
}

int detect_overflow_carry(int a, int b) {
  int raw = (a & 0xF) + (b & 0xF);
  int c4 = (raw >> 4) & 1;
  int c3 = (((a & 0x7) + (b & 0x7)) >> 3) & 1;
  return c3 ^ c4;
}

void add4(int a, int b) {
  int raw = (a & 0xF) + (b & 0xF);
  int result = raw & 0xF;
  int rsign = to_signed4(result);
  int ov = detect_overflow(a, b, result);

  printf("A = %+d (%04d)  B = %+d (%04d)\n", a, to_binary4(a), b,
         to_binary4(b));
  printf("Result bits: %04d  =>  signed: %+d\n", to_binary4(result), rsign);
  printf("Overflow: %s\n\n", ov ? "YES" : "no");
}

int main() {
  printf(" 4-bit signed addition \n\n");
  add4(3, 4);
  return 0;
}
