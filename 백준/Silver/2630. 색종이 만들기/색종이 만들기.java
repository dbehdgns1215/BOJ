import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] arr;   // arr[y][x] : y=행(c), x=열(r)
    static int blue = 0;
    static int white = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        arr = new int[N][N];
        for (int y = 0; y < N; y++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                arr[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        paper(0, 0, N); // (x=0, y=0)에서 시작, 한 변 길이 N

        // BOJ 2630 출력 형식: 흰색, 파란색
        System.out.println(white);
        System.out.println(blue);
    }

    // (x, y) : 현재 영역의 좌상단 좌표, size : 현재 영역의 한 변 길이
    static void paper(int x, int y, int size) {
        if (isUniform(x, y, size)) {
            if (arr[y][x] == 1) blue++;
            else white++;
            return;
        }
        int half = size / 2;

        // 좌상, 우상, 좌하, 우하 (x는 가로, y는 세로)
        paper(x, y, half);
        paper(x + half, y, half);
        paper(x, y + half, half);
        paper(x + half, y + half, half);
    }

    // 해당 영역이 한 색(0 또는 1)으로만 채워졌는지 검사
    static boolean isUniform(int x, int y, int size) {
        int color = arr[y][x];
        for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
                if (arr[i][j] != color) return false;
            }
        }
        return true;
    }
}
