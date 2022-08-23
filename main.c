#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t s_len;
  char  *ret;
  s_len = strlen(s);
  if (s_len <= start || len == 0 || s_len == 0) return ((char *)calloc(1, 1));
  if (len > s_len - start) len = s_len - start;
  ret = (char *)malloc(sizeof(char) * (len + 1));
  if (ret == 0) return (0);
  strlcpy(ret, s + start, len + 1);
  return (ret);
}
int main() {
  const char *a = "c:\\abc\\bbb\\ccc";
  size_t      s = strlen(a);
  while (s > 0) {
    if (a[s] == '\\') printf("%s\n", ft_substr(a, s + 1, strlen(a) - s));
    s--;
  }
}
