//递归构造即可，注意同值四个节点的合并
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree2->isLeaf){
            return new Node(quadTree1->val | quadTree2->val, 1);
        }
        if(quadTree1->isLeaf && !quadTree2->isLeaf){
            Node* tl = intersect(quadTree1, quadTree2->topLeft);
            Node* tr = intersect(quadTree1, quadTree2->topRight);
            Node* bl = intersect(quadTree1, quadTree2->bottomLeft);
            Node* br = intersect(quadTree1, quadTree2->bottomRight);
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf){
                if(tl->val == tr->val && tr->val == bl->val && bl->val == br->val){
                    return new Node(tl->val, 1);
                }
            }
            return new Node(0, 0, tl, tr, bl, br);
        }
        if(!quadTree1->isLeaf && quadTree2->isLeaf){
            return intersect(quadTree2, quadTree1);
        }
        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf){
            if(tl->val == tr->val && tr->val == bl->val && bl->val == br->val){
                return new Node(tl->val, 1);
            }
        }
        return new Node(0, 0, tl, tr, bl, br);
    }
};
