#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include <queue>
#include <memory>

using namespace std;

class Graph {
	long v, w, it;
	pair<long, long> pos;
	vector<shared_ptr<Graph>> adj;
	set<long> nonValid;
	void AddEdge(long n, pair<long, long> val);
	bool DestValid(const Graph &f, const Graph &s, const long &maxLen) {
		return abs(f.pos.first - s.pos.first)
			+ abs(f.pos.second - s.pos.second) <= maxLen;
	}
public:
	Graph() {};
	Graph(Graph &&s) : v(move(s.v)), w(move(s.w)), it(move(s.it)),
		pos(move(s.pos)), adj(move(s.adj)), nonValid(move(s.nonValid)){ }
	Graph(istream &s) {
		long len;
		it = 1;
		v = 1;
		s >> len;
		adj = vector<shared_ptr<Graph>>(len);
		w = 0;
		for (long i = 0; i < len; ++i) {
			long x, y;
			s >> x >> y;
			adj[i] = make_shared<Graph>(i, len, pair<long, long>(x, y));
			//adj[i]
			adj[i]->w = 1;
		}
		s >> len;
		for (long i = 0; i < adj.size() - 1; ++i) {
			for (long j = i + 1; j < adj.size(); ++j) {
				if (adj[i]->nonValid.find(j) != adj[i]->nonValid.end() ||
					adj[j]->nonValid.find(i) != adj[j]->nonValid.end())
						continue;
				else if (!DestValid(*adj[i], *adj[j], len)) {
					adj[i]->nonValid.insert(j);
					adj[j]->nonValid.insert(i);
						continue;
				}
				else {
					adj[i]->adj[adj[i]->it++] = adj[j];
					++adj[i]->w;
					adj[j]->adj[adj[j]->it++] = adj[i];
					++adj[j]->w;
				}
			}
		}
	}
	Graph(const long &vert, const long &len, const pair<long, long> &srcPos) : v(vert),
		w(0), it(1), adj(vector<shared_ptr<Graph>>(len)), pos(srcPos) { ; }
	void GraphCout() {
		cout << "List of adjustables:" << endl;
		for (long i = 0; i < adj.size(); ++i) {
			cout << adj[i]->v + 1 << ": ";
			if (adj[i]->w == 1) cout << "none" << endl;
			else {
				for (long j = 1; j < adj[i]->w; ++j)
					cout << adj[i]->adj[j]->v + 1 << ((j != adj[i]->w - 1) ? ' ' : '\n');
			}
		}
	}
	const vector<shared_ptr<Graph>> &getGraphVector() const { return adj; }
	const long &getEdgeNumber() const { return w; }
	const long &getVertNumber() const { return v; }
};

class BreadthFirstSearch {
	long s;
	vector<long> distTo;
	vector<bool> marked;
public:
	BreadthFirstSearch() = delete;
	BreadthFirstSearch(Graph &&src, const long &start) {
		Graph g = move(src);
		s = start - 1;
		vector<shared_ptr<Graph>> roll = g.getGraphVector();
		marked = vector<bool>(roll.size(), false);
		distTo = vector<long>(roll.size(), -1);
		queue<shared_ptr<Graph>> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(g.getGraphVector()[s]);
		while (!q.empty()) {
			shared_ptr<Graph> tmp = q.front();
			q.pop();
			roll = tmp->getGraphVector();
			for (long i = 1; i < tmp->getEdgeNumber(); ++i) {
				if (!marked[roll[i]->getVertNumber()]) {
					distTo[roll[i]->getVertNumber()] = distTo[tmp->getVertNumber()] + 1;
					marked[roll[i]->getVertNumber()] = true;
					q.push(roll[i]);
				}
			}
			roll.clear();
		}
	}
	long pathTo(const long &dst) {
		long p = dst - 1;
		if (p < 0 || p > marked.size() - 1) return -1;
		return distTo[p];
	}
};

int main() {
	ifstream in("../input.txt");
	ofstream out("../output.txt");
	long s, p;

	Graph init(in);
	init.GraphCout();
	in >> s >> p;
	BreadthFirstSearch seek(move(init), s);
	out << seek.pathTo(p) << endl;
	return 0;
}
