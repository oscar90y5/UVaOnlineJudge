#include<iostream>
#include<cmath>


int main(){
	int n, i;
	long long abso;
	bool jolly;
	while(std::cin >> n){
		if(n==1){
			std::cin >> n;
			std::cout << "Jolly\n";
		} else {
			long long vector[n]; //input vector
			bool comp[n-1];
			jolly = true;

			//Inicialize vector
			for(i = 0; i < n; i++){
				std::cin >> vector[i];
			}

			//Inicializa comp
			for(i = 0; i < n-1; i++){
				comp[i] = false;
			}

			for(i = 0; i < n-1; i++){
				abso = std::abs(vector[i]-vector[i+1]);
				if(abso<n){
					comp[abso-1]=true;
				}
			}

			for(i = 0; i < n-1; i++){
				if(!comp[i]){
					jolly=false;
					break;
				}
			}

			if(jolly){
				std::cout << "Jolly\n"; 
			} else {
				std::cout << "Not jolly\n"; 
			}
		}
	}
	return 0;
}
