// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

int max(int a,int b){
    if(a>b)return a;
    else return b;
}

int min(int a,int b){
    if(a<b)return a;
    else return b;
}

int maxArea(int* height, int heightSize) {
    int left=0,right=heightSize-1;
    int area=0;int maxArea=0;
    while(left<right){
        area=min(height[left],height[right])*(right-left);
        maxArea=max(area,maxArea);
        if(height[left]<height[right])left++;
        else right--;
    }
    return maxArea;
}