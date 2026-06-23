int largestRectangleArea(int* heights, int heightsSize) {
    int arr[heightsSize];int top=-1;
    int Area=heights[0];int area;
    arr[++top]=0;
    int b,h;
    for(int i=1;i<=heightsSize;i++){
        int currentHeight = (i == heightsSize) ? 0 : heights[i];
        while(top!=-1 && heights[arr[top]]>currentHeight){
            h=heights[arr[top--]];
            b=(top==-1)?i:(i-arr[top]-1); 
            area=h*b;
            Area=(area>Area)?area:Area;
        }
        if(i<heightsSize){
            arr[++top]=i;
        }
    }
    return Area;
}