#include <iostream>

#include "List.cpp"
// #include "List.cpp"

using namespace ds;
using std::cout;
using std::endl;


int main() {
    int arr[] = {3, 5, 7, 9};
    DoublyLinkedList dLL = DoublyLinkedList(arr, 4);
    dLL.Insert(0, 1);
    dLL.Insert(2, 6);
    dLL.Insert(dLL.length, 11);
    dLL.PrintList();
    cout << "dLL.length: " << dLL.length << endl;
    cout << "dLL.Get(2): " << dLL.Get(2) << endl;
    cout << "dLL.Get(11): " << dLL.Get(11) << endl;
    cout << "dLL.Search(2): " << dLL.Search(2) << endl;
    cout << "dLL.Search(11): " << dLL.Search(11) << endl;

    dLL.ReverseList();
    cout << "dLL.ReverseList(): ";
    dLL.PrintList();

    dLL.Remove(6);
    cout << "dLL.Remove(6): ";
    dLL.PrintList();
    dLL.Remove(2);
    cout << "dLL.Remove(2): ";
    dLL.PrintList();
    dLL.Remove(0);
    cout << "dLL.Remove(0): ";
    dLL.PrintList();
    cout << "dLL.length: " << dLL.length << endl;

    int arr2[] = {0, 0};
    DoublyLinkedList dLL2 = DoublyLinkedList(arr2, 2);
    dLL.MergeList(&dLL2);
    cout << "dLL.MergeList(dLL2): ";
    dLL.PrintList();

    DoublyLinkedList dLL3 = DoublyLinkedList();
    dLL.MergeList(&dLL3);
    cout << "dLL.MergeList(dLL3): ";
    dLL.PrintList();

    return 0;
}