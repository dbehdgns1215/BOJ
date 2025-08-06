import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] network;
    static boolean[] invited;
    static int[] depth;
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        
        network = new boolean[N + 1][N + 1]; // A의 친구 B -> [A][B]
        invited = new boolean[N + 1];
        depth = new int[N + 1];
        
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            network[a][b] = true;
            network[b][a] = true;
        }

        q.add(1);
        invited[1] = true;

        int inviteCnt = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int i = 1; i <= N; i++) {
                if (!invited[i] && network[cur][i]) {
                    depth[i] = depth[cur] + 1;
                    if (depth[i] <= 2) {
                        inviteCnt++;
                        invited[i] = true;
                        q.add(i);
                    }
                }
            }
        }

        System.out.println(inviteCnt);
    }
}
