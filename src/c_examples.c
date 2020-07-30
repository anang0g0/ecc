#include "bigint.h"

#include <stdio.h>

int main(){
    char buf[65536];

    /* neat trick to avoid having to write &a, &b, &c everywhere */
    bigint a[1], b[1], c[1];

    /* bigints have to be initialized (same as memset'ed to zero) */
    bigint_init(a);
    bigint_init(b);
    bigint_init(c);

    /* create bigint from string */
    bigint_from_str(a, "12345678900000000000000000000000003");
    //  bigint_from_str(a, "0xff");
    bigint_from_str(b, "98765432100000000000000000000000001");
    
    /* c = a * b */
    /* first parameter is destination parameter */
    bigint_mul(c, a, b);

    /* write and print */
    puts(bigint_write(buf, sizeof(buf), c));

    /* bigints have to be free'd */
    bigint_free(a);
    bigint_free(b);
    bigint_free(c);

    return 0;
}
