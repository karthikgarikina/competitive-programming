class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        move,neutral=0,0
        for ch in moves:
            if ch=='L':
                move-=1
            elif ch=='R':
                move+=1
            else:
                neutral+=1
                
        return neutral+abs(move)                
        