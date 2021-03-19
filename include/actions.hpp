#include <iostream>
#include <vector>
#include "files.hpp"
using namespace std;

task::Files files;

void help_message()
{
    cout << "Task\n" <<
    "Options:\n" <<
    "-h | --help\t Show help message\n" <<
    "-n | --new\t Create a new task\n" << 
    "-d | --delete\t Delete task\n" <<
    "-f | --finish\t Finish task\n";
}

void create_task(string name)
{
    int taskCount = 0;

    vector<string> buffer = {};
    string temp = "";

    fstream taskFile;
    files.file_exists(taskFile, files.taskFileDir);

    
    taskFile.close();
}