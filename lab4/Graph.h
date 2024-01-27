#ifndef Graph_h
#define Graph_h


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
//#include <graphviz/gvc.h>


const int INF = 1000000000;


template <class T>
class Graph{
private:
    std::vector<std::vector<T> *> *matrix;
    std::vector<std::string> *names;
    int size = 0;

public:
    Graph() : matrix(new std::vector<std::vector<T> *>), names(new std::vector<std::string>){};

    ~Graph(){
        for (int i = 0; i < size; ++i){
            delete matrix->operator[](i);
        }
        delete matrix;
        delete names;
    }

    int Find(std::string name){
        for (int i = 0; i < size; i++){
            if (name == names->operator[](i)){
                return i;
            }
        }
        return -1;
    }

    int FindEdge(std::string name){
        if(this->Find(name) == -1) {
            return false;
        }
        return true;
    }

    int AddVertex(std::string name){
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

    int AddEdge(T data, std::string first, std::string second){
        if (this->Find(first) == -1 || this->Find(second) == -1){
            return -1;
        }
        matrix->operator[](Find(first))->operator[](Find(second)) = data;
        matrix->operator[](Find(second))->operator[](Find(first)) = data;
        return 0;
    }

    int DeleteEdge(std::string first, std::string second){
        if (Find(first) == -1 || Find(second) == -1) {
            return -1;
        }
        matrix->operator[](Find(first))->operator[](Find(second)) = 0;
        matrix->operator[](Find(second))->operator[](Find(first)) = 0;
        return 0;
    }

    int DeleteVertex(std::string name){
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
            for (int j = i; j < size; j++){
                if (matrix->operator[](i)->operator[](j) != 0){
                    file << "\t" << names->operator[](i) << "->" << names->operator[](j);
                    file << "[dir=none,"<< "label=\"" << matrix->operator[](i)->operator[](j) << "\",weight=\"" << matrix->operator[](i)->operator[](j) << "\"];";
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

    void PrintSpanningTree(std::vector<std::vector<int>> min_spanning_tree){
        std::fstream file;
        file.open("g.gv", std::ofstream::out | std::ofstream::trunc);
        file << "digraph G {\n";
        for (int i = 0; i < size; i++){
            file << "\t" << names->operator[](i);
        }
        file << "\n";
        for (int i = 0; i < size; i++){
            for (int j = i; j < size; j++){
                if (matrix->operator[](i)->operator[](j) != 0){
                    file << "\t" << names->operator[](i) << "->" << names->operator[](j);
                    file << "[dir=none,"<< "label=\"" << matrix->operator[](i)->operator[](j) << "\",weight=\"" << matrix->operator[](i)->operator[](j);
                    bool flag = false;
                    for (int t = 0; t < size - 1;t++){
                        if ((min_spanning_tree[0][t] == i and min_spanning_tree[1][t] == j) || (min_spanning_tree[0][t] == j and min_spanning_tree[1][t] == i)){
                            flag = true;
                        }
                    }
                    if (flag){
                        file << "\",color=\"red";
                    }
                    file << "\"];\n";
                }
            }
        }
        file << "}";
        file.close();
        std::string command = "dot -Tpng g.gv -o g.png";
        command += " && start g.png";
        system(command.c_str());
    }

    std::vector<std::vector<int>> PrimAlgorythm(){
        std::vector<std::vector<int>> min_spanning_tree(2);
        std::vector<bool> selected (size, false);
        selected[0] = true;
        for(int t = 0; t < size - 1; t++){
            int minimum = INF;
            int x = 0, y = 0;
            for (int i = 0; i < size; i++){
                if (selected[i]) {
                    for (int j = 0; j < size; j++){
                        if ((!selected[j]) && matrix->operator[](i)->operator[](j)){
                            if (minimum > matrix->operator[](i)->operator[](j)){
                                minimum = matrix->operator[](i)->operator[](j);
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            selected[y] = 1;
            min_spanning_tree[0].push_back(x);
            min_spanning_tree[1].push_back(y);
        }
        return min_spanning_tree;
    }
};


#endif