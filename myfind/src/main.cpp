#include <iostream>
#include <exception>
#include <unistd.h>

#include "FileSearcher.hpp"

void PrintUsage();

int main(int argc, char **argv)
{
    int opt;
    bool error{false};
    FileSearcher searcher;

    while ((opt = getopt(argc, argv, "Ri")) != EOF)
    {
        switch (opt)
        {
        case 'R':
            if (searcher.Recursive())
            {
                error = true;
                break;
            }
            searcher.SetRecursive(true);
            std::cout << "Searching folders\n";
            break;
        case 'i':
            if (searcher.CaseInsensitive())
            {
                error = true;
                break;
            }
            searcher.SetCaseInsensitive(true);
            std::cout << "Case-Insensitive search\n";
            break;
        case '?':
            error = true;
            break;
        default:
            throw std::domain_error("Unreachable code location");
        }
    }

    if (error)
    {
        PrintUsage();
        return EXIT_FAILURE;
    }

    searcher.Start();

    return EXIT_SUCCESS;
}

void PrintUsage()
{
    std::cout << "myfind usage:\n";
    std::cout << "./myfind [-R] [-i] <searchpath> <filename1> [filename2] ... [filenameN]" << std::endl;
}