/*
Author: Katie McLane
File: graph.cpp
Summary: Implemenation file for graph.h Graph Class
*/

#include "graph.h"
#include <string>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;


Graph::Graph() {
	vertexCount = 0;
};

Graph::~Graph() {
	for (int i = 0; i < vertexCount; i++) {
		delete[] graphArr[i];
	}
	delete[] graphArr;
};

void Graph::load(char *filename) {
	//read in file
	//first line creates list of structs size N
	//save the two numbers as first and second
	ifstream file;
	file.open(filename);
	if (!file) {
		cout << "Hey! Yo! Sorry, but we can't open that file for whatever reason.";
		exit(1);
	}
	string line;
	getline(file, line);
	vertexCount = stoi(line);
	this->vertexCount = vertexCount;
	graphArr = new  bool*[vertexCount];

	for (int i = 0; i < vertexCount; i++) {
		graphArr[i] = new bool[vertexCount];
	}
	for (int i = 0; i < vertexCount; i++) {
		for (int j = 0; j < vertexCount; j++) {
			graphArr[i][j] = false;
		}
	}

	while(getline(file, line)){
		string st(1, line.at(0));
		string de(1, line.at(2));
		int start = stoi(st);
		int dest = stoi(de);
		graphArr[start][dest] = true;
		graphArr[dest][start] = true;
	}
};

void Graph::display() {
	for (int i = 0; i < vertexCount; i++) {
		for (int j = 0; j < vertexCount; j++) {
			cout << graphArr[i][j] << " ";
		}
		cout << endl;
	}
};

void Graph::DFSrecurs(int v, bool visitedV[]) {
	visitedV[v] = true;
	cout << v << " ";
	for (int i = 0; i < vertexCount; i++) {
		if (graphArr[v][i] && !visitedV[i])
			DFSrecurs(i, visitedV);
	}
};

void Graph::displayDFS(int vertex) {
	bool *visited = new bool[vertexCount];
	for (int i = 0; i < vertexCount; i++) {
		visited[i] = false;
	}
	DFSrecurs(vertex, visited);
};
void Graph::displayBFS(int vertex) {
	bool *visited = new bool[vertexCount];
	for (int i = 0; i < vertexCount; i++) {
		visited[i] = false;
	}
	queue <int> processBFS;
	visited[vertex] = true;
	processBFS.push(vertex);
	while (!processBFS.empty()) {
		int v = processBFS.front();
		cout << v << " ";
		processBFS.pop();
		for (int i = 0; i < vertexCount; i++) {
			if ((graphArr[v][i]) && (!visited[i])) {
				visited[i] = true;
				processBFS.push(i);
			}
		}
	}

};