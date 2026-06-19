// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int trap(int* height, int heightSize) {
	int leftarr[heightSize];int rightarr[heightSize];
	leftarr[0]=height[0];
	for(int i=1;i<heightSize;i++){
		leftarr[i]=max(leftarr[i-1],height[i]);
	}
	rightarr[heightSize-1]=height[heightSize-1];
	for(int i=heightSize-2;i>=0;i--){
		rightarr[i]=max(rightarr[i+1],height[i]);
	}
	int trapped=0;
	int water=0;
	for(int i=0;i<heightSize;i++){
		trapped=min(leftarr[i],rightarr[i])-height[i];
		water+=trapped;
	}	
    return water;
}
