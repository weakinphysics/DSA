#ifndef WEAK_DLL
#define WEAK_DLL
#endif

template <class T>
class DoublyLinkedList{
    private:
        T data;
        DoublyLinkedList* next;
        DoublyLinkedList* prev;
        DoublyLinkedList* head;
    public:
        DoublyLinkedList(); // default constructor
        DoublyLinkedList(T &value); // value constructor
        DoublyLinkedList(DoublyLinkedList* copy); // copy constructor

        ~DoublyLinkedList(); // destructor

        bool search(T data);
        void insertNode(T data);
        bool deleteNode(T data);
        bool deleteNode(DoublyLinkedList<T>* node);
};


template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->data = static_cast<T>(0.0);
    this->next = this;
    this->prev = this;
    this->head = this;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T &value){
    this->data = data;
    this->next = this;
    this->prev = this;
    this->head = this;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>* ){
    this->data = data;
    this->next = this;
    this->prev = this;
    this->head = this;
}