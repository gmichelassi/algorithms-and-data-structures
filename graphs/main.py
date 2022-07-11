from Graph import Graph
from DepthFirstSearch import DepthFirstSearch
from BreadthFirstSearch import BreadthFirstSearch


def main():
    graph = Graph(n_vertices=6)

    graph.add_edge(1, 3)
    graph.add_edge(3, 1)
    graph.add_edge(3, 2)
    graph.add_edge(2, 4)
    graph.add_edge(4, 3)
    graph.add_edge(1, 1)
    graph.add_edge(0, 1)
    graph.add_edge(0, 4)
    graph.add_edge(4, 0)

    graph.add_edge(5, 5)

    graph.show()

    bfs = BreadthFirstSearch(graph=graph, vertice_i=0)
    print(f'Breadth-first search: path from 0 to 3: {bfs.path_to(3)}')
    print(f'Breadth-first search: path from 0 to 5: {bfs.path_to(5)}')

    dfs = DepthFirstSearch(graph=graph)
    print(f'Depth-first search distance between 0 and 3: {dfs.dfs(0, 3)}')
    print(f'Depth-first search distance between 0 and 2: {dfs.dfs(0, 2)}')
    print(f'Depth-first search distance between 0 and 5: {dfs.dfs(0, 5)}')


if __name__ == '__main__':
    main()  
