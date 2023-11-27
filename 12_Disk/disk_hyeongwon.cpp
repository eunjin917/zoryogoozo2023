#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef struct {
    int fStart, fEnd;
    string fName;
    int size() { return fEnd - fStart; }
} File;

class Disk {
private:
    int maxCap, dCap = 0;
    list<File> disk;
    vector<string> fNameC;
public:
    Disk(int dSize) : maxCap(dSize) {
        disk.pb({0, dSize, ""});
    }

    vector<string>::iterator has(string fName) {
        return find(fNameC.begin(),fNameC.end(),fName);
    }

    void fulldisk(list<File>& newL) {
        if(newL.back().fEnd != maxCap) {
            newL.pb({newL.back().fEnd,maxCap,""});
        }
        if(newL.front().fEnd == 0) {
            newL.pop_front();
        }
        disk = newL;
    }


    void w_disk(string fName, int fSize) {

        if(has(fName) != fNameC.end()) {
            cout << "error" << endl;
            return;
        }

        if(fSize > maxCap - dCap) {
            cout << "diskfull" << endl;
            return;
        }

        dCap += fSize;
        fNameC.pb(fName);

        list<File> newL {{0,0,""}};

        bool split = true;

        for(File x : disk) {
            if(x.fName == "" && x.size() >= fSize) {
                split = false;
                break;
            }
        }

        for(File w : disk) {

            if(newL.back().fEnd != w.fStart) {
                newL.pb({newL.back().fEnd,w.fStart,""});
            }

            if(fSize > 0 && w.fName == "") {
                if(split && w.size() < fSize) {
                    w.fName = fName;
                    fSize -= w.size();
                    newL.pb(w);
                    continue;
                }
                if(w.size() >= fSize) {
                    w.fName = fName;
                    w.fEnd = w.fStart + fSize;
                    fSize = 0;
                }
            }

            newL.pb(w);
        }

        fulldisk(newL);
    }

    void s_disk(string fName) {

        if(has(fName) == fNameC.end()) {
            cout << "error" << endl;
            return;
        }

        for(File w : disk) {
            if(w.fName == fName) {
                cout << w.fStart << " ";
            }
        }
        cout << endl;
    }

    void d_disk(string fName) {

        if(has(fName) == fNameC.end()) {
            cout << "error" << endl;
            return;
        }

        list<File> newL {{0,0,""}};

        for(File w : disk) {
            if(w.fName == fName) {
                w.fName = "";
                dCap -= w.size();
            }

            if(newL.back().fName == w.fName) {
                newL.back().fEnd = w.fEnd;
            }
            else {
                newL.pb(w);
            }
        }

        fulldisk(newL);

        fNameC.erase(has(fName));
    }

    void c_disk() {
        list<File> newL{{0,0,""}};

        for(File w : disk) {
            if(w.fName != "") {
                if(newL.back().fName == w.fName) {
                    newL.back().fEnd += w.size();
                }
                else {
                    int fSize = w.size();
                    w.fStart = newL.back().fEnd;
                    w.fEnd = w.fStart + fSize;
                    newL.pb(w);
                }
            }
        }

        fulldisk(newL);
    }
};

int main() {
    int dSize, fSize;
    string op, fName;

    cin >> dSize;

    Disk disk(dSize);

    while(true) {
        cin >> op;

        if(op == "end") break;
        else if(op == "write") {
            cin >> fName >> fSize;
            disk.w_disk(fName, fSize);
        }
        else if(op == "show") {
            cin >> fName;
            disk.s_disk(fName);
        }
        else if(op == "delete") {
            cin >> fName;
            disk.d_disk(fName);
        }
        else disk.c_disk();
    }
}
