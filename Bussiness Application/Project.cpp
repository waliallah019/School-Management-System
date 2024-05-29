// Header Files

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

// For Colored Text
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Declaration of Runtime Arrays and Variables
string user_accessing, user_accessing_designation, date[30], subjects[10], class_incharge[20];
int paidFees[50], paidSalaryTeacher[20], paidSalaryAdmin[10], current_user_index = 0, user_accessing_grade = 0;

// Declaration of Admin arrays and variables

string adminFirstName[10], adminLastName[10], admin_father_name[10], admin_gender[10], admin_cnic[10], admin_dob[10], admin_username[10], admin_password[10];
int admin_count = 0, admin_salary[10], adminId[10];

// Declaration of Teacher arrays and variables

string teacherFirstName[20], teacherLastName[20], teacher_father_name[20], announcements[10], teacher_username[20], teacherCnic[20], teacher_password[20], teacher_gender[20], teacher_qualification[20];
int teacherID[20], teacherClass[20], teacher_count = 0, teacher_salary[20], time_table[500];

// Declaration of Student arrays and variables

string studentFirstName[50], studentLastName[50], student_father_name[50], student_username[50], student_gender[50], student_password[50], student_dob[50], teacher_dob[20], father_profession[50];
int student_count = 0, studentClass[50], studentRollno[50], fees[50];

// Declaration of Time Table arrays and variables

string subjects1[100], starting_time1[100], ending_time1[100], subjects2[100], starting_time2[100], ending_time2[100], subjects3[100], starting_time3[100], ending_time3[100], subjects4[100], starting_time4[100], ending_time4[100], subjects5[100], starting_time5[100], ending_time5[100], subjects6[100], starting_time6[100], ending_time6[100];

// Declaration of Accounts related variables
int totalMoney = 0, expense_money[100], expense_count = 0;
string expense_type[100];
// prototypes of miscellaneous functions
void header();
void storeAnnouncements(int);
void loadAnnouncements();
int printLogin();
void adminMenu();
void storeStudentData();
void storeTeacherData();
void storeAdminData();
void storeTimeTableData();
void readTimeTableData();
void readStudentDataFromFile();
void readTeacherDataFromFile();
void readAdminDataFromFile();
string getField(string, int);
int getintField(string, int);
void updateTeachersData();
int doesStudentExist(int, int);
int doesTeacherExist(int);
int doesAdminExist(int);
bool isValidUsername(string userName);
int student_check(int, int);
int teacher_check(int);
int admin_check(int id);
int authentication(string, string);
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
int intValidation(int);
bool stringValidation(string);
void updateStudentsData();
void updateAdminsData();

// prototypes of Admin functions

void adminFunction(int);
int manageStudent(int);
int manageTeacher(int);
int manageAdmin(int);
int manageAccounts(int);
void addStudent();
void addTeacher();
void addAdmin();
void viewStudents();
void viewTeachers();
void viewAdmins();
void viewExpense();
bool deleteStudent();
bool deleteTeacher();
bool deleteAdmin();
bool deleteStudent();
bool deleteTeacher();
bool deleteAdmin();
// prototypes of Teacher functions
void teacherMenu();
int teacherFunction(int);
void update_timeTable();
void makeAnnouncement();

