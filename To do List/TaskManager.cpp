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

        for(int i=0; i<task_list.size(); i++)
        {
            cout << task_list[i] << "\t" <<task_status[i] << endl;
        }
    }
    else
    {
        cout << "Your task list is empty.\n" << endl;
    }

}

void TaskManager::delete_task(const string& task)
{
    auto it = std::find(task_list.begin(), task_list.end(), task);

    if (it != task_list.end())
    {
        size_t index = std::distance(task_list.begin(), it);
        cout << "Task deleted.\n";
        task_list.erase(task_list.begin() + index);
        task_status.erase(task_status.begin() + index);
        override_old_file();
    }
    else
    {
        cout << "The task you searched for does not exist.\n";
    }
}

void TaskManager::clear_task_list()
{
    ofstream outFile;
    outFile.open("outfile.txt", ofstream::out | ofstream::trunc); // Open for writing and truncate existing content
    if (!outFile.is_open())
    {
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
    bool task_found = false;
    // search for the given task in the list of tasks
    for(int i=0; i<task_list.size(); i++)
    {
        if(task_list[i] == task)
        {
            task_status[i] = status;
            task_found = true;
            break;
        }
    }

    // update the output file if the task is found
    if(task_found != true)
        cout << "Task is not in the list.\n" << endl;
    else
        override_old_file();
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

    outFile << task << "," << status << "\n";
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
        outFile << task_list[i] << "," << task_status[i] << "\n";
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
        string line;
        // read a whole line in the file and use
        // a stringstream to split the data in the line by a comma
        while(getline(inFile, line))
        {

            stringstream ss(line);
            string task;
            char status;

            if(getline(ss, task, ',') && ss >> status)
            {
                task_list.push_back(task);

                if(islower(status))
                    status = toupper(status);

                task_status.push_back(status);
            }
        }
    }

    inFile.close();
}
