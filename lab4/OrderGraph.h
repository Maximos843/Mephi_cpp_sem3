#pragma once
#ifndef OrderGraph_h
#define OrderGraph_h


#include "Graph.h"
#include <fstream>
#include <queue>


template <class T>
class OrderGraph : public Graph<T>{
private:
    std::vector<std::vector<T> *> *matrix;
    std::vector<std::string> *names;
    int size = 0;

public:
    OrderGraph() : matrix(new std::vector<std::vector<T> *>), names(new std::vector<std::string>){};

    ~OrderGraph(){
        for (int i = 0; i < size; ++i){
            delete matrix->operator[](i);
        }
        delete matrix;
        delete names;
    }

    int Find(std::string name) override {
        for (int i = 0; i < size; i++){
            if (name == names->operator[](i)){
                return i;
            }
        }
        return -1;
    }

    int FindEdge(std::string name) override {
        if(this->Find(name) == -1) {
            return false;
        }
        return true;
    }

    int AddVertex(std::string name) override {
        if (this->Find(name) != -1){
            return -1;
        }
        names->push_back(name);
        matrix->push_back(new std::vector<T>(size, 0));
        ++size;
        for (int i = 0; i < size; i++){
            matrix->operator[](i)->push_back(0);
        }
        return 0;
    }

    int AddEdge(T data, std::string first, std::string second) override {
        if (this->Find(first) == -1 || this->Find(second) == -1){
            return -1;
        }
        matrix->operator[](Find(first))->operator[](Find(second)) = data;
        return 0;
    }

    int DeleteEdge(std::string first, std::string second) override {
        if (Find(first) == -1 || Find(second) == -1) {
            return -1;
        }
        matrix->operator[](Find(first))->operator[](Find(second)) = 0;
        return 0;
    }

    int DeleteVertex(std::string name) override {
        int index = Find(name);
        if (index == -1){
            return -1;
        }
        for (int i = index; i < size - 1; i++)
            matrix->operator[](i) = matrix->operator[](i + 1);
        matrix->resize(size - 1);
        names->erase(names->begin() + index);
        for (int i = 0; i < size - 1; i++){
            for (int j = index; j < size - 1; j++){
                matrix->operator[](i)->operator[](j) = matrix->operator[](i)->operator[](j + 1);
                matrix->operator[](i)->resize(size - 1);
            }
        }
        --size;
        return 0;
    }

    std::vector<std::string> *BellmanFord(std::string first, std::string second){
        int start = Find(first);
        int end = Find(second);
        if (start == -1 || end == -1){
            return nullptr;
        }
        std::vector<std::string> *path = new std::vector<std::string>;
        std::vector<int> distance(size, INF);
        std::vector<int> p(size, -1);
        distance[start] = 0;
        for (int k = 1; k < size; k++){
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (matrix->operator[](i)->operator[](j) != 0){
                        if (distance[j] > (distance[i] + matrix->operator[](i)->operator[](j))){
                            distance[j] = distance[i] + matrix->operator[](i)->operator[](j);
                            p[j] = i;
                        }
                    }
                }
            }
        }
        if (distance[end] != INF){
            int prev_vert = end;
            while (prev_vert != -1){
                path->push_back(names->operator[](prev_vert));
                prev_vert = p[prev_vert];
            }
        }
        reverse(path->begin(), path->end());
        return path;
    }


    void PrintGraph(){
        std::fstream file;
        file.open("g.gv", std::ofstream::out | std::ofstream::trunc);
        file << "digraph G {\n";
        for (int i = 0; i < size; i++){
            file << "\t" << names->operator[](i);
        }
        file << "\n";
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (matrix->operator[](i)->operator[](j) != 0){
                    file << "\t" << names->operator[](i) << "->" << names->operator[](j);
                    file << "[dir=forward,"<< "label=\"" << matrix->operator[](i)->operator[](j) << "\",weight=\"" << matrix->operator[](i)->operator[](j) << "\"];";
                    file << "\n";
                }
            }
        }
        file << "}";
        file.close();
        std::string command = "dot -Tpng g.gv -o g.png";
        command += " && start g.png";
        system(command.c_str());
    }

    std::vector<std::string>* TopologicSort() {
        std::vector<std::string>* ans = new std::vector<std::string>();
        std::queue<int> my_que;
        std::vector<int> indegrees(size, 0);
        int num = size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix->operator[](j)->operator[](i)){
                    indegrees[i]++;
                }
            }
        }
        for (int i = 0; i < indegrees.size(); i++){
            if (!indegrees[i]) {
                my_que.push(i);
                ans->push_back(names->operator[](i));
            }
        }
        while (!my_que.empty()) {
            int index = my_que.front();
            my_que.pop();
            for (int i = 0; i < size; i++) {
                if (matrix->operator[](index)->operator[](i)) {
                    if (--indegrees[i] == 0) {
                        my_que.push(i);
                        ans->push_back(names->operator[](i));
                    }
                }
            }
            num--;
        }
        if (num != 0){
            ans->clear();
            return ans;
        }
        return ans;
    }

};


#endif