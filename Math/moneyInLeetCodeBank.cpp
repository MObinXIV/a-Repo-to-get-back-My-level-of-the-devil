//https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/
int totalMoney(int n) 
    {
        int k =n/7;
        int f =28;// this fixed for the week
        int l = 28+(k-1)*7;// the last week value
        int arthSum = k*(f+l)/2;// the full weeks sum
        int monday=1+k;//this is the week which is not completed
        int finalWeek=0;
        for(int day=0;day<n%7;day++){
            finalWeek+=monday+day;
        }
        return arthSum+finalWeek;
    }