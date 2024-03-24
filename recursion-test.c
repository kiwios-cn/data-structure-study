#include <stdio.h>
int func(int n){
  if(n == 0) {
    return 0;
  } else   {
    return func(n-1)+n;
  }
}




int main() {

  printf("%d\n",func(100));
  return 0;  
}
