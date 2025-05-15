#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
    Node * prev;
};

class DoubleLinkedList
{
    private:
        Node * START; 
    
    public:
        DoubleLinkedList()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            string nm;
            cout << "\nEnter the roll number of the student";
            cin >> nim;

            // Step 1: Allcate memory for new node
            Node *newNode = new Node();
            
            // Step 2: Assign value to the data fields
            newNode->noMhs = nim;
            
            //Step 3 Insert at beginning if list is empty or nim is smallest
            if (START == NULL || nim <= START->noMhs)
            {
                if (START != NULL && nim == START->noMhs)
                {
                    cout << "\nDuplicate number not allowed" << endl;
                    return;
                }
                // step 4: newnode .next =  start
                newNode->next = START;

            //step 5 if start exits
            if (START != NULL)
                START->prev = newNode;
            
            // step 6 
            newNode->prev= NULL;

            //step 7 
            START = newNode;
            return;

           }
           // insert in beetween mode 
           //step 8: location potition for insertion
           Node *current = START;
           while (current ->next !=NULL && current ->next->noMhs <nim )
           {
            current = current->next;
           }
            if (current->next !=NULL && nim == current->next->noMhs)
            {
                cout << "\nDuplicate roll number not allowed" << endl;
                return;

            }
            //step 9
            newNode->next = current->next; //part A
            newNode->prev = current; //part B

            //insert last node
            if (current->next != NULL)
                current->next->prev = newNode; //part C
            
            current->next = newNode; //part D
           
        }
         void hapus()
        {
            if (START == NULL)
           {
            cout << "nList is empty" << endl;
            return;
           }
           cout << "\nEnter the roll number of the student whose record is to be deleted: ";
           int rollNo;
           cin >> rollNo;

           Node *current = START;
           //step 1 traverse the lost tp final node
           while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            if (current == NULL)
            {
                cout << "Record not found" << endl;
                return;
            }
            //step 2 if node is at the beginning\

            if (current == START)
            {
                START = current->next;
                if(START !=NULL)
                START->prev =NULL;
            }
            else
            {
                //step
            }

        }


        
    
};
