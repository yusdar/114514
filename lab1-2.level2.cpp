#include<iostream>
#include<string>
#include<fstream>
#include<vector>
//#include<>
using namespace std;
 
string Keyword[32]=
{
    "auto","break","case","char","const","continue","default","double",
    "do","else","enum","extern","float","for","goto","if","int","long",
    "register","return","short","signed","sizeof","static","struct",
    "switch","typedef","union","unsigned","void","volatile","while"
};

struct KeywordnNum{
	string name;
	int num;
};

int keywordnum=0;
vector<int> switchcase;
int main(){
	string fileaddress;
	string filecontent;
	string testcontent;
	vector<string> realvocabulary;
	
	cout <<"Enter file address:";
	cin >>fileaddress;
	ifstream file;
	file.open(fileaddress);
	while(getline(file,testcontent)){
		filecontent+=testcontent;
		
		
	}
	int j=0;
	//cout <<filecontent;
	for (int i=0;i<filecontent.length();i++){
		j=0;
		while (filecontent[i+j]<='z' && filecontent[i+j]>='a'){
			//cout<<filecontent[i+j]<<endl;	
			j++;
		}
		if (j!=0){
			realvocabulary.push_back(filecontent.substr(i,j));
			//cout<<filecontent.substr(i,j)<<endl;
			i+=j;
		}
	}
	for (int i=0;i<realvocabulary.size();i++) {
		for (j=0;j<32;j++){
			if (realvocabulary[i]==Keyword[j]){
				keywordnum++;
				break;
			}
		}
		if (realvocabulary[i]=="switch"){
			switchcase.push_back(0);
		}
		else if (realvocabulary[i]=="case"){
			switchcase[switchcase.size()-1]++;
		}	
	}
	cout<<"total num:"<<keywordnum<<endl;
	cout<<"switch num:"<<switchcase.size()<<endl;
	cout<<"case num:";
	for (j=0;j<switchcase.size();j++){
		cout<<switchcase[j]<<' ';
	}
	cout<<endl;
}

