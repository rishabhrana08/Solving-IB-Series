int Solution::uniquePaths(int A, int B)
{
if(A==B && A==1){
return 1;
}
if(A==1 || B==1){
return 1;
}
return uniquePaths(A-1,B)+uniquePaths(A,B-1);
}

