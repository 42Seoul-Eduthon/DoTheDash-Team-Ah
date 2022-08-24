#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined _WIN32
#define DELIMITER '\\'
#elif defined __APPLE__
#define DELIMITER '/'
#elif defined __linux__
#define DELIMITER '/'
#else
#define DELIMITER -1
#endif

char* ft_get_filename(const char* path) {
  char*  filename = NULL;
  char*  last_delimiter = NULL;
  size_t pos;
  if (path == NULL) {
    return NULL;
  }
  last_delimiter = strrchr(path, DELIMITER);
  if (last_delimiter == NULL) {
    return NULL;
  }
  pos = strlen(last_delimiter);
  if (pos == 1) {
    return NULL;
  }
  filename = malloc(pos + 1);
  if (filename == NULL) {
    return NULL;
  }
  strcpy(filename, last_delimiter + 1);
  return filename;
}