#include <iostream>
#define INF 0x3f3f3f3f
#define MAX_VERTICES 5
using namespace std;
 
int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 8, INF, INF},
        {4, 0, 1, 2, INF},
        {8, INF, 0, 4, 2},
        {INF, 2, 4, 0, 7},
        {INF, INF, 2, 7, 0}
};
 
int P[MAX_VERTICES][MAX_VERTICES]; //Matriz de recorridos, utilizada para trazar las rutas
int D[MAX_VERTICES][MAX_VERTICES]; //Matriz de distancias, guarda la distancia mas corta entre todos los pares de vertices
 
string aLetra(int b){
if(b==0){
return "A";
}else if(b==1){
return "B";
}else if(b==2){
return "C";
}else if(b==3){
return "D";
}else if(b==4){
return "E";
}else{
return "";
}
}
 
void getPath(int a,int b){
    if(P[a][b]==b){
        cout << aLetra(b) << " ";
        return;
    }
    getPath(a,P[a][b]);
    cout << aLetra(b) << " ";
}
 
void printSolution(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << "De " << aLetra(i) << " a " << aLetra(j) << " : ";
            if(D[i][j] == INF){
                cout << "-" << endl;
                continue;
            }
            else{
                cout << D[i][j] << endl;
                getPath(i,j);
                cout << endl;
            }
        }
        cout << endl;
    }
}
void floydWarshall(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            D[i][j] = graph[i][j];
            P[i][j] = i;
        }
    }
    //Programacion Dinamica
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
    printSolution();
}
 
void imprimirMatriz(int matriz[][5]){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(matriz[i][j] == INF){
				cout << "I" << " ";
			}else{
				cout << matriz[i][j]<< " ";
			}
		}
		cout << "\n";
	}	
}
 
int main(){
	cout << "Matriz grafo de entrada:\n\n";
	imprimirMatriz(graph);
	cout << "\n\nResultado implementacion del algoritmo de Floyd-Warshall:\n\n";
    floydWarshall();
    cout << "Matriz de distancias:\n\n";
    imprimirMatriz(D);
    return 0;
}

