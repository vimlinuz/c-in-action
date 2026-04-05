#include <stdio.h>

/**
 * Function: towerOfHanoi
 * --------------------
 * Implements the recursive logic to move n disks from source to destination.
 *
 * n: number of disks
 * from_peg: The source peg (e.g., 'A')
 * aux_peg: The auxiliary/buffer peg (e.g., 'B')
 * to_peg: The destination peg (e.g., 'C')
 */
void towerOfHanoi(int n, char from_peg, char aux_peg, char to_peg) {
  // 1. Base Case: If only 1 disk, move it directly from Source to Destination
  // [4, 5].
  if (n == 1) {
    printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
    return;
  }

  // 2. Recursive Step 1: Move n-1 disks from Source to Auxiliary [Conversation
  // History]. Note: Here, Destination becomes the temporary 'buffer'.
  towerOfHanoi(n - 1, from_peg, to_peg, aux_peg);

  // 3. Intermediate Step: Move the nth (largest) disk from Source to
  // Destination.
  printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);

  // 4. Recursive Step 2: Move the n-1 disks from Auxiliary to Destination.
  // Note: Here, Source becomes the temporary 'buffer'.
  towerOfHanoi(n - 1, aux_peg, from_peg, to_peg);
}

int main() {
  int n = 3; // Example with 3 disks (requires 2^n - 1 = 7 moves) [Conversation
             // History].
  printf("Steps to solve Tower of Hanoi with %d disks:\n", n);

  // Call the recursive function starting with pegs A, B, and C
  towerOfHanoi(n, 'A', 'B', 'C');

  return 0;
}
