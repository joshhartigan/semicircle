#include <stdio.h>
#include <unistd.h>

int main() {
  
  int uid_t = geteuid();
  
  if (uid_t > 0) {
    printf("You're not using sudo!\n");
  } else {
    printf("You're using sudo!\n");
  }
  
}
