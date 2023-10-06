#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// rep 매크로 정의
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Song {
    string title;
    char genre;
    int broadcastCount;
    double fileSize;
    int downloadCount;
};

bool compareSongs(const Song& a, const Song& b) {
    if (a.broadcastCount != b.broadcastCount) {
        return a.broadcastCount > b.broadcastCount;
    } else if (a.downloadCount != b.downloadCount) {
        return a.downloadCount > b.downloadCount;
    } else {
        return a.fileSize < b.fileSize;
    }
}

int main() {
    int N, order;
    cin >> N >> order;

    vector<Song> songs(N);

    rep(i, N) {
        cin >> songs[i].title >> songs[i].genre >> songs[i].broadcastCount >> songs[i].fileSize >> songs[i].downloadCount;
    }
    
    sort(songs.begin(), songs.end(), compareSongs);

    vector<Song> result(N); // 새로운 벡터 생성

    rep(i, N) {
        result[i] = songs[i];
    }

    rep(i, N - 1) {
        // k, k+1의 장르가 같을 때
        if (result[i].genre == result[i + 1].genre) {
            for (int j = i + 2; j < N; j++) {
                if (result[i].genre != result[j].genre) {
                    // 장르가 다른 다음 곡을 특정 곡 + 1의 위치에 삽입
                    result.insert(result.begin() + i + 1, result[j]);
                    result.erase(result.begin() + j + 1);
                    break;
                }
            }
        }
    }

    cout << result[order - 1].title << endl;

    return 0;
}
