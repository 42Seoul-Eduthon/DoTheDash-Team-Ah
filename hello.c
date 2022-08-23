#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined __WINDOWS__
#define DELIMITER '\\'
#elif defined __APPLE__
#define DELIMITER '/'
#elif defined __linux__
#define DELIMITER '/'
#endif

char* ft_get_filename(const char* path) {
  char* filename = NULL;
  char* last_delimiter = NULL;
  if (path == NULL) {
    return NULL;
  }
  last_delimiter = strrchr(path, DELIMITER);
  if (last_delimiter == NULL) {
    return NULL;
  }
  filename = malloc(strlen(last_delimiter) + 1);
  if (filename == NULL) {
    return NULL;
  }
  strcpy(filename, last_delimiter + 1);
  return filename;
}

int main() {
  char* filename = ft_get_filename("/Users/username/Desktop/test.c");
  char* win_name = ft_get_filename("C:\\Users\\username\\Desktop\\test.c");
  printf("%s\n", filename);
  printf("%s\n", win_name);
  free(filename);
  free(win_name);
}