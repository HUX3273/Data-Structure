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
	S.str = " ccbaaacabaababccabacabca";	// ע��str[0]ȫ�����Ͽ��ַ�
	S.length = S.str.length() - 1;

	SString T;
	T.str = " ababc";	// ע��str[0]ȫ�����Ͽ��ַ�
	T.length = T.str.length() - 1;

	int next[T.length+1];

	getNext(next,T); // ���next����

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


// ���Ĳ��ԣ� 
// �� 6 λƥ�����
// ֻ֪��ǰ 5 λ��Ϣ
// abaab���Ҵ�λƥ����next:
// abaab
//    abaab
// �����λƥ��������ƥ�� 2 �� ���� ab�� 
// next = 2+1 = 3

// �� 5 λƥ�����
// ֻ֪��ǰ 4 λ��Ϣ
// abaa���Ҵ�λƥ����next:
// abaa
//    abaa
// �����λƥ��������ƥ�� 1 �� ���� a�� 
// next = 1+1 = 2

// �� 4 λƥ�����
// ֻ֪��ǰ 3 λ��Ϣ
// aba���Ҵ�λƥ����next:
// aba
//   aba
// �����λƥ��������ƥ�� 1 �� ���� a�� 
// next = 1+1 = 2

// �� 3 λƥ�����
// ֻ֪��ǰ 2 λ��Ϣ
// ab���Ҵ�λƥ����next:
// ab
//   ab
// �����λƥ��������ƥ�� 0 �� ���� �� 
// next = 0+1 = 1

// �� 2 λƥ�����next��Ϊ1
// ֻ֪��ǰ 1 λ��Ϣ
// a���Ҵ�λƥ����next:
// a
//  a
// �����λƥ��������ƥ�� 0 �� ���� �� 
// next = 0+1 = 1����Ϊ1��

// �� 1 λƥ�����next��Ϊ0
// ֻ֪��ǰ 0 λ��Ϣ
// NULL ���Ҵ�λƥ����next
// �����λƥ��������ƥ�� -1 �� ���� �� 
// next = -1+1 = 0����Ϊ0��

