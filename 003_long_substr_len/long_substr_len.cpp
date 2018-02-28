/*
 * 最长不重复子串长度
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#最长不重复子字符串-003
 *
 * @author PLM
 * @date 2018-02-28
 */


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


void show(const vector<int>& a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}


void show_map(map<char, int> &m) {
    cout << "map: ";
    for (map<char, int>::iterator it=m.begin(); it != m.end(); ++it) {
        cout << it->first << "=" << it->second << " ";
    }
    cout << endl;
}


/*
 * 字符串中，最长不重复子串的长度，是连续
 * Args:
 *      s -- 原字符串
 * Returns:
 *      len -- 最长子串长度
 */
int long_substr_len(const string& s) {
    if (s.empty()) {
        return 0;
    }
    // 长度，l[i]=k，以s[i]结尾的最大子串长度为k
    vector<int> l(s.length(), 0);
    // 位置，m['a']=i，最近，字符a出现的位置是i
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (i == 0) {
            l[i] = 1;
            m[ch] == i;
            continue;
        }
        if (m.find(ch) == m.end()) {
            // ch 没出现过
            l[i] = l[i-1] + 1;
        } else {
            // ch 出现过
            int d = i - m[ch];
            if (d > l[i-1]) {
                // 上一个ch距离很远
                l[i] = l[i-1] + 1;
            } else {
                // 上一个ch距离很近
                l[i] = d;
            }
        }
        // 更新出现位置
        m[ch] = i;
    }
    return *max_element(l.begin(), l.end());
}


void test(const string& test_name, const string& s, int expected) {
    cout << test_name << ": ";
    int res = long_substr_len(s);
    if (res == expected) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail!" << ",exp=" << expected << ",res=" << res<< endl;
    }
    return;
}

void test1() {
    string s = "abcabcbb";
    int exp = 3;
    test("test1", s, exp);
}


void test2() {
    string s = "pwwkew";
    int exp = 3;
    test("test2", s, exp);
}


void test_map() {
    map<char, int> m;
    m['a'] = 0;
    char ch = 'b';
    if (m.find(ch) != m.end()) {
        cout << "found: " << ch << "=" << m[ch]<< endl;
    } else {
        cout << "not found: " << ch << endl;
    }
}


int main() {
    test1();
    test2();
    // test_map();
    return 0;
}
