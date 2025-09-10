
# Qt-Tests

A simple Qt Core application for exploring Qt database operations and unit testing.

## Features

- **Database Wrapper:**  
  Provides functions to interact with a SQL database:
  - Select all records
  - Insert records
  - Delete records

- **Unit Tests:**  
  Uses Qt's testing framework to verify database functionality:
  - Checks expected record counts
  - Tests unique record insertion
  - Tests record deletion

## Project Structure

```
├── CMakeLists.txt
├── database.cpp
├── database.h
├── databasetest.cpp
├── databasetest.h
├── main.cpp
├── README.md
└── .gitignore
```

## Building

This project uses CMake and Qt 6.5+.  
To build:

```sh
cmake -S . -B build
cmake --build build
```

## Running Tests

After building, run the executable to execute the unit tests:

```sh
./build/Qt-Tests
```

## Requirements

- Qt 6.5 or newer (Core, Sql, Test modules)
- CMake 3.19+

## Notes

- The database connection parameters (driver, name, table) are currently set as empty strings in the test class.  
  Update these values in `DatabaseTest` for your environment.
- The application is a work in progress.
