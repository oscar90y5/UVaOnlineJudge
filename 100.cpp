#include <iostream>
#include<cstring>
#include<cstdlib>

int main() {
	
	int inA, inB, num, count, maxCount, aux;

	while(std::cin >> inA >> inB){
		
		maxCount = 1;
		std::cout << inA << " " << inB << " ";

		if(inA>inB){
			aux = inA;
			inA = inB;
			inB = aux;
		}

		for(int i = inA; i <= inB; i++){
			num = i;
			count = 1;
			while(num!=1){
				if(num%2==0){
					num = num/2;
				} else {
					num = 3*num+1;
				}
				count++;
			}
			
			if(count>maxCount){
				maxCount=count;
			}
		}
		std::cout << maxCount << "\n";
	}

	return 0;

}
