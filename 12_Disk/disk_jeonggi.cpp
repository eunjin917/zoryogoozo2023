#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>

#define LIST                list<File>
#define MAP                 map<string, set<int> >

#define DISKFULL            cout << "diskfull" << endl
#define ERROR               cout << "error" << endl
#define IsFileExist(fname)  (f_table.find(fname) != f_table.end())

using namespace std;

class File {
public:
    int type, pos, size;
    string name;
    File(int type, int pos, int size, string name=""): type(type), pos(pos), size(size), name(name) {} 
};

class FileSystem {
    MAP  f_table;
    LIST node_list;

    int try_write_whole(string fa, int sa);
    int try_write_split(string fa, int sa);
    void write_(string fa, int sa);
    void show_(string fa);
    void compact_();
    void delete_(string fa);
public:
    FileSystem(int volume) {
        node_list = {File(EOF, volume, 0)};
    }
    void run() {
        string cmd, fa;
        int sa;

        cin >> cmd;

        while (cmd != "end") {
            switch (cmd[0]) {
                case 'w':
                    cin >> fa >> sa;
                    write_(fa, sa);
                    break;
                case 's':
                    cin >> fa;
                    show_(fa);
                    break;
                case 'c':
                    compact_();
                    break;
                case 'd':
                    cin >> fa;
                    delete_(fa);
                    break;
            }
            cin >> cmd;
        }
    }
};

int main() {
    int volume;
    
    cin >> volume;
    
    FileSystem FS(volume);
    FS.run();
    
    return 0;
}

int FileSystem::try_write_whole(string fa, int sa)
{
    int free_pos=0;
    auto it = node_list.begin();
    for (; it != node_list.end(); free_pos = it->pos + (it++)->size)
        if (it->pos - free_pos >= sa)
            break;
    
    if (it == node_list.end())
        return 1;
    
    f_table[fa].insert(free_pos);
    node_list.insert(it, File(1, free_pos, sa, fa));
    return 0;
}

int FileSystem::try_write_split(string fa, int sa)
{
    int size_to_write, free_pos = 0;

    f_table[fa] = set<int>();
    auto it = node_list.begin();
    for (; it != node_list.end(); free_pos = it->pos + (it++)->size) {
        size_to_write = it->pos - free_pos;
        if (size_to_write) {
            f_table[fa].insert(free_pos);
            if (size_to_write > sa)
                size_to_write = sa;

            node_list.insert(it, File(1, free_pos, size_to_write, fa));
            sa -= size_to_write;
        }
        if (!sa)
            return 0;
    }
    return 1;
}

void FileSystem::write_(string fa, int sa)
{
    if (IsFileExist(fa)) {
        ERROR;
        return;
    }

    if (try_write_whole(fa, sa)) {
        if (try_write_split(fa, sa)) {
            delete_(fa);
            DISKFULL;
            return;
        }
    }
}
void FileSystem::show_(string fa)
{
    if (!IsFileExist(fa)) {
        ERROR;
        return;
    }

    for (auto w: f_table[fa])
        cout << w << " ";

    cout << endl;
}

void FileSystem::compact_()
{
    if (f_table.empty())
        return;
    f_table.clear();

    auto it = node_list.begin();
    int new_pos = 0;
    while (it->type != EOF) {
        auto fname = it->name;
        it->pos = new_pos;
        f_table[fname].insert(it->pos);
        new_pos += it->size;

        if (fname == (++it)->name) {
            int size_to_add = it->size;
            it = node_list.erase(it);
            (--it)->size += size_to_add;
            new_pos = it->pos;
        }
    }
}
void FileSystem::delete_(string fa)
{
    if (!IsFileExist(fa)) {
        ERROR;
        return;
    }
    f_table.erase(fa);

    auto it = node_list.begin();
    while (it->type != EOF) {
        if(it->name == fa)
            it = node_list.erase(it);
        else
            ++it;
    }
}
