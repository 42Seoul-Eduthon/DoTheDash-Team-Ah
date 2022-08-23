#include <stdio.h>
#include <windows.h>
​
int main() {
  const char *a = "c:\\abc\\bbb\\ccc";
  int         s = strlen(a);
​
  while (s > 0) {
    if (a[s] == '\\') printf("%s\n", substr(a, s + 1, strlen(a) - s));
  }
}
