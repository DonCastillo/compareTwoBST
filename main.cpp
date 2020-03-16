/**
*   @author Don Castillo
*   @date 16/03/2020
*   @brief  Assignment 4
*
*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "BinarySearchTree.h"
#include "Menu.h"

/**
*   @date 16/03/2020
*   @brief  check if both trees are similar
*   @param nodeA    root of the first tree
*          nodeB    root of the second tree
*   @return true if both trees are empty or equal, otherwise false
*/
bool isSimilar(BinarySearchTree<int>::BinaryNode* nodeA,
               BinarySearchTree<int>::BinaryNode* nodeB)
{
    // if both trees are empty
    if(nodeA == nullptr && nodeB == nullptr)
    {
        return true;
    }
    // if one of the nodes is empty when compared
    else if( (nodeA != nullptr && nodeB == nullptr) || (nodeA == nullptr && nodeB != nullptr) )
    {
        return false;
    }
    // if nodes contain same elements
    else if ( nodeA->element == nodeB->element )
    {
        return isSimilar( nodeA->left, nodeB->left ) && isSimilar( nodeA->right, nodeB->right );
    }
    else
    {
        return false;
    }
}

void showData(std::string name, const BinarySearchTree<int> tree)
{
    std::cout << "\n\nData in " << name << " (sorted):\n";
    tree.printTree();
}

void insertElements(int &numOfElements, BinarySearchTree<int> &tree)
{
    int x;
    while(numOfElements > 0)
    {
        std::cout << "Enter unique integer: ";
        std::cin >> x;

        tree.insert(x);
        --numOfElements;
    }
}


int main()
{
    Menu menu("COMPARE TWO BST", "Don Castillo");
    BinarySearchTree<int> treeA;
    BinarySearchTree<int> treeB;
    int aSize = 0, bSize = 0;

    menu.displayTitle();
    menu.displayInstructions();

    std::cout << "\n\n";

    /// Tree A
    std::cout << "\nTree A\n";
    std::cout << "How many integers to input: ";
    std::cin >> aSize;
    insertElements(aSize, treeA);


    /// Tree B
    std::cout << "\nTree B\n";
    std::cout << "How many integers to input: ";
    std::cin >> bSize;
    insertElements(bSize, treeB);




    showData("Tree A", treeA);
    showData("Tree B", treeB);
    std::cout << std::endl << std::endl;
    if( isSimilar(treeA.root, treeB.root) )
    {
        std::cout << "Trees A and B are similar"
    }
    else
    {
        std::cout << "Trees A and B are different"
    }


    return 0;
}










































