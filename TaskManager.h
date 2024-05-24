//TaskManager class definition
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class TaskManger{
    public:
        void add_task(const string& task, ofstream& outfile);
        void view_task_list(ifstream& inFile);
        void delete_task(const string& task, ifstream& inFile);
        void change_task_status(const string& task);
        void get_task_list(ifstream& inFile);
    
    private:
        vector<string> task_list;
        vector<char> task_status;
}