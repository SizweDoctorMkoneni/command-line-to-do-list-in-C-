#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "TaskManager.h"

using namespace std;

void TaskManager::add_task(const string& task, const char& status)
{
    task_list.push_back(task);
    task_status.push_back(status);
    store_to_file(task, status);
}

void TaskManager::view_task_list()
{

    if(!task_list.empty())
    {
        cout << setw(8) << "Your task List" << endl;
        cout << left <<setw(16) << "Tasks" <<  right << "Status" << endl;
        for(int i=0; i<task_list.size(); i++)
        {
            cout << left << setw(16) << task_list[i] << right << task_status[i] << endl;
        }
    }
    else
    {
        cout << "Your task list is empty.\n";
    }

}

void TaskManager::delete_task(const string& task) {
    auto it = std::find(task_list.begin(), task_list.end(), task);

    if (it != task_list.end()) {
        size_t index = std::distance(task_list.begin(), it);
        cout << "Task deleted.\n";
        task_list.erase(task_list.begin() + index);
        task_status.erase(task_status.begin() + index);
        override_old_file();
    } else {
        cout << "The task you searched for does not exist.\n";
    }
}

void TaskManager::clear_task_list() {
    ofstream outFile;
    outFile.open("outfile.txt", ofstream::out | ofstream::trunc); // Open for writing and truncate existing content
    if (!outFile.is_open()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    task_list.clear();
    task_status.clear();
    outFile.flush();
    outFile.close();
}

void TaskManager::change_task_status(const string& task,const char& status)
{

}

void TaskManager::store_to_file(const string& task, const char& status)
{
    ofstream outFile;

    outFile.open("outfile.txt", ios::app);

    if(outFile.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }

    outFile << task << " " << status << "\n";
    outFile.close();

}

void TaskManager::override_old_file()
{
    ofstream outFile;

    outFile.open("outfile.txt");

    if(outFile.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }

    outFile.flush();

    for(int i=0; i<task_list.size(); i++)
    {
        outFile << task_list[i] << task_status[i] << "\n";
    }
    outFile.close();
}

void TaskManager::get_from_file()
{
    ifstream inFile;
    inFile.open("outfile.txt");
    if(!inFile.is_open())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    else
    {
        string task;
        char status;

        while(inFile >> task >> status)
        {
            task_list.push_back(task);

            if(islower(status))
                status = toupper(status);

            task_status.push_back(status);
        }
    }

    inFile.close();
}