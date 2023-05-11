//
//  journeyList.cpp
//  inter
//
//  Created by WildBoarGonnaGo on 10.05.2023.
//

#include <list>
#include <fstream>
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct gData {
	int v;
	pair<int, int> pos;
};

class Graph {
	int v;
	vector<list<gData>> adj;
	bool validDist(const gData &f, const gData &s, const int &max) {
		return abs(f.pos.first - s.pos.first)
		+ abs(f.pos.second - s.pos.second) <= max;
	}
public:
	Graph() { ; }
	Graph(istream &s) {
		int maxLen;

		s >> v;
		adj = vector<list<gData>>(v);
		for (int i = 0; i < v; ++i) {
			int x, y;
			s >> x >> y;
			adj[i].push_back({i, {x, y}});
		}
		s >> maxLen;
		for (int i = 0; i < v - 1; ++i)
			for (int j = i + 1; j < v; ++j)
				if (validDist(adj[i].front(), adj[j].front(), maxLen)) {
					adj[i].push_back(adj[j].front());
					adj[j].push_back(adj[i].front());
				}
	}
	void graphCout() {
		cout << "Adjustable verticies:" << endl;
		for (int i = 0; i < v; ++i) {
			for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
				if (it == adj[i].begin()) cout << it->v + 1 << ": ";
				else if (adj[i].size() == 1) cout << "none";
				else cout << it->v + 1 << " ";
			}
			cout << endl;
		}
	}
	const int &getV() const { return v; }
	const vector<list<gData>> &getAdj() const { return adj; }
};

class BFS {
	vector<bool> marked;
	vector<int> distTo;
public:
	BFS(const Graph &src, const int &s) {
		int st = s - 1;
		queue<gData> q;

		marked = vector<bool>(src.getV(), false);
		distTo = vector<int>(src.getV(), -1);
		marked[st] = true;
		distTo[st] = 0;
		q.push(*src.getAdj()[st].begin());
		while (!q.empty()) {
			auto aux = src.getAdj()[q.front().v];
			q.pop();
			for (auto it = aux.begin(); it != aux.end(); ++it) {
				if (it != aux.begin() && !marked[it->v]) {
					marked[it->v] = true;
					distTo[it->v] = distTo[aux.begin()->v] + 1;
					q.push(*it);
				}
			}
		}
	}
	int pathTo(const int &d) { return distTo[d - 1]; }
};

int main() {
	int s, d;

	ifstream in("../input_3.txt");
	Graph g(in);
	g.graphCout();
	in >> s >> d;
	BFS test(g, s);
	cout << endl << test.pathTo(d) << endl;
	return 0;
}
