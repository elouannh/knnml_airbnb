//
// Created by panda on 30/01/2024.
//

#include <string.h>
#include <stdlib.h>
#include "csv_manager.h"
#include "knnml.h"


char** split_line_by_comma(char* line)
{
  char** result = malloc(MAX_LINE_SIZE * sizeof(char*));
  int i = 0;

  const char* token = strtok(line, ",");
  while (token != NULL)
  {
    result[i] = malloc(strlen(token) + 1);
    strcpy(result[i], token);
    i++;
    token = strtok(NULL, ",");
  }
  result[i] = NULL;

  return result;
}