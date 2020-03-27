/**
 * 134. 加油站
 */



class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0, current_gas = 0, start = 0;
        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];
            if(current_gas < 0){
                current_gas = 0;
                start = i+1;
            }
        }

        return total>=0?start:-1;
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */
