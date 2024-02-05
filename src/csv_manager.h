//
// Created by panda on 29/01/2024.
//

#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#define MAX_LINE_SIZE 2048

/**
 * \brief Returns the number of columns included into a CSV file.
 * \param filename The file name.
 * \return The number of columns.
 */
int count_columns(const char* filename);

/**
 * \brief Read a file and returns the content of each lines.
 * \param filename The file name.
 * \return Nothing.
 */
void read_all_lines(const char* filename);

/**
 * \brief Read a file and returns a line content.
 * \param file The file where the line is.
 * \return The content of the line.
 */
char* read_line(FILE* file);

#endif //CSV_MANAGER_H
