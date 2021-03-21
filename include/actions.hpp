#include <iostream>
#include <vector>
#include "files.hpp"
using namespace std;

task::Files files;

void help_message()
{
    cout << "\tTask - cli tool to manage your tasks\n" <<
    "Usage: task [option] [argument]\n" <<
    "Options:\n" <<
    "-h | --help\t Show help message\n" <<
    "-l | --list\t List tasks\n" <<
    "-n | --new\t Create a new task\n" << 
    "-d | --delete\t Delete task\n" <<
    "-f | --finish\t Finish task\n" <<
    "-e | --edit\t Modify a task\n";
}

// Appends new task
void create_task(string name)
{
    fstream taskFile;
    files.file_exists(taskFile, files.taskFileDir);

    taskFile.open(files.taskFileDir, ios::app);

    taskFile << endl << name;

    taskFile.close();
}

// Mark task as finished
void finish_task(int taskNumber)
{
    
}

// Edit task
void edit_task(int taskNumber, string name)
{

}

// Delete task
void delete_task(int taskNumber)
{
    fstream taskFile;
    files.file_exists(taskFile, files.taskFileDir);

    cout << files.count_tasks(taskFile);

    ofstream tempFile("temp.txt");

    tempFile.close();
}

// Lists tasks
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