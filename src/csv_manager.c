//
// Created by panda on 29/01/2024.
//

#include <stdio.h>
#include "csv_manager.h"

int count_columns(const char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("Could not open file\n");
    return -1;
  }

  char line[5002];
  if (fgets(line, sizeof(line), file) == NULL) {
    printf("Could not read file\n");
    fclose(file);
    return -1;
  }

  int count = 0;
  for (int i = 0; line[i]; i++) if (line[i] == ',') count ++;

  return count;
}
