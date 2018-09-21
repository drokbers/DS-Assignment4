//  Roster Number / s  :         (YOUR ROSTER NUMBER HOESKIBROSKI) && 02
//
// Author / s : Conor Schindel and Jacob Benavente
//  Due Date  : Monday March 7th , 2016
//  Programming Assignment Number  4
//
//  Spring   2016   -   CS 3358    -    Section  Number 253
//
//  Instructor:    Husain Gholoom.
//
//  <Brief description of the  purpose of the program>



#include <iostream>
#include <cstdlib>
//#include <ctime>
#include <cstddef>
#include <ctype.h>

using namespace std;

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
class linkedList
{

    private:
        struct listNode
        {
            int value;
            struct listNode *next;
        };
        listNode *head;


    public:
        linkedList();
        ~linkedList();

        void appendNode(int);
        int insertNode(int);
        void deleteNode(int);
        void displayList();
        void searchList(int);
        void emptyList();
        void rotateList();
        void displayBackwards();
        void splitList();
        void deleteDup ();
        void deleteList();
        bool isPresent(int);



};



int main()
{

    char choice;
    int choiceN;
    linkedList list;
    srand((unsigned)time(NULL));
    int placeholder = 0;


    cout << "\tA. Build a sorted list of 20 random integer numbers that are less than or equal to 10.\n";
    cout << "\tB. Insert new number.\n";
    cout << "\tC. Search the main list for a given item or number.\n";
    cout << "\tD. Remove an existing number from the lists.\n";
    cout << "\tE. Check if empty.\n";
    cout << "\tF. Rotate list two positions.\n";
    cout << "\tG. Display the main list backwards.\n";
    cout << "\tH. Split the list into two sub lists.\n";
    cout << "\tI. Delete duplicate numbers.\n";
    cout << "\tJ. Delete entire list.\n";
    cout << "\tX. Exit the program.\n\n";



    do{

        cout << "Please select an option: ";
        cin >> choice;


        switch(choice)
        {
            case 'a':
            case 'A':
                for(int x = 0; x < 20; ++x)
                {
                    placeholder = rand() % 10;
                    list.appendNode(placeholder);
                }

                list.displayList();
                cout << endl;
                break;
            case 'b':
            case 'B':
                cout << "Please enter an integer: ";
                cin >> choiceN;

                while(cin.fail())
                {
                    cout << "invalid input" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "Please enter a valid input: ";
                    cin >> choiceN;
                }
                list.insertNode(choiceN);
                list.displayList();
                cout << endl;
                break;
            case 'c':
            case 'C':
                cout << "Please enter value you want to search for: ";
                cin >> choiceN;
                list.searchList(choiceN);
                break;
            case 'd':
            case 'D':
                cout << "Please enter value you want to delete: ";
                cin >> choiceN;
                while(cin.fail())
                {
                    cout << "invalid input" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "Please enter a valid input: ";
                    cin >> choiceN;
                }
                list.deleteNode(choiceN);
                list.displayList();
                cout << endl;
                break;
            case 'e':
            case 'E':
                list.emptyList();
                break;
            case 'f':
            case 'F':
                list.rotateList();
                list.displayList();
                cout << endl;
                break;
            case 'g':
            case 'G':
                list.displayBackwards();
                list.displayList();
                cout << endl;
                break;
            case 'h':
            case 'H':

                list.splitList();
                cout << endl;
                break;
            case 'i':
            case 'I':
                list.deleteDup();
                list.displayList();
                cout << endl;
                break;
            case 'j':
            case 'J':
                list.deleteList();
                list.displayList();
                break;
            case 'x':
            case 'X':
                break;
            default: cout << "Invalid choice." << endl;


        }

    }while(choice != 'x' && choice != 'X');

    cout << "\nThank you.";
    cout << "\nThis program was implemented By Conor Schindel and Jacob Benavente" << endl;

    return 0;

}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
linkedList::linkedList()
{
    head = NULL;
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
linkedList::~linkedList()
{
    listNode *nodePtr;
    listNode *nextNode;
    nodePtr = head;
    while(nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::appendNode(int num)
{
    listNode *newNode;
    newNode = new listNode;
    newNode->value = num;
    newNode->next = NULL;

    if(!head)
    {
        head = newNode;
    }

    else
    {
        listNode *nodePtr;
        nodePtr = head;

        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }

    for(listNode *nodePtr1 = head; nodePtr1 != NULL; nodePtr1 = nodePtr1->next)
    {
        listNode *smallerNum = nodePtr1;

        for(listNode *nodePtr2 = nodePtr1->next; nodePtr2 != NULL; nodePtr2 = nodePtr2->next)
        {
            if (nodePtr2->value < smallerNum->value)
            {
                smallerNum = nodePtr2;
            }

        }

        if (nodePtr1 != smallerNum)
        {
            int temp = smallerNum->value;
            smallerNum->value = nodePtr1->value;
            nodePtr1->value = temp;
        }
    }
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::displayList()
{
    listNode *nodePtr;
    nodePtr = head;
    while(nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
int linkedList::insertNode(int num)
{
    listNode *newNode;
    listNode *nodePtr;
    listNode *previousNode;

    newNode = new listNode;
    newNode->value = num;

    if(!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;
        previousNode = NULL;

        while(nodePtr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }

        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::deleteNode(int num)
{
    if(!head)
    {
        cout << "The list is empty.";
        return;
    }


    listNode *nodePtr;

    if(head->value == num)
    {
        nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
    }
    else
    {
        listNode *previousNode;
        nodePtr = head;

        while(nodePtr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
        else
            return;
    }
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::emptyList()
{
    if(!head)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "List is not empty." << endl;
    }
}
//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::deleteList()
{
    if(!head)
    {
        cout << "List is empty." << endl;
    }
    else
    {
       listNode *current = head;

        while(head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
}
//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::displayBackwards()
{
    if(!head)
    {
        cout << "The list is empty.";
        return;
    }


    for(listNode *nodePtr1 = head; nodePtr1 != NULL; nodePtr1 = nodePtr1->next)
    {
        listNode *largerNum = nodePtr1;

        for(listNode *nodePtr2 = nodePtr1->next; nodePtr2 != NULL; nodePtr2 = nodePtr2->next)
        {
            if (nodePtr2->value > largerNum->value)
                largerNum = nodePtr2;
        }


        if (nodePtr1 != largerNum)
        {
            int temp = largerNum->value;
            largerNum->value = nodePtr1->value;
            nodePtr1->value = temp;
        }
    }
}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::searchList(int number)
{
    listNode *nodePtr = head;
    bool flag1 = false;
    while(nodePtr)
    {
        if(number == nodePtr->value)
        {
            flag1 = true;
        }

        nodePtr = nodePtr->next;

    }
    if(flag1 == true)
    {
        cout << "Number is in the list." << endl;
    }
    else
    {
        cout << "Number is not in the list." << endl;
    }

}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::rotateList()
{

    listNode *nodePtr = head;
    listNode *lastPtr = head;
    listNode *previousNode = NULL;
    listNode *node;
    int holder;
    int holder2;
    int holder3;



    if(!head)
    {
        cout << "The list is empty.";
        return;
    }
    else
    {
        while(lastPtr->next)
        {
            previousNode = lastPtr;
            lastPtr = lastPtr->next;
        }

        node = head;
        node = node->next;
        holder = node->value;
        //rotating 2 values
        holder2 = lastPtr->value;
        lastPtr->value = node->value;
        node->value = holder2;
        node = head;
        //rotating last 2 values
        holder3 = previousNode->value;
        previousNode->value = node->value;
        node->value = holder3;

    }


}

//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::deleteDup()
{

    listNode *nodePtr = head;
    listNode *dupPtr;

    if(!head)
    {
        cout << "The list is empty.";
        return;
    }
    cout << "Deleting Duplicate Numbers..." << endl;
    while(nodePtr->next != NULL)
    {
        dupPtr = nodePtr->next;
        if(nodePtr->value == dupPtr->value)
        {
            nodePtr->next = dupPtr->next;
            delete dupPtr;
        }
        else
        {
            nodePtr = nodePtr->next;
        }
    }
}
//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
void linkedList::splitList()
{
    linkedList slOne;
    linkedList slTwo;

    linkedList unList;
    linkedList inList;

    listNode *nodePtr = head;


    if(!head)
    {
        cout << "The list is empty.";
        return;
    }
    cout << "Splitting the list into two sublists...";
    for(int x = 0; x < 10; x++)
    {
        slOne.appendNode(nodePtr->value);
        if(!unList.isPresent(nodePtr->value))
        {
            unList.appendNode(nodePtr->value);
        }
        nodePtr = nodePtr->next;
    }

    listNode *slOnePtr = slOne.head;
    cout << "\nFirst sub list: ";
    while(slOnePtr)
    {
        cout << slOnePtr->value << " ";
        slOnePtr = slOnePtr->next;
    }

    while(nodePtr)
    {
        slTwo.appendNode(nodePtr->value);
        if(!unList.isPresent(nodePtr->value))
        {
            unList.appendNode(nodePtr->value);
        }
        if(slOne.isPresent(nodePtr->value)&&!inList.isPresent(nodePtr->value))
        {
            inList.appendNode(nodePtr->value);
        }
        nodePtr = nodePtr->next;
    }

    listNode *slTwoPtr = slTwo.head;
    cout << "\nSecond sub list: ";
    while(slTwoPtr)
    {
        cout << slTwoPtr->value << " ";
        slTwoPtr = slTwoPtr->next;
    }

    listNode *unPtr = unList.head;
    cout << "\nUnion of lists: ";
    while(unPtr)
    {
        cout << unPtr->value << " ";
        unPtr = unPtr->next;
    }

    listNode *inPtr = inList.head;
    cout << "\nIntersection of lists: ";
    while(inPtr)
    {
        cout << inPtr->value << " ";
        inPtr = inPtr->next;
    }

    cout << endl;
}
//*************************************************************************
//
//
//                      👌template for comments👌
//
//
//**************************************************************************
bool linkedList::isPresent(int number)
{
    listNode *nodePtr = head;
    while(nodePtr)
    {
        if(nodePtr->value == number)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;
}



