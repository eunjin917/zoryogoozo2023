#include <bits/stdc++.h>

using namespace std;

list<string> diskBlocks, fileNames;
string fileContent, previousBlockContent, userCommand;
list<pair<int, int>> emptyBlockList;
int filesToWrite, totalUsedBlocks = 0, maxDiskCapacity, blockIndex;

void initializeDiskBlocks() {
    cin >> maxDiskCapacity;
    diskBlocks = *new list<string>(maxDiskCapacity);
}

void writeToFile() {
    cin >> fileContent >> filesToWrite;
    if (totalUsedBlocks + filesToWrite > maxDiskCapacity) {
        cout << "diskfull\n";
        return;
    }

    int startIndex, consecutiveEmptyBlocks = 0;
    for (auto& block : diskBlocks) {
        if (block.empty() && block != previousBlockContent) startIndex = blockIndex;
        if (block.empty()) consecutiveEmptyBlocks++;
        if (previousBlockContent.empty() && previousBlockContent != block) {
            emptyBlockList.emplace_back(startIndex, consecutiveEmptyBlocks);
            consecutiveEmptyBlocks = 0;
        }
        previousBlockContent = block;
        blockIndex++;
    }

    emptyBlockList.emplace_back(startIndex, consecutiveEmptyBlocks);
    startIndex = 0;
    blockIndex = 0;

    for (auto& emptyBlock : emptyBlockList) {
        if (emptyBlock.second >= filesToWrite) {
            startIndex = emptyBlock.first;
            break;
        }
    }
    emptyBlockList.clear();

    totalUsedBlocks += filesToWrite;
    fileNames.push_back(fileContent);

    for (auto& block : diskBlocks) {
        if (blockIndex >= startIndex) {
            if (block.empty()) {
                block = fileContent;
                filesToWrite--;
                if (filesToWrite == 0) break;
            }
        }
        blockIndex++;
    }
}

void deleteFile() {
    cin >> fileContent;

    if (find(begin(fileNames), end(fileNames), fileContent) != end(fileNames)) {
        fileNames.remove(fileContent);

        for (auto& block : diskBlocks)
            if (block == fileContent) {
                block = "";
                blockIndex++;
            }
    } else cout << "error\n";
    totalUsedBlocks -= blockIndex;
}

void showFileLocations() {
    cin >> fileContent;
    if (find(begin(fileNames), end(fileNames), fileContent) != end(fileNames))
        for (auto& block : diskBlocks) {
            if (block != previousBlockContent && block == fileContent) cout << blockIndex << " ";
            previousBlockContent = block;
            blockIndex++;
        }
    else cout << "error";
    cout << "\n";
}

int main() {
    initializeDiskBlocks();
    while (true) {
        cin >> userCommand;
        blockIndex = 0;
        previousBlockContent = "_";
        if (userCommand == "end") return 0;
        if (userCommand == "write") writeToFile();
        if (userCommand == "delete") deleteFile();
        if (userCommand == "compact") diskBlocks.remove("");
        diskBlocks.resize(maxDiskCapacity);
        if (userCommand == "show") showFileLocations();
    }
}
