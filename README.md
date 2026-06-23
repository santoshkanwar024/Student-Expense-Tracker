# Student Expense Tracker

## Overview
Student Expense Tracker is a console-based application developed in C++ to help students record, manage, and analyze their daily expenses. The application stores expense records in a CSV file and automatically loads previously saved data when it starts.

## Features
- Add Expense
- Automatic Expense ID Generation
- View Expenses
- Edit Expense
- Delete Expense
- Search Expenses by Category
- Total Expense Calculation
- Category-wise Expense Report
- CSV File Storage (`expense.csv`)
- Automatic Data Loading
- Console-based Menu Driven Application

## Technologies Used
- C++
- Object-Oriented Programming (OOP)
- File Handling
- STL (`vector`, `map`)
- `stringstream`
- `iomanip`

## How to Run

### Compile

```bash
g++ main.cpp -o expense
```

### Run

```bash
./expense
```

> **Note (Windows):**
> If you are using MinGW on Windows, run:

```bash
expense.exe
```

## Project Structure

```
Student-Expense-Tracker/
│── main.cpp
│── README.md
│── .gitignore
│── docs/
│   └── Project_Description.md
└── tests/
    └── test_cases.md
```

## Future Enhancements
- Search Expense by ID
- Monthly Expense Report
- Expense Sorting (Date/Amount)
- Budget Limit Warning
- Student Pocket Money Management
- Borrow/Lend Tracking
- GUI-Based Interface
- Database Integration (MySQL/SQLite)