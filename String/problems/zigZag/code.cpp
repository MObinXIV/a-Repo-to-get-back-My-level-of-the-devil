/**
 *Let's mimic the zigzag movements
 * yeah go down till U out of bound 
 * then up
 * vise versa 
 * boil the matrix inside the returned string 
 */
string convert(string s, int numRows) {
       if(numRows==1) return s;
       vector<string>rows(min( int(s.size()),numRows));
       int curRow=0;
       bool goDown = false;

       // let's construct the matrix
       for(auto ch:s)
       {
         rows[curRow]+=ch;
         if(curRow==0 || curRow==numRows-1) goDown = !goDown;

         curRow+= goDown ?1 : -1;
       } 
       string res ;
       for(string row:rows) res+=row;

      return res;
    }