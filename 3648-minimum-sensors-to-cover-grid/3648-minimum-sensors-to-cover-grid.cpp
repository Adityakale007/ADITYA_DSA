class Solution {
public:
    int minSensors(int n, int m, int k) {
        int blockSensor = 2 * k + 1;
        
        int SensorRows = (int)ceil((double)n/blockSensor); //ceil()
        
        int SensorColumns = (int)ceil((double)m/blockSensor); //ceil()

        return SensorRows*SensorColumns;
    }
};