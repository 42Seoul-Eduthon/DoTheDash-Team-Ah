#define FT_USE_LITTLE_ENDIAN
#define FT_USE_64_BIT

#define FT_COMPARE(a, b) ((a) == (b))

#if defined(FT_USE_32_BIT)
  #define FT_HOST_CMP_IMPL(a, b) (FT_COMPARE((a) & 0xff, ((b) & (0xff << 24)) >> 24) && FT_COMPARE(((a) & (0xff << 8)) >> 8, ((b) & (0xff << 16)) >> 16) \
        && FT_COMPARE(((a) & (0xff << 16)) >> 16, ((b) & (0xff << 8)) >> 8) && FT_COMPARE(((a) & (0xff << 24)) >> 24, (b) & 0xff))
#else
  #define FT_HOST_CMP_IMPL(a, b) (FT_COMPARE((a) & 0xff, ((b) & (0xff << 56)) >> 56) && FT_COMPARE(((a) & (0xff << 8)) >> 8, ((b) & (0xff << 48)) >> 48))
        // && FT_COMPARE(((a) & (0xff << 16)) >> 16, ((b) & (0xff << 40)) >> 40) && FT_COMPARE(((a) & (0xff << 24)) >> 24, ((b) & 0xff) >> 32) \
        // && FT_COMPARE(((a) & (0xff << 32)) >> 32, ((b) & (0xff << 24)) >> 24) && FT_COMPARE(((a) & (0xff << 40)) >> 40, ((b) & (0xff << 16)) >> 16) \
        // && FT_COMPARE(((a) & (0xff << 48)) >> 48, ((b) & (0xff << 8)) >> 8) && FT_COMPARE(((a) & (0xff << 56)) >> 56, (b) & 0xff))
#endif

#if defined(FT_USE_LITTLE_ENDIAN)
    #define hostcmp(a, b) FT_HOST_CMP_IMPL((a), (b))
#else
    #define hostcmp(a, b) ((a) == (b))
#endif

#include <stdio.h>
#include <arpa/inet.h>

int main() {
    unsigned long a, b;

    a = 8080; b = htonl(a);
    printf("%d\n", hostcmp(a, b));
}