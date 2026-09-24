class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Pair up each car's position with its speed, then sort by position
        // in descending order (car closest to target first). Sorting
        // descending removes ambiguity: once we know a car's own arrival
        // time, we can immediately compare it against the fleet ahead
        // without worrying about that fleet's time changing later.
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first; // descending by position
        });

        // Stack holds the arrival "time to target" of each distinct fleet
        // formed so far, from front-most fleet to back-most fleet.
        // The top of the stack is always the most recently processed
        // (i.e., currently closest-behind) fleet's time.
        stack<double> st;

        for (int i = 0; i < n; i++) {
            int pos = cars[i].first;
            int spd = cars[i].second;

            // Time this car would take to reach target if it never
            // catches up to anyone ahead of it.
            double time = (double)(target - pos) / spd;

            // If this car's time is greater than the time of the fleet
            // immediately ahead (top of stack), it CANNOT catch up in
            // time — it arrives later, so it forms its own new fleet.
            // Push its own time as a new fleet marker.
            //
            // If this car's time is <= the fleet ahead's time, it means
            // this car is faster (or equal) and will catch up to that
            // fleet before/at the target, merging into it. In that case
            // we do NOT push a new time — this car simply adopts the
            // existing fleet's time, so the stack stays unchanged.
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // else: car merges into the fleet ahead, no new fleet formed
        }

        // Each entry remaining in the stack represents one distinct fleet
        // that reaches the destination.
        return st.size();
    }
};