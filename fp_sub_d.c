/* TomsFastMath, a fast ISO C bignum library.
 * 
 * This project is meant to fill in where LibTomMath
 * falls short.  That is speed ;-)
 *
 * This project is public domain and free for all purposes.
 * 
 * Tom St Denis, tomstdenis@iahu.ca
 */
#include <tfm.h>

/* c = a - b */
void fp_sub_d(fp_int *a, fp_digit b, fp_int *c)
{
   fp_int tmp;
   fp_set(&tmp, b);
   fp_sub(a, &tmp, c);
}