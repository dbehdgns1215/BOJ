import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        
        int[][] delta = {{0, 1}, {1, 0}, {-1, -1}};
        
        int[][] arr = new int[n][n];
        
        int cnt = 0;
        int x = 0;
        int y = -1;
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - cnt; j++) {
                if (i % 3 == 0) {
                    arr[y + delta[0][1]][x + delta[0][0]] = num++;
                    y = y + delta[0][1];
                    x = x + delta[0][0];
                } else if (i % 3 == 1) {
                    arr[y + delta[1][1]][x + delta[1][0]] = num++;
                    y = y + delta[1][1];
                    x = x + delta[1][0];
                } else if (i % 3 == 2) {
                    arr[y + delta[2][1]][x + delta[2][0]] = num++;
                    y = y + delta[2][1];
                    x = x + delta[2][0];
                }
            }
            cnt++;
        }
        answer = new int[num - 1];
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                answer[idx++] = arr[i][j];
            }
        }
        
        return answer;
    }
}