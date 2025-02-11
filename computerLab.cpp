#include <iostream>
using namespace std;
 
const int NUMLABS = 4;
 
  // Function prototypes
  void createArrays(int * labs[], int labsizes[]);
  void freeArrays(int * labs[]);
  void showLabs(int * labs[], int labsizes[]);
  void login(int * labs[], int labsizes[]);
  void logout(int * labs[], int labsizes[]);
  void search(int * labs[], int labsizes[]);
  
  int main()
  {
     int *labs[NUMLABS];
     int labsizes[NUMLABS];
     int choice = -1;
 
     cout << "Welcome to the LabMonitorProgram!\n";

     cout << "Please enter the number of computer stations in each lab:\n";
 
     for (int i = 0; i < NUMLABS; i++)
     {
        do
        {
           cout << "How many computers in Lab " << i + 1 << "? ";
           cin >> labsizes[i];
        }
        while (labsizes[i] < 0);
        }
        createArrays(labs, labsizes);
 
       while (choice != 0)
       {
         cout << endl;
         cout << "MAIN MENU" << endl;
         cout << "0) Quit" << endl;
         cout << "1) Simulate login" << endl;
         cout << "2) Simulate logout" << endl;
         cout << "3) Search" << endl;
         cin >> choice;

            if (choice == 1)
            {
                login(labs, labsizes);
                showLabs(labs, labsizes);
            }
            else if (choice == 2)
            {
                logout(labs, labsizes);
                showLabs(labs, labsizes);
            }
            else if (choice == 3)
            {
                search(labs, labsizes);
            }
        }
        freeArrays(labs);
        cout << "Bye!\n";
        return 0;
      }
 
    void createArrays(int * labs[], int labsizes[])
    {
        for (int i = 0; i < NUMLABS; i++)
        {
          labs[i] = new int[labsizes[i]];
          
          // Initialize the array to 0 (empty)
 
            for (int j = 0; j < labsizes[i]; j++)
            {
               labs[i][j] = 0;
            }
        }
    }
  
   void freeArrays(int * labs[])
   {
       for (int i = 0; i < NUMLABS; i++)
       {
           delete[] labs[i];
       }
   }
  
   void showLabs(int * labs[], int labsizes[])
   {
     cout << "LAB STATUS" << endl;
     cout << "Lab #     Computer Stations" << endl;
  
      for (int i = 0; i < NUMLABS; i++)
      {
            cout << i + 1 << "         ";
 
            for (int j = 0; j < labsizes[i]; j++)
            {
               cout << (j + 1) << ": ";
                if (labs[i][j] == 0)
                {
                   cout << "empty ";
                }
                else
                {
                   cout << labs[i][j] << " ";
                }
            }
 
          cout << endl;
     }
      cout << endl;
   }

  void login(int * labs[], int labsizes[])
  {    
    int userId, labNum, computerNum;

     cout << "Enter the 5 digit ID number of the user logging in: \n";
     cin >> userId;
 
     cout << "Enter the lab number the user is logging in from (1-4): \n";
     cin >> labNum;

     cout << "Enter computer station number the user is logging in to (1-" << labsizes[labNum - 1] << "): \n";
     cin >> computerNum;

    //Validate input
     if (labNum >= 1 && labNum <= NUMLABS && computerNum >= 1 && computerNum <= labsizes[labNum - 1])
     {
          if (labs[labNum - 1][computerNum - 1] == 0)
          {
            labs[labNum - 1][computerNum - 1] = userId;
            cout << "User " << userId << " logged in Lab " << labNum << " at computer " << computerNum << endl;
         }
         else
         {
            cout << "Computer station " << computerNum << " in Lab " << labNum << " is already in use." << endl;
         }
       }
         else
         {
           cout << "Invalid input. Please enter valid lab and computer station numbers." << endl;
         }
 }
 
    void logout(int * labs[], int labsizes[])
    {
      int userId;
 
       cout << "Enter the 5 digit ID number of the user logging out: ";
       cin >> userId;
 
      // Search for the user and log them out if found
      for (int i = 0; i < NUMLABS; i++)
      {
            if (labs[i][j] == userId)
             {
                 labs[i][j] = 0;
                cout << "Logout: User " << userId << " in Lab " << i + 1 << " at computer " << j + 1 << endl;
                 return;
             }
      }
    }

     cout << "User not logged in." << endl;
 }

    void search(int * labs[], int labsizes[])
    {
     int userId;
 
        cout << "Enter the 5-digit ID number of the user to search for: ";
        cin >> userId;
 
        // Search for the user and display the location if found
        for (int i = 0; i < NUMLABS; i++)
        {
            for (int j = 0; j < labsizes[i]; j++)
            {
                if (labs[i][j] == userId)
                {
                   count << "User " << userId << " logged in Lab " << i + 1 << " at computer " << j + 1 << endl;
                   return;        
                }
         }
     }
 
    cout << "User not found." << endl;
 }

