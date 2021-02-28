// Copyright 2020 Andreytorix
#pragma once
#include <utility>
template <typename T>
class Stack
{
private:
    struct Node
    {
        Node* next; //указатель на следующий элемент списка
        T obj; //хранит данные
    };
public:
    Node* nodeHead;
    size_t length;
    Stack() {
        nodeHead = NULL;
        length = 0;
    }
    void push(T&& value) { //push - передаём rvalue сслыку на объект
        Node* nd = new Node;
        nd->obj = std::move(value);
        nd->next = nodeHead;
        ++length;
        nodeHead = std::move(nd);
    }
    void push(const T& value) { //push - передаём lvalue сслыку на объект
        Node* nd = new Node;
        nd->obj = std::move(value);
        nd->next = nodeHead;
        ++length;
        nodeHead = nd;
    }

    size_t Length() {
        return length;
    }
    void pop() { //снимаем верхний элемент стэка (удаляем)
        if (length > 0){
        //T tmp = std::move(nodeHead->obj);
        nodeHead = std::move(nodeHead->next);
        length--;
        }
    }
    const T& head() const { //возвращает ссылку на шапку стэка
        T& ref = nodeHead->obj;
        return ref;
    }
};

