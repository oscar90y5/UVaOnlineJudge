#include<iostream>
#include<string>
#include<algorithm>

int main(){
	std::string a, b, x;
	while(std::getline(std::cin,a)){
		std::getline(std::cin,b);
		x = "";
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < b.size(); j++){
				if(a[i]==b[j]){
					x+=a[i];
					b[j]='*';
					break;
				}
			}
		}
		std::sort(x.begin(),x.end());
		std::cout << x << "\n";
	}
}
