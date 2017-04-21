#include<iostream>
#include<cmath>
#include<cstring>
#include<string>

void printNumber(int size, char number, int row){
	int i;
	if(row==0){
		if(number=='1' || number=='4'){
			for(i=0;i<size+2;i++){
				std::cout << " ";
			}
		} else {
			std::cout << " ";
			for(i=0;i<size;i++){
				std::cout << "-";
			}
			std::cout << " ";
		}
	}
	if(row>0 && row<size+1){
		if(number=='5' || number=='6'){
			std::cout << "|";
			for(i=0;i<size+1;i++){
				std::cout << " ";
			}
		} else{
			if(number=='1' || number=='2' || number=='3' || number=='7'){
				for(i=0;i<size+1;i++){
					std::cout << " ";
				}
				std::cout << "|";
			} else {
				std::cout << "|";
				for(i=0;i<size;i++){
					std::cout << " ";
				}
				std::cout << "|";
			}
		}
	}
	if(row==size+1){
		if(number=='1' || number=='7' || number=='0'){
			for(i=0;i<size+2;i++){
				std::cout << " ";
			}
		} else {
			std::cout << " ";
			for(i=0;i<size;i++){
				std::cout << "-";
			}
			std::cout << " ";
		}
	}
	if(row>size+1 && row<(2*size)+2){
		if(number=='2'){
			std::cout << "|";
			for(i=0;i<size+1;i++){
				std::cout << " ";
			}
		} else{
			if(number=='1' || number=='3' || number=='4' || number=='5' || number=='7' || number=='9'){
				for(i=0;i<size+1;i++){
					std::cout << " ";
				}
				std::cout << "|";
			} else {
				std::cout << "|";
				for(i=0;i<size;i++){
					std::cout << " ";
				}
				std::cout << "|";
			}
		}
	}
	if(row==(2*size)+2){
		if(number=='1' || number=='4' || number=='7'){
			for(i=0;i<size+2;i++){
				std::cout << " ";
			}
		} else {
			std::cout << " ";
			for(i=0;i<size;i++){
				std::cout << "-";
			}
			std::cout << " ";
		}
	}
}


int main(){
	int size, digits, i, j;
	std::string number;
	std::cin >> size >> number;

	while(size!=0 || number.compare("0")!=0){
		digits = number.length();

		for(i=0; i<(size*2)+3; i++){
			for(j=0; j<digits-1; j++){
				printNumber(size, number.at(j),i);
				std::cout << " ";
			}
			printNumber(size,number.at(digits-1),i);
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cin >> size >> number;
	}
	return 0;
}
