class Graph:
    """
    A class to represent a direct graph using an adjacency list.
    """
    def __init__(self, n_vertices: int = 0):
        self.n_vertices = n_vertices
        self.adjacency_list = []

        self.__initialize()

    def __initialize(self):
        for vertice in range(self.n_vertices):
            self.adjacency_list.append([])

    def show(self):
        """
        Basic function to print the adjacency list.
        """
        for index, adjacent_vertices in enumerate(self.adjacency_list):
            print(f'v({index}): {adjacent_vertices}')

    def add_vertice(self):
        """
        Adds a new empty vertice to the graph.
        """
        self.adjacency_list.append([])

    def add_edge(self, vertice_i: int, vertice_j: int):
        """Adds a new edge to the graph.

        :param vertice_i: index of vertice i
        :param vertice_j: index of vertice j

        :raises ValueError when any of the vertices index is bigger than the max index of the adjacency list or when
        vertice_j already has an edge with vertice_i
        """
        if vertice_i >= len(self.adjacency_list) or vertice_j >= len(self.adjacency_list):
            raise ValueError(f'Vertice {max([vertice_i, vertice_j])} not found on graph')

        if vertice_j in self.adjacency_list[vertice_i]:
            raise ValueError(f'Vertice({vertice_j}) already has an edge connected with vertice({vertice_i}) list.')

        self.adjacency_list[vertice_i].append(vertice_j)

    def degree_of(self, vertice: int) -> int:
        """Computes the degree of a given vertice.

        :param vertice: integer indicating the index of a vertice
        :return: the degree of vertice i

        :raises ValueError when vertice is bigger than the number of vertices in the graph
        """
        if vertice >= len(self.adjacency_list):
            raise ValueError(f'Vertice {vertice} not found on graph')

        return len(self.adjacency_list[vertice])

    def max_degree(self) -> int:
        """Computes the maximum degree of a vertice in the graph.

        :return: The maximum degree of a vertice in the graph.
        """
        degree = 0
        for index in range(len(self.adjacency_list)):
            if self.degree_of(index) > degree:
                degree = self.degree_of(index)

        return degree

    def get_adjacent(self, vertice: int):
        if vertice >= len(self.adjacency_list):
            raise ValueError(f'Vertice {vertice} not found on graph')

        return self.adjacency_list[vertice]
