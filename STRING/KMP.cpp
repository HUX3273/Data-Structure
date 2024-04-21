#include <cstdio>
#include <cstring>
#include <iostream>


typedef struct {
	std::string str;
	std::size_t length;
} SString;


int selfMatch(std::string tempStr) {
	int len = tempStr.length();
	std::cout<<"length:"<<len<<" ";
	std::cout<<"selfMatch: ";
	for(int i=1; i<=len; i++) {
		std::string str1 = tempStr.substr(i,len);
		std::cout<<"("<<str1<<":";
		std::string str2 = tempStr.substr(0,len-i);
		std::cout<<str2<<")"<<" ";

		if(str1.compare(str2) == 0) {
			std::cout<<"match succeed!"<<std::endl;
			return len-i+1;
		}
	}
	if(len == 0) {
		std::cout<<"nothing matched!"<<std::endl;
		return 0;
	}

	std::cout<<"match failed!"<<std::endl;

	return -1;
}

void getNext(int next[],SString T) {
	next[0] = 3273;
	for(int i = 1; i <= T.length ; i++ ) {
		std::string tempStr = T.str.substr(1,i-1);
		std::cout<<"getNext: "<<tempStr<<" ";
		next[i] = selfMatch(tempStr);

	}

	std::cout<<std::endl;
	return;
}


int KMP(int next[],SString S,SString T) {
	int len_s = S.length;
	int len_t = T.length;

	int i = 1;
	int j = 1;

	while(i<len_s+1) {
		if(S.str[i]==T.str[j]) {
			i++;
			j++;
		} else {
			j=next[j];
		}

		if(j>=len_t+1) {
			return i-j+1;
		} else if(j==0) {
			i++;
			j++;
		}
	}

	return -1;

}



int main() {
	SString S;
	S.str = " ccbaaacabaababccabacabca";	// 注意str[0]全部填上空字符
	S.length = S.str.length() - 1;

	SString T;
	T.str = " ababc";	// 注意str[0]全部填上空字符
	T.length = T.str.length() - 1;

	int next[T.length+1];

	getNext(next,T); // 算出next数组

	std::cout<<"NEXT output:";
	for(int i=1; i<T.length+1; i++) {
		std::cout<<next[i]<<' ';
	}
	std::cout<<std::endl;
	int resultIndex =  KMP(next,S,T);

	std::cout<<std::endl<<"KMP output:"<<resultIndex<<std::endl;

	if(resultIndex>0) {
		std::cout<<std::endl<<"T:"<<T.str.substr(1,T.length)<<std::endl;
		std::cout<<std::endl<<"S:"<<S.str.substr(1,resultIndex-1)<<"["<<S.str.substr(resultIndex,T.length)<<"]"<<S.str.substr(resultIndex+T.length,S.length-T.length-resultIndex+1)<<std::endl;
	} else {
		std::cout<<std::endl<<"ERROR: T doesn't exist in S!"<<std::endl;
	}

	return 0;
}


// 核心策略： 
// 第 6 位匹配出错
// 只知道前 5 位信息
// abaab自我错位匹配求next:
// abaab
//    abaab
// 自身错位匹配最多可以匹配 2 个 （即 ab） 
// next = 2+1 = 3

// 第 5 位匹配出错
// 只知道前 4 位信息
// abaa自我错位匹配求next:
// abaa
//    abaa
// 自身错位匹配最多可以匹配 1 个 （即 a） 
// next = 1+1 = 2

// 第 4 位匹配出错
// 只知道前 3 位信息
// aba自我错位匹配求next:
// aba
//   aba
// 自身错位匹配最多可以匹配 1 个 （即 a） 
// next = 1+1 = 2

// 第 3 位匹配出错
// 只知道前 2 位信息
// ab自我错位匹配求next:
// ab
//   ab
// 自身错位匹配最多可以匹配 0 个 （即 ） 
// next = 0+1 = 1

// 第 2 位匹配出错，next必为1
// 只知道前 1 位信息
// a自我错位匹配求next:
// a
//  a
// 自身错位匹配最多可以匹配 0 个 （即 ） 
// next = 0+1 = 1（必为1）

// 第 1 位匹配出错，next必为0
// 只知道前 0 位信息
// NULL 自我错位匹配求next
// 自身错位匹配最多可以匹配 -1 个 （即 ） 
// next = -1+1 = 0（必为0）

