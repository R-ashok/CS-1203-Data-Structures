#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[7];
    int a, b, c, d, e, f, g, h;
    //variables a to h represent rows 0 to 7 or 1 to 8, Their values will represent the column on which the row has a queen places.
int k=1;
    for (a = 0; a < 8; a++) {
        arr[0] = a;
        for (b = 0; b < 8; b++) {
            if (b != a && abs(a - b) != 1) {
                //if two numbers are not equal that means they dont fall on the same column.
                arr[1] = b;
                for (c = 0; c < 8; c++) {
                    if (c != a && c != b && abs(a - c) != 2 && abs(b - c) != 1) {
                        //if the absolute ie |x| notation of the difference between two columns is equal to the difference between their rows then they will diagonally colide and thus are filtered out.
                        arr[2] = c;
                        for (d = 0; d < 8; d++) {
                            if (d != a && d != b && d != c && abs(a - d) != 3 && abs(b - d) != 2 && abs(c - d) != 1) {
                                //making sure that the columns are checked before the diagonals increases efficiency.
                                arr[3] = d;
                                for (e = 0; e < 8; e++) {
                            if (e != a && e != b && e != c && e != d && abs(a - e) != 4 && abs(b - e) != 3 && abs(c - e) != 2 && abs(d - e) != 1) {
                                        arr[4] = e;
                                        for (f = 0; f < 8; f++) {
                            if (f != a && f != b && f != c && f != d && f != e && abs(a - f) != 5 && abs(b - f) != 4 && abs(c - f) != 3 && abs(d - f) != 2 && abs(e - f) != 1) {
                                                arr[5] = f;
                                                for (g = 0; g < 8; g++) {
                            if (g != a && g != b && g != c && g != d && g != e && g != f && abs(a - g) != 6 && abs(b - g) != 5 && abs(c - g) != 4 && abs(d - g) != 3 && abs(e - g) != 2 && abs(f - g) != 1) {
                                                        arr[6] = g;
                                                        for (h = 0; h < 8; h++) {
                                                            if (h != a && h != b && h != c && h != d && h != e && h != f && h != g && abs(a - h) != 7 && abs(b - h) != 6 && abs(c - h) != 5 && abs(d - h) != 4 && abs(e - h) != 3 && abs(f - h) != 2 && abs(g - h) != 1) {
                                                                arr[7] = h;

                                                                // Output valid permutation
                            printf("Solution %d:\n",k);
                                    k++;
                             for (int i = 0; i < 8; i++) {
                             for(int j=0; j<8; j++){
                                                                    if(j==arr[i]){
                                    printf(" Q |");}                else
                                    {printf(" _ |");}
                                    }
                                   printf("\n");
                                    }
                                  printf("\n\n");
                                                            }//total of 92 results printed
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

//note: Neatness of output displayed is relient on the fact that the display keeps the size of Q and _ equal. In my compiler it does but other compilers dont do the exact same which affects the neatness. 
