/*
Author: Katie McLane
File: graph.h
Summary: Header file to Graph class
*/
class Graph {
public:
	void DFSrecurs(int vertex, bool visitedV[]);
	int vertexCount;
	bool ** graphArr;
	Graph();
	~Graph();
	void load(char *filename);
	void display();
	void displayDFS(int vertex);
	void displayBFS(int vertex);

};