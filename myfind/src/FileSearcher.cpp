#include "FileSearcher.hpp"
#include "ProcessFactory.hpp"

void FileSearcher::AddFileName(const std::string &filename)
{
    mFileNames.emplace(filename);
}

void FileSearcher::Start()
{
    // TODO:
    // go through mFileNames and create a child process for each entry via ProcessFactory
    // that child process starts at mSearchPath and searches through all files in that folder
    // and, if recursive is set, through all folders as well
    // if child process finds a target send the path of that file back to the parent process
    // if not do nothing, either way terminate the child process and let parent process know
}