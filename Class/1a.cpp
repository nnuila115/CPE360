#include <iostream>
#include <cstring>
using namespace std;

void function(char *str) {

  char buffer[16];

  strcpy(buffer,str);

}

int main() {

  char large_string[256];

  int i;

  for( i = 0; i < 255; i++){

    large_string[i] = 'A';
    cout << large_string[i] << endl;
  }
  function(large_string);
  cout << large_string;
}
