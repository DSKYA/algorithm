#include "stdafx.h"
#include<iostream>

using namespace std;

const int MAX_DATANUM = 100;

void usage();

template <class T>
struct node
{
    int key;
    T value;
};

template <class T>
class priority_queue
{
public:
    priority_queue();
    ~priority_queue();

    void enqueue(int key,T value);
    node<T>* dequeue();
    T search(int key);
    void makeHeap();
    void showQueue();
    void pushdown(int first, int last);
    void swap(node<T>* data1, node<T>* data2);

private:
    int number;
    node<T>* head;
};

template <class T>
priority_queue <T>::priority_queue()
{
    head = new node<T>[MAX_DATANUM];
    number = 0;
}

template <class T>
priority_queue <T>::~priority_queue()
{
    delete[] head;
}

template <class T>
void priority_queue <T>::swap(node<T>* data1, node<T>* data2)
{
    node<T> temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

template <class T>
void priority_queue <T>::pushdown(int first, int last)
{
    int pos = first;
    while (pos <= last / 2)
    {
        if (pos == last / 2 && last % 2 == 0)
        {
            if ((head+pos)->key > (head+pos * 2)->key)
            {
                swap(head+pos, head+pos * 2);
                pos = last;
            }
            else
            {
                pos = last;
            }
        }
        else if ((head+pos)->key > (head+pos * 2)->key && (head+pos*2)->key < (head+pos * 2 + 1)->key)
        {
            swap(head+pos, head+pos * 2);
            pos *= 2;
        }
        else if ((head + pos)->key >(head + pos * 2 + 1)->key && (head + pos*2)->key > (head + pos * 2+1)->key)
        {
            swap(head+pos, head + pos * 2 + 1);
            pos = pos * 2 + 1;
        }
        else
        {
            pos = last;
        }
    }
}

template <class T>
void priority_queue <T>::enqueue(int key, T value)
{
    cout << "Inserting info into the priority_queue..." << endl;
    number++;
    (head+number)->key = key;
    (head + number)->value = value;
    pushdown(1, number);
    cout << "Done!" << endl;
    showQueue();
}

template <class T>
node<T>* priority_queue <T>::dequeue()
{
    cout << "The next one is..." << endl;
    swap(head+1, head+number);
    pushdown(1, --number);
    cout << "(" << (head + number + 1)->key << "," << (head + number + 1)->value << ")" << endl;
    return head + number + 1;
}

template <class T>
T priority_queue<T>::search(int key)
{
    cout << "Searching for value related to the key " << key << "..." << endl;
    for (int i = 1; i <= number; i++)
    {
        if ((head+i)->key == key)
        {
            cout << "Ok! The value is " << (head + i)->value << endl;
            return (head + i)->value;
        }
    }
    cout << "Oops! There's such key! " << endl;
    return NULL;
}

template<class T>
void priority_queue<T>::makeHeap()
{
    for (int i = number / 2+1; i >= 1; i--)
    {
        pushdown(i, number);
    }
}
template<class T>
void priority_queue<T>::showQueue()
{
    cout << "The queue(in priority order) is...";
    for (int i = number; i >= 2; i--)
    {
        swap(head+1, head + i);
        pushdown(1, i - 1);
        cout << " (" << (head + i)->key << "," << (head + i)->value << ") ";
    }
    cout << " (" << (head + 1)->key << "," << (head + 1)->value << ") " << endl;
    makeHeap();
}

void usage()
{
    cout << " Now, try the priority_queue..." << endl;
    cout << "Enter '1' to add info into the queue..." << endl;
    cout << "Enter '2' to get the next info from the queue..." << endl;
    cout << "Enter '3' to search info in the queue..." << endl;
    cout << "Enter '4' to show the queue in priority order..." << endl;
    cout << "Enter 'q' to quit the program..." << endl;

}

int main()
{
    int param1;
    float param2;

    priority_queue <float> queue;
    while (true) {
        usage();

        char op = getchar();
        switch (op) {
            case '1':
                cout << "Input key and value you want to add into the queue... like '1 15'" << endl;
                cin >> param1 >> param2;
                queue.enqueue(param1, param2);
                break;
            case '2':
                cout << "Next info is..." << endl;
                queue.dequeue();
                break;
            case '3':
                cout << "Input key of the info you want to search..." << endl;
                cin >> param1;
                queue.search(param1);
                break;
            case '4':
                queue.showQueue();
                break;
            case 'q':
                exit(0);
            default:
                break;
        }
        getchar();
    }
}