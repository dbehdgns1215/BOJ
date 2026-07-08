import java.util.*;

// 정렬을 활용한 구현
class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);

        for (int i = 0; i < phone_book.length - 1; i++) {
            if (phone_book[i + 1].startsWith(phone_book[i])) {
                return false;
            }
        }

        return true;
    }
}

// 해시셋을 활용한 구현
/*
class Solution {
    public boolean solution(String[] phone_book) {
        Set<String> set = new HashSet<>();

        for (String phone : phone_book) {
            set.add(phone);
        }

        for (String phone : phone_book) {
            for (int i = 1; i < phone.length(); i++) {
                String prefix = phone.substring(0, i);

                if (set.contains(prefix)) {
                    return false;
                }
            }
        }

        return true;
    }
}
*/