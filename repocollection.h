#include <vector>
#include <iostream>
#include <string>

class RepoCollection {
    private:
        static RepoCollection* instance;
        std::vector<std::string>* repo_names;
        RepoCollection();
        ~RepoCollection();

    protected:
    public:
        static RepoCollection* getInstance();
        void add(const char* name, const char* filepath);
        void print();
};
