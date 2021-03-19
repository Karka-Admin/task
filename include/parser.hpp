#include <iostream>
#include "actions.hpp"
using namespace std;

class Parser
{
public:

    // Gets and does arguments from command line
    void do_args(int argc, char **argv)
    {
        if (argc > 1)
        {
            for (int i = 1; i <= argc; i++)
            {
                if ((string) argv[i] == "-h" || (string) argv[i] == "--help")
                {
                    help_message();
                    break;
                }
                else if (((string) argv[i] == "-n" || (string) argv[i] == "--new") && i + 1 <= argc)
                {
                    create_task(argv[i + 1]);
                    break;
                }
                else
                {
                    cerr << "Argument " << argv[i] << " unrecognized.\n";
                    break;
                }
            }
        }
        else
        {
            cerr << "Not enough arguments.\n";
        }
    }
};