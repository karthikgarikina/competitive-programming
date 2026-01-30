class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0) return 0;
        int let1=towerOfHanoi(n-1,from,aux,to);
        int let2=towerOfHanoi(n-1,aux,from,to);
        return 1+let1+let2;
        
    }
};