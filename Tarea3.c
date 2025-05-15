/*@ 
  requires -10 <= i <= 10;
  requires -10 <= j <= 10;
  requires i * j + 2 * j + 3 * i == 0;
  ensures (i + 2) * (j + 3) == 6;
*/
void tarea(int i, int j) {
  j = j + 3;
  i = i + 2;
}

