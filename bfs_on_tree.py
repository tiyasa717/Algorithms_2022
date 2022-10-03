import random
from collections import defaultdict

class Graph:

	def _init_(self):

		self.graph = defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def BFS(self, s):

		visited = [False] * (max(self.graph) + 1)

		queue = []

		queue.append(s)
		visited[s] = True

		while queue:

			s = queue.pop(0)
			print (s, end = " ")

			for i in self.graph[s]:
				if visited[i] == False:
					queue.append(i)
					visited[i] = True

# Driver code
g = Graph()
n = (int)(input("Enter the number of vertices:"))
while(2*n):
	n = n - 1
	g.addEdge(random.randint(1,10), random.randint(1,10))
source = (int)(input("Enter the source vertex:"))

g.BFS(source)
