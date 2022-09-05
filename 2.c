#include<stdio.h>

struct node{
  int value;
  int next1, next2;
};

struct node arr[100];
int ans;

int findans(int i, int sum){
  if(i==0&&sum!=0){
    if(ans<sum)
      ans = sum;
    return 0;
  }
  sum += arr[i].value;
  findans(arr[i].next1, sum);
  findans(arr[i].next2, sum);
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    scanf("%d",&arr[i].value);
  }
  int idx = 1, line = 1;
  for(int i=0;i<n;++i){
    if(idx+1>=n) break;
    arr[i].next1 = idx;
    arr[i].next2 = idx+1;
    if(i+1 == line*(line+1)/2){
      ++line;
      ++idx;
    }
    ++idx;
  }
  findans(0, 0);
  printf("%d",ans);
}