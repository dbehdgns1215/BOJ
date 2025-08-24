import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer>[] node = new ArrayList[N + 1];
		boolean visited[] = new boolean[N + 1];
		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i <= N; i++) {
			node[i] = new ArrayList<>();
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			node[from].add(to);
			node[to].add(from);
		}
		
		int size = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			size++;
			
			visited[i] = true;
			q.add(i);
			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int nxt : node[cur]) {
					if (visited[nxt]) continue;
					
					q.add(nxt);
					visited[nxt] = true;
				}
			}
		}
		
		System.out.println(size);
	}

}
