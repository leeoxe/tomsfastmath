/* Generates squaring comba code... it learns it knows our secrets! */
#include <stdio.h>

int main(int argc, char **argv)
{
   int x, y, z, N;
   N = atoi(argv[1]);

printf(
"void fp_sqr_comba%d(fp_int *A, fp_int *B)\n"
"{\n"
"   fp_word t;\n"
"   fp_digit *a, b[%d], c0, c1, c2;\n"
"\n"
"   a = A->dp;\n"
"   COMBA_START; \n"
"\n"
"   /* clear carries */\n"
"   CLEAR_CARRY;\n"
"\n"
"   /* output 0 */\n"
"   SQRADD(a[0],a[0]);\n"
"   COMBA_STORE(b[0]);\n", N, N+N);

   for (x = 1; x < N+N-1; x++) {
printf(
"\n   /* output %d */\n"
"   CARRY_FORWARD;\n   ", x);
       for (y = 0; y < N; y++) {
           for (z = 0; z < N; z++) {
               if (y<=z && (y+z)==x) {
                  if (y == z) { 
                     printf("SQRADD(a[%d], a[%d]); ", y, y);
                  } else {
                     printf("SQRADD2(a[%d], a[%d]); ", y, z);
                  }
               }
           }
       }
printf("\n   COMBA_STORE(b[%d]);\n", x);
   }
printf("   COMBA_STORE2(b[%d]);\n", N+N-1);

printf(
"   COMBA_FINI;\n"
"\n"
"   B->used = %d;\n"
"   B->sign = FP_ZPOS;\n"
"   memcpy(B->dp, b, %d * sizeof(fp_digit));\n"
"   fp_clamp(B);\n"
"}\n\n\n", N+N, N+N);

  return 0;
}