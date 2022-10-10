

import java.util.*;

public class CycleDetectionInGraphs {
	static class Pair {
		int current;
		int parent;

		public Pair(int current, int parent) {
			super();
			this.current = current;
			this.parent = parent;
		}

	}

	public static void main(String[] args) {
		int n = 5;
		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
		boolean[] visited = new boolean[n];
		for (int i = 0; i < n; i++)
			adj.add(i, new ArrayList<Integer>());

		adj.get(0).add(1);
		adj.get(1).add(0);

		// edge 1---2
		adj.get(1).add(2);
		adj.get(2).add(1);

		// edge 2--3
		adj.get(2).add(3);
		adj.get(3).add(2);

		// edge 3--4
		adj.get(3).add(4);
		adj.get(4).add(3);

		// edge 1--4
		adj.get(1).add(4);
		adj.get(4).add(1);

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				boolean cycleWithBfs = detectCycleWithBFS(adj, i, visited);
				System.out.println(cycleWithBfs + " bfs" + i);
			}
		}
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				boolean cycleWithDFS = detectCycleWithDFS(adj, i, visited, -1);
				System.out.println(cycleWithDFS + " dfs" + i);
			}
		}
		// We need a different input for detectCycleWithDirectedDFS
	}

	public static boolean detectCycleWithBFS(ArrayList<ArrayList<Integer>> graph, int src, boolean[] visited) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(src, -1));
		visited[src] = true;
		while (q.size() > 0) {
			int size = q.size();
			while (size-- > 0) {
				int current = q.element().current;
				int parent = q.element().parent;
				q.remove();

				for (Integer i : graph.get(current)) {
					if (visited[i] == false) {
						q.add(new Pair(i, current));
						visited[i] = true;
					} else if (parent != i)
						return true;
				}
			}
		}
		return false;
	}

	public static boolean detectCycleWithDFS(ArrayList<ArrayList<Integer>> graph, int src, boolean[] visited,
			int parent) {

		visited[src] = true;
		for (Integer i : graph.get(src)) {
			if (!visited[i]) {
				if (detectCycleWithDFS(graph, i, visited, src))
					;
				return true;
			} else if (i != parent)
				return true;
		}
		return false;
	}

	public static boolean detectCycleWithDirectedDFS(ArrayList<ArrayList<Integer>> graph, int src, boolean[] visited,
			boolean[] dfsvisited) {

		visited[src] = true;
		dfsvisited[src] = true;
		for (Integer i : graph.get(src)) {
			if (!visited[i]) {
				if (detectCycleWithDirectedDFS(graph, i, visited, dfsvisited))
					return true;
			} else if (dfsvisited[i]) {
				return true;
			}
		}
		dfsvisited[src] = false;
		return false;
	}
}