#pragma once
#ifndef Menu_funtions_h
#define Menu_funtions_h


#include <iostream>
#include <string>
#include <vector>
#include "UnorderGraph.h"
#include "OrderGraph.h"


void OrderTests(){
    OrderGraph<int> test;
    bool flag = true;
    test.AddVertex("a");
    test.AddVertex("b");
    test.AddVertex("c");
    if(test.FindEdge("a") == 0 or test.FindEdge("b") == 0 or test.FindEdge("c") == 0){
        flag = false;
        std::cout << "Vertex add function failed" << std::endl;
    }
    test.DeleteVertex("a");
    if(test.FindEdge("a")){
        flag = false;
        std::cout << "Vertex delete function failed" << std::endl;
    }
    OrderGraph<int> path_test;
    path_test.AddVertex("a");
    path_test.AddVertex("b");
    path_test.AddVertex("c");
    path_test.AddVertex("d");
    path_test.AddVertex("e");
    path_test.AddVertex("f");
    path_test.AddVertex("z");
    path_test.AddEdge(4, "a", "b");
    path_test.AddEdge(6, "a", "c");
    path_test.AddEdge(33, "a", "z");
    path_test.AddEdge(1, "b", "c");
    path_test.AddEdge(2, "c", "d");
    path_test.AddEdge(10, "c", "e");
    path_test.AddEdge(4, "d", "e");
    path_test.AddEdge(3, "e", "f");
    path_test.AddEdge(8, "e", "z");
    path_test.AddEdge(2, "f", "z");
    path_test.PrintGraph();
    std::vector<std::string>* ans = path_test.BellmanFord("a", "z");
    std::string path = "";
    for(int i = 0; i < ans->size(); i++){
        if (i == ans->size() - 1){
            path += ans->operator[](i);
            break;
        }
        path += ans->operator[](i) + " -> ";
    }
    if (path != "a -> b -> c -> d -> e -> f -> z") {
        std::cout << "Bellman Ford failed" << std::endl;
        flag = false;
    }
    path_test.DeleteEdge("a", "b");
    path_test.AddEdge(4, "b", "a");
    std::vector<std::string>* topologic = path_test.TopologicSort();
    std::string res = "";
    for(int i = 0; i < topologic->size(); i++){
        if (i == topologic->size() - 1){
            res += topologic->operator[](i);
            break;
        }
        res += topologic->operator[](i) + " -> ";
    }
    if (res != "b -> a -> c -> d -> e -> f -> z") {
        std::cout << "Topologic Sort failed" << std::endl;
        flag = false;
    }
    path_test.PrintGraph();
    if (flag){
        std::cout << "Tests success" << std::endl;
    }
    else{
        std::cout << "Tests Failed" << std::endl;
    }
}

void UnorderTests() {
    UnorderGraph<int> test;
    bool flag = true;
    test.AddVertex("a");
    test.AddVertex("b");
    test.AddVertex("c");
    if(test.FindEdge("a") == 0 or test.FindEdge("b") == 0 or test.FindEdge("c") == 0){
        flag = false;
        std::cout << "Vertex add function failed" << std::endl;
    }
    test.DeleteVertex("a");
    if(test.FindEdge("a")){
        flag = false;
        std::cout << "Vertex delete function failed" << std::endl;
    }
    UnorderGraph<int> path_test;
    path_test.AddVertex("a");
    path_test.AddVertex("b");
    path_test.AddVertex("c");
    path_test.AddVertex("d");
    path_test.AddVertex("e");
    path_test.AddVertex("f");
    path_test.AddVertex("z");

    path_test.AddEdge(4, "a", "b");
    path_test.AddEdge(6, "a", "c");
    path_test.AddEdge(33, "a", "z");
    path_test.AddEdge(1, "b", "c");
    path_test.AddEdge(2, "c", "d");
    path_test.AddEdge(10, "c", "e");
    path_test.AddEdge(4, "d", "e");
    path_test.AddEdge(3, "e", "f");
    path_test.AddEdge(8, "e", "z");
    path_test.AddEdge(2, "f", "z");
    std::vector<std::string>* ans = path_test.BellmanFord("a", "z");
    std::string path = "";
    for(int i = 0; i < ans->size();i++){
        if (i == ans->size() - 1){
            path += ans->operator[](i);
            break;
        }
        path += ans->operator[](i) + " -> ";
    }
    path_test.PrintSpanningTree(path_test.PrimAlgorythm());
    //std::cout << path << std::endl;
    if(path != "a -> b -> c -> d -> e -> f -> z"){
        std::cout << "Bellman Ford failed" << std::endl;
        flag = false;
    }
    path_test.DeleteEdge("a", "z");
    path_test.DeleteEdge("a", "b");
    path_test.DeleteEdge("a", "c");
    int count = path_test.CountComponents();
    if (count != 2){
        flag = false;
        std::cout << "CountComponents failed" << std::endl;
    }
    if (flag){
        std::cout << "Tests success" << std::endl;
    }
    else{
        std::cout << "Tests failed";
    }
}


void MenuOptionsUnorder() {
    std::cout << "1. Add vertex" << std::endl;
    std::cout << "2. Add edge" << std::endl;
    std::cout << "3. Delete vertex" << std::endl;
    std::cout << "4. Delete edge" << std::endl;
    std::cout << "5. Shortest path" << std::endl;
    std::cout << "6. Print Graph" << std::endl;
    std::cout << "7. Min spanning tree" << std::endl;
    std::cout << "8. exit" << std::endl;
}

