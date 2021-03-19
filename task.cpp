#include <iostream>
#include <processenv.h>
#include <fstream>
#include "enums.hpp"
#include "parser.hpp"
using namespace std;

// Checks if file exists, if not creates it
void file_exists(fstream &file, string &filename)
{
    file.open(filename);
    if (file.is_open())
    {
        file.close();
    }
    else
    {
        ofstream newFile(filename);
        newFile.close();
    }
}

void do_actions(int cmd)
{
    
}

int main(int argc, char *argv[])
{
    // string taskFileDir = "tasks.txt";

    // fstream taskFile;
    // file_exists(taskFile, taskFileDir);

    // taskFile.open(taskFileDir);
    
    // taskFile.close();

    Parser parser;
    parser.get_actions(argc, argv);
    return 0;
}