import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static class Node implements Comparable<Node> {
        int r, c; // 가row줄
        int cost;

        public Node(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost; // 오름차순 정렬
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int tc = 1;

        while (true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0) break;

            int[][] map = new int[N][N];
            int[][] dist = new int[N][N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    dist[i][j] = Integer.MAX_VALUE; 
                }
            }

            System.out.println("Problem " + tc + ": " + dijkstra(N, map, dist));
            tc++;
        }
    }

    private static int dijkstra(int N, int[][] map, int[][] dist) {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        dist[0][0] = map[0][0];
        pq.offer(new Node(0, 0, map[0][0]));

        while (!pq.isEmpty()) {
            
            Node current = pq.poll();

            if (current.r == N - 1 && current.c == N - 1) {
                return current.cost;
            }

            for (int i = 0; i < 4; i++) {
                int nr = current.r + dr[i];
                int nc = current.c + dc[i];

                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {

                    int nextCost = current.cost + map[nr][nc];

                    if (nextCost < dist[nr][nc]) {
                        
                        dist[nr][nc] = nextCost;
                        
                        pq.offer(new Node(nr, nc, nextCost));
                    }
                }
            }
        }
        return 0;
    }
}