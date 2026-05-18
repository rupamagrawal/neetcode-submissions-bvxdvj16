class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();

        vector<pair<int,int>>cars;
        for(int i=0; i<n; i++){
            cars.push_back({pos[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

       int fleets = 0;
        float top = 0;

        for(int i = 0; i < n; i++){
            float t = (float)(target - cars[i].first) / cars[i].second;
            if(t > top){
                fleets++;
                top = t;
            }
        }

        return fleets;
    }
};
