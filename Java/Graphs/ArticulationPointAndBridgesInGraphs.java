
/*A node is called "Articulation point" when on removing the node, graph gets divided into two or more components*/
import java.util.*;
public class ArticulationPointAndBridgesInGraphs {
	static int[] parent;
	static int[] disc;
	static int[] low;
	static int time;
	static boolean visited[];
	static boolean ap[]; // articulation point array
	static List<List<Integer>> bridges;

	public static void dfs(int u, ArrayList<ArrayList<Integer>> graph) {
		disc[u] = low[u] = time;
		time++;
		visited[u] = true;
		int countforsrc = 0;
		ArrayList<Integer> nbrs = graph.get(u);
		for (int i = 0; i < nbrs.size(); ++i) {
			int v = nbrs.get(i);

			if (parent[u] == v && visited[v]) {
				continue;
			} else if (visited[u] == true) {
				low[u] = Math.min(low[u], disc[v]);
			} else {
				parent[v] = u; // settingparent
				dfs(v, graph);
				low[u] = Math.min(low[u], low[v]);
				// Update articulation point below
				if (parent[u] == -1) {
					// then it is actual source
					if (countforsrc >= 2) {
						ap[u] = true;
					}

				} else {
					if (low[v] > disc[u]) {
						ap[u] = true;
						ArrayList<Integer> bridge = new ArrayList<>();
						bridge.add(u);
						bridge.add(v);
						bridges.add(bridge);
					} else if (low[v] == disc[u]) {
						ap[u] = true;
					}
				}
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int e = sc.nextInt();

		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < e; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			graph.get(u).add(v);
			graph.get(v).add(u);
		}

		parent = new int[n];
		disc = new int[n];
		low = new int[n];
		time = 0;
		visited = new boolean[n];
		ap = new boolean[n];
		bridges = new ArrayList<>();
		parent[0] = -1;
		dfs(0, graph);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i] == true)
				ans++;
		}
		System.out.println(ans);
	}
}
