/*
 * Course: COEN 2220 - Programming 2
 * Name: [John Badillo Lamourt]
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [october 16, 2026]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define a Node with string groupCode, int meetingRoom, and Node *next.
    // TODO (Part C): Declare a Node *head data member for the first node address.
    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
   struct Node {
    string groupCode;
    int meetingRoom;
    Node *next;
   };

   Node *head;
    int groupCount;

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
    StudyGroupList() 
    {
     head = nullptr;
     groupCount = 0;
    }
    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.
    void addGroup(const string newgroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newgroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
        groupCount++;
    }

    
    // TODO (Part D): Write displayGroups as a const member function.
    void displayGroups() const
    {
        Node *currentNode = head;
        while (currentNode != nullptr) {
            cout << "Group Code: " << currentNode->groupCode << ", Meeting Room: " << currentNode->meetingRoom << endl;
            currentNode = currentNode->next;
        }
    }

    // TODO (Part D): Write size as a const member function that returns groupCount.
    int size() const
    {
        return groupCount;
    }

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
    bool containsGroup(const string searchGroupCode) const
    {
        Node *currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->groupCode == searchGroupCode) {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }

};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    StudyGroupList myStudyGroupList;

    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    myStudyGroupList.addGroup("A010", 25);
    myStudyGroupList.addGroup("A020", 45);
    myStudyGroupList.addGroup("A030", 65);

    // TODO (Part E): Display every stored group and print the result of size().
    myStudyGroupList.displayGroups();
    cout << "Number of groups: " << myStudyGroupList.size() << endl;

    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.
    cout << "Contains 'A010': " << myStudyGroupList.containsGroup("A010") << endl;
    cout << "Contains 'A040': " << myStudyGroupList.containsGroup("A040") << endl;

    return 0;
}