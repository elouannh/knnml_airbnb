#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
29/01/2024
@author: Elouann HOSTA
"""
import random

# The columns of the CSV file.
# Each value determines the type, and the parameters for the main loop.
columns: dict = {
    "id": ("int", "index"),
    "price": ("float", 20, 100),
    "rooms": ("int", 1, 4),
    "accommodates": ("int", 1, 8),
    "cleaning_fee": ("float", 40, 200),
    "latitude": ("float", -90, 90),
    "longitude": ("float", -180, 180)
}

# We generate the CSV file with each column.
with open("res/rawdict.csv", "w") as csv_file:
    for column_key in columns.keys():
        csv_file.write(f"{column_key}{',' if column_key == list(columns.keys())[-1] else '\\n'}")

# The number of entries in the CSV file.
entries: int = 5000

# We generate the CSV file with each column.
with open("res/rawdict.csv", "w") as csv_file:
    csv_file.write(','.join(columns.keys()) + '\n')  # Write the column headers

    for i in range(entries):
        # The row of the dict.
        entry_definition: list = []

        # For each column, we generate a random value using the parameters. 
        for column_key, column_value in columns.items():
            entry = None

            # We apply the effects for each possibility.
            if column_value[0] == "int":
                if column_value[1] == "index":
                    entry = i
                elif len(column_value) == 3:
                    entry = random.randint(column_value[1], column_value[2])
            elif column_value[0] == "float":
                if len(column_value) == 3:
                    entry = random.uniform(column_value[1], column_value[2])

            # We add the value to the CSV file.
            entry_definition.append(entry)

        # We write the entry into the CSV.
        csv_file.write(','.join(map(str, entry_definition)) + '\n')