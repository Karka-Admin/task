#include <unistd.h>
#include "actions.hpp"

class Parser
{
public:

    // Parses argv and calls corresponding functions
    void parse_args(int &argc, char **argv)
    {
        int opt;
        opterr = 0;

        if (argc > 1)
        {
            while ((opt = getopt(argc, argv, "hlc:d:")) != -1)
            {
                switch (opt)
                {
                    case 'h': help_message(); break;
                    case 'l': list_tasks(); break;
                    case 'c': create_task(optarg); break;
                    case 'd': delete_task(atoi(optarg)); break;
                    case 'f': finish_task(atoi(optarg)); break;
                    case 'e': edit_task(atoi(optarg)); break;
                    case '?':
                        std::cout << "Problem with command: -" << (char) optopt << '\n';
                        abort();
                        break;
                    default: abort();
                }
            }
        }
        else
        {
            std::cout << "Not enough arguments.\n";
        }
    }
};