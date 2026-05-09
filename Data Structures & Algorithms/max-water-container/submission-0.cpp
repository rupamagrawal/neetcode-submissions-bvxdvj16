class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int area = 0;

        while(left < right){
            int hig = min(heights[left], heights[right]);
            int wid = right - left;
            area = max(area, hig*wid);

            if(heights[left] < heights[right])left++;
            else right--;
        }

        return area;
    }
};
