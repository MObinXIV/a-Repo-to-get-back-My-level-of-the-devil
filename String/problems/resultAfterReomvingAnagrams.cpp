//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
bool isAnagram(string &a, string &b) {
    if (a.size() != b.size()) return false;

    int freq[26] = {0};
    for (char c : a) freq[c - 'a']++;
    for (char c : b) {
        if (--freq[c - 'a'] < 0) return false; // early exit if mismatch
    }
    return true;
}

vector<string> removeAnagrams(vector<string>& words) {
    vector<string> res;
    res.push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (!isAnagram(words[i], res.back())) // compare with last kept word
            res.push_back(words[i]);
    }

    return res;
}