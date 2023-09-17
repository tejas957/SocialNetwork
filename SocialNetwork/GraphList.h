#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class GraphList
{
	

private:
	vector<list<int>> adj;
	int size;


public:
	GraphList(int s) {
		size = s;
		adj.resize(size);
	}
	void add(int s, int e) {
		if (s < size && s >= 0 && e < size && e >= 0 && s != e) {
			adj[s].push_back(e);
			adj[e].push_back(s);
		}
	}

	void remove(int s, int e) {
		if (s < size && s >= 0 && e < size && e >= 0 && s != e) {
			adj[s].remove(e);
			adj[e].remove(s);
		}
	}
	int getSize() {
		return size;
	}
	void display() {
		for (int b = 0; b < size; b++) {
			cout << "vertex " << b << " ";
			for (int w : adj[b]) {
				cout << w << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int edges() {
		int num = 0;
		for (int b = 0; b < size; b++) {
			for (int w : adj[b]) {
					num++;
			}

		}
		return num / 2;
	}

	void depthFirstTraversal(int s) {
		stack<int> vertices;
		vector<bool> visited(size);
		for (int r = 0; r < size; r++) {
			visited[r] = false;
		}
		vertices.push(s);
		visited[s] = true;
		int topVertex;
		while (vertices.empty() == false) {
			topVertex = vertices.top();
			vertices.pop();
			cout << topVertex << " ";

			for (int v: adj[topVertex]) {
				if (!visited[v]) {
					visited[v] = true;
					vertices.push(v);
				}
			}
		}

	}

	void breadthFirstTraversal(int s) {
		vector<bool> visited(size);
		queue<int> vq;
		for (int r = 0; r < size; r++) {
			visited[r] = false;
		}
		vq.push(s);
		visited[s] = true;
		int front;
		while (vq.empty() == false) {
			front = vq.front();
			vq.pop();
			cout << front;
			for (int q: adj[front]) {
				if(!visited[q]) {
					visited[q] = true;
					vq.push(q);
				}
			}
		}

	}
};

