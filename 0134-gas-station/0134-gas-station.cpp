class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //travel is possible only if petrol - distance >= 0
        int n = gas.size();
        //time -> 1:12:06

        //queue based approach

        int front = 0;
        int balance = 0;   
        int deficet = 0;   

        for(int rear = 0 ; rear < n ; rear++){
            balance += (gas[rear] - cost[rear]);
            if(balance < 0){
                deficet += balance;
                front = rear + 1;
                balance = 0;
            }
        }

        if(balance + deficet >= 0){
            return front;
        }
        else{
            return -1;
        }
        return -1;
    }
};