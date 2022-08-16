class Solution {
public:
      void merge(vector<int>& numbers1, int size1, vector<int>& numbers2, int size2)
    {                        
        int index1 = size1 - 1, index2 = size2 - 1, validIndex = numbers1.size() - 1;
        while (index1 >= 0 && index2 >= 0)
        {
            numbers1[validIndex--] = (numbers1[index1] > numbers2[index2]) 
                                     ? (numbers1[index1--]) : (numbers2[index2--]);
        }
        
        while (index2 >= 0) numbers1[validIndex--] = numbers2[index2--];
    }
};