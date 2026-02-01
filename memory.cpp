#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//funzione che genera le coppie
void genera_coppie(char carte[], int d){
	
	//variabile che mi serve per inserire le lettere nell'array
	int conta_carte=0;
	//tengo traccia delle lettere che uso
	int lettere_usate[26]={0};
	
	for(int i=0; i<d; i++){
		
		//genera lettere casuali
		//trasforma il numero di rand in una lettera secondo la tebella ascii
		char caratteri_casuali=rand()%26+65;
		//se la lettera generata è libera la metto se no la rigenero
		if(lettere_usate[caratteri_casuali-65]==1){
		i--;
		continue;
		}
		//inserisco la lettera nella posizione dell'array
		carte[conta_carte]=caratteri_casuali;
		//incremento conta_carte per passare alla posizione successiva
		conta_carte++;
		//inserisco la lettera nella posizione successiva per avere una coppia
		carte[conta_carte]=caratteri_casuali;
		//incremento di nuovo così al prossimo giro inserisco una nuova coppia nelle posizioni accanto
		conta_carte++;
		//segno la lettera occupata
		lettere_usate[caratteri_casuali-65]=1;	
		//se è dispari l'ultima coppia non si fa ed è nulla (/)
		if(d%2!=0){
		carte[d-1]='/';
		}	
	}		
}


int main(int argc, char** argv){
	
	srand(time(NULL));
	cout<<"GIOCO DEL MEMORY!!\n\n";
	
	//generare casualmente la dimensione della matrice
	int dimensione=rand()%4+3;
	cout<<"dimensione: "<<dimensione<<'*'<<dimensione<<endl;
	//matrice quadrata di caratteri 
	//metto la grandezza al massimo e utilizzo solo quelle che mi servono
	char tabella[7][7];
	
	char carte[24];
	int d=dimensione*dimensione;
	
	//azzero array
	for(int i=0; i<dimensione; i++){
		
		for(int j=0; j<dimensione; j++){
			
			tabella[i][j]=0;	
		}
	}
	cout<<"le coppie da indovinare sono: "<<dimensione*dimensione/2<<endl<<endl;
	//richiamo la funzione
	genera_coppie(carte, d);
	for(int i=0; i<d; i++) {
        cout<<carte[i]<<" ";
    }

	return 0;
}
