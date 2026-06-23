#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<map>
using namespace std;

class Expense{
public:
   int id;
   string date;
   string category;
   string description;
   double amount;

};

class ExpenseManager{
private:
   vector<Expense> expenses;

public:
   void addExpense();
   void saveToFile();
   void loadFromFile();
   void viewExpenses();
   void editExpense();
   void deleteExpense();
   void totalExpense();
   void categoryReport();
   void searchByCategory();
   int getNextId();
};

int ExpenseManager::getNextId()
{
    int maxId = 0;

    for(const auto &e : expenses)
    {
        if(e.id > maxId)
        {
            maxId = e.id;
        }
    }

    return maxId + 1;
}


void ExpenseManager::saveToFile(){
   ofstream file("expense.csv");

   if(!file){
    return;
   }

   for (const auto &e : expenses){
    file<< e.id<<","
        << e.date<<","
        << e.category<<","
        << e.description<<","
        << e.amount<<endl;
   }

   file.close();

}



void ExpenseManager::addExpense(){
   Expense e;

   e.id = getNextId();
   cout<<"Expense ID generated successfully: "<<e.id<<endl;

   cout<<"Enter Date: ";
   cin>>e.date;

   cout<<"Enter Category: ";
   cin>>e.category;

   cin.ignore();

   cout<<"Enter Description: ";
   getline(cin, e.description);

   cout<<"Enter Amount: ";
   cin>>e.amount;

   expenses.push_back(e);

   saveToFile();
   cout<<"Expense added successfully!"<<endl;

}

void ExpenseManager::loadFromFile(){
   ifstream file("expense.csv");

   if(!file){
    return;
   }

   string line;

   while(getline(file,line)){
    stringstream ss(line);

    Expense e;
    string temp;

    getline (ss, temp ,',');
    e.id = stoi (temp);

    getline (ss, e.date, ',');

    getline(ss, e.category, ',');

    getline(ss, e.description, ',');

    getline(ss, temp ,',');
    e.amount = stod (temp );

    expenses.push_back(e);
   }

   file.close();

}



void ExpenseManager::viewExpenses(){
   if(expenses.empty()){
      cout<<"No expenses found!"<<endl;
      return;
   }

   cout<<"\n";

   cout<<left
       << setw(5) <<"ID"
       << setw(15) <<"Date"
       << setw(15) <<"Category"
       << setw(20) <<"Description"
       << setw(10) <<"Amount"
       <<endl;

   cout<<"---------------------------------------------------------------"<<endl;

   for(const auto &e : expenses){
      cout<<left
         << setw(5) <<e.id
         << setw(15) <<e.date
         << setw(15) <<e.category
         << setw(20) <<e.description
         << setw(10) <<e.amount
         <<endl;
   }
}

void ExpenseManager::editExpense()
{
    int editId;

    cout<<"Enter Expense ID to edit: ";
    cin>>editId;

    bool found = false;

    for(auto &e : expenses)
    {
        if(e.id == editId)
        {
            found = true;

            cout<<"\nCurrent Details\n";
            cout<<"Date: "<<e.date<<endl;
            cout<<"Category: "<<e.category<<endl;
            cout<<"Description: "<<e.description<<endl;
            cout<<"Amount: "<<e.amount<<endl;

            cout<<"\nEnter New Date: ";
            cin>>e.date;

            cout<<"Enter New Category: ";
            cin>>e.category;

            cin.ignore();

            cout<<"Enter New Description: ";
            getline(cin, e.description);

            cout<<"Enter New Amount: ";
            cin>>e.amount;

            saveToFile();

            cout<<"\nExpense updated successfully!"<<endl;

            break;
        }
    }

    if(!found)
    {
        cout<<"Expense ID not found!"<<endl;
    }
}


void ExpenseManager::deleteExpense(){
   int deleteId;

   cout<<"Enter Expense ID to delete: ";
   cin>>deleteId;

   bool found = false;

   for (int i = 0 ; i< expenses.size(); i++){
      if (expenses[i].id == deleteId){
         expenses.erase(expenses.begin() + i);

         found = true;

         saveToFile();
         cout<<"Expense deleted successfully!"<<endl;
         break;
      }
   }

   if (!found){
      cout<<"Expense ID not found!"<<endl;
   }
}

void ExpenseManager::totalExpense(){
   double total = 0;

   for (const auto &e : expenses){
      total += e.amount ;
   }

   cout<<"\n Total Expense = Rs."<<total<<endl;
}

void ExpenseManager::categoryReport(){
   if(expenses.empty()){
      cout<<"No Expenses Found!"<<endl;
      return;
   }

   map<string,double>report;

   for(const auto &e : expenses){
      report[e.category] += e.amount;
   }

   cout<<"\n ===== Category Wise Report ===== \n\n";

   for (const auto &item : report){
      cout << left
          << setw(20) << item.first
          << "Rs. "
          << item.second << endl;
   }
}

void ExpenseManager::searchByCategory()
{
    if(expenses.empty())
    {
        cout << "No expenses found!" << endl;
        return;
    }

    string searchCategory;
    bool found = false;

    cout << "Enter Category: ";
    cin >> searchCategory;

    cout << "\n";

    cout << left
         << setw(5) << "ID"
         << setw(15) << "Date"
         << setw(15) << "Category"
         << setw(20) << "Description"
         << setw(10) << "Amount"
         << endl;

    cout << "---------------------------------------------------------------" << endl;

    for(const auto &e : expenses)
    {
        if(e.category == searchCategory)
        {
            cout << left
                 << setw(5) << e.id
                 << setw(15) << e.date
                 << setw(15) << e.category
                 << setw(20) << e.description
                 << setw(10) << e.amount
                 << endl;

            found = true;
        }
    }

    if(!found)
    {
        cout << "No expense found in this category." << endl;
    }
}


int main(){
   ExpenseManager manager;

   manager.loadFromFile();

   int choice;

   while(true){

      cout<<"\n ===== Student Expense Tracker ===== \n";
      cout<<"1. Add Expense\n";
      cout<<"2. View Expense\n";
      cout<<"3. Edit Expense\n";
      cout<<"4. Delete Expense\n";
      cout<<"5. Total Expenses\n";
      cout<<"6. Category Report\n";
      cout<<"7. Search by Category\n";
      cout<<"8. Exit\n";

      cout<<"Enter Choice: ";
      cin>>choice;

      switch(choice){
         case 1:
           manager.addExpense();
           break;

         case 2 :
           cout<<"\n Viewing Expenses...\n";
           manager.viewExpenses();
           break;

         case 3:
           manager.editExpense();
           break;

         case 4:
           manager.deleteExpense();
           break;
      
         case 5 :
           manager.totalExpense();
           break;
         
         case 6 :
           manager.categoryReport();
           break;
         case 7 :
           manager.searchByCategory();
           break;

         case 8 :
           cout<<"Exiting Program..."<<endl;
           return 0;

         default:
           cout<<"Invalid Choice!"<<endl;
      }
   }

}