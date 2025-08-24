import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        long[] ps = new long[N + 1]; // ps[0]=0, ps[i]=a[1]+...+a[i]

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            ps[i] = ps[i - 1] + Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        for (int q = 0; q < M; q++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            sb.append(ps[r] - ps[l - 1]).append('\n');
        }
        System.out.print(sb);
    }
}
