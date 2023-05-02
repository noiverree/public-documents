#include <stdio.h>
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>  
#include <vector>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;



Node *head;
int nodeCount = 0;



void Init()
{
    head = NULL;
}



void VisualizeNode()
{
    Node *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->data << " > ";
        currentNode = currentNode->next;
    }

    cout << endl;
}



bool IsNodeEmpty()
{
    return head == NULL;
}



void AddHead(int _data)
{
    Node *newNode = new Node{0, NULL};
    newNode->data = _data;

    if (IsNodeEmpty())
    {
        head = newNode;
    }

    else
    {
        Node *oldHead = head;
        head = newNode;
        newNode->next = oldHead;
    }

    nodeCount++;
}



void AddTail(int _data)
{
    Node *newNode = new Node{0, NULL};
    newNode->data = _data;
    
    if (IsNodeEmpty())
    {
        head = newNode;
    }

    else
    {
        Node *currentNode = head;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }

    nodeCount++;
}



void AddAfter(int _dataToSearch, int _data)
{
    Node *newNode = new Node{0, NULL};
    newNode->data = _data;

    Node *currentNode = head;

    if (currentNode == NULL)
    {
        cout << "Nilai " << _dataToSearch << " tidak ditemukan." << endl;
        return;
    }

    while (currentNode != NULL)
    {
        if (currentNode->data == _dataToSearch)
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;

            cout << "Nilai " << _data << " telah ditambahan pada di sebelum nilai " << _dataToSearch << endl;
            nodeCount++;
            return;
        }

        currentNode = currentNode->next;
    }

    cout << "Nilai " << _dataToSearch << " tidak ditemukan." << endl;
}



void AddBefore(int _dataToSearch, int _data)
{
    Node *newNode = new Node{0, NULL};
    newNode->data = _data;

    Node *currentNode = head;
    
    if (currentNode == NULL)
    {
        cout << "Nilai " << _dataToSearch << " tidak ditemukan." << endl;
        return;
    }

    if (currentNode->data == _dataToSearch)
    {
        AddHead(_data);
        cout << "Nilai " << _data << " telah ditambahan pada di sebelum nilai " << _dataToSearch << endl;
        return;
    }

    while (currentNode->next != NULL)
    {
        if (currentNode->next->data == _dataToSearch)
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;

            cout << "Nilai " << _data << " telah ditambahan pada di sebelum nilai " << _dataToSearch << endl;
            nodeCount++;
            return;
        }

        currentNode = currentNode->next;
    }

    cout << "Nilai " << _dataToSearch << " tidak ditemukan." << endl;
}




void Tokenize(string const &str, const char delimiter, vector<string> &out) 
{ 
    stringstream ss(str); 
    string s; 

    while (getline(ss, s, delimiter)) 
    { 
        out.push_back(s); 
    } 

    while (out.size() < 3)
    {
        out.push_back("");
    }
} 



void InputCommand()
{
    cout << "===================================================================" << endl;
    cout << "Ketik perintah berikut untuk melanjutkan" << endl;
    cout << "===================================================================" << endl;
    cout << "ADDTAIL <nilai>: menambahkan nilai pada akhir node." << endl;
    cout << "ADDHEAD <nilai>: menambahkan nilai pada awal node." << endl;
    cout << "ADDBEFORE <nilai dicari> <nilai>: menambahkan nilai setelah node tertentu." << endl;
    cout << "ADDAFTER <nilai dicari> <nilai>: menambahkan nilai setelah node tertentu." << endl;
    cout << "DISPLAY: menampilkan seluruh node." << endl;
    cout << "EXIT: keluar dari aplikasi" << endl;

    while (true)
    {
        string input;
        cout << endl << "> ";
        getline(cin, input);

        vector<string> splittedInputs;
        Tokenize(input, ' ', splittedInputs);

        string choice = splittedInputs[0];
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "addtail")
        {
            try
            {
                int data = stoi(splittedInputs[1]);
                AddTail(data);
                cout << data << " telah ditambahkan di node akhir." << endl;
            } 
            
            catch (invalid_argument) 
            {
                cout << "Error! Penggunaan yang benar: ADDTAIL <nilai (int)>" << endl;
            }
        }

        else if (choice == "addhead")
        {
            try
            {
                int data = stoi(splittedInputs[1]);
                AddHead(data);
                cout << data << " telah ditambahkan di node awal." << endl;
            } 
            
            catch (invalid_argument) 
            {
                cout << "Error! Penggunaan yang benar: ADDHEAD <nilai (int)>" << endl;
            }
        }

        else if (choice == "addbefore")
        {
            try
            {
                int data = stoi(splittedInputs[1]);
                int data2 = stoi(splittedInputs[2]);
                AddBefore(data, data2);
            } 
            
            catch (invalid_argument) 
            {
                cout << "Error! Penggunaan yang benar: ADDBEFORE <nilai dicari (int)> <nilai (int)>" << endl;
            }
        }

        else if (choice == "addafter")
        {
            try
            {
                int data = stoi(splittedInputs[1]);
                int data2 = stoi(splittedInputs[2]);
                AddAfter(data, data2);
            } 
            
            catch (invalid_argument) 
            {
                cout << "Error! Penggunaan yang benar: ADDAFTER <nilai dicari (int)> <nilai (int)>" << endl;
            }
        }

        else if (choice == "display")
        {
            cout << "Terdapat " << nodeCount << " node:" << endl;
            VisualizeNode();
        }

        else if (choice == "exit")
        {
            break;
        }

        else 
        {
            cout << "Perintah tidak ditemukan." << endl;
        }
    }
}



int main()
{
    Init();
    InputCommand();

    return 0;
}