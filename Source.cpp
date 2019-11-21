/*
Author: Katie McLane
file - source.cpp
Summary: test driver for Graph class

*/
#include "graph.h"
#include <iostream>
#include "string"
using namespace std;

int main() {
	char quit = 'p';
	while (quit != 'q'){
		string pathway;
		cout << "What is the FULL file pathway where the txt is located?" << endl;
		cin >> pathway;
		char *pStr = &pathway[0];
		Graph g;
		g.load(pStr);
		cout << endl;
		cout << "Adjacency Matrix:" << endl;
		g.display();
		cout << endl << endl;
		cout << "DFS at vertex 0: ";
		g.displayDFS(0);
		cout << endl << endl;
		cout << "BFS at vertex 0: ";
		g.displayBFS(0);
		cout << endl << endl;
		cout << "Press a key and then enter to enter another graph OR press q then enter to quit" << endl;
		cin >> quit;
	}
	
	return 0;
};