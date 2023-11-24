#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Song {
public:
    string title, genre;
    int broadcast, download;
    double filesize;
    Song(string title, string genre, int broadcast, double filesize, int download) :
        title(title), genre(genre), broadcast(broadcast), filesize(filesize), download(download) {}
};

bool comp_song(Song songA, Song songB) {
    //first, compare broadcast
    //second, compare download
    //third, compare filesize
    if(songA.broadcast != songB.broadcast) return songA.broadcast > songB.broadcast;
    else if(songA.download != songB.download) return songA.download > songB.download;
    else return songA.filesize < songB.filesize;
}

int main() {
    int numOfsongs, songRank;
    string title, genre;
    int broadcast, download;
    double filesize;
    vector<Song> songComb;

    //input
    cin >> numOfsongs >> songRank;

    for(int i = 0; i < numOfsongs; i++) {
        cin >> title >> genre >> broadcast >> filesize >> download;
        songComb.push_back(Song(title, genre, broadcast, filesize, download));
    }

    //sort
    sort(songComb.begin(), songComb.end(), comp_song);

    //but, can't same genre next rank. if there are any different genre at all, then it can
    for(int i = 1; i < numOfsongs; i++) {
        if(songComb[i-1].genre == songComb[i].genre) {
            for(int j = i; j < numOfsongs; j++) {
                if(songComb[i].genre != songComb[j].genre) {
                    songComb.emplace(songComb.begin() + i, songComb[j]);
                    songComb.erase(songComb.begin() + j + 1);
                    break;
                }
            }
        }
    }

    /*
    //correct sort check
    for(int i = 0; i < numOfsongs; i++) {
        cout << songComb[i].title << " " << songComb[i].genre << " " << songComb[i].broadcast << " " << songComb[i].filesize << " " << songComb[i].download << endl;
    }
    */

    //answer
    cout << songComb[songRank-1].title << endl;

}
