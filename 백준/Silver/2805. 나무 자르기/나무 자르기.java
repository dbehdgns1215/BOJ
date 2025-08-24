import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static long[] arr;
    static int N;
    static long M;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Long.parseLong(st.nextToken());

        arr = new long[N];
        long maxH = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            if (arr[i] > maxH) maxH = arr[i];
        }

        long lo = 0;
        long hi = maxH;
		long ans = 0;
        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            long cut = 0;
            for (long h : arr) {
                if (h > mid) cut += (h - mid);
            }
            if (cut >= M) {      // 충분히 잘렸으니 높이를 더 올려본다
                ans = mid;
                lo = mid + 1;
            } else {             // 부족하면 높이를 낮춘다
                hi = mid - 1;
            }
        }
        System.out.println(ans);
    }
}
