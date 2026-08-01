class Solution {
public:
    bool iswin(vector<int>& nums, int i, int j, long long player1, long long player2, bool turn){
        if(i > j){
            return player1 >= player2;
        }
        if(turn){
            return( iswin(nums, i + 1, j, player1 + nums[i], player2, !turn) or iswin(nums, i, j - 1, player1 + nums[j], player2, !turn) );
        }
        else{
            return ( iswin(nums, i + 1, j, player1, player2 + nums[i], !turn) and iswin(nums, i, j - 1, player1, player2 + nums[j], !turn) );
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        long long player1 = 0, player2 = 0;
        int i = 0, j = nums.size() - 1;
        return iswin(nums, i, j, player1, player2, true);
    }
};