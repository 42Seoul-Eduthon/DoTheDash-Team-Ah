#include <stdio.h>

#define CNT_TEST 10

char* ft_get_filename(const char* path);

int main() {
  const char* testcase[CNT_TEST] = {"C:\\Documents\\Newsletters\\article.pdf",
                                    "C:\\Program files\\foo\\bar.exe",
                                    "C:\\Program files\\Downloads\\index.html",
                                    "C:\\Program files\\Downloads\\",
                                    "/Users/Me/for_test",
                                    "/Users/Me/Downloads/index.html",
                                    "/usr/share/doc/bash/article.pdf",
                                    "/usr/share/doc/bash/article list.pdf",
                                    "/usr/share/",
                                    ""};

  for (int i = 0; i < CNT_TEST; i++) {
    char* filename = ft_get_filename(testcase[i]);
    printf("[Test case %d]\n\t%s\n", i, filename);
  }
}