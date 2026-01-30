#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
	
	srand(time(NULL));
	cout<<"GIOCO DEL MEMORY!!";
	
	//generare casualmente la dimensione della matrice
	int dim_tabella=rand()%3+4;
	//matrice quadrata di caratteri 
	//metto la grandezza al massimo e utilizzo solo quelle che mi servono
	char caselle[7][7];
	//genero dei caratteri casuali e in base al numero corrispondente al codice ascii viene generata la lettera
	char caratteri_casuali=rand()%25+65;
	
	//azzero array
	for(int i=0; i<dim_tabella; i++){
		
		for(int j=0; j<dim_tabella; j++){
			
			caselle[i][j]=0;	
		}
	}
	//genero caselle
	cout<<"\ncaselle: "<<endl<<endl;
	for(int i=0; i<dim_tabella; i++){
		
		for(int j=0; j<dim_tabella; j++){
			
			//genero lettere casuali e le inserisco nella matrice
			caratteri_casuali=rand()%25+65;
			caselle[i][j]=caratteri_casuali;
			cout<<caselle[i][j]<<"    ";	
		}
		//va a capo ogni volta che fnisce la riga
		if(i/dim_tabella==0){
			cout<<endl<<endl;
		}
	}

	return 0;
}
