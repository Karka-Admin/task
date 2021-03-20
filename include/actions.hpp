#include <iostream>
#include <vector>
#include "files.hpp"
using namespace std;

task::Files files;

void help_message()
{
    cout << "\tTask - cli tool to manage your tasks\n" <<
    "Usage: task [options]\n" <<
    "Options:\n" <<
    "-h | --help\t Show help message\n" <<
    "-l | --list\t List tasks\n" <<
    "-n | --new\t Create a new task\n" << 
    "-d | --delete\t Delete task\n" <<
    "-f | --finish\t Finish task\n";
}

// Appends new task to tasks.txt
void create_task(string name)
{
    fstream taskFile;
    files.file_exists(taskFile, files.taskFileDir);

    taskFile.open(files.taskFileDir, ios::app);

    taskFile << endl << name;

    taskFile.close();
}

void delete_task(int taskNumber)
{

}

// Lists all tasks from tasks.txt
void list_tasks()
{
    int counter = 1;
    string task = "";

    fstream taskFile;
    files.file_exists(taskFile, files.taskFileDir);

    taskFile.open(files.taskFileDir);

    while (!taskFile.eof())
    {
        getline(taskFile, task);
        cout << counter << ". " << task << "\n";
        counter++;
    }

    taskFile.close();
}