void MenuOptionsOrder() {
    std::cout << "1. Add vertex" << std::endl;
    std::cout << "2. Add edge" << std::endl;
    std::cout << "3. Delete vertex" << std::endl;
    std::cout << "4. Delete edge" << std::endl;
    std::cout << "5. Shortest path" << std::endl;
    std::cout << "6. Print Graph" << std::endl;
    std::cout << "7. Topoligic Sort" << std::endl;
    std::cout << "8. exit" << std::endl;
}


int GetUserChoice(int unorder) {
    int choice = 0;
    if (unorder){
        MenuOptionsUnorder();
        std::cin >> choice;
        while(choice > 8 or choice < 0){
            std::cout << "Please choose again" << std::endl;
            MenuOptionsUnorder();
            std::cin >> choice;
        }
    }
    else{
        MenuOptionsOrder();
        std::cin >> choice;
        while(choice > 8 or choice < 0){
            std::cout << "Please choose again" << std::endl;
            MenuOptionsOrder();
            std::cin >> choice;
        }
    }
    return choice;
}

void MenuUnorder() {
    UnorderGraph<int> test;
    int choice = GetUserChoice(1);
    while(choice != 8){
        switch (choice)
        {
            case 1:{
                std::string name = "";
                std::cout << "Enter vertex name: ";
                std::cin >> name;
                if(test.AddVertex(name) == -1){
                    std::cout << "This vertex already exists" << std::endl;
                }
                break;
            }
            case 2:{
                int length = 0;
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;
                std::cout << "Enter edge weight: ";
                std::cin >> length;
                if(test.AddEdge(length, first, second) == -1){
                    std::cout << "One of the vertexes doesn't exist" << std::endl;
                }
                break;
            }
            case 3:{
                std::string name = "";
                std::cout << "Enter vertex name: ";
                std::cin >> name;
                if(test.DeleteVertex(name) == -1){
                    std::cout << "This vertex doesn't exist" << std::endl;
                }
                break;
            }
            case 4:{
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;
                if(test.DeleteEdge(first, second) == -1){
                    std::cout << "One of the vertexes doesn't exist" << std::endl;
                }
                break;
            }
            case 5:{
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;

                std::vector<std::string>* path = test.BellmanFord(first, second);
                for(int i = 0; i < path->size();i++){
                    std::cout << path->operator[](i);
                    if(i != path->size() - 1){
                        std::cout << " -> ";
                    }

                }
                std::cout << std::endl;
                break;
            }
            case 6:{
                test.PrintGraph();
                break;
            }
            case 7:{
                test.PrintSpanningTree(test.PrimAlgorythm());
            }

        }
        choice = GetUserChoice(1);
    }
}

void MenuOrder() {
    OrderGraph<int> test;
    int choice = GetUserChoice(0);
    while(choice != 8){
        switch (choice)
        {
            case 1:{
                std::string name = "";
                std::cout << "Enter vertex name: ";
                std::cin >> name;
                if(test.AddVertex(name) == -1){
                    std::cout << "This vertex already exists" << std::endl;
                }
                break;
            }
            case 2:{
                int length = 0;
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;
                std::cout << "Enter edge weight: ";
                std::cin >> length;
                if(test.AddEdge(length, first, second) == -1){
                    std::cout << "One of the vertexes doesn't exist" << std::endl;
                }
                break;
            }
            case 3:{
                std::string name = "";
                std::cout << "Enter vertex name: ";
                std::cin >> name;
                if(test.DeleteVertex(name) == -1){
                    std::cout << "This vertex doesn't exist" << std::endl;
                }
                break;
            }
            case 4:{
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;
                if(test.DeleteEdge(first, second) == -1){
                    std::cout << "One of the vertexes doesn't exist" << std::endl;
                }
                break;
            }
            case 5:{
                std::string first = "", second = "";
                std::cout << "Enter first vertex: ";
                std::cin >> first;
                std::cout << "Enter second vertex: ";
                std::cin >> second;

                std::vector<std::string>* path = test.BellmanFord(first, second);
                for(int i = 0; i < path->size();i++){
                    std::cout << path->operator[](i);
                    if(i != path->size() - 1){
                        std::cout << " -> ";
                    }

                }
                std::cout << std::endl;
                break;
            }
            case 6:{
                test.PrintGraph();
                break;
            }
            case 7:{
                std::vector<std::string>* topologic = test.TopologicSort();
                if (topologic->empty()){
                    std::cout << "Tologic Sort doesn\'t exist for your graph" << std::endl;
                }
                else{
                    std::string res = "";
                    for(int i = 0; i < topologic->size(); i++){
                        if (i == topologic->size() - 1){
                            res += topologic->operator[](i);
                            break;
                        }
                        res += topologic->operator[](i) + " -> ";
                    }
                    std::cout << "TopSort: " << res << std::endl;
                }
            }

        }
        choice = GetUserChoice(0);
    }
}

void Menu(){
    int choice;
    std::cout << "Choose Graph type:\n1. Ordered\n2. Unorder\n";
    std::cin >> choice;
    switch (choice){
        case 1:
            MenuOrder();
            break;
        case 2:
            MenuUnorder();
            break;
        default:
            break;
    }
}

#endif