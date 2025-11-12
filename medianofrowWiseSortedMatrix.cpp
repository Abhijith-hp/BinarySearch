class Solution {
  public:
  
    int upperBound(vector<int>&arr,int value){
        int low = 0;
        int high = arr.size() -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] <= value)
                    low = mid+1;
            else high = mid-1;
              
        }
        return low;
    }
    int getNoOfSmallerElements(vector<vector<int>>&mat,int element){
        int noOfSmallerElements = 0;
        for(int i=0;i<mat.size();i++)
            noOfSmallerElements += upperBound(mat[i],element);
        return noOfSmallerElements;
        
    }
    int median(vector<vector<int>> &mat) {
        
        int low = INT_MAX;;
        int high = INT_MIN;
        int row = mat.size();
        int col = mat[0].size();
        int required = (row * col)/2;
        
        for(int i=0;i<row;i++){
            low = min(low,mat[i][0]);
            high = max(high, mat[i][col-1]);  
        }
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int noOfmallerElements = getNoOfSmallerElements(mat,mid);
            if(noOfmallerElements<=required) low = mid +1;
            else high = mid -1;
        }
        return low;
    }
};