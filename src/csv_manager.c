//
// Created by panda on 29/01/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "csv_manager.h"

int count_columns(const char* filename)
{
  FILE* file = fopen(filename, "r");

  if (file == NULL)
  {
    printf("Could not open file\n");
    return -1;
  }

  char line[5002];
  if (fgets(line, sizeof(line), file) == NULL)
  {
    printf("Could not read file\n");
    fclose(file);
    return -1;
  }

  int count = 0;
  for (int i = 0; line[i]; i++) if (line[i] == ',') count ++;

  return count;
}

void read_all_lines(const char* filename)
{
  FILE* file = fopen(filename, "r");

  if (file == NULL)
  {
    printf("Could not open file\n");
    return;
  }

  char* line;
  while ((line = read_line(file)) != NULL)
  {
    printf("%s", line);
    free(line);
  }

  fclose(file);
}

char* read_line(FILE* file)
{
  char* line = malloc(MAX_LINE_SIZE * sizeof(char));
  if (fgets(line, MAX_LINE_SIZE, file) == NULL)
  {
    free(line);
    return NULL;
  }

  return line;
}
