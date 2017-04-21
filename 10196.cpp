#include<iostream>

int findCheck(char board[8][8], int i, int j){
	int k, l;
	switch(board[i][j]){
		case 'k':
		case 'K':
			return 0;

		case 'p':
			if( board[i+1][j-1]=='K' || board[i+1][j+1]=='K'){
				return 2;
			} else {
				return 0;
			}


		case 'P':
			if( board[i-1][j-1]=='k' || board[i-1][j+1]=='k'){
				return 1;
			} else {
				return 0;
			}


		case 'n':
			if( board[i-1][j-2]=='K' || board[i-1][j+2]=='K' || board[i-2][j-1]=='K' || board[i-2][j+1]=='K' || board[i+1][j-2]=='K' || board[i+1][j+2]=='K' || board[i+2][j-1]=='K' || board[i+2][j+1]=='K'){
				return 2;
			} else {
				return 0;
			}

		case 'N':
			if( board[i-1][j-2]=='k' || board[i-1][j+2]=='k' || board[i-2][j-1]=='k' || board[i-2][j+1]=='k' || board[i+1][j-2]=='k' || board[i+1][j+2]=='k' || board[i+2][j-1]=='k' || board[i+2][j+1]=='k'){
				return 1;
			} else {
				return 0;
			}
		case 'q':
		case 'r':
			for(k=j-1; k>=0; k--){
				if(board[i][k]=='K'){
					return 2;
				}
				if(board[i][k]!='.'){
					break;
				}
			}
			for(k=j+1; k<8; k++){
				if(board[i][k]=='K'){
					return 2;
				}
				if(board[i][k]!='.'){
					break;
				}
			}
			for(k=i-1; k>=0; k--){
				if(board[k][j]=='K'){
					return 2;
				}
				if(board[k][j]!='.'){
					break;
				}
			}
			for(k=i+1; k<8; k++){
				if(board[k][j]=='K'){
					return 2;
				}
				if(board[k][j]!='.'){
					break;
				}
			}
			
			//if is a tower and didnt find check return 0. if is a queen dont.
			if(board[i][j]=='r'){
				return 0;
			}
			//look in the cross until the limit o a piece
		case 'b':
			for(k=i-1, l=j-1; k>=0 && l>=0; k--, l--){
				if(board[k][l]=='K'){
					return 2;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i-1, l=j+1; k>=0 && l<8; k--, l++){
				if(board[k][l]=='K'){
					return 2;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i+1, l=j-1; k<8 && l>=0; k++, l--){
				if(board[k][l]=='K'){
					return 2;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i+1, l=j+1; k<8 && l<8; k++, l++){
				if(board[k][l]=='K'){
					return 2;
				}
				if(board[k][l]!='.'){
					break;
				}
			}

			return 0;


		case 'Q':
		case 'R':
			for(k=j-1; k>=0; k--){
				if(board[i][k]=='k'){
					return 1;
				}
				if(board[i][k]!='.'){
					break;
				}
			}
			for(k=j+1; k<8; k++){
				if(board[i][k]=='k'){
					return 1;
				}
				if(board[i][k]!='.'){
					break;
				}
			}
			for(k=i-1; k>=0; k--){
				if(board[k][j]=='k'){
					return 1;
				}
				if(board[k][j]!='.'){
					break;
				}
			}
			for(k=i+1; k<8; k++){
				if(board[k][j]=='k'){
					return 1;
				}
				if(board[k][j]!='.'){
					break;
				}
			}
			
			//if is a tower and didnt find check return 0. if is a queen dont.
			if(board[i][j]=='R'){
				return 0;
			}
			//look in the cross until the limit o a piece
		case 'B':
			for(k=i-1, l=j-1; k>=0 && l>=0; k--, l--){
				if(board[k][l]=='k'){
					return 1;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i-1, l=j+1; k>=0 && l<8; k--, l++){
				if(board[k][l]=='k'){
					return 1;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i+1, l=j-1; k<8 && l>=0; k++, l--){
				if(board[k][l]=='k'){
					return 1;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			for(k=i+1, l=j+1; k<8 && l<8; k++, l++){
				if(board[k][l]=='k'){
					return 1;
				}
				if(board[k][l]!='.'){
					break;
				}
			}
			return 0;

	}
}

int main(){
	bool find = true;
	int check; //0 -> no check, 1 -> black in check & 2 -> white in check
	int nGame = 1; 
	char board[8][8];
	while(find){
		find = false;

		//Collect the board
		for(int i = 0; i<8; i++){
			for(int j=0; j<8; j++){
				std::cin >> board[i][j];
			}
		}
		
		check=0;
		//Walk the board looking for a check
		for(int i = 0; i<8 && check==0; i++){
			for(int j=0; j<8 && check==0; j++){
				if(board[i][j]!='.'){
					find = true;
					check = findCheck(board, i, j);

				}
			}
		}

		//Print the result
		if(find){
			switch(check){
				case 0:
					std::cout << "Game #" << nGame << ": no king is in check.\n";
					break;
				case 1:
					std::cout << "Game #" << nGame << ": black king is in check.\n";
					break;
				case 2:
					std::cout << "Game #" << nGame << ": white king is in check.\n";
					break;
			}
		}
		nGame++;
	}
	return 0;
}
//con una gorra de helice y chanclas
//CHANCLAS
