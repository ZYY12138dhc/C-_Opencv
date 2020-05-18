#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];

   // 以读模式打开文件
   ifstream infile; 
   infile.open("test.png"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 关闭打开的文件
   infile.close();
 
   return 0;
}
