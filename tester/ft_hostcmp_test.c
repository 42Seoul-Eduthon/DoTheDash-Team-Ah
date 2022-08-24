#if defined __APPLE__
#include <arpa/inet.h>
#elif defined _WIN32
#include <Winsock2.h>
#endif
#include <stdlib.h>
#include <stdio.h>

void check(size_t a, size_t b, int expect_same);

#if defined(TEST1)

#define FT_USE_32_BIT
#define FT_USE_LITTLE_ENDIAN
#include "FT_HOSTCMP.h"

int main() {


    check(8080, htonl(8080), 1);
    check(8080, 8080, 0);
    check(htonl(8080), 8080, 1);
    check(0, 0, 1);
    check(UINT32_MAX, UINT32_MAX, 1);
    check(5, 5, 0);
    check(8080, 0x901f000000000000, 0);
    #undef FT_USE_32_BIT
    #undef FT_USE_LITTLE_ENDIAN

    return 0;
}
#endif

#if defined(TEST2)
    #define FT_USE_64_BIT
    #define FT_USE_LITTLE_ENDIAN

    check(8080, htonl(8080), 0);
    check(8080, 8080, 0);
    check(htonl(8080), 8080, 0);
    check(0, 0, 1);
    check(UINT32_MAX, UINT32_MAX, 0);
    check(5, 5, 0);
    check(8080, 0x901f000000000000, 1);


    #define FT_USE_32_BIT
    #define FT_USE_BIG_ENDIAN

    check(8080, htonl(8080), 0);
    check(8080, 8080, 1);
    check(htonl(8080), 8080, 0);
    check(0, 0, 1);
    check(UINT32_MAX, UINT32_MAX, 1);
    check(5, 5, 1);
    check(8080, 0x901f000000000000, 0);

    #undef FT_USE_32_BIT
    #undef FT_USE_BIG_ENDIAN

    #define FT_USE_64_BIT
    #define FT_USE_BIG_ENDIAN

    check(8080, htonl(8080), 0);
    check(8080, 8080, 1);
    check(htonl(8080), 8080, 0);
    check(0, 0, 1);
    check(UINT32_MAX, UINT32_MAX, 1);
    check(5, 5, 1);
    check(8080, 0x901f000000000000, 0);

    #undef FT_USE_64_BIT
    #undef FT_USE_BIG_ENDIAN
}
#endif

void check(size_t a, size_t b, int expect_same) {
    if ((expect_same && (FT_HOSTCMP(a, b) != 0)) || (!expect_same && (FT_HOSTCMP(a, b) == 0)))
        exit(EXIT_FAILURE);
}
