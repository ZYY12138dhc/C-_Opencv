#include <fstream> // ifstream, ifstream::in
#include<iostream>

using namespace std;

int main(){
	// 1. ��ͼƬ�ļ�
	ifstream is("test.png", ifstream::in);
	// 2. ����ͼƬ����
	is.seekg(0, is.end);
	int length = is.tellg();
	is.seekg(0, is.beg);
	// 3. �����ڴ滺����
	char * buffer = new char[length];
	// 4. ��ȡͼƬ
	cout << "Reading " << length << " characters... ";
	is.read(buffer, length);
	//cout.write (buffer,length);
	// ���ˣ�ͼƬ�Ѿ��ɹ��ı���ȡ���ڴ棨buffer����
	
	delete [] buffer;
	return 0;
}

