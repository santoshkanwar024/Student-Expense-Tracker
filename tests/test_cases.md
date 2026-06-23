# Student Expense Tracker - Test Cases

## Test Case 1
### Feature: Add Expense

**Input:**
- Date: 21-06-2026
- Category: Food
- Description: Lunch at Canteen
- Amount: 150

**Expected Result:**
- A new expense should be added successfully.
- A unique Expense ID should be generated automatically.
- Data should be saved in `expense.csv`.


## Test Case 2
### Feature: View Expenses

**Expected Result:**
- All saved expenses should be displayed in a properly formatted table with:
  - ID
  - Date
  - Category
  - Description
  - Amount


## Test Case 3
### Feature: Edit Expense

**Input:**
- Existing Expense ID

**Expected Result:**
- Existing expense details should be displayed.
- User should be able to modify the details.
- Updated data should be saved to `expense.csv`.


## Test Case 4
### Feature: Delete Expense

**Input:**
- Existing Expense ID

**Expected Result:**
- Selected expense should be deleted successfully.
- Updated data should be saved to `expense.csv`.


## Test Case 5
### Feature: Total Expense

**Expected Result:**
- Sum of all expense amounts should be displayed correctly.


## Test Case 6
### Feature: Category-wise Report

**Expected Result:**
- Expenses should be grouped by category.
- Total amount spent in each category should be displayed.


## Test Case 7
### Feature: Search by Category

**Input:**
- Category: Food

**Expected Result:**
- All expenses belonging to the "Food" category should be displayed.
- If no matching category exists, display:
  - "No expense found in this category."


## Test Case 8
### Feature: Automatic Expense ID Generation

**Expected Result:**
- Every new expense should receive a unique ID automatically.
- User should not be asked to enter an Expense ID.
- Deleted IDs should not be reused.


## Test Case 9
### Feature: CSV File Loading

**Expected Result:**
- Previously saved expense records should be loaded automatically when the application starts.


## Test Case 10
### Feature: CSV File Saving

**Expected Result:**
- Every Add, Edit, or Delete operation should update the `expense.csv` file automatically.