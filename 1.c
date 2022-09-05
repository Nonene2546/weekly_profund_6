#include<stdio.h>

/*
0 -> 1,2

1 -> 3,4
2 -> 4,5

3 -> 6,7
4 -> 7,8
5 -> 8,9

6 -> 10,11
*/
int mk(int a, int b){
  if(a>b) return a;
  return b;
}

int arr[1000],ans[1000];

int main(){
  int n;
  scanf("%d",&n);
  int line = 1;
  int cnt = 1;
  int idx = 1;
  for(int i=0;i<n;++i){
    scanf("%d",&arr[i]);
  }
  ans[0] = arr[0];
  for(int i=0;i<n;++i){
    if(idx+1>=n) break;
    ans[idx] = mk(ans[idx], arr[idx] + ans[i]);
    ans[idx+1] = mk(ans[idx+1], arr[idx+1] + ans[i]);
    if(i+1 == line*(line+1)/2){
      ++line;
      ++idx;
    }
    ++idx;
  }
  int mx = -9999;
  for(int i=0;i<n;++i){
    if(mx<ans[i])
      mx = ans[i];
  }
  printf("\n%d",mx);
}