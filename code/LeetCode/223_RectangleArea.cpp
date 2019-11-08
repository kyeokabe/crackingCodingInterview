class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        long rec1_area=(C-A)*(D-B);
        long rec2_area=(G-E)*(H-F);
        
        long I=max(A,E);
        long J=min(C,G);
        long overlap_x_length=J-I;
        
        if(overlap_x_length<=0)
            return int(rec1_area+rec2_area);
        
        long L=max(B,F);
        long M=min(D,H);
        long overlap_y_length=M-L;
        
        if(overlap_y_length<=0)
            return int(rec1_area+rec2_area);
        
        long overlap_area=overlap_x_length*overlap_y_length;
        
        return int(-overlap_area+rec1_area+rec2_area);
    }
};
