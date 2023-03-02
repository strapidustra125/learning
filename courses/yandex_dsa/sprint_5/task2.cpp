/************************************************************************** 
 * 
 * Успешная попытка: 83045467 
 * 
 * -- ПРИНЦИП РАБОТЫ -- 
 * 
 *  При удалении элемента, на его место перемещается наименьший элемент из  
 * правого поддерева. 
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ -- 
 * 
 *  Минимальный элемент правого поддерева будет больше любого элемента в  
 * левом поддереве, принцип построения бинарного дерева поиска сохранится. 
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ -- 
 * 
 *  Временная сложность в худшем случае - дойти до самого дальнего листа от  
 * корня, т.е. на высоту дерета, т.е. O(log(n)), где n - число узлов в  
 * дереве. 
 * 
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ -- 
 * 
 *  Cтек вызовов рекурсии - O(log(n)), где n - число узлов в дереве. 
 * 
 *************************************************************************/ 
 
#ifndef REMOTE_JUDGE 
struct Node { 
    int value; 
    Node* left = nullptr; 
    Node* right = nullptr; 
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {} 
}; 
#endif 
#ifdef REMOTE_JUDGE 
#include "solution.h" 
#endif 
#include <cassert> 
 
Node * _findMinElement(Node * node)  
{ 
    if (!node->left) return node; 
    return _findMinElement(node->left); 
} 
 
Node * _remove(Node* currentNode, int itemValue)  
{ 
    if (currentNode->value == itemValue)  
    { 
        if (!currentNode->left && !currentNode->right) return nullptr; 
        if (!currentNode->left) return currentNode->right; 
        if (!currentNode->right) return currentNode->left; 
         
        Node * minNodeInRightSubtree = _findMinElement(currentNode->right); 
        currentNode->value = minNodeInRightSubtree->value; 
 
        currentNode->right = _remove(currentNode->right, minNodeInRightSubtree->value); 
        return currentNode; 
    } 
 
    if (itemValue < currentNode->value)  
    { 
        if (!currentNode->left) return currentNode; 
        currentNode->left = _remove(currentNode->left, itemValue); 
        return currentNode; 
    } 
 
    if (itemValue > currentNode->value)  
    { 
        if (!currentNode->right) return currentNode; 
        currentNode->right = _remove(currentNode->right, itemValue); 
        return currentNode; 
    } 
} 
 
Node* remove(Node* root, int key)  
{ 
    if (!root) return nullptr; 
    return _remove(root, key); 
} 
 
#ifndef REMOTE_JUDGE 
void test() { 
    Node node1({ nullptr, nullptr, 2 }); 
    Node node2({ &node1, nullptr, 3 }); 
    Node node3({ nullptr, &node2, 1 }); 
    Node node4({ nullptr, nullptr, 6 }); 
    Node node5({ &node4, nullptr, 8 }); 
    Node node6({ &node5, nullptr, 10 }); 
    Node node7({ &node3, &node6, 5 }); 
    Node* newHead = remove(&node7, 10); 
    assert(newHead->value == 5); 
    assert(newHead->right == &node5); 
    assert(newHead->right->value == 8); 
} 
 
int main() { 
    test(); 
} 
#endif 