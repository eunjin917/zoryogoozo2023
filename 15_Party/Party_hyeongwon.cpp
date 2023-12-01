#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> road;
array<char, 3> startNode;
array<map<char, int>, 3> allDist;
array<map<char, bool>,3> allVisited;

void bfs(char start, map<char, int>& dist, map<char, bool>& visited) {
    queue<char> q;

    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        for (char neighbor : road[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                dist[neighbor] = dist[current] + 1;
                if(dist[neighbor] > 1) {
                    dist[neighbor] += 2;
                }
            }
        }
    }
}

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    char nodeName, linkedNode;
    int nodeCount;
    vector<char> nodes;

    cin >> nodeCount;
    for (int i = 0; i < 3; i++) {
        cin >> nodeName;
        startNode[i] = nodeName;
    }

    while (nodeCount-- > 0) {
        cin >> nodeName;
        road[nodeName];
        nodes.push_back(nodeName);
        while (cin >> linkedNode) {
            if (linkedNode == '$') break;
            road[nodeName].push_back(linkedNode);
        }
    }

    bool canMeet = false;
    for (int i = 0; i < 3; i++) {
        map<char, int> dist;
        map<char, bool> visited;

        bfs(startNode[i], dist, visited);
        allDist[i] = dist;
        allVisited[i] = visited;
    }

    if(allVisited[0] == allVisited[1] && allVisited[0] == allVisited[2]) {
        canMeet = true;
    }

    if(canMeet) {
        vector<pair<char, int>> sortedNodes;
        for (char w : nodes) {
            sortedNodes.emplace_back(w, max({allDist[0][w], allDist[1][w], allDist[2][w]}));
        }
        sort(sortedNodes.begin(), sortedNodes.end(), cmp);

        cout << sortedNodes[0].first << endl << sortedNodes[0].second << endl;
    }
    else {
        cout << "@" << endl << -1 << endl;
    }
}
