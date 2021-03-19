#include <iostream>
using namespace std;

class Parser
{
public:

    bool get_actions(int argc, char **argv)
    {
        if (argc > 1)
        {
            for (int i = 1; i <= argc; i++)
            {
                if (argv[i] == "-n" && i + 1 <= argc)
                {
                    
                    break;
                }
            }
        }

        return true;
    }
};