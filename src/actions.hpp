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
    "-n | Create a new task\n" << 
    "-d | Delete task\n" <<
    "-f | Finish task\n" <<
    "-e | Edit a task\n";
}

void create_task(const std::string &name)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);
    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    buffer[0] = std::to_string(atoi(buffer[0].c_str()) + 1);

    taskFile.open(files.taskFileDir, std::ios::out | std::ios::trunc);
    
    buffer.push_back(name);
    files.buffer_to_file(taskFile, buffer);
    
    std::cout << "Created task: " << name;

    taskFile.close();
}

void finish_task(int taskNumber)
{
    
}

void edit_task(int taskNumber)
{

}

void delete_task(int taskNumber)
{
    
}

void list_tasks(void)
{
    std::fstream taskFile;
    files.error_check_file(taskFile);

    std::vector<std::string> buffer = files.file_to_buffer(taskFile);

    std::cout << "\n";
    for (int i = 1; i < buffer.size(); i++)
    {
        std::cout << i << ". " << buffer[i] << "\n";
    }
    
    std::cout << "\nTotal tasks: " << buffer[0] << ".\n\n";
}