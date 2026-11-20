#include <stdio.h>
#include <math.h>
int gcd(int a, int b) {
   int temp;
   while (1) {
       temp = a % b;
       if (temp == 0)
           return b;
       a = b;
       b = temp;
   }
}
int main() {
   double p = 3, q = 7;
   double n = p * q; 
   double tot = (p - 1) * (q - 1); 
   double e = 2;
   while (e < tot) {
       if (gcd(e, tot) == 1)
           break;
       else
           e++;
   }
   double d;
   double k = 2; 
   d = (1 + (k * tot)) / e;
   double msg = 12;
   double c = fmod(pow(msg, e), n); 
   double m = fmod(pow(c, d), n); 
   printf("Message: %lf\n", msg);
   printf("Encrypted: %lf\n", c);
   printf("Decrypted: %lf\n", m);
   return 0;
}