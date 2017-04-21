#include<iostream>
#include<vector>

std::vector< std::vector<int> > grafo;
std::vector< int > nodos; //info

std::vector<bool> visitado;

//CONSTRUCCION GRAFO --------------------------------------------

void addNodo(int nodo){ //info
	std::vector<int> aristas;
	grafo.push_back(aristas);

	nodos.push_back(0);
}

void addArista(int origen, int destino){
	grafo[origen].push_back(destino);
}

//RECORRIDOS GRAFOS--------------------------------------------------------


void profRec(int nodo, int valor){
	visitado[nodo]=true;

	//chimichanga
	nodos[nodo] = valor;
	valor++;

	for(int i = 0; i<grafo[nodo].size(); i++){
		if(!visitado[ grafo[nodo][i] ]){
			profRec( grafo[nodo][i], valor );
		}
	}
}

void profundidad(int inicio){
	visitado = std::vector<bool> (grafo.size(), false);
	//inicializar variables GLOBALES del metodo
	
	profRec(inicio, 0);
}
//---------------------------------------------------------------

int main(){
	int numNodos, aristas, ini, fin;
	bool pint;

	std::cin >> numNodos;
	while(numNodos!=0){
		//paricular
		grafo.clear();
		nodos.clear();
		
		for(int i = 0; i<numNodos; i++){
			addNodo(i);
		}

		std::cin >> aristas;
		for(int j = 0; j<aristas; j++){
			std::cin >> ini >> fin;

			addArista(ini,fin);
			addArista(fin,ini);
		}
		
		profundidad(0);
		
		pint = true;
		for(ini = 0; ini<grafo.size() && pint; ini++){
			for(int j = 0; j<grafo[ini].size() && pint; j++){
				fin = grafo[ini][j];
				if((nodos[fin]+nodos[ini])%2 == 0){
					pint = false;
				}
			}
		}
		if(pint){
			std::cout << "BICOLORABLE.\n";
		} else {
			std::cout << "NOT BICOLORABLE.\n";
		}

		std::cin >> numNodos;
	}
}
