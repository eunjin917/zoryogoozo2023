#include <bits/stdc++.h>

using namespace std;

struct Person {
    string name;
    vector<Person*> children;
    Person* boss;
    int depth, countNodes;
};

void set_depth(Person* boss, int depth) {
    boss->depth = depth;
    if(boss->children.size() == 0) return;
    else {
        for(auto* child : boss->children) {
            set_depth(child, depth + 1);
        }
    }
}

int set_count_child(Person* boss) {
    int countChild = 1;
    if(boss->children.size() != 0) {
        for(auto* child : boss->children) {
            countChild += set_count_child(child);
        }
    }
    boss->countNodes = countChild - 1;
    return countChild;
}

bool comp_rank(Person* a, Person* b) {
    if(a->countNodes != b->countNodes) {
        return a->countNodes > b->countNodes;
    }
    else if(a->depth != b->depth) {
        return a->depth < b->depth;
    }
    else {
        return a->name < b->name;
    }
}

int main() {
    int n;
    cin >> n;

    map<string, Person*> people;
    vector<Person*> peopleC;

    for (int i = 0; i < n - 1; i++) {
        string childName, bossName;
        cin >> childName >> bossName;

        if (people.find(childName) == people.end()) {
            people[childName] = new Person{childName, {}, nullptr, 0, 0};
        }
        if (people.find(bossName) == people.end()) {
            people[bossName] = new Person{bossName, {}, nullptr, 0, 0};
        }
        people[childName]->boss = people[bossName];
        people[bossName]->children.push_back(people[childName]);
    }

    Person* ultimateBoss = nullptr;
    for (const auto& person : people) {
        if (person.second->boss == nullptr) {
            ultimateBoss = person.second;
            break;
        }
    }

    set_depth(ultimateBoss, 0);
    set_count_child(ultimateBoss);

    for(const auto& w : people) {
        peopleC.push_back(w.second);
    }

    sort(peopleC.begin(), peopleC.end(), comp_rank);

    for(const auto& person : peopleC) {
        cout << person->name << endl;
    }

}
