#include "iostream"
#include "string"
using namespace std;

// Узел двусвязного списка
struct Node
{
    int data;
    Node* prev, * next;
    // Функция для получения нового узла
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

// Структура для представления двухсторонней очереди
class Deque
{
    Node* front;
    Node* rear;
    int Size;

public:
    Deque()
    {
        front = rear = NULL;
        Size = 0;
    }

    // Операции на Deque
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    void erase();
};

// Функция для проверки наличия deque
// пусто или нет
bool Deque::isEmpty()
{
    return (front == NULL);
}

// Функция для возврата количества
// элементы в двухсторонней очереди
int Deque::size()
{
    return Size;
}

// Функция для вставки элемента
// в передней части
void Deque::insertFront(int data)
{
    Node* newNode = Node::getnode(data);
    // Если true, то новый элемент не может быть добавлен
     // и это условие переполнения
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // Если двухсторонняя очередь пуста
        if (front == NULL)
            rear = front = newNode;

        // Вставляет узел в переднюю часть
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        // Увеличивает количество элементов на 1
        Size++;
    }
}

// Функция для вставки элемента
// в задней части
void Deque::insertRear(int data)
{
    Node* newNode = Node::getnode(data);
    // Если true, то новый элемент не может быть добавлен
     // и это условие переполнения
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // Если двухсторонняя очередь пуста
        if (rear == NULL)
            front = rear = newNode;

        // Вставки узла в задней части
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

// Функция для удаления элемента
// из передней части
void Deque::deleteFront()
{
    // Если deque пусто, то
     // Состояние недостаточного заполнения
    if (isEmpty())
        cout << "UnderFlow\n";

    // Удаляет узел из передней части и 
    // выполняет корректировку в ссылках
    else
    {
        Node* temp = front;
        front = front->next;

        // Если бы присутствовал только один элемент
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Уменьшает количество элементов на 1
        Size--;
    }
}

// Функция для удаления элемента
// из задней части
void Deque::deleteRear()
{
    // Если deque пусто, то
     // Состояние недостаточного заполнения
    if (isEmpty())
        cout << "UnderFlow\n";

    // Удаляет узел из передней части и 
   // выполняет корректировку в ссылках 
    else
    {
        Node* temp = rear;
        rear = rear->prev;

        // Если бы присутствовал только один элемент
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Уменьшает количество элементов на 1
        Size--;
    }
}

// Функция для возврата элемента
// в передней части
int Deque::getFront()
{
    // Функция для удаления всех элементов
    // из Deque
    if (isEmpty())
        return -1;
    return front->data;
}

// Функция для возврата элемента
// в задней части 
int Deque::getRear()
{
    // Если двухсторонняя очередь пуста, возвращается
     // значение мусора
    if (isEmpty())
        return -1;
    return rear->data;
}

// Функция для удаления всех элементов
// из Deque
void Deque::erase()
{
    rear = NULL;
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}

// Тест 
int main()
{
    setlocale(0, "rus");
    Deque dq;

    cout << "Вставляем элемент '5' в задний конец\n";
    dq.insertRear(5);

    cout << "Вставляем элемент '10' в задний конец\n";
    dq.insertRear(10);

    cout << "Задний элемент с краю: "
        << dq.getRear() << endl;

    dq.deleteRear();
    cout << "После удаления заднего элемента,"
        << " новый задний: " << dq.getRear() << endl;

    cout << "Вставка элемента '15' на переднем конце \n";
    dq.insertFront(15);

    cout << "Передний крайний элемент: "
        << dq.getFront() << endl;

    cout << "Количество элементов в очереди:"
        << dq.size() << endl;

    dq.deleteFront();
    cout << "После удаления переднего элемента появляется новый "
        << "передний: " << dq.getFront() << endl;

    return 0;
}