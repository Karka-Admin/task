#include <iostream>
#include <vector>
#include "files.hpp"

Files files;

void help_message(void)
{
    std::cout << "\tTask - cli tool to manage your tasks\n" <<
    "Usage: task [option] [argument]\n" <<
    "Options:\n" <<
    "-h | Show help message\n" <<
    "-l | List tasks\n" <<
    "-c | Create a new task\n" << 
    "-d | Delete task\n" <<
    "-f | Finish task\n" <<
    "-e | Edit a task\n";
}

void create_task(const std::string &name)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);
    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    taskFile.open(files.taskFileDir, std::ios::out | std::ios::trunc);

    std::string nameAndAttr = name + " |u|";

    buffer.push_back(nameAndAttr);
    files.buffer_to_file(taskFile, buffer);
    
    std::cout << "\nCreated task: " << name << "\n\n";

    taskFile.close();
}

void finish_task(int taskNumber)
{
    
}

void edit_task(int taskNumber)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);
    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    taskFile.open(files.taskFileDir, std::ios::out | std::ios::trunc);



    taskFile.close();
}

void delete_task(int taskNumber)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);
    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    taskFile.open(files.taskFileDir, std::ios::out | std::ios::trunc);

    std::cout << "\nDeleted task: " << buffer[taskNumber - 1] << "\n\n";

    buffer.erase(buffer.begin() + taskNumber - 1);
    files.buffer_to_file(taskFile, buffer);

    taskFile.close();
}

void list_tasks(void)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);

    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    std::cout << '\n';
    for (int i = 0; i < buffer.size(); i++)
    {
        std::cout << i + 1 << ". " << buffer[i] << '\n';
    }
    std::cout << '\n';
}