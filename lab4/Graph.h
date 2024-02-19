#pragma once
#ifndef Graph_h
#define Graph_h


#include <iostream>
#include <vector>
#include <string>
//#include <graphviz/gvc.h>


const int INF = 1000000000;


template <class T>
class Graph{
public:

   virtual int Find(std::string name) = 0;

    virtual int FindEdge(std::string name) = 0;

    virtual int AddVertex(std::string name) = 0;

    virtual int AddEdge(T data, std::string first, std::string second) = 0;

    virtual int DeleteEdge(std::string first, std::string second) = 0;

    virtual int DeleteVertex(std::string name) = 0;

};

#endif