class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx == tx && sy == ty){
            return true;
        }
        else if(sx > tx || sy > ty) {
            return false;
        }
        else{
            return reachingPoints(sx + sy, sy, tx, ty) || reachingPoints(sx, sy + sx, tx, ty);
        }
    }
};