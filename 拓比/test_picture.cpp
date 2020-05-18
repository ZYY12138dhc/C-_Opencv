#include <fstream> // ifstream, ifstream::in
#include<iostream>

using namespace std;

int main(){
	// 1. 打开图片文件
	ifstream is("test.png", ifstream::in);
	// 2. 计算图片长度
	is.seekg(0, is.end);
	int length = is.tellg();
	is.seekg(0, is.beg);
	// 3. 创建内存缓存区
	char * buffer = new char[length];
	// 4. 读取图片
	cout << "Reading " << length << " characters... ";
	is.read(buffer, length);
	//cout.write (buffer,length);
	// 到此，图片已经成功的被读取到内存（buffer）中
	
	delete [] buffer;
	return 0;
}

