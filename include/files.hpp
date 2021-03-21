#include <fstream>
#include <filesystem>
using namespace std;

namespace task
{
    class Files
    {
    public:

        string homePath = getenv("HOMEPATH");
        string taskFileDir = homePath + "/tasks.txt";

        // Count amount of tasks
        int count_tasks(fstream &file)
        {
            string temp;
            int counter = 0;
            while (!file.eof())
            {
                file >> temp;
                if (temp == "\n")
                {
                    counter++;
                }
            }
            return counter;
        }

        // Checks if file exists
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
    };
}