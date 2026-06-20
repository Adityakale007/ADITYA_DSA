class Solution {
public:
    double angleClock(int hour, int minutes) {
        //for this we need to find how much the hour hand mive every minute
        // In 12 hours = 360°
        // In 1 hour = 360° ÷ 12 = 30°
        // In 1 minute = 30° ÷ 60 = 0.5°
        // The hour hand moves 0.5° (half a degree) every minute.
        hour %= 12;

        // Hour hand angle moved = 0.5 × minutes passed
        double hourHand = (hour * 10 * 3) + (0.5 * minutes);
        double minuteHand = (6 * minutes);

        double diff = abs(hourHand - minuteHand);
        return min(diff, 360 - diff);
    }
};