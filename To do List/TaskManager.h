//TaskManager class definition
#ifndef TASKMANAGER.H
#define TASKMANAGER.H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TaskManager{
    public:
        void add_task(const string& task, const char& status);
        void view_task_list();
        void delete_task(const string& task);
        void change_task_status(const string& task,const char& status);
        void store_to_file(const string& task, const char& status);
        void override_old_file();
        void get_from_file();
        void clear_task_list();
    private:
        vector<string> task_list;
        vector<char> task_status;
};
#endif