// prototypes of Student functions
void studentMenu();
int studentFunction(int);
void view_timeTable();
void viewAnnouncement();
// prototypes of Account related Functions
bool addMoney(int);
bool retrieveMoney(int);
void storeExpense();
void readExpense();
void storeTotal();
void readTotal();
// A variable that controls execution of program
bool execution = true;
int main()
{
  // Reading Data From Files
  readAdminDataFromFile();
  readStudentDataFromFile();
  readTeacherDataFromFile();
  readTimeTableData();
  readExpense();
  readTotal();
  loadAnnouncements();
  // Removing some Garbage value
  student_count--;
  teacher_count--;
  admin_count--;
  expense_count--;
  // This Loop will control the execution of program
  while (execution == true)
  {
    int login, ch;
    // Printing Login and Authentication
    login = printLogin();
    if (login == 1)
    {
      user_accessing_designation = "Admin";
      adminMenu();
    }
    else if (login == 2)
    {
      user_accessing_designation = "Teacher";
      user_accessing_grade = teacherClass[current_user_index];
      teacherMenu();
    }
    else if (login == 3)
    {
      user_accessing_designation = "Student";
      user_accessing_grade = studentClass[current_user_index];
      studentMenu();
    }
    else
    {
      SetConsoleTextAttribute(hConsole, 4);
      cout << "User not Found!" << endl;
      cout << "Press any key to continue...";
      getch();
      SetConsoleTextAttribute(hConsole, 15);
    }
  }
}
int printLogin()
{
  string pass;
  system("cls");
  header();
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                                Login Screen                              " << endl;
  cout << "                                                                                                                               " << endl;
  // Taking Login Information

  SetConsoleTextAttribute(hConsole, 3);
  cout << "Enter Username: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> user_accessing;
  SetConsoleTextAttribute(hConsole, 3);
  cout << "Enter Password: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> pass;
  // Authentication
  int c = authentication(user_accessing, pass);
  SetConsoleTextAttribute(hConsole, 15);
  return c;
}
int authentication(string user, string pass)
{
  for (int i = 0; i < student_count; i++)
  {
    if (user == student_username[i] && pass == student_password[i])
    {
      current_user_index = i;
      return 3;
    }
  }
  for (int i = 0; i < teacher_count; i++)
  {
    if (user == teacher_username[i] && pass == teacher_password[i])
    {
      current_user_index = i;
      return 2;
    }
  }
  for (int i = 0; i < admin_count; i++)
  {
    current_user_index = i;
    if (user == admin_username[i] && pass == admin_password[i])
    {
      return 1;
    }
  }
  if (user == "usama" && pass == "1111")
  {
    return 1;
  }
  else
  {
    return 4;
  }
}
void adminMenu()
{
  char ch;
  bool flag = true;
  while (flag == true)
  {
    system("cls");
    header();
    int choice;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                                  Main Menu                               " << endl;
    cout << "                                                                                                                               " << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "User accessing: ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << user_accessing << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Designation:";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " Admin" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    SetConsoleTextAttribute(hConsole, 3);
    cout << "1. Manage Students" << endl;
    cout << "2. Manage Teachers" << endl;
    cout << "3. Manage Admins" << endl;
    cout << "4. Manage Accounts" << endl;
    cout << "5. Exit" << endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Enter your choice: ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> choice;
    choice = intValidation(choice);
    if (choice == 5)
    {
      execution = false;
      system("cls");
      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                               PROGRAM ENDED!                           " << endl;
      SetConsoleTextAttribute(hConsole, 15);
      flag = false;
      break;
    }
    adminFunction(choice);
  }
}
void adminFunction(int choice)
{
  system("cls");
  header();
  if (choice == 1)
  {
    char c;
    bool flag = true;
    int ch, decsion;
    while (flag != false)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                                Managing Students                               " << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "                                                                                                                               " << endl;
      cout << "User accessing: ";
      SetConsoleTextAttribute(hConsole, 4);
      cout << user_accessing << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "Designation:";
      SetConsoleTextAttribute(hConsole, 4);
      cout << " Admin" << endl;
      SetConsoleTextAttribute(hConsole, 15);
      SetConsoleTextAttribute(hConsole, 3);
      cout << "1. Add new student" << endl;
      cout << "2. View Students" << endl;
      cout << "3. Remove a Student" << endl;
      cout << "4. Exit" << endl;
    SetConsoleTextAttribute(hConsole, 4);
      cout << "Enter your choice: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> ch;
      ch = intValidation(ch);
      decsion = manageStudent(ch);
      if (decsion == 1)
      {
        SetConsoleTextAttribute(hConsole, 6);
        cout << "                                      \nPress 1 if you want to go back to Main Menu or Press any key to continue...";
        SetConsoleTextAttribute(hConsole, 15);
        c = getch();
        if (c == '1')
        {
          flag = false;
        }
      }
      else
      {
        flag = false;
      }
    }
  }
  else if (choice == 2)
  {
    char c;
    bool flag = true;
    int ch, decsion;
    while (flag != false)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 4);

      cout << "                                                                               Managing Teachers                               " << endl;
      cout << "                                                                                                                               " << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "User accessing: ";
      SetConsoleTextAttribute(hConsole, 4);
      cout << user_accessing << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "Designation:";
      SetConsoleTextAttribute(hConsole, 4);
      cout << " Admin" << endl;
      SetConsoleTextAttribute(hConsole, 15);
      SetConsoleTextAttribute(hConsole, 3);
      cout << "1. Add new Teacher" << endl;
      cout << "2. View Teachers" << endl;
      cout << "3. Remove a Teacher" << endl;
      cout << "4. Exit" << endl;
    SetConsoleTextAttribute(hConsole, 4);
      cout << "Enter your choice: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> ch;
      ch = intValidation(ch);
      decsion = manageTeacher(ch);
      if (decsion == 1)
      {
        SetConsoleTextAttribute(hConsole, 6);

        cout << "                                      \nPress 1 if you want to go back to Main Menu or Press any key to continue...";
        SetConsoleTextAttribute(hConsole, 15);
        c = getch();
        if (c == '1')
        {
          flag = false;
        }
      }
      else
      {
        flag = false;
      }
    }
  }
  else if (choice == 3)
  {
    char c;
    bool flag = true;
    int ch, decsion;
    while (flag != false)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 4);

      cout << "                                                                                 Managing Admins                               " << endl;
      cout << "                                                                                                                               " << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "User accessing: ";
      SetConsoleTextAttribute(hConsole, 4);
      cout << user_accessing << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "Designation:";
      SetConsoleTextAttribute(hConsole, 4);
      cout << " Admin" << endl;
      SetConsoleTextAttribute(hConsole, 15);
      SetConsoleTextAttribute(hConsole, 3);
      cout << "1. Add new Admin" << endl;
      cout << "2. View Admins" << endl;
      cout << "3. Remove an Admin" << endl;
      cout << "4. Exit" << endl;

    SetConsoleTextAttribute(hConsole, 3);
      cout << "Enter your choice: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> ch;
      ch = intValidation(ch);
      decsion = manageAdmin(ch);
      if (decsion == 1)
      {
        SetConsoleTextAttribute(hConsole, 6);
        cout << "                                      \nPress 1 if you want to go back to Main Menu or Press any key to continue...";
        SetConsoleTextAttribute(hConsole, 15);
        c = getch();
        if (c == '1')
        {
          flag = false;
        }
      }
      else
      {
        flag = false;
      }
    }
  }
  else if (choice == 4)
  {
    char c;
    bool flag = true;
    int ch, decsion;
    while (flag != false)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 4);

      cout << "                                                                               Managing Accounts                               " << endl;
      SetConsoleTextAttribute(hConsole, 10);

      cout << "\nUser accessing: ";
      SetConsoleTextAttribute(hConsole, 4);
      cout << user_accessing << endl;
      SetConsoleTextAttribute(hConsole, 10);
      cout << "Designation:";
      SetConsoleTextAttribute(hConsole, 4);
      cout << " Admin" << endl;
      SetConsoleTextAttribute(hConsole, 15);
      SetConsoleTextAttribute(hConsole, 3);
      cout << "1. Add an Expense" << endl;
      cout << "2. Enter fee of a student" << endl;
      cout << "3. Enter Salary of a Teacher" << endl;
      cout << "4. Enter Salary of an Admin" << endl;
      cout << "5. View Expenses" << endl;
      cout << "6. View Total Revenue left" << endl;
      cout << "7. Exit" << endl;

    SetConsoleTextAttribute(hConsole, 4);
      cout << "Enter your choice: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> ch;
      ch = intValidation(ch);
      if (ch == 7)
      {
        break;
      }
      decsion = manageAccounts(ch);
      if (decsion == 1)
      {
        SetConsoleTextAttribute(hConsole, 6);
        cout << "                                      \nPress 1 if you want to go back to Main Menu or Press any key to continue...";
        SetConsoleTextAttribute(hConsole, 15);
        c = getch();
        if (c == '1')
        {
          flag = false;
        }
      }
    }
  }
}
int manageStudent(int choice)
{
  if (choice == 1)
  {
    system("cls");
    header();
    addStudent();
    storeStudentData();
    return 1;
  }
  else if (choice == 2)
  {
    system("cls");
    header();
    viewStudents();
    return 1;
  }
  else if (choice == 3)
  {
    bool check;
    check = deleteStudent();
    if (check == true)
    {
      SetConsoleTextAttribute(hConsole, 10);
      cout << "\nThe Student was Removed!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
      SetConsoleTextAttribute(hConsole, 4);
      cout << "Invalid Data!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    return 1;
  }
  else if (choice == 4)
  {
    system("cls");
    return 0;
  }
}
int manageTeacher(int choice)
{
  if (choice == 1)
  {
    system("cls");
    header();
    addTeacher();
    storeTeacherData();
    return 1;
  }
  else if (choice == 2)
  {
    system("cls");
    header();
    viewTeachers();
    return 1;
  }
  else if (choice == 3)
  {
    bool check;
    check = deleteTeacher();
    if (check == true)
    {
      SetConsoleTextAttribute(hConsole, 10);
      cout << "\nThe Teacher was Removed!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
      SetConsoleTextAttribute(hConsole, 4);
      cout << "Invalid Data!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    return 1;
  }
  else if (choice == 4)
  {
    execution = false;
    system("cls");
    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                                      PROGRAM ENDED!                           " << endl;
    SetConsoleTextAttribute(hConsole, 15);
    return 0;
  }
}
int manageAdmin(int choice)
{
  if (choice == 1)
  {
    system("cls");
    header();
    addAdmin();
    storeAdminData();
    return 1;
  }
  else if (choice == 2)
  {
    system("cls");
    header();
    viewAdmins();
    return 1;
  }
  else if (choice == 3)
  {
    bool check;
    check = deleteAdmin();
    if (check == true)
    {
      SetConsoleTextAttribute(hConsole, 10);
      cout << "\nThe Admin was Removed!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
      SetConsoleTextAttribute(hConsole, 4);
      cout << "Invalid Data!";
      SetConsoleTextAttribute(hConsole, 15);
    }
    return 1;
  }
  else if (choice == 4)
  {
    execution = false;
    system("cls");
    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                                      PROGRAM ENDED!                           " << endl;
    SetConsoleTextAttribute(hConsole, 15);
    return 0;
  }
}
int manageAccounts(int choice)
{
  int id;
  system("cls");
  header();
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                              Managing Accounts                                                                              " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Admin" << endl;

  cout << "Confirm your Admin ID: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> id;
  id = intValidation(id);
  if (id == adminId[current_user_index])
  {
    if (choice == 1)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 10);
      cout << "                                                                Access Granted                                                                              " << endl;

      SetConsoleTextAttribute(hConsole, 15);
      cout << "Write down the type of expense: ";
      getline(cin, expense_type[expense_count]);
      getline(cin, expense_type[expense_count]);

      cout << "Enter total amount needed: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> expense_money[expense_count];
      expense_money[expense_count] = intValidation(expense_money[expense_count]);
      storeExpense();
      totalMoney = totalMoney - expense_money[expense_count];
      storeTotal();
      SetConsoleTextAttribute(hConsole, 10);
      cout << "\nExpense has been added!";
      SetConsoleTextAttribute(hConsole, 15);
      return 1;
    }
    else if (choice == 2)
    {
      system("cls");
      header();
      int grade, rollno, check;

      cout << "Enter Class: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> grade;
      grade = intValidation(grade);

      cout << "Enter Student Roll no: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> rollno;
      rollno = intValidation(rollno);
      check = student_check(grade, rollno);
      if (check != -1)
      {
        char c;
        paidFees[check] = fees[check];
        cout << "The Fee of ";

        cout << studentFirstName[check] << " " << studentLastName[check];
        SetConsoleTextAttribute(hConsole, 15);
        cout << " is ";

        cout << "Rs: " << fees[check] << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press 1 to proceed...";
        c = getch();
        if (c == '1')
        {
          totalMoney = totalMoney + paidFees[check];
          storeTotal();
          SetConsoleTextAttribute(hConsole, 10);
          cout << "\nFees has been submitted...";
          SetConsoleTextAttribute(hConsole, 15);
        }
        return 1;
      }
      else
      {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Invalid Data!";
        SetConsoleTextAttribute(hConsole, 15);
        return 1;
      }
    }
    else if (choice == 3)
    {
      system("cls");
      header();
      int id, check;

      cout << "Enter Teacher ID: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> id;
      id = intValidation(id);
      check = teacher_check(id);
      if (check != -1)
      {
        char c;
        paidSalaryTeacher[check] = teacher_salary[check];
        cout << "The Salary of ";

        cout << teacherFirstName[check] << " " << teacherLastName[check];
        SetConsoleTextAttribute(hConsole, 15);
        cout << " is";

        cout << " Rs: " << teacher_salary[check] << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press 1 to proceed...";
        c = getch();
        if (c == '1')
        {
          totalMoney = totalMoney - paidSalaryTeacher[check];
          storeTotal();
          SetConsoleTextAttribute(hConsole, 10);
          cout << "\nSalary has been paid...";
          SetConsoleTextAttribute(hConsole, 15);
        }
        return 1;
      }
      else
      {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Invalid Data!";
        SetConsoleTextAttribute(hConsole, 15);
        return 1;
      }
    }
    else if (choice == 4)
    {
      system("cls");
      header();
      int id, check;

      cout << "Enter Admin ID: ";
      SetConsoleTextAttribute(hConsole, 15);
      cin >> id;
      id = intValidation(id);
      check = admin_check(id);
      if (check != -1)
      {
        char c;
        paidSalaryAdmin[check] = admin_salary[check];
        cout << "The Salary of ";

        cout << adminFirstName[check] << " " << adminLastName[check];
        SetConsoleTextAttribute(hConsole, 15);
        cout << " is";

        cout << " Rs: " << admin_salary[check] << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press 1 to proceed...";
        c = getch();
        if (c == '1')
        {
          totalMoney = totalMoney - paidSalaryAdmin[check];
          storeTotal();
          SetConsoleTextAttribute(hConsole, 10);
          cout << "\nSalary has been paid...";
          SetConsoleTextAttribute(hConsole, 15);
        }
        return 1;
      }
      else
      {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Invalid Data!";
        SetConsoleTextAttribute(hConsole, 15);
        return 1;
      }
    }
    else if (choice == 5)
    {
      system("cls");
      header();
      viewExpense();

      return 1;
    }
    else if (choice == 6)
    {
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 15);
      cout << "Total Revenue left is";
      SetConsoleTextAttribute(hConsole, 10);
      cout << " Rs: " << totalMoney;
      return 1;
    }
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\n Invalid Data!";
    SetConsoleTextAttribute(hConsole, 15);
    return 1;
  }
}
int student_check(int grade, int rollno)
{
  int count = 0;
  for (int i = 0; i < student_count; i++)
  {
    if (grade == studentClass[i] && rollno == studentRollno[i])
    {
      count++;
      return i;
    }
  }
  if (count == 0)
  {
    return -1;
  }
}
int teacher_check(int id)
{
  int count = 0;
  for (int i = 0; i < teacher_count; i++)
  {
    if (teacherID[i] == id)
    {
      count++;
      return i;
    }
  }
  if (count == 0)
  {
    return -1;
  }
}
int admin_check(int id)
{
  int count = 0;
  for (int i = 0; i < admin_count; i++)
  {
    if (adminId[i] == id)
    {
      count++;
      return i;
    }
  }
  if (count == 0)
  {
    return -1;
  }
}
void teacherMenu()
{
  char ch;
  bool flag = true;
  while (flag == true)
  {
    system("cls");
    header();
    int choice;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                                    Main Menu                               " << endl;
    cout << "                                                                                                                               " << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "User accessing: ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << user_accessing << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Designation:";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " Teacher" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "                                                                                                                               " << endl;
    cout << "1. Update the Time Table" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Make an Announcement" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter your choice: ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> choice;
    if (choice == 4)
    {
      execution = false;
      system("cls");
      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                               PROGRAM ENDED!                           " << endl;
      SetConsoleTextAttribute(hConsole, 15);
      flag = false;
      break;
    }
    teacherFunction(choice);
    SetConsoleTextAttribute(hConsole, 6);
    cout << "                                      \nPress 1 if you want to go back to login screen or press any other key to continue...";
    SetConsoleTextAttribute(hConsole, 15);
    ch = getch();
    if (ch == '1')
    {
      flag = false;
    }
  }
}
int teacherFunction(int choice)
{
  system("cls");
  header();
  if (choice == 1)
  {
    update_timeTable();
  }
  else if (choice == 2)
  {
    viewStudents();
  }
  else if (choice == 3)
  {
    makeAnnouncement();
  }
}
void studentMenu()
{
  char ch;
  bool flag = true;
  while (flag == true)
  {
    system("cls");
    header();
    int choice;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                                    Main Menu                               " << endl;
    cout << "                                                                                                                               " << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "User accessing: ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << user_accessing << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Designation:";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " Student" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "1. See your Time Table" << endl;
    cout << "2. View Announcements" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter your choice: ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> choice;
    choice = intValidation(choice);
    if (choice == 3)
    {
      execution = false;
      system("cls");
      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                               PROGRAM ENDED!                           " << endl;
      SetConsoleTextAttribute(hConsole, 15);
      flag = false;
      break;
    }
    studentFunction(choice);
    SetConsoleTextAttribute(hConsole, 6);
    cout << "                                      \nPress 1 if you want to go back to login screen or press any other key to continue...";
    SetConsoleTextAttribute(hConsole, 15);
    ch = getch();
    if (ch == '1')
    {
      flag = false;
    }
  }
}
int studentFunction(int choice)
{
  system("cls");
  header();
  if (choice == 1)
  {
    view_timeTable();
  }
  else if (choice == 2)
  {
    viewAnnouncement();
  }
}
void addStudent()
{
  string stu_user, stuFname, stuLname;
  int stuRN, stuCl, check;
  bool decsion, ch;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                     Adding Student                                                                              " << endl;
  cout << "                                                                                                                               " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Admin" << endl;
  SetConsoleTextAttribute(hConsole, 15);
p1:
  cout << "Enter Student First Name: ";
  cin >> stuFname;
  ch = stringValidation(stuFname);
  if (ch == true)
  {
    studentFirstName[student_count] = stuFname;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nInvalid Data\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto p1;
  }
p2:
  cout << "Enter Student Last Name: ";
  cin >> stuLname;
  ch = stringValidation(stuLname);
  if (ch == true)
  {
    studentLastName[student_count] = stuLname;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nInvalid Data\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto p2;
  }
  cout << "Enter Father/Guradian name: ";
  cin.ignore();
  getline(cin, student_father_name[student_count]);
  cout << "Gender (M for Male and F for Female): ";
  cin >> student_gender[student_count];
  cout << "Enter Students Date of birth in format(dd-mm-yyyy): ";
  cin >> student_dob[student_count];
  cout << "Enter Father/Guardian Profession: ";
  cin.ignore();
  getline(cin, father_profession[student_count]);
  cout << "Fees per month: ";
  cin >> fees[student_count];
  fees[student_count] = intValidation(fees[student_count]);
  cout << "Enter Class: ";
  cin >> stuCl;
  stuCl = intValidation(stuCl);
here:
  cout << "Alot Roll no: ";
  cin >> stuRN;
  stuRN = intValidation(stuRN);
  check = doesStudentExist(stuCl, stuRN);
  if (check == -1)
  {
    studentRollno[student_count] = stuRN;
    studentClass[student_count] = stuCl;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "A student with same Roll No and Class already Exists\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto here;
  }
jump:
  cout << "Assign Login Username: ";
  cin >> stu_user;
  decsion = isValidUsername(stu_user);
  if (decsion == true)
  {
    student_username[student_count] = stu_user;
    cout << "Assign Login Password: ";
    cin >> student_password[student_count];
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Student Added!";
    SetConsoleTextAttribute(hConsole, 15);
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nThis Username already exists!\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto jump;
  }
}
void storeStudentData()
{
  fstream file;
  file.open("student_data.txt", ios::app);
  file << studentFirstName[student_count] << ",";
  file << studentLastName[student_count] << ",";
  file << student_father_name[student_count] << ",";
  file << student_gender[student_count] << ",";
  file << student_dob[student_count] << ",";
  file << father_profession[student_count] << ",";
  file << studentClass[student_count] << ",";
  file << fees[student_count] << ",";
  file << studentRollno[student_count] << ",";
  file << student_username[student_count] << ",";
  file << student_password[student_count] << "\n";
  file.close();
  student_count++;
}
void addTeacher()
{
  string teaFname, teaLname;
  bool check, ch, decsion;
  int id;
  string userName;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                  Adding Teacher                                                                              " << endl;
  cout << "                                                                                                                               " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Admin" << endl;
  SetConsoleTextAttribute(hConsole, 15);
p3:
  cout << "Enter Teacher First Name: ";
  cin >> teaFname;
  ch = stringValidation(teaFname);
  if (ch == true)
  {
    teacherFirstName[teacher_count] = teaFname;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nInvalid Data\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto p3;
  }
p4:
  cout << "Enter Teacher Last Name: ";
  cin >> teaLname;
  ch = stringValidation(teaLname);
  if (ch == true)
  {
    teacherLastName[teacher_count] = teaLname;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nInvalid Data\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto p4;
  }
  cout << "Enter Father/Guradian name: ";
  cin.ignore();
  getline(cin, teacher_father_name[teacher_count]);
  cout << "Gender (M for Male and F for Female): ";
  cin >> teacher_gender[teacher_count];
  cout << "Enter Teacher Date of birth in format(dd-mm-yyyy): ";
  cin >> teacher_dob[teacher_count];
  cout << "Enter CNIC in format(00000-0000000-0): ";
  cin >> teacherCnic[teacher_count];
  cout << "Enter Qualification: ";
  cin.ignore();
  getline(cin, teacher_qualification[teacher_count]);
  cout << "Enter Class to be assigned: ";
  cin >> teacherClass[teacher_count];
  teacherClass[teacher_count] = intValidation(teacherClass[teacher_count]);
  cout << "Enter Salary: ";
  cin >> teacher_salary[teacher_count];
  teacher_salary[teacher_count] = intValidation(teacher_salary[teacher_count]);
fromHere:
  cout << "Alot Teacher ID: ";
  cin >> id;
  id = intValidation(id);
  decsion = doesTeacherExist(id);
  if (decsion != -1)
  {
    teacherID[teacher_count] = id;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "A teacher with same Teacher ID already Exists\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto fromHere;
  }
thisWay:
  cout << "Assign Login Username: ";
  cin >> userName;
  check = isValidUsername(userName);
  if (check == true)
  {
    teacher_username[teacher_count] = userName;
    cout << "Assign Login Password: ";
    cin >> teacher_password[teacher_count];
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Teacher added!";
    SetConsoleTextAttribute(hConsole, 15);
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nThis Username already exists!\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto thisWay;
  }
}
void storeTeacherData()
{
  fstream file;
  file.open("teacher_data.txt", ios::app);
  file << teacherFirstName[teacher_count] << ",";
  file << teacherLastName[teacher_count] << ",";
  file << teacher_father_name[teacher_count] << ",";
  file << teacher_gender[teacher_count] << ",";
  file << teacher_dob[teacher_count] << ",";
  file << teacherCnic[teacher_count] << ",";
  file << teacher_qualification[teacher_count] << ",";
  file << teacherClass[teacher_count] << ",";
  file << teacher_salary[teacher_count] << ",";
  file << teacherID[teacher_count] << ",";
  file << teacher_username[teacher_count] << ",";
  file << teacher_password[teacher_count] << "\n";
  file.close();
  teacher_count++;
}
void addAdmin()
{
  bool check, decsion;
  int id;
  string userName;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                  Adding Admin                                                                              " << endl;
  cout << "                                                                                                                               " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Admin" << endl;
  SetConsoleTextAttribute(hConsole, 15);
  cout << "Enter First Name: ";
  cin >> adminFirstName[admin_count];
  cout << "Enter Last Name: ";
  cin >> adminLastName[admin_count];
  cout << "Enter Father/Guradian name: ";
  cin.ignore();
  getline(cin, admin_father_name[admin_count]);
  cout << "Gender (M for Male and F for Female): ";
  cin >> admin_gender[admin_count];
  cout << "Enter Admin Date of birth in format(dd-mm-yyyy): ";
  cin >> admin_dob[admin_count];
  cout << "Enter CNIC in format(00000-0000000-0): ";
  cin >> admin_cnic[admin_count];
  cout << "Enter Salary: ";
  cin >> admin_salary[admin_count];
  admin_salary[admin_count] = intValidation(admin_salary[admin_count]);
point:
  cout << "Alot Admin ID: ";
  cin >> id;
  id = intValidation(id);
  decsion = doesAdminExist(id);
  if (decsion != -1)
  {
    adminId[admin_count] = id;
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "An Admin with same Admin ID already Exists\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto point;
  }
pointTwo:
  cout << "Assign Login Username: ";
  cin >> userName;
  check = isValidUsername(userName);
  if (check == true)
  {
    admin_username[admin_count] = userName;
    cout << "Assign Login Password: ";
    cin >> admin_password[admin_count];
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Admin added!";
    SetConsoleTextAttribute(hConsole, 15);
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nThis Username already exists!\n";
    SetConsoleTextAttribute(hConsole, 15);
    goto pointTwo;
  }
}
void storeAdminData()
{
  fstream file;
  file.open("admin_data.txt", ios::app);
  file << adminFirstName[admin_count] << ",";
  file << adminLastName[admin_count] << ",";
  file << admin_father_name[admin_count] << ",";
  file << admin_gender[admin_count] << ",";
  file << admin_dob[admin_count] << ",";
  file << admin_cnic[admin_count] << ",";
  file << admin_salary[admin_count] << ",";
  file << adminId[admin_count] << ",";
  file << admin_username[admin_count] << ",";
  file << admin_password[admin_count] << "\n";
  file.close();
  admin_count++;
}
void storeTimeTableData()
{
  fstream file;
  file.open("time_table.txt", ios::app);
  file << subjects1[user_accessing_grade] << ",";
  file << subjects2[user_accessing_grade] << ",";
  file << subjects3[user_accessing_grade] << ",";
  file << subjects4[user_accessing_grade] << ",";
  file << subjects5[user_accessing_grade] << ",";
  file << subjects6[user_accessing_grade] << ",";
  file << starting_time1[user_accessing_grade] << ",";
  file << ending_time1[user_accessing_grade] << ",";
  file << starting_time2[user_accessing_grade] << ",";
  file << ending_time2[user_accessing_grade] << ",";
  file << starting_time3[user_accessing_grade] << ",";
  file << ending_time3[user_accessing_grade] << ",";
  file << starting_time4[user_accessing_grade] << ",";
  file << ending_time4[user_accessing_grade] << ",";
  file << starting_time5[user_accessing_grade] << ",";
  file << ending_time5[user_accessing_grade] << ",";
  file << starting_time6[user_accessing_grade] << ",";
  file << ending_time6[user_accessing_grade] << "\n";
  file.close();
}
void readTimeTableData()
{
  int idx = 0;
  string record;
  fstream data;
  data.open("time_table.txt", ios::in);
  while (getline(data, record))
  {
    subjects1[idx] = getField(record, 1);
    subjects2[idx] = getField(record, 2);
    subjects3[idx] = getField(record, 3);
    subjects4[idx] = getField(record, 4);
    subjects5[idx] = getField(record, 5);
    subjects6[idx] = getField(record, 6);
    starting_time1[idx] = getField(record, 7);
    ending_time1[idx] = getField(record, 8);
    starting_time2[idx] = getField(record, 9);
    ending_time2[idx] = getField(record, 10);
    starting_time3[idx] = getField(record, 11);
    ending_time3[idx] = getField(record, 12);
    starting_time4[idx] = getField(record, 13);
    ending_time4[idx] = getField(record, 14);
    starting_time5[idx] = getField(record, 15);
    ending_time5[idx] = getField(record, 16);
    starting_time6[idx] = getField(record, 17);
    ending_time6[idx] = getField(record, 18);
    idx = idx + 1;
  }
  data.close();
}
void readStudentDataFromFile()
{
  int idx = 0;
  string record;
  fstream data;
  data.open("student_data.txt", ios::in);
  while (!(data.eof()))
  {

    getline(data, record);
    studentFirstName[student_count] = getField(record, 1);
    studentLastName[student_count] = getField(record, 2);
    student_father_name[student_count] = getField(record, 3);
    student_gender[student_count] = getField(record, 4);
    student_dob[student_count] = getField(record, 5);
    father_profession[student_count] = getField(record, 6);
    studentClass[student_count] = getintField(record, 7);
    fees[student_count] = getintField(record, 8);
    studentRollno[student_count] = getintField(record, 9);
    student_username[student_count] = getField(record, 10);
    student_password[student_count] = getField(record, 11);
    student_count = student_count + 1;
  }
  data.close();
}
void readTeacherDataFromFile()
{
  string record;
  fstream data;
  data.open("teacher_data.txt", ios::in);
  while (!(data.eof()))
  {
    getline(data, record);
    teacherFirstName[teacher_count] = getField(record, 1);
    teacherLastName[teacher_count] = getField(record, 2);
    teacher_father_name[teacher_count] = getField(record, 3);
    teacher_gender[teacher_count] = getField(record, 4);
    teacher_dob[teacher_count] = getField(record, 5);
    teacherCnic[teacher_count] = getField(record, 6);
    teacher_qualification[teacher_count] = getField(record, 7);
    teacherClass[teacher_count] = getintField(record, 8);
    teacher_salary[teacher_count] = getintField(record, 9);
    teacherID[teacher_count] = getintField(record, 10);
    teacher_username[teacher_count] = getField(record, 11);
    teacher_password[teacher_count] = getField(record, 12);
    teacher_count++;
  }
  data.close();
}
void readAdminDataFromFile()
{
  string record;
  fstream data;
  data.open("admin_data.txt", ios::in);
  while (!(data.eof()))
  {
    getline(data, record);
    adminFirstName[admin_count] = getField(record, 1);
    adminLastName[admin_count] = getField(record, 2);
    admin_father_name[admin_count] = getField(record, 3);
    admin_gender[admin_count] = getField(record, 4);
    admin_dob[admin_count] = getField(record, 5);
    admin_cnic[admin_count] = getField(record, 6);
    admin_salary[admin_count] = getintField(record, 7);
    adminId[admin_count] = getintField(record, 8);
    admin_username[admin_count] = getField(record, 9);
    admin_password[admin_count] = getField(record, 10);
    admin_count++;
  }
  data.close();
}
void viewStudents()
{
  int admin_ch, teacher_cl, cl;
  if (user_accessing_designation == "Admin")
  {
    SetConsoleTextAttribute(hConsole, 15);
    cout << "1. All Students" << endl;
    cout << "2. Class wise" << endl;

    cout << "Enter Your Choice: ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> admin_ch;
    if (admin_ch == 1)
    {
      system("cls");
      header();

      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                          Viewing Students: " << endl;
      int x = 5, y = 15;
      gotoxy(x - 2, y);

      cout << "First Name";
      gotoxy(x + 18, y);
      cout << "Last Name";
      x = x + 10;
      gotoxy(x + 8, y);
      cout << "Father Name";
      gotoxy(x + 26, y);
      cout << "Gender";
      gotoxy(x + 40, y);
      cout << "Date of Birth";
      gotoxy(x + 60, y);
      cout << "Father's Profession";
      gotoxy(x + 88, y);
      cout << "Class";
      gotoxy(x + 98, y);
      cout << "Fee";
      gotoxy(x + 106, y);
      cout << "Roll no";
      gotoxy(x + 118, y);
      cout << "Username";
      gotoxy(x + 132, y);
      cout << "Password";
      y = y + 2;
      x = x - 10;

      for (int idx = 0; idx < student_count; idx++)
      {

        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(x - 2, y);
        cout << studentFirstName[idx];
        gotoxy(x + 18, y);
        cout << studentLastName[idx];
        x = x + 10;
        gotoxy(x + 8, y);
        cout << student_father_name[idx];
        gotoxy(x + 26, y);
        cout << student_gender[idx];
        gotoxy(x + 40, y);
        cout << student_dob[idx];
        gotoxy(x + 60, y);
        cout << father_profession[idx];
        gotoxy(x + 88, y);
        cout << studentClass[idx];
        gotoxy(x + 98, y);
        cout << fees[idx];
        gotoxy(x + 106, y);
        cout << studentRollno[idx];
        gotoxy(x + 118, y);
        cout << student_username[idx];
        gotoxy(x + 132, y);
        cout << student_password[idx];
        y++;
        x = x - 10;
      }
    }
    else if (admin_ch == 2)
    {

      cout << "Enter the class: " << endl;
      SetConsoleTextAttribute(hConsole, 15);
      cin >> cl;
      system("cls");
      header();
      SetConsoleTextAttribute(hConsole, 4);
      cout << "                                                                         Viewing Students: " << endl;

      int x = 5, y = 17;
      gotoxy(x - 2, y);
      cout << "First Name";
      gotoxy(x + 18, y);
      cout << "Last Name";
      x = x + 10;
      gotoxy(x + 8, y);
      cout << "Father Name";
      gotoxy(x + 26, y);
      cout << "Gender";
      gotoxy(x + 40, y);
      cout << "Date of Birth";
      gotoxy(x + 60, y);
      cout << "Father's Profession";
      gotoxy(x + 88, y);
      cout << "Class";
      gotoxy(x + 98, y);
      cout << "Fee";
      gotoxy(x + 106, y);
      cout << "Roll no";
      gotoxy(x + 118, y);
      cout << "Username";
      gotoxy(x + 132, y);
      cout << "Password";
      y = y + 2;
      x = x - 10;

      for (int idx = 0; idx < student_count; idx++)
      {
        if (studentClass[idx] == cl)
        {
          SetConsoleTextAttribute(hConsole, 15);
          gotoxy(x - 2, y);
          cout << studentFirstName[idx];
          gotoxy(x + 18, y);
          cout << studentLastName[idx];
          x = x + 10;
          gotoxy(x + 8, y);
          cout << student_father_name[idx];
          gotoxy(x + 26, y);
          cout << student_gender[idx];
          gotoxy(x + 40, y);
          cout << student_dob[idx];
          gotoxy(x + 60, y);
          cout << father_profession[idx];
          gotoxy(x + 88, y);
          cout << studentClass[idx];
          gotoxy(x + 98, y);
          cout << fees[idx];
          gotoxy(x + 106, y);
          cout << studentRollno[idx];
          gotoxy(x + 118, y);
          cout << student_username[idx];
          gotoxy(x + 132, y);
          cout << student_password[idx];
          y++;
          x = x - 10;
        }
      }
    }
    else
    {
      SetConsoleTextAttribute(hConsole, 4);
      cout << "Invalid Choice!";
      SetConsoleTextAttribute(hConsole, 15);
      return;
    }
  }
  else
  {
    teacher_cl = user_accessing_grade;

    SetConsoleTextAttribute(hConsole, 4);
    cout << "                                                                         Viewing Students: " << endl;
    int x = 5, y = 15;
    gotoxy(x - 2, y);

    cout << "First Name";
    gotoxy(x + 18, y);
    cout << "Last Name";
    x = x + 10;
    gotoxy(x + 8, y);
    cout << "Father Name";
    gotoxy(x + 26, y);
    cout << "Gender";
    gotoxy(x + 40, y);
    cout << "Date of Birth";
    gotoxy(x + 60, y);
    cout << "Father's Profession";
    gotoxy(x + 88, y);
    cout << "Class";
    gotoxy(x + 98, y);
    cout << "Fee";
    gotoxy(x + 106, y);
    cout << "Roll no";
    gotoxy(x + 118, y);
    cout << "Username";
    gotoxy(x + 132, y);
    cout << "Password";
    y = y + 2;
    x = x - 10;

    for (int idx = 0; idx < student_count; idx++)
    {
      if (studentClass[idx] == teacher_cl)
      {
        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(x - 2, y);
        cout << studentFirstName[idx];
        gotoxy(x + 18, y);
        cout << studentLastName[idx];
        x = x + 10;
        gotoxy(x + 8, y);
        cout << student_father_name[idx];
        gotoxy(x + 26, y);
        cout << student_gender[idx];
        gotoxy(x + 40, y);
        cout << student_dob[idx];
        gotoxy(x + 60, y);
        cout << father_profession[idx];
        gotoxy(x + 88, y);
        cout << studentClass[idx];
        gotoxy(x + 98, y);
        cout << fees[idx];
        gotoxy(x + 106, y);
        cout << studentRollno[idx];
        gotoxy(x + 118, y);
        cout << student_username[idx];
        gotoxy(x + 132, y);
        cout << student_password[idx];
        y++;
        x = x - 10;
      }
    }
  }
}
void viewTeachers()
{
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                         Viewing Teachers: " << endl;
  int x = 5, y = 15;
  gotoxy(x - 2, y);

  cout << "First Name";
  gotoxy(x + 18, y);
  cout << "Last Name";
  gotoxy(x + 38, y);
  cout << "CNIC";
  gotoxy(x + 55, y);
  cout << "Gender";
  gotoxy(x + 69, y);
  cout << "Qualification";
  gotoxy(x + 86, y);
  cout << "Class";
  gotoxy(x + 104, y);
  cout << "Salary";
  gotoxy(x + 116, y);
  cout << "Teacher ID";
  gotoxy(x + 132, y);
  cout << "Username";
  gotoxy(x + 145, y);
  cout << "Password";
  y = y + 2;
  for (int idx = 0; idx < teacher_count; idx++)
  {

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(x - 2, y);
    cout << teacherFirstName[idx];
    gotoxy(x + 18, y);
    cout << teacherLastName[idx];
    gotoxy(x + 38, y);
    cout << teacherCnic[idx];
    gotoxy(x + 57, y);
    cout << teacher_gender[idx];
    gotoxy(x + 69, y);
    cout << teacher_qualification[idx];
    gotoxy(x + 88, y);
    cout << teacherClass[idx];
    gotoxy(x + 104, y);
    cout << teacher_salary[idx];
    gotoxy(x + 119, y);
    cout << teacherID[idx];
    gotoxy(x + 132, y);
    cout << teacher_username[idx];
    gotoxy(x + 145, y);
    cout << teacher_password[idx];
    y++;
  }
}
void viewAdmins()
{
  SetConsoleTextAttribute(hConsole, 4);
  int x = 5, y = 15;
  cout << "                                                                         Viewing Admins: " << endl;
  gotoxy(x - 2, y);

  cout << "First Name";
  gotoxy(x + 18, y);
  cout << "Last Name";
  gotoxy(x + 38, y);
  cout << "CNIC";
  gotoxy(x + 55, y);
  cout << "Gender";
  gotoxy(x + 69, y);
  cout << "Date of Birth";
  gotoxy(x + 90, y);
  cout << "Salary";
  gotoxy(x + 108, y);
  cout << "Admin ID";
  gotoxy(x + 129, y);
  cout << "Username";
  gotoxy(x + 147, y);
  cout << "Password";
  y = y + 2;
  for (int idx = 0; idx < admin_count; idx++)
  {
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(x - 2, y);
    cout << adminFirstName[idx];
    gotoxy(x + 18, y);
    cout << adminLastName[idx];
    gotoxy(x + 38, y);
    cout << admin_cnic[idx];
    gotoxy(x + 57, y);
    cout << admin_gender[idx];
    gotoxy(x + 69, y);
    cout << admin_dob[idx];
    gotoxy(x + 90, y);
    cout << admin_salary[idx];
    gotoxy(x + 111, y);
    cout << adminId[idx];
    gotoxy(x + 129, y);
    cout << admin_username[idx];
    gotoxy(x + 147, y);
    cout << admin_password[idx];
    y++;
  }
}
void viewExpense()
{
  int x = 5, y = 15;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                         Viewing Expenses: " << endl;
  gotoxy(x - 2, y);

  cout << "Expense Type";
  gotoxy(x + 18, y);
  cout << "Expense Money";
  y = y + 2;
  for (int idx = 0; idx < expense_count; idx++)
  {
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(x - 2, y);
    cout << expense_type[idx];
    gotoxy(x + 18, y);
    cout << expense_money[idx];
    y++;
  }
}
bool isValidUsername(string userName)
{
  bool flag = true;
  for (int idx = 0; idx < student_count; idx++)
  {
    if (student_username[idx] == userName)
    {
      flag = false;
      break;
    }
  }
  for (int idx = 0; idx < teacher_count; idx++)
  {
    if (teacher_username[idx] == userName)
    {
      flag = false;
      break;
    }
  }
  for (int idx = 0; idx < admin_count; idx++)
  {
    if (admin_username[idx] == userName)
    {
      flag = false;
      break;
    }
  }
  return flag;
}
bool deleteStudent()
{
  bool flag = false;
  int stu_rollno, stu_class, check;
  SetConsoleTextAttribute(hConsole, 3);
  cout << endl
       << "Enter Class of the Student: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> stu_class;
  SetConsoleTextAttribute(hConsole, 3);
  cout << endl
       << "Enter Student Roll Number: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> stu_rollno;
  check = doesStudentExist(stu_class, stu_rollno);
  if (check != -1)
  {
    for (int i = check; i < student_count - 1; i++)
    {
      studentFirstName[i] = studentFirstName[i + 1];
      studentLastName[i] = studentLastName[i + 1];
      student_father_name[i] = student_father_name[i + 1];
      student_gender[i] = student_gender[i + 1];
      student_dob[i] = student_dob[i + 1];
      father_profession[i] = father_profession[i + 1];
      studentClass[i] = studentClass[i + 1];
      fees[i] = fees[i + 1];
      studentRollno[i] = studentRollno[i + 1];
      student_username[i] = student_username[i + 1];
      student_password[i] = student_password[i + 1];
    }
    student_count--;
    flag = true;
  }
  updateStudentsData();
  return flag;
}
bool deleteTeacher()
{

  bool flag = false;
  int tea_Id, check;
  string tea_name;
  SetConsoleTextAttribute(hConsole, 3);
  cout << endl
       << "Enter Teacher ID: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> tea_Id;
  check = doesTeacherExist(tea_Id);
  if (check != -1)
  {
    for (int i = check; i < teacher_count - 1; i++)
    {
      teacherFirstName[i] = teacherFirstName[i + 1];
      teacherLastName[i] = teacherLastName[i + 1];
      teacher_father_name[i] = teacher_father_name[i + 1];
      teacher_gender[i] = teacher_gender[i + 1];
      teacher_dob[i] = teacher_dob[i + 1];
      teacherCnic[i] = teacherCnic[i + 1];
      teacher_qualification[i] = teacher_qualification[i + 1];
      teacherClass[i] = teacherClass[i + 1];
      teacher_salary[i] = teacher_salary[i + 1];
      teacherID[i] = teacherID[i + 1];
      teacher_username[i] = teacher_username[i + 1];
      teacher_password[i] = teacher_password[i + 1];
    }
    teacher_count--;
    flag = true;
    updateTeachersData();
  }
  return flag;
}
bool deleteAdmin()
{
  bool flag = false;
  int adm_Id, check;
  string adm_name;
  cout << endl
       << "Enter Admin ID: ";
  cin >> adm_Id;
  check = doesAdminExist(adm_Id);
  if (check != -1)
  {
    for (int i = check; i < admin_count - 1; i++)
    {
      adminFirstName[i] = adminFirstName[i + 1];
      adminLastName[i] = adminLastName[i + 1];
      admin_father_name[i] = admin_father_name[i + 1];
      admin_gender[i] = admin_gender[i + 1];
      admin_dob[i] = admin_dob[i + 1];
      admin_cnic[i] = admin_cnic[i + 1];
      admin_salary[i] = admin_salary[i + 1];
      adminId[i] = adminId[i + 1];
      admin_username[i] = admin_username[i + 1];
      admin_password[i] = admin_password[i + 1];
    }
    admin_count--;
    flag = true;
  }
  updateAdminsData();
  return flag;
}
int doesStudentExist(int stu_class, int stu_rollno)
{
  for (int i = 0; i < student_count; i++)
  {
    if (studentClass[i] == stu_class && studentRollno[i] == stu_rollno)
    {
      return i;
    }
  }
  return -1;
}
int doesTeacherExist(int tea_Id)
{

  for (int i = 0; i < teacher_count; i++)
  {
    if (teacherID[i] == tea_Id)
    {
      return i;
    }
  }
  return -1;
}
int doesAdminExist(int adm_Id)
{

  for (int i = 0; i < admin_count; i++)
  {
    if (adminId[i] == adm_Id)
    {
      return i;
    }
  }
  return -1;
}
void updateStudentsData()
{
  fstream file;
  file.open("student_data.txt", ios::out);
  for (int i = 0; i < student_count; i++)
  {
    file << studentFirstName[i] << ",";
    file << studentLastName[i] << ",";
    file << student_father_name[i] << ",";
    file << student_gender[i] << ",";
    file << student_dob[i] << ",";
    file << father_profession[i] << ",";
    file << studentClass[i] << ",";
    file << fees[i] << ",";
    file << studentRollno[i] << ",";
    file << student_username[i] << ",";
    file << student_password[i] << "\n";
  }
  file.close();
}
void updateTeachersData()
{
  fstream file;
  file.open("teacher_data.txt", ios::out);
  for (int i = 0; i < teacher_count; i++)
  {
    file << teacherFirstName[i] << ",";
    file << teacherLastName[i] << ",";
    file << teacher_father_name[i] << ",";
    file << teacher_gender[i] << ",";
    file << teacher_dob[i] << ",";
    file << teacher_qualification[i] << ",";
    file << teacherClass[i] << ",";
    file << teacher_salary[i] << ",";
    file << teacherID[i] << ",";
    file << teacher_username[i] << ",";
    file << teacher_password[i] << "\n";
  }
  file.close();
}
void updateAdminsData()
{
  fstream file;
  file.open("admin_data.txt", ios::out);
  for (int i = 0; i < admin_count; i++)
  {
    file << adminFirstName[i] << ",";
    file << adminLastName[i] << ",";
    file << admin_father_name[i] << ",";
    file << admin_gender[i] << ",";
    file << admin_dob[i] << ",";
    file << admin_salary[i] << ",";
    file << adminId[i] << ",";
    file << admin_username[i] << ",";
    file << admin_password[i] << "\n";
  }
  file.close();
}
void update_timeTable()
{
  SetConsoleTextAttribute(hConsole, 4);
  int id;
  cout << "                                                                  Updating Time Table                                                                              " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Teacher" << endl;

  cout << "Confirm your Teacher ID: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> id;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                            Break Time is 12:00 AM to 01:00 PM" << endl;
  if (id == teacherID[current_user_index])
  {
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Enter name of First Subject: ";
    getline(cin, subjects1[user_accessing_grade]);
    getline(cin, subjects1[user_accessing_grade]);
    cout << "Enter name of Second Subject: ";
    getline(cin, subjects2[user_accessing_grade]);
    cout << "Enter name of Third Subject: ";
    getline(cin, subjects3[user_accessing_grade]);
    cout << "Enter name of fourth Subject: ";
    getline(cin, subjects4[user_accessing_grade]);
    cout << "Enter name of fifth Subject: ";
    getline(cin, subjects5[user_accessing_grade]);
    cout << "Enter name of sixth Subject: ";
    getline(cin, subjects6[user_accessing_grade]);
    cout << "Enter Starting time of first Subject in format (00:00 Am): ";
    getline(cin, starting_time1[user_accessing_grade]);
    cout << "Enter Ending time of first Subject in format (00:00 Am): ";
    getline(cin, ending_time1[user_accessing_grade]);
    cout << "Enter Starting time of Second Subject in format (00:00 Am): ";
    getline(cin, starting_time2[user_accessing_grade]);
    cout << "Enter Ending time of Second Subject in format (00:00 Am): ";
    getline(cin, ending_time2[user_accessing_grade]);
    cout << "Enter Starting time of Third Subject in format (00:00 Am): ";
    getline(cin, starting_time3[user_accessing_grade]);
    cout << "Enter Ending time of first Third in format (00:00 Am): ";
    getline(cin, ending_time3[user_accessing_grade]);
    cout << "Enter Starting time of fourth Subject in format (00:00 Am): ";
    getline(cin, starting_time4[user_accessing_grade]);
    cout << "Enter Ending time of fourth Subject in format (00:00 Am): ";
    getline(cin, ending_time4[user_accessing_grade]);
    cout << "Enter Starting time of fifth Subject in format (00:00 Am): ";
    getline(cin, starting_time5[user_accessing_grade]);
    cout << "Enter Ending time of fifth Subject in format (00:00 Am): ";
    getline(cin, ending_time5[user_accessing_grade]);
    cout << "Enter Starting time of Sixth Subject in format (00:00 Am): ";
    getline(cin, starting_time6[user_accessing_grade]);
    cout << "Enter Ending time of Sixth Subject in format (00:00 Am): ";
    getline(cin, ending_time6[user_accessing_grade]);
    storeTimeTableData();
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Time Table has been Updated!";
    SetConsoleTextAttribute(hConsole, 15);
  }
  else
  {
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Access Denied";
    SetConsoleTextAttribute(hConsole, 15);
  }
}
void view_timeTable()
{
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                         Viewing Time Table: " << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "User accessing: ";
  SetConsoleTextAttribute(hConsole, 4);
  cout << user_accessing << endl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Designation:";
  SetConsoleTextAttribute(hConsole, 4);
  cout << " Student" << endl;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                  Break Time is 12:00 AM to 01:00 PM" << endl;
  int x = 5, y = 15;
  gotoxy(x - 2, y);

  cout << "Subject";
  gotoxy(x + 38, y);
  cout << "Timings";
  y = y + 2;
  SetConsoleTextAttribute(hConsole, 15);
  gotoxy(x - 2, y);
  cout << subjects1[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time1[user_accessing_grade - 1] << " to " << ending_time1[user_accessing_grade - 1];
  gotoxy(x - 2, y);
  cout << subjects2[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time2[user_accessing_grade - 1] << " to " << ending_time2[user_accessing_grade - 1];
  gotoxy(x - 2, y);
  cout << subjects3[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time3[user_accessing_grade - 1] << " to " << ending_time3[user_accessing_grade - 1];
  gotoxy(x - 2, y);
  cout << subjects4[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time4[user_accessing_grade - 1] << " to " << ending_time4[user_accessing_grade - 1];
  gotoxy(x - 2, y);
  cout << subjects5[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time5[user_accessing_grade - 1] << " to " << ending_time5[user_accessing_grade - 1];
  gotoxy(x - 2, y);
  cout << subjects6[user_accessing_grade - 1];
  gotoxy(x + 38, y++);
  cout << starting_time6[user_accessing_grade - 1] << " to " << ending_time6[user_accessing_grade - 1];
}
void makeAnnouncement()
{
  SetConsoleTextAttribute(hConsole, 4);
  int cl;
  string message;
  cout << "                                                                              Making Announcement: " << endl;

  cout << "Enter your Class: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> cl;

  cout << "Write your message: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin.ignore();
  getline(cin, announcements[cl - 1]);
  storeAnnouncements(cl - 1);
  SetConsoleTextAttribute(hConsole, 10);
  cout << "                                                                           Announcement has been made... " << endl;
}
void viewAnnouncement()
{
  int cl;
  SetConsoleTextAttribute(hConsole, 4);
  cout << "                                                                            Viewing Announcement: " << endl;

  cout << "Enter your Class: ";
  SetConsoleTextAttribute(hConsole, 15);
  cin >> cl;
  SetConsoleTextAttribute(hConsole, 10);
  cout << "Announcement: ";
  SetConsoleTextAttribute(hConsole, 15);
  cout << announcements[cl - 1];
}
bool addMoney(int money)
{
  totalMoney = totalMoney + money;
  return true;
}
bool retrieveMoney(int money)
{
  if (totalMoney > money)
  {
    totalMoney = totalMoney - money;
    return true;
  }
  else
  {
    return false;
  }
}
void storeExpense()
{
  fstream file;
  file.open("expenses.txt", ios::app);
  file << expense_type[expense_count] << ",";
  file << expense_money[expense_count] << "\n";
  file.close();
}
void readExpense()
{
  string record;
  fstream data;
  data.open("expenses.txt", ios::in);
  while (!(data.eof()))
  {
    getline(data, record);
    expense_type[expense_count] = getField(record, 1);
    expense_money[expense_count] = getintField(record, 2);
    expense_count++;
  }
  data.close();
}
void storeTotal()
{
  fstream file;
  file.open("total_money.txt", ios::out);
  file << totalMoney;
  file.close();
}
void readTotal()
{
  string data;
  fstream file;
  file.open("total_money.txt", ios::in);
  getline(file, data);
  istringstream(data) >> totalMoney;
}
void storeAnnouncements(int cl)
{
  fstream file;
  file.open("announcements.txt", ios::out);
  for (int i = 0; i < 10; i++)
  {
    if (i == cl)
    {
      file << announcements[i] << "\n";
    }
    else if (announcements[i] == "No Announcements!" || announcements[i] != "")
    {
      continue;
    }
    else
    {
      file << "No Announcements!"
           << "\n";
    }
  }
  file.close();
}
void loadAnnouncements()
{

  int idx = 0;
  string record;
  fstream data;
  data.open("announcements.txt", ios::in);
  while (getline(data, record))
  {
    announcements[idx] = record;
    idx++;
  }
  data.close();
}
void header()
{
  SetConsoleTextAttribute(hConsole, 3);
  cout << "                                                                                                                               " << endl;
  cout << "                                                                                                                               " << endl;
  cout << "                                                                                                                              " << endl;
  cout << "                                                 ___              _      __     __ ___      __     ____    __             __   " << endl;
  cout << "                                                / _ \\__ _____    (_)__ _/ /    / // (_)__ _/ /    / __/___/ /  ___  ___  / /   " << endl;
  cout << "                                               / ___/ // / _ \\  / / _ `/ _ \\  / _  / / _ `/ _ \\  _\\ \\/ __/ _ \\/ _ \\/ _ \\/ /    " << endl;
  cout << "                                              /_/   \\_,_/_//_/_/ /\\_,_/_.__/ /_//_/_/\\_, /_//_/ /___/\\__/_//_/\\___/\\___/_/     " << endl;
  cout << "                                                            |___/                   /___/                                      " << endl;
  cout << "                                                                                                                               " << endl;
  cout << "                                                                                                                               " << endl;
  cout << "                                                                                                                               " << endl;
  SetConsoleTextAttribute(hConsole, 15);
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
  CHAR_INFO ci;
  COORD xy = {0, 0};
  SMALL_RECT rect = {x, y, x, y};
  COORD coordBufsize;
  coordBufsize.X = 1;
  coordBufsize.Y = 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
string getField(string record, int field)
{
  int commaCount = 1;
  string item = "";
  for (int x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
    {
      commaCount = commaCount + 1;
    }
    else if (commaCount == field)
    {
      item = item + record[x];
    }
  }
  return item;
}
int getintField(string record, int field)
{

  int commaCount = 1, num;
  string item = "";
  for (int x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
    {
      commaCount = commaCount + 1;
    }
    else if (commaCount == field)
    {
      item = item + record[x];
    }
  }
  istringstream(item) >> num;
  return num;
}
int intValidation(int number)
{
  while (cin.fail())
  {
    cin.clear();
    cin.ignore(100, '\n');
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\nInvalid input!! Put integer as an input: ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> number;
  }
  return number;
}
bool stringValidation(string line)
{
  bool check = true;
  for (int i = 0; i < line.length(); i++)
  {
    if (isdigit(line[i]) || !isalpha(line[i]))
    {
      check = false;
      break;
    }
  }
  return check;
}