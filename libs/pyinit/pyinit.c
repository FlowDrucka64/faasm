#include "faasm/pyinit.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <string.h>
#include <locale.h>
#include <setjmp.h>
#include <math.h>
#include <complex.h>

#define FORCE_LINK(func) fprintf(devNull, "%p", func)

// Link all trig functions
#define FORCE_LINK_TRIGONOMETRY(sfx) \
    fprintf(devNull, "%p", sin##sfx); \
    fprintf(devNull, "%p", cos##sfx); \
    fprintf(devNull, "%p", tan##sfx); \
    fprintf(devNull, "%p", asin##sfx); \
    fprintf(devNull, "%p", acos##sfx); \
    fprintf(devNull, "%p", atan##sfx); \
    fprintf(devNull, "%p", csin##sfx); \
    fprintf(devNull, "%p", ccos##sfx); \
    fprintf(devNull, "%p", ctan##sfx); \
    fprintf(devNull, "%p", casin##sfx); \
    fprintf(devNull, "%p", cacos##sfx); \
    fprintf(devNull, "%p", catan##sfx); \
    fprintf(devNull, "%p", sinh##sfx); \
    fprintf(devNull, "%p", cosh##sfx); \
    fprintf(devNull, "%p", tanh##sfx); \
    fprintf(devNull, "%p", asinh##sfx); \
    fprintf(devNull, "%p", acosh##sfx); \
    fprintf(devNull, "%p", atanh##sfx); \
    fprintf(devNull, "%p", csinh##sfx); \
    fprintf(devNull, "%p", ccosh##sfx); \
    fprintf(devNull, "%p", ctanh##sfx); \
    fprintf(devNull, "%p", casinh##sfx); \
    fprintf(devNull, "%p", cacosh##sfx); \
    fprintf(devNull, "%p", catanh##sfx); \

// Logs
#define FORCE_LINK_LOGS(sfx) \
    fprintf(devNull, "%p", log##sfx); \
    fprintf(devNull, "%p", log10##sfx); \
    fprintf(devNull, "%p", log1p##sfx); \
    fprintf(devNull, "%p", log2##sfx); \
    fprintf(devNull, "%p", clog##sfx); \

// Misc
#define FORCE_LINK_MATHS(sfx) \
    fprintf(devNull, "%p", modf##sfx); \
    fprintf(devNull, "%p", fmod##sfx); \
    fprintf(devNull, "%p", exp##sfx); \
    fprintf(devNull, "%p", exp2##sfx); \
    fprintf(devNull, "%p", expm1##sfx); \
    fprintf(devNull, "%p", frexp##sfx); \
    fprintf(devNull, "%p", cabs##sfx); \
    fprintf(devNull, "%p", nextafter##sfx); \
    fprintf(devNull, "%p", cabs##sfx); \
    fprintf(devNull, "%p", cpow##sfx); \
    fprintf(devNull, "%p", csqrt##sfx); \
    fprintf(devNull, "%p", hypot##sfx); \
    fprintf(devNull, "%p", ldexp##sfx); \
    fprintf(devNull, "%p", pow##sfx); \
    fprintf(devNull, "%p", cbrt##sfx); \
    fprintf(devNull, "%p", ceil##sfx); \
    fprintf(devNull, "%p", floor##sfx); \
    fprintf(devNull, "%p", trunc##sfx); \
    fprintf(devNull, "%p", rint##sfx); \


void setUpPyNumpy() {
    FILE *devNull = fopen("/dev/null", "w");

    FORCE_LINK_TRIGONOMETRY();
    FORCE_LINK_TRIGONOMETRY(f);
    FORCE_LINK_TRIGONOMETRY(l);

    FORCE_LINK_LOGS();
    FORCE_LINK_LOGS(f);
    FORCE_LINK_LOGS(l);

    FORCE_LINK(abs);
    FORCE_LINK_MATHS();
    FORCE_LINK_MATHS(f);
    FORCE_LINK_MATHS(l);

    // I/O
    FORCE_LINK(scanf);
    FORCE_LINK(fscanf);
    FORCE_LINK(putchar);
    FORCE_LINK(sscanf);
    FORCE_LINK(fgetc);

    // Printing doubles
    FORCE_LINK(strtod);
    FORCE_LINK(strtold);

    const char *res = strpbrk("aabbcc", "bb");
    fprintf(devNull, "%s", res);
    FORCE_LINK(strcspn);

    // Locale
    FORCE_LINK(newlocale);
    FORCE_LINK(freelocale);
}
