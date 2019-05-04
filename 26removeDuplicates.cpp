/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t;
        vector<int>::iterator itr; 
        itr = unique(nums.begin(), nums.end());
        nums.erase(itr, nums.end());
        t = nums.size();
        return t;
    }
};
*/
//题目默认给出条件vector数组，因此用unique()及erase()函数即可。
//unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器再用erase函数擦除从这个元素到最后元素的所有的元素


//标准题解：双指针法itr1与itr2两个迭代器，itr2类似于快指针，itr1则为慢指针。
//         若两者相等，itr2前进以跳过重复项
//         若两者不等，即重复项结束，把itr2的值赋值给itr1前进后指向的区域。即(*(++itr1)) = *itr2
//         最后通过erase()删除itr指针所指向区域后面的部分，并调用size()来获取vector大小。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int>::iterator itr1 = nums.begin();
        for(vector<int>::iterator itr2 = nums.begin() + 1; itr2 != nums.end(); ++itr2)
            if(*itr1 != *itr2)
            {
                (*(++itr1)) = *itr2;
            }
        nums.erase(itr1 + 1, nums.end());
        return nums.size();
    }
};