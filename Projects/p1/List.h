namespace ds
{
    class Node {
        public:
            Node();
            Node(int v);

            int val = 0;
            Node *next;
            Node *prev;
    };



    class DoublyLinkedList {
        public:
            DoublyLinkedList();  // ctor
            DoublyLinkedList(int arr[], int size);  // ctor

            void Insert(int idx, int v);
            void Remove(int idx);
            int Get(int idx);
            int Search(int v);
            void ReverseList();
            void PrintList();

            void MergeList(DoublyLinkedList *list);

            Node *head;
            Node *tail;
            int length = 0;
    };
} // namespace ds
