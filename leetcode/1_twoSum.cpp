void maxHeapify(vector<int> &numVector){
    for (int i = (numVector.size()/2) - 1; i >=0 ; i--){
        int j = i;
        while (j < numVector.size() - 1) {
            int leftVal = -999;
            int rightVal = -999;
            if ((2*j+1) < numVector.size()) leftVal = numVector[2*j + 1];
            if ((2*j+2) < numVector.size()) rightVal = numVector[2*j + 2];
            
            if (rightVal > numVector[j]) {
                if (rightVal >= leftVal) {
                    int temp = numVector[j];
                    numVector[j] = rightVal;
                    numVector[2*j + 2] = temp;
                    j = 2*j + 2;
                }
                else {
                    int temp = numVector[j];
                    numVector[j] = leftVal;
                    numVector[2*j + 1] = temp;
                    j = 2*j + 1;
                }
            }
            else if (leftVal > numVector[j]) {
                int temp = numVector[j];
                numVector[j] = leftVal;
                numVector[2*j + 1] = temp;
                j = 2*j + 1;
            }
            else break;
        }
    }
}

void fixHeap(vector<int> &numVector, int curLast) {
    int j = 0;
    
    while (j < curLast) {
        int leftVal = -999;
        int rightVal = -999;
        if ((2*j+1) < curLast) leftVal = numVector[2*j + 1];
        if ((2*j+2) < curLast) rightVal = numVector[2*j + 2];
        
        if (rightVal > numVector[j]) {
            if (rightVal >= leftVal) {
                int temp = numVector[j];
                numVector[j] = rightVal;
                numVector[2*j + 2] = temp;
                j = 2*j + 2;
            }
            else {
                int temp = numVector[j];
                numVector[j] = leftVal;
                numVector[2*j + 1] = temp;
                j = 2*j + 1;
            }
        }
        else if (leftVal > numVector[j]) {
            int temp = numVector[j];
            numVector[j] = leftVal;
            numVector[2*j + 1] = temp;
            j = 2*j + 1;
        }
        else break;
    }
}


void heapSort(vector<int> &numVector) {
    maxHeapify(numVector);
    
    for (int i = 0 ; i < numVector.size(); i++) {
        int temp = numVector[0];
        int curLast = numVector.size() - 1 - i;
        numVector[0] = numVector[curLast];
        numVector[curLast] = temp;
        fixHeap(numVector,curLast);
    }
}

int findIndex(vector<int> &nums,int number,int start) {
    
    for (int j = 0; j < nums.size(); j++){
        if (nums[j] == number && j != start) return j;
    }
    return -1;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tempNums = nums;
        heapSort(tempNums);
        int start = 0;
        int end = nums.size() - 1;
        vector<int> results;
        
        while (start <= end) {
            if (tempNums[start] + tempNums[end] > target){
                end--;
            }
            else if (tempNums[start] + tempNums[end] < target) {
                start++;
            }
            else {
                int pos = findIndex(nums,tempNums[start],-1);
                results.push_back(pos+1);
                results.push_back(findIndex(nums,tempNums[end],pos)+1);
                if (results[0] > results[1]) {
                    int temp = results[0];
                    results[0] = results[1];
                    results[1] = temp;
                }
                return results;
            }
        }
        
        return results;
    }
};