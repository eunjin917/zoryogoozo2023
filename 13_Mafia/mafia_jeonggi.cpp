#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    string name;
    int follower;
    int depth;
    Node* parent;
    set<Node*> child;
    // Node(): follower(0), parent(nullptr) {}
    Node(string name): name(name), follower(0), depth(0), parent(nullptr) {}
    void append_child(Node* child) {
        this->child.insert(child);
    }
    void update_follower() {
        for (auto w: child)
            w->update_follower();
            
        if (parent) {
            parent->follower += follower+1;
        }
    }
    void update_depth() {
        for (auto w: child) {
            w->depth = depth + 1;
            w->update_depth();
        }
    }
    // void print() {
    //     cout << name << " follower-" << follower << " depth-" << depth << endl;
    //     for (auto w: child) {
    //         w->print();
    //     }
    // }
};
Node* make_node(string name) {
    Node* n;
    n = new Node(name);
    return n;
}

bool my_comp(pair<string, Node*> a, pair<string, Node*> b) {
    auto l = a.second;
    auto r = b.second;
    if(l->follower == r->follower) {
        if (l->depth == r->depth)
            return l->name < r->name;

        return l->depth < r->depth;
    }
    return l->follower > r->follower;
}

int main () {
    int N;
    Node* boss, * super, * sub;
    set<string> follower, leader;
    map<string, Node* > mafias;
    string name1, name2;
    cin >> N;

    for (int i=0; i<N-1; ++i) {
        cin >> name1 >> name2;
        auto it = mafias.find(name2);
        if (it == mafias.end()) {
            super = make_node(name2);
            mafias[name2] = super;
        }
        else
            super = it->second;
        
        it = mafias.find(name1);
        if (it == mafias.end()) {
            sub = make_node(name1);
            mafias[name1] = sub;
        }
        else
            sub = it->second;
        sub->parent = super;
        super->append_child(sub);
        leader.insert(name2);
        follower.insert(name1);
    }
    for (auto w: leader)
        if (follower.find(w) == follower.end())
            boss = mafias[w];
    
    boss->update_follower();
    boss->update_depth();
    
    vector<pair<string, Node*> > vec_mafias(mafias.begin(), mafias.end());
    sort(vec_mafias.begin(), vec_mafias.end(), my_comp);
    for (auto w: vec_mafias)
        cout << w.first << endl;

    return 0;
}
