class Solution {
public:
    bool isAnagram(string s, string t) {
        // Get the lengths of both strings
        int n1 = s.size();
        int n2 = t.size();

        // Frequency array for 26 lowercase English letters, initialized to 0
        vector<int> f(26, 0);

        // If the lengths are different, they cannot be anagrams
        if (n1 != n2)
            return false;

        // Count the frequency of each character in string `s`
        for (int i = 0; i < n1; i++) {
            int idx = s[i] - 'a'; // Convert character to index (0 for 'a', ..., 25 for 'z')
            f[idx]++;             // Increment the count for this character
        }

        // Subtract the frequency of each character in string `t`
        for (int i = 0; i < n2; i++) {
            int idx = t[i] - 'a'; // Convert character to index
            f[idx]--;             // Decrement the count for this character
        }

        // After both operations, all frequencies should be zero if they are anagrams
        for (int i = 0; i < 26; i++) {
            if (f[i] != 0)        // If any frequency is not zero, strings are not anagrams
                return false;
        }

        // All checks passed, the strings are anagrams
        return true;
    }
};
