import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int maxCapacity = nums.length / 2;

        HashSet<Integer> set = new HashSet<>();
        
        for (int num : nums) {
            set.add(num);
        }

        return Math.min(set.size(), maxCapacity);
    }
}