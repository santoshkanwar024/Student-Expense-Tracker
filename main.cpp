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
   void viewExpenses();
   void deleteExpense();
   void categoryReport();
   void totalExpense();
   void saveToFile();
   void loadFromFile();
};

void ExpenseManager::saveToFile(){
   ofstream file ("expense.txt");

   for (auto e : expenses){
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

   cout<<"Enter ID: ";
   cin>>e.id;

   cout<<"Enter Date: ";
   cin>>e.date;

  cout<<"Enter Category: ";
   cin>>e.category;

  cout<<"Enter Description: ";
   cin>>e.description;

  cout<<"Enter Amount: ";
   cin>>e.amount;

   expenses.push_back(e);

   saveToFile();
   cout<<"Expense added successfully!"<<endl;

}

void ExpenseManager::loadFromFile(){
   ifstream file("expense.txt");

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

   for(auto e : expenses){
      cout<<left
         << setw(5) <<e.id
         << setw(15) <<e.date
         << setw(15) <<e.category
         << setw(20) <<e.description
         << setw(10) <<e.amount
         <<endl;
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

   for (auto e : expenses){
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

   for(auto e : expenses){
      report[e.category] += e.amount;
   }

   cout<<"\n ===== Category Wise Report ===== \n\n";

   for (auto item : report){
      cout<<left
          <<setw(15) << item.first
          <<" :Rs."
          <<item.second
          <<endl;
   }
}


int main(){
   ExpenseManager manager;

   manager.loadFromFile();

   int choise;

   while(true){

      cout<<"\n ===== Student Expense Tracker ===== \n";
      cout<<"1. Ad Expense\n";
      cout<<"2. View Expense\n";
      cout<<"3. Delete Expense\n";
      cout<<"4. Total Expenses\n";
      cout<<"5. Catagory Report\n";
      cout<<"6. Exit\n";

      cout<<"Enter Choise: ";
      cin>>choise;

      switch(choise){
         case 1:
           manager.addExpense();
           break;

         case 2 :
           cout<<"\n Viewing Expenses...\n";
           manager.viewExpenses();
           break;

         case 3 :
           manager.deleteExpense();
           break;
      
         case 4 :
           manager.totalExpense();
           break;
         
         case 5 :
           manager.categoryReport();
           break;

         case 6 :
           cout<<"Existing Program..."<<endl;
           return 0;

         default:
           cout<<"Invalid Choice!"<<endl;
      }
   }

}