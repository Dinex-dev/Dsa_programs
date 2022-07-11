#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int i,j,k=0,a[100][100],m,n,count=0;
  std::cout << "Enter the number of rows and columns: " ;
  std::cin >> m>>n;
  std::cout << "Enter the array elements: " << '\n';
  for (size_t i = 0; i <m; i++) {
    for (size_t j = 0; j<n;j++) {
        std::cin >> a[i][j];
        if (a[i][j]==0) {
          count=count+1;
        }
    }
  }
if (count>(m*n)/2) {
  std::cout << "This is a sparse matrix." << '\n';
}else{
  std::cout << "Not a sparse matrix." << '\n';
}
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      std::cout << a[i][j] << " ";
    }
    std::cout << '\n';
  }


  return 0;
}