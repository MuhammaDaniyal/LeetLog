/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> nodes;

public:

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }

    Node* dfs(Node* original)
    {
        if (original == nullptr) return nullptr;
        Node* copying = new Node(original->val);
        nodes[original->val] = copying;

        for (Node* e : original->neighbors)
        {
            if (!nodes[e->val])
            {
                copying->neighbors.push_back(dfs(e));
            }
            else
            {
                copying->neighbors.push_back(nodes[e->val]);
            }

        }
        return copying;
    }

};

