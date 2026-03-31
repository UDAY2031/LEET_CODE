class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;
        string res(L, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < L; i++) {
            if (res[i] == '?') res[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    bool changed = false;
                    for (int j = m - 1; j >= 0; j--) {
                        char orig = res[i + j];
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == orig) continue;
                            res[i + j] = c;
                            bool ok = true;
                            for (int k = 0; k < n; k++) {
                                if (str1[k] == 'T') {
                                    for (int t = 0; t < m; t++) {
                                        if (res[k + t] != str2[t]) {
                                            ok = false;
                                            break;
                                        }
                                    }
                                    if (!ok) break;
                                }
                            }
                            if (ok) {
                                changed = true;
                                break;
                            }
                        }
                        if (changed) break;
                        res[i + j] = orig;
                    }
                    if (!changed) return "";
                }
            }
        }

        return res;
    }
};