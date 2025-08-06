import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] network;
    static boolean[] visited;
    static int[] depth;
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        
        network = new boolean[N + 1][N + 1];
        visited = new boolean[N + 1];
        depth = new int[N + 1];

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            network[a][b] = true;
            network[b][a] = true;
        }

        Queue<Integer> q = new LinkedList<>();
        
        q.add(1);
        visited[1] = true;

        int inviteCnt = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int i = 1; i <= N; i++) {
                if (!visited[i] && network[cur][i]) {
                    depth[i] = depth[cur] + 1;
                    if (depth[i] <= 2) {
                        inviteCnt++;
                        visited[i] = true;
                        q.add(i);
                    }
                }
            }
        }

        System.out.println(inviteCnt);
    }
}
