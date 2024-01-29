//
// Created by panda on 29/01/2024.
//

#include <stdio.h>
#include "src/csv_manager.h"

int main() {
  const char* filename = "res/rawdict.csv";
  const int column_count = count_columns(filename);

  if (column_count >= 0)
    printf("The file has %d columns.", column_count);

  read_all_lines(filename);

  return 0;
}