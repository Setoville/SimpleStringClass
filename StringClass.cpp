#include "StringClass.h"
#include <iostream>
using namespace std;




myStr::myStr(){
	strLen = 0;
	data = new char [1];
	data[0]=0;
	dataLen=1;
}
myStr::myStr(const myStr& copyMe){
	dataLen = copyMe.dataLen;
	strLen = copyMe.strLen;
	data = new char[dataLen];
	for(int r=0;r<dataLen;r++){
		data[r]=copyMe.data[r];
	}

}
myStr::myStr(const char* copyMe){
	int length = 0;
	while(copyMe[length] != 0){
		length++;
	}
	strLen=length;
	dataLen = length+1;
	
	data = new char [dataLen];
	for(int r=0;r<dataLen;r++){
		data[r]=copyMe[r];
	}
}

int myStr::length() const{
	return strLen;
}
int myStr::strCmp(const myStr& compareMe) const{ //not a strng

	return strCmp(compareMe.data);

}
int myStr::strCmp(const char* compareMe) const{//the strng one
	int r=0;
	//str1 is now data
	if (compareMe[0]=='\0') {
		
		return -1;
	}
	while (data[r]!=0 && compareMe[r]!=0){ //if they the same content


		
		if (tolower(data[r])<tolower(compareMe[r])){
			return 1;
		}
		else if (tolower(data[r])>tolower(compareMe[r])){
			return -1;
		}
		r++;
	}
  if (data[r]) {
    return -1;
  } 
  else if (compareMe[r]) {
    return 1;
  }
  else return 0;


}
bool myStr::strCpy(const myStr& copyMe){
	dataLen = copyMe.dataLen;
	strLen=copyMe.strLen;
	data = new char [strLen+1];
	int r=0;
	while (copyMe.data[r]!=0){
		data[r]=copyMe.data[r];
	}
	data[r]=0;
	return true;


}
bool myStr::strCpy(const char* copyMe){
	int sizeOfcopyMe=0;
	while (copyMe[sizeOfcopyMe]!=0){
		sizeOfcopyMe++;
	}
	data = new char [sizeOfcopyMe+1]; //dynamic memory allocate
	strLen = sizeOfcopyMe;
	dataLen = sizeOfcopyMe+1;

	int r=0;
	for (int b=0;b<sizeOfcopyMe;b++){
		data[r]=copyMe[r];
		r++;
	}

	return true;

}
int myStr::subStr(const char* findMe) const{
	int startingAt=0;
	int ctr=0;
	while (findMe[ctr]!='\0'){
		ctr++;
	}
	if (ctr > strLen){
		return -1;
	}
	else{
		for(int r=startingAt;r<strLen;r++){
			if (findMe[0]==data[r]){
			int ctr1=0;
			for(int c=0;c<ctr;c++){
				if(findMe[c] == data[c+r]){
					ctr1++;
				}
			}
			if (ctr1==ctr){
				return r;
				}
			}
		}
	}
	return -1;

}
int myStr::subStr(const myStr& findMe) const{
	return subStr(findMe.data); //pass it the same thing
}
int myStr::subStr(const char* findMe, int startingAt) const{
	int ctr=0;
	while (findMe[ctr]!='\0'){
		ctr++;
	}
	if (ctr > strLen){
		return -1;
	}
	else{
		for(int r=startingAt;r<strLen;r++){
			if (findMe[0]==data[r]){
			int ctr1=0;
			for(int c=0;c<ctr;c++){
				if(findMe[c] == data[c+r]){
					ctr1++;
				}
			}
			if (ctr1==ctr){
				return r;
				}
			}
		}
	}
	return -1;

}
int myStr::subStr(const myStr& findMe, int startingAt) const{
	return subStr(findMe.data, startingAt);//pass it the same thing
}
char myStr::at(const unsigned int index) const{
	if(index > strLen){
		return 0;
	}
	if (index < 0){
		return 0;
		
	}
	return data[index];
}
myStr::~myStr() {
	strLen = -1;
	dataLen = -1;
	delete[] data;
}