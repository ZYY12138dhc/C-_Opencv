#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];

   // �Զ�ģʽ���ļ�
   ifstream infile; 
   infile.open("test.png"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // �رմ򿪵��ļ�
   infile.close();
 
   return 0;
}
