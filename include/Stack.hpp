// Copyright 2020 Andreytorix
#include <utility>
#include <memory>
#ifndef Stack.hpp
template <typename T>
class Stack
{
private:
    struct Node
    {
        std::unique_ptr<Node> next;
        T obj; //хранит данные
    };
public:
    std::unique_ptr<Node> nodeHead;
    size_t length;
    Stack() {
        nodeHead = NULL;
        length = 0;
    }
    ~Stack() {
    }
    void push(T&& value) { //push - передаём rvalue сслыку на объект
        std::unique_ptr<Node> nd(new Node);
        nd->obj = std::move(value);
        nd->next = std::move(nodeHead);
        ++length;
        nodeHead = std::move(nd);
    }
    void push(const T& value) { //push - передаём lvalue сслыку на объект
        std::unique_ptr<Node> nd(new Node);
        nd->obj = std::move(value);
        nd->next = std::move(nodeHead);
        ++length;
        nodeHead = std::move(nd);
    }
    size_t Length() {
        return length;
    }
    void pop() { //снимаем верхний элемент стэка (удаляем)
        if (nodeHead){
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

