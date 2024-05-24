#include <iostream>
#include <fstream>
#include <iomanip>
#include "TaskManager.h"

using namespace std;

void show_menu(char& _key);

int main()
{
    TaskManager myToDoList;
    myToDoList.get_from_file();
    ofstream listFile;
    string myTask;
    char key;
    show_menu(key);

    while(toupper(key) != 'C')
    {
        if(toupper(key) == 'C'){
            cout << "Closing to do list . . ." << endl;
        }
        else if(toupper(key) == 'A'){
            cout << " + ";
            cin.ignore();
            getline(cin, myTask);
            myToDoList.add_task(myTask, 'T');
            show_menu(key);
            cout << endl;
        }
        else if(toupper(key) == 'V'){
            myToDoList.view_task_list();
            show_menu(key);
            cout << endl;
        }
        else if(toupper(key) == 'D'){
            cout << "\nWhich task do you wish to delete?" << endl;
            cout << "Task: ";
            cin.ignore();
            getline(cin, myTask);
            myToDoList.delete_task(myTask);
            show_menu(key);
            cout << endl;
        }
        else if(toupper(key) == 'E'){
            myToDoList.clear_task_list();
            show_menu(key);
            cout << endl;
        }
    }

    return 0;
}

void show_menu(char& _key){
    cout << " =============== TO DO LIST =============== \n\n";
    cout << " --------------- Navigation keys ---------- \n\n";
    cout << left << setw(14) << "Description" << right << setw(14) << "Key" << endl;
    cout << left << setw(14) << "Add a task" << right << setw(14) << "A" << endl;
    cout << left << setw(14) << "View task list" << right << setw(14) << "V" << endl;
    cout << left << setw(14) << "Close to do list" << right << setw(12) << "C" << endl;
    cout << left << setw(14) << "Delete task" << right << setw(14) << "D" << endl;
    cout << left << setw(14) << "Clear task list" << right << setw(14) << "E" << endl;
    cout << endl;
    cout << "Select key: ";
    cin >> _key;
}
