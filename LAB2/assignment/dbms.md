# Mini Database Engine

## OBJECTIVE
Design and implement a simplified SQL-like in-memory
database engine in C++.

The system must support table creation, data insertion,
basic querying, and file persistence.

---

## CONCEPTS COVERED
- OOP (Classes, Encapsulation)
- Pointers and Dynamic Memory
- File Handling (fstream)
- Arrays
- Vectors
- Bitwise Operators
- Constraint Validation

---

## FUNCTIONAL REQUIREMENTS

### 1) CREATE TABLE

Allow user to create a table with:
- Table name
- Multiple columns

Each column must contain:
- Name
- Data type (int / string)
- Constraint flags (bitwise)

Example command:

```text
CREATE TABLE users
```

---

### 2) COLUMN CONSTRAINTS (BITWISE FLAGS)

Use unsigned int to store column constraints.

Bit Flags:

```text
1 -> Primary Key
2 -> Not Null
4 -> Unique
```

Example:

```text
Primary Key + Not Null = 1 | 2
```

You must:
- Use bitwise OR to set flags
- Use bitwise AND to check flags
- Prevent violations during insert

---

### 3) INSERT

Allow insertion of rows dynamically.

Example:

```text
INSERT INTO users VALUES (1, Ali, 20)
```

Each row must:
- Be dynamically allocated using new
- Be stored using vector<Row*>

---

### 4) SELECT

Support:

```text
SELECT * FROM users
```

Display all records in table format.

---

### 5) FILE HANDLING

Implement:
- SAVE TO FILE
- LOAD FROM FILE

File format example:

```text
TABLE users
id int 3
name string 2
age int 0
DATA
1 Ali 20
2 Sara 21
```

Where:
- 3 = PrimaryKey + NotNull
- 2 = NotNull
- 0 = No constraint

You must:
- Write structure + data to file
- Load structure + data correctly

---

### 6) CLASS STRUCTURE REQUIREMENT

You must implement at least the following classes:

```cpp
class Column
{
string name;
string type;
unsigned int constraints;
};

class Row
{
vector<string> values;
};

class Table
{
string tableName;
vector<Column> columns;
vector<Row*> rows;
};
```

---

### 7) ARRAY USAGE

Use fixed-size arrays for:
- Query parsing buffer
- Temporary command storage

Example:

```cpp
char buffer[256];
```

---

### 8) MEMORY MANAGEMENT
- All rows must be allocated dynamically.
- Implement destructor in Table class.
- Free all allocated memory.
- No memory leaks allowed.

---

## ADVANCED EXTENSIONS (BONUS)
1) WHERE clause support
2) DELETE command
3) Prevent duplicate primary keys
4) Implement simple indexing
5) Multi-table support

---

## CONSTRAINTS
- Do NOT use external database libraries.
- Do NOT use STL map/set for primary key checking.
- Must rely on vectors + manual validation.
- Must use bitwise operators explicitly.

---

## EXPECTED OUTPUT SAMPLE

```text
CREATE TABLE users
Table created successfully.

INSERT INTO users VALUES (1, Ali, 20)
Record inserted.

SELECT * FROM users

ID Name Age
1 Ali 20
```

---

## EVALUATION CRITERIA
- Proper OOP design
- Correct bitwise usage
- Proper memory management
- Correct file persistence
- Clean modular code
- No memory leaks

---

## END