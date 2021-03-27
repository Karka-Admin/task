#include <fstream>

class Files
{

public:

    std::string homePath = getenv("HOMEPATH");
    std::string taskFileDir = homePath + "/tasks.txt";

    // Writes data from file to buffer
    std::vector<std::string> file_to_buffer(std::fstream &file)
    {
        std::vector<std::string> buffer;
        std::string data;

        file.open(taskFileDir);

        while (getline(file, data))
        {
            buffer.push_back(data);
        }

        file.close();

        return buffer;
    }

    void buffer_to_file(std::fstream &file, std::vector<std::string> &buffer)
    {
        for (int i = 0; i < buffer.size(); i++)
        {
            file << buffer[i] << '\n';
        }

        file.clear();
    }

    void error_check_file(std::fstream &file)
    {
        file.open(taskFileDir);
        if (file.is_open())
        {
            file.close();
        }
        else
        {
            std::ofstream newFile(taskFileDir);
            newFile << 0;
            newFile.close();
        }
    }
};