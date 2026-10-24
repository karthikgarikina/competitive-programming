class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
        vector<int>days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < 12; i++) days[i] += days[i - 1];

        int ali_st = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0') - 1;
        if(ali_st > 0) ali_st = days[ali_st - 1];
        ali_st += (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');

        int bob_st = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0') - 1;
        if(bob_st > 0) bob_st = days[bob_st - 1];
        bob_st += (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');

        int start = max(ali_st, bob_st);

        int ali_ed = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0') - 1;
        if(ali_ed > 0) ali_ed = days[ali_ed - 1];
        ali_ed += (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

        int bob_ed = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0') - 1;
        if(bob_ed > 0) bob_ed = days[bob_ed - 1];
        bob_ed += (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

        int end = min(ali_ed, bob_ed);
        
        int ans = end - start + 1;
        return (ans > 0) ? ans : 0;
    }
};