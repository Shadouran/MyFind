#pragma once
#include <unordered_set>
#include <string>

enum class SearchOptions
{
    CaseInsensitive,
    Recursive
};

class FileSearcher
{
public:
    FileSearcher();

    bool Recursive() const { return mRecursive; }
    bool CaseInsensitive() const { return mCaseInsensitive; }
    void SetRecursive(bool enabled) { mRecursive = enabled; }
    void SetCaseInsensitive(bool enabled) { mCaseInsensitive = enabled; }

    void AddFileName(const std::string &filename);
    void SetSearchPath(const std::string &path);

    void Start();

private:
    std::unordered_set<std::string> mFileNames;
    std::string mSearchPath;

    bool mRecursive;
    bool mCaseInsensitive;
};