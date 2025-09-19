class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet=vector<vector<int>>(26,vector<int>(rows+1,0));
    }
    
    void setCell(string cell, int value) {
        int row=cell[0]-'A';
        cell.erase(0,1);
        int col=stoi(cell);
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        int row=cell[0]-'A';
        cell.erase(0,1);
        int col=stoi(cell);
        sheet[row][col]=0;
    }
    
    int getValue(string formula) {
       formula.erase(0,1);
       stringstream ss(formula);
       char sep='+';
       string a,b;
       getline(ss,a,sep);
       getline(ss,b,sep);
       int one=0,two=0,row,col;
       if(a[0]>='A' and a[0]<='Z'){
          row=(a[0]-'A');
          a.erase(0,1);
          col=stoi(a);
          one=sheet[row][col];
       }
       else{
          one=stoi(a);
       }
       if(b[0]>='A' and b[0]<='Z'){
          row=(b[0]-'A');
          b.erase(0,1);
          col=stoi(b);
          
          two=sheet[row][col];
       }
       else{
          two=stoi(b);
       }
       return one+two;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */