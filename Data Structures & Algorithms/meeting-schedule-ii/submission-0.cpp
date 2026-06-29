/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<pair<int,int>>diff;

        for(auto interval : intervals) {

            int L = interval.start;
            int R = interval.end;

            diff.push_back({L,1});
            diff.push_back({R,-1});

        }

        sort(diff.begin(),diff.end());

        int max_rooms = 0;

        int c_r_count = 0;

        for(auto d : diff) {

            c_r_count += d.second;

            max_rooms = max(max_rooms,c_r_count);
        }
        return max_rooms;
    }
};
