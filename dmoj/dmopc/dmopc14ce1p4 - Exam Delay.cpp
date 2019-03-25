#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <queue>
#include <cmath>

#define iinf numeric_limits<int>::max()
#define dinf numeric_limits<double>::max()

using namespace std;

struct Edge;

struct Node
{
	vector<Edge> edges;
	double dist;
	int edge;
	bool visited;

	Node()
	{
		dist = dinf;
		edge = iinf;
		visited = 0;
	}
};

struct Edge
{
	Node* dest;
	double dist;

	Edge(Node* _dest, double _dist)
	{
		dest = _dest;
		dist = _dist;
	}
};

class Compare
{
public:
	bool operator() (Node* a, Node* b)
	{
		if (a->dist > b->dist)
			return 1;
		if (a->dist == b->dist && a->edge > b->edge)
			return 1;
		return 0;
	}
};

Node graph[1001];

void Dijkstra()
{
	priority_queue<Node*, vector<Node*>, Compare> q;
	graph[1].dist = graph[1].edge = 0;
	q.push(&graph[1]);

	while (!q.empty())
	{
		Node* x = q.top();
		q.pop();

		x->visited = 1;

		for (Edge &e : x->edges)
		{
			if (!e.dest->visited)
			{
				double dist = x->dist + e.dist;
				int edges = x->edge + 1;

				if (dist < e.dest->dist)
				{
					e.dest->dist = dist;
					e.dest->edge = edges;
					q.push(e.dest);
				}
				else if (dist == e.dest->dist && edges < e.dest->edge)
				{
					e.dest->edge = edges;
					q.push(e.dest);
				}
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);

	int V, E;
	cin >> V >> E;

	while (E--)
	{
		int m, n;
		double d, s;

		cin >> m >> n >> d >> s;
		graph[m].edges.push_back(Edge(&graph[n], d * 60 / s));
		graph[n].edges.push_back(Edge(&graph[m], d * 60 / s));
	}

	Dijkstra();

	cout << graph[V].edge << endl;
	cout << round(graph[V].dist / 3) << endl;

	return 0;
}
