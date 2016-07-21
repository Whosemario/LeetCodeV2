#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define MAXLEN 256

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.length() == 0) return 0;
        int color[MAXLEN];
        memset(color, 0, sizeof(color));
        int len = s.length();
        int head = 0, tail = 1;
        int ret = 1;
        color[(int)s[head]] = 1;
        while(tail < len) {
        	color[(int)s[tail]] += 1;
        	if(color[(int)s[tail]] > 1) {
        		while(head < tail) {
        			if(color[(int)s[head]] > 1) {
        				color[(int)s[head]] -= 1;
        				head += 1;
        				break;
        			} else  {
        				color[(int)s[head]] -= 1;
        				head += 1;
					}
				}
			}
			tail += 1;
			if(tail - head > ret) ret = tail - head;
		}
		return ret;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << s.lengthOfLongestSubstring("tmmzuxt") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}

