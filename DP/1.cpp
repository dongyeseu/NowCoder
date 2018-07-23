/*
题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。

给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。

测试样例：
[1,2,3,4,5]
返回：false
*/

（一）
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        for(int i = 0 ; i < n ; i++)
        {
            if(A[i] == i)
                return true;
        }
        return false;
    }
};


（二）
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        int left = 0 , right = n-1 , mid;
        while(left < right)
        {
            mid = left + (right + left)/2;
            if(mid == A[mid])
                return true;
            else if (A[mid] > mid)
                right = mid;
            else if (A[mid] < mid)
                left = mid+1;
        }
        return false;
    }
};


//他山之玉
class MagicIndex {
private:
    bool magic(vector<int> A,int start, int end){
        if(start >= end) return false;
        int mid = (start+end)/2;
        if(mid == A[mid]) return true;
        else if(mid > A[mid]) return magic(A,mid+1,end);
        else return magic(A,start,mid);
    }
public:
    bool findMagicIndex(vector<int> A, int n) {
        if(n == 0) return true;
        else return magic(A,0,n);
    }
};




public boolean findMagicIndex(int[] A, int n) {
  return A[0]==0;
}
