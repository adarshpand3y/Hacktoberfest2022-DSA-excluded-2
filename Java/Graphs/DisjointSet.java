import java.util.Scanner;

public class DisjointSet {
	int[] parent;
	int[] rank;

	DisjointSet(int n) {
		parent = new int[n];
		rank = new int[n];
	}

	public void makeSet(int n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	public void union(int x, int y) {
		int lx = find(x);
		int ly = find(y);
		if (lx != ly) {
			if (rank[lx] > rank[ly]) {
				parent[ly] = lx;
			} else if (rank[lx] < rank[ly]) {
				parent[lx] = ly;
			} else {
				parent[lx] = ly;
				rank[ly]++;
			}
		}
	}

	public int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		int temp = find(parent[x]);
		parent[x] = temp;
		return temp;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		DisjointSet dsu = new DisjointSet(m);
		dsu.makeSet(m);
		while (m-- > 0) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			dsu.union(u, v);
		}
		System.out.println("Dsu created Succesfully");
	}

}