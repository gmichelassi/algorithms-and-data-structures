from Graph import Graph


class DepthFirstSearch:
    def __init__(self, graph: Graph):
        self.marked = []

        self.graph = graph

        for vertice in range(len(graph.adjacency_list)):
            self.marked.append(False)

    def dfs(self, vertice_i: int, vertice_j: int):
        self.marked[vertice_i] = True

        if vertice_i == vertice_j:
            return 0

        for adjacent_vertice in self.graph.get_adjacent(vertice_i):
            if not self.marked[adjacent_vertice]:
                distance = self.dfs(adjacent_vertice, vertice_j) + 1

                if distance > 0:
                    return distance

        return -1
