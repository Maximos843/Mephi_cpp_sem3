//
//  LinkedList.h
//  lab2
//
//  Created by Максим Шелестов on 12.12.2023.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "IndexError.h"
#include <iostream>

template <class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LinkedList{
    int length = 0;
    Node<T>* head = nullptr;
    Node<T>* end = nullptr;

public:
    LinkedList(){
        this->length = 0;
        this->head = nullptr;
        this->end = nullptr;
    };

    LinkedList(T* items, int count){
        for (int i = 0; i < count; ++i){
            Append(items[i]);
        }
    };

    LinkedList(const LinkedList<T>& list){
        Node<T>* new_elem = list->head;
        for (int i = 0; i < list.len; ++i){
            Append(new_elem->data);
            new_elem = new_elem->next;
        }
    };

    ~LinkedList(){
        Node<T>* elem = head;
        Node<T>* elem1 = head;
        while (elem){
            elem1 = elem;
            elem = elem->next;
            delete elem1;
        }
    };

    T GetFirst(){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        return head->data;
    };

    T GetLast(){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        return end->data;
    };

    T Get(int index){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        if (index >= this->length || index < 0){
            throw IndexError(Invalid_args);
        }
        Node<T>* tmp = new Node<T>;
        tmp = head;
        for (int i = 0; i < index; ++i){
            tmp = tmp->next;
        }
        return tmp->data;
    };

    LinkedList<T>* GetSubList(int start_index, int end_index){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        if (end_index >= this->length || start_index >= this->length || end_index < 0 || start_index < 0 || end_index < start_index){
            throw IndexError(Invalid_args);
        }
        Node<T>* elem_start = new Node<T>;
        elem_start = head;
        for (int i = 0; i < start_index; ++i){
            elem_start = elem_start->next;
        }
        LinkedList<T>* list = new LinkedList<T>;
        for (int i = 0; i < end_index - start_index; ++i){
            list->Append(elem_start->data);
            elem_start = elem_start->next;
        }
        list->end = elem_start;
        return list;
    };

    void Append(T item){
        Node<T>* new_elem = new Node<T>;
        new_elem->data = item;
        new_elem->next = nullptr;
        new_elem->prev = end;
        this->length++;
        if (head == nullptr){
            head = new_elem;
            end = new_elem;
            return;
        }
        end->next = new_elem;
        end = new_elem;
    };

    void Prepend(T item){
        Node<T>* new_elem = new Node<T>;
        new_elem->data = item;
        new_elem->next = nullptr;
        new_elem->prev = nullptr;
        this->length++;
        if (head == nullptr){
            head = new_elem;
            end = new_elem;
            return;
        }
        new_elem->next = head;
        head = new_elem;
    };

    void InsertAt(T item, int index){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        if (index < 0 || index >= this->length){
            throw IndexError(Invalid_args);
        }
        Node<T>* tmp = new Node<T>;
        Node<T>* elem = new Node<T>;
        tmp = head;
        for (int i = 0; i < index; ++i){
            tmp = tmp->next;
        }
        elem->data = item;
        elem->next = tmp->next->next;
        tmp->next = elem;
    };

    int GetLength(){
        return this->length;
    };

    void Set(T item, int index){
        if (head == nullptr){
            throw IndexError(Empty_list);
        }
        if (index < 0 || index >= this->length){
            throw IndexError(Invalid_args);
        }
        Node<T>* tmp = new Node<T>;
        tmp = head;
        for (int i = 0; i < index; ++i){
            tmp = tmp->next;
        }
        tmp->data = item;
    };
};


#endif /* LinkedList_h */
