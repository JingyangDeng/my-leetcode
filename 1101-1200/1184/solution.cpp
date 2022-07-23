//一次遍历
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination) return distanceBetweenBusStops(distance, destination, start);
        int sum = 0, clockwise = 0;
        for(int i = 0; i < distance.size(); ++i){
            sum += distance[i];
            if(start <= i && i < destination){
                clockwise += distance[i];
            }
        }
        return min(clockwise, sum - clockwise);
    }
};
