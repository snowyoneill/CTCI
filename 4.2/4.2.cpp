#if 0
#include <iostream>

#include "myQueue.h"

using namespace std;

bool *visited;

int N = 0; //number of nodes;
int M = 0; //number of edges;

bool route_exists(int **arr, int s, int e)
{
	myQueue<int> q;
	visited[s] = true;
	
	q.enqueue(s);
	while(q.size != 0)
	{
		int n = q.dequeue();
		if(n == e)
			return true;

		for(int i=0; i<N; i++)
			if(arr[n][i] && !visited[i])
			{
				q.enqueue(i);
				visited[i] = true;
			}
	}

	return false;
}

int main()
{
	freopen("4.2.in", "r", stdin);

    cin >> N >> M; //first line N = total nodes, M=total edges

	visited = new bool[N];
	memset(visited, false, sizeof(bool)*N);

	int **a = new int*[N];
	for(int i=0; i<N; i++)
		a[i] = new int[N];

	for(int i=0; i<N; i++)
		memset(a[i], 0, sizeof(int)*N);

	int n, m;
	for(int i=0; i<M; i++)
	{
		cin >> n >> m;
		a[n][m] = 1;
	}

	int s = 3;
	int e = 1;
	bool ret = route_exists(a, s, e);
	cout << "Route exists from " << s << " to " << e << ": " << ret << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

#include "LinkedListT.h"
#include "myQueue.h"

bool *visited; // list of visited indexs in the graph vector.

using namespace std;

int N = 0; //number of nodes;
int M = 0; //number of edges;

bool route_exists(vector<LinkedListT<int>*> arr, int s, int e)
{
	myQueue<LinkedListT<int>*> q;
	visited[s] = true;
	
	q.enqueue(arr[s]);
	while(q.size != 0)
	{
		LinkedListT<int> *l = q.dequeue();
		
		int len = l->size;
		for(int i=0; i<len; i++)
		{
			if(l->data == e)
				return true;

			if(!visited[l->data])
			{
				q.enqueue(arr[l->data]);
				visited[l->data] = true;
			}
			l = l->next;
		}
	}

	return false;
}

int main()
{
	freopen("4.2.in", "r", stdin);

    cin >> N >> M; //first line N = total nodes, M=total edges

	visited = new bool[N];
	memset(visited, false, sizeof(bool)*N);

	/*
		0 1
		0 3
		1 2
		2 3

		{1, 3},
		{2},
		{3}
		{}
	*/

	//vector<LinkedListT<int>*> *graph;
	vector<LinkedListT<int>*> graph;
	for(int i=0; i<N; i++)
		//(*graph)[i] = new LinkedListT<int>();
		graph.push_back(new LinkedListT<int>());

	int n, m;
	for(int i=0; i<M; i++)
	{
		cin >> n >> m;
		graph[n]->appendToTail(m);
	}

	int s = 0; //idx of start node in graph array.
	int e = 2; //idx of end node in graph array.
	bool ret = route_exists(graph, s, e);
	cout << "Route exists from " << s << " to " << e << ": " << ret << endl;

	return 0;
}
#endif

#if 1
#include <iostream>
#include <vector>

#include "LinkedListT.h"
#include "myQueue.h"

//template <class T>
//class LinkedListWithState : public LinkedListT<T>
//{
//public:
//	bool visited;
//
//	LinkedListWithState() : visited(false) {}
//};

template <class T>
class LinkedListWithState {

	public:

		bool visited;
		LinkedListWithState *next;
		T data;
		int size;

		LinkedListWithState() : next(NULL), data(), size(0), visited(false) {}
		LinkedListWithState(T d) : next(NULL), data(d), size(1), visited(false) {}
		~LinkedListWithState() {}

		void appendToTail(T d) {
			LinkedListWithState *start = this;
			if(size == 0) { // used to overwrite the head of the linked list with a node containing data.
				start->data = d;
				size++;
				return;
			}

			LinkedListWithState<T> *curr = new LinkedListWithState(d);
			while(start->next != NULL)
				start = start->next;
			start->next = curr;
			size++;
		}
		void appendToTail(LinkedListWithState<T> *node)
		{
			LinkedListWithState *start = this;
			if(size == 0) { // used to overwrite the head of the linked list with a node containing data.
				start = node;
				size++;
				return;
			}

			LinkedListWithState<T> *curr = node;
			while(start->next != NULL)
				start = start->next;
			start->next = curr;
		}

		void printList() {
			LinkedListWithState *curr = this;

			while(curr != NULL) {
				cout << curr->data << ", ";
				curr = curr->next;
			}
		}
};

using namespace std;

int N = 0; //number of nodes;
int M = 0; //number of edges;

bool route_exists(vector<LinkedListWithState<int>*> arr, int s, int e)
{
	myQueue<LinkedListWithState<int>*> q;
	
	q.enqueue(arr[s]);
	while(q.size != 0)
	{
		LinkedListWithState<int> *l = q.dequeue();
		
		int len = l->size;
		for(int i=0; i<len; i++)
		{
			if(l->data == e)
				return true;

			if(!l->visited)
			{
				q.enqueue(arr[l->data]);
				l->visited = true;
			}
			l = l->next;
		}
	}

	return false;
}

int main()
{
	freopen("4.2.in", "r", stdin);

    cin >> N >> M; //first line N = total nodes, M=total edges

	/*
		0 1
		0 3
		1 2
		2 3

		{1, 3},
		{2},
		{3}
		{}
	*/

	//vector<LinkedListT<int>*> *graph;
	vector<LinkedListWithState<int>*> graph;
	for(int i=0; i<N; i++)
		//(*graph)[i] = new LinkedListT<int>();
		graph.push_back(new LinkedListWithState<int>());

	int n, m;
	for(int i=0; i<M; i++)
	{
		cin >> n >> m;
		graph[n]->appendToTail(m);
	}

	int s = 0; //idx of start node in graph array.
	int e = 3; //idx of end node in graph array.
	bool ret = route_exists(graph, s, e);
	cout << "Route exists from " << s << " to " << e << ": " << ret << endl;

	return 0;
}

#endif