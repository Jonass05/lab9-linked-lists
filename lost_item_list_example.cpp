/*
 * Course: COEN 2220 - Programming 2
 * Name: [John Badillo Lamourt]
 * Lab: Lab 9 - Linked Lists
 * Description: Guided example - a linked list of lost-item codes
 * Due date: [october 16, 2026]
 */

#include <iostream>
#include <string>
using namespace std;

class LostItemList
{
private:
    struct Node
    {
        string itemCode; // Store one lost-item code.
        Node *next;      // Store the address of the next node.
    };

    Node *head;          // Store the first node address or nullptr.

public:
    LostItemList()
    {
        head = nullptr;  // A new list begins with no nodes.
    }

    bool isEmpty() const
    {
        return head == nullptr; // No first node means the list is empty.
    }

    // --- STEP B2: Add one item at the end ---
    
    void addItem(const string& newItemCode)
    {
        Node *newNode = new Node;
        newNode->itemCode = newItemCode;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }
    

    // --- STEP B3: Traverse and search the list ---
    
    void display() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Lost item: " << currentNode->itemCode << endl;
            currentNode = currentNode->next;
        }
    }

    bool contains(const string& targetItemCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->itemCode == targetItemCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
    
};

int main()
{
    cout << boolalpha; // Print bool results as true or false.

    LostItemList lostItems;

    cout << "List starts empty: " << lostItems.isEmpty() << endl;

    // --- STEP B2: Add dummy lost-item codes ---
    
    lostItems.addItem("LF-104");
    lostItems.addItem("LF-215");
    lostItems.addItem("LF-330");

    cout << "List starts empty after additions: "
         << lostItems.isEmpty() << endl;
    

    // --- STEP B3: Display and search stored codes ---
    
    lostItems.display();
    cout << "Contains LF-215: " << lostItems.contains("LF-215") << endl;
    cout << "Contains LF-999: " << lostItems.contains("LF-999") << endl;
    

    return 0;
}

/*
 * Analysis Answers
 *
 * B4 — Appending LF-330
 * When addItem("LF-330") reaches its final assignment, which node does head point to,
 * which node does currentNode point to, and what link is created? Explain why head does
 * not change in this case.
 * Answer:
 * Head continues to point to the very first node (LF-104), while currentNode points to the last node (LF-330) before the new node is added. 
 * The link created is from LF-215's next pointer to the new node LF-330. 
 * Head does not change because it always points to the first node in the list, and adding a new item at the end does not affect the first node.
 * 
 * B5 — Traversal and linear search
 * What traversal step do display and contains have in common? What is different about
 * the action each function performs at a node, and why may contains stop earlier?
 * Answer:
 *Both functions initialize a working pointer Node (*currentNode = head;) and advance it iteratively using (currentNode = currentNode->next;) until currentNode reaches nullptr.
 the difference is that display prints the itemCode of each node, while contains checks if the itemCode matches the targetItemCode. 
 Contains may stop earlier if it finds a match, while display continues until the end of the list.
 */