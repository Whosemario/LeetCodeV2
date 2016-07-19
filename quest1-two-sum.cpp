/*
   1. sort 的使用
   2. 二分查找 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell {
	int idx, val;
};

bool comp(const Cell& a, const Cell& b) {
	if(a.val < b.val) return true;
	else if(a.val > b.val) return false;
	else return a.idx < b.idx;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Cell> cells(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
        	cells[i].idx = i;
        	cells[i].val = nums[i];
		}
		sort(cells.begin(), cells.end(), comp);
		vector<int> ret(2);
		for(int i = 0; i < cells.size() - 1; ++i) {
			if(target - cells[i].val < cells[i].val) break;
			int idx = findOne(cells, i+1, cells.size() - 1, target - cells[i].val);
			if(idx != -1) {
				ret[0] = cells[i].idx;
				ret[1] = cells[idx].idx;
				if(ret[0] > ret[1]) {
					int tmp = ret[0];
					ret[0] = ret[1];
					ret[1] = tmp;
				}
				break;
			}
		}
		return ret;
    }
    
private:
	int findOne(vector<Cell>& cells, int low, int high, int target) {
		while(low <= high) {
			int mid = (low + high) / 2;
			if(cells[mid].val == target) {
				return mid;
			} else if(cells[mid].val > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;
	}
};

int main() 
{ 
	Solution s;
	int nums[] = {3,2,4};
	vector<int> v(nums, nums+3);
	vector<int> ret = s.twoSum(v, 6);
	cout << ret[0] << " " << ret[1] << endl;
	return 0;
}
