from Graph import Graph


class BreadthFirstSearch:
    def __init__(self, graph: Graph, vertice_i: int = 0):
        self.edge_to = []
        self.marked = []

        self.graph = graph
        self.vertice_i = vertice_i

        for vertice in range(len(graph.adjacency_list)):
            self.edge_to.append(0)
            self.marked.append(False)

        self.bfs()

    def bfs(self):
        queue = []

        self.marked[self.vertice_i] = True
        queue.append(self.vertice_i)

        while not len(queue) == 0:
            current_vertice = queue.pop(0)

            for adjacent_vertice in self.graph.get_adjacent(current_vertice):
                if not self.marked[adjacent_vertice]:
                    self.edge_to[adjacent_vertice] = current_vertice
                    self.marked[adjacent_vertice] = True
                    queue.append(adjacent_vertice)

    def has_path_to(self, vertice_j):
        return self.marked[vertice_j]

    def path_to(self, vertice_j):
        if not self.has_path_to(vertice_j):
            return []

        stack, current_vertice = [], vertice_j

        while current_vertice != self.vertice_i:
            stack.append(current_vertice)
            current_vertice = self.edge_to[current_vertice]

        stack.append(self.vertice_i)

        return stack
