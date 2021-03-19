#include <fstream>
using namespace std;

namespace task
{
    class Files
    {
    public:

        string taskFileDir = "tasks.txt";

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
                newFile << 0;
                newFile.close();
            }
        }
    };
}