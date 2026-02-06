#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//funzione che genera le coppie
void genera_coppie(char carte[], int d) {

	//variabile che mi serve per inserire le lettere nell'array
	int conta_carte=0;
	//tengo traccia delle lettere che uso
	int lettere_usate[26]= {0};

	for(int i=0; i<d/2; i++) {

		//genera lettere casuali
		//trasforma il numero di rand in una lettera secondo la tabella ascii
		char caratteri_casuali=rand()%26+65;
		//se la lettera generata e' libera la metto se no la rigenero
		if(lettere_usate[caratteri_casuali-65]==1) {
			i--;
			continue;
		}
		//inserisco la lettera nella posizione dell'array
		carte[conta_carte]=caratteri_casuali;
		//incremento conta_carte per passare alla posizione successiva
		conta_carte++;
		//inserisco la lettera nella posizione successiva per avere una coppia
		carte[conta_carte]=caratteri_casuali;
		//incremento di nuovo cosC, al prossimo giro inserisco una nuova coppia nelle posizioni accanto
		conta_carte++;
		//segno la lettera occupata
		lettere_usate[caratteri_casuali-65]=1;
		//se C( dispari l'ultima coppia non si fa ed C( nulla (/)
		if(d%2!=0) {
			carte[d-1]='/';
		}
	}
}
//funzione che mescola le lettere generate
void mescola_lettere(char carte[], int d) {

	//ciclo che si ripete tante volte quante la dimensione
	for(int i=0; i<d; i++) {
	    
		//prendo una posizione casuale dell'array compresa tra la dimensiomne
		int mescola=rand()%d;
		//adesso scambio la lettera nella posizione i nella posizione casuale che ho generato
		char ordine_casuale=carte[i];
		carte[i]=carte[mescola];
		carte[mescola]=ordine_casuale;
	}

}

int main(int argc, char** argv) {

	srand(time(NULL));
	cout<<"GIOCO DEL MEMORY!!\n\n";

	//generare casualmente la dimensione della matrice
	//int dimensione=rand()%4+4;
	int dimensione=5;
	//metto la grandezza al massimo e utilizzo solo quelle che mi servono
	char tabella[7][7];
	//dichiaro l'array carte con il massimo possibile
	char carte[49];
	int d=dimensione*dimensione;

	//azzero array
	for(int i=0; i<dimensione; i++) {

		for(int j=0; j<dimensione; j++) {

			tabella[i][j]=0;
		}
	}
	cout<<"le coppie da indovinare sono: "<<dimensione*dimensione/2<<endl<<endl<<endl;
	//richiamo le funzioni
	genera_coppie(carte, d);
	mescola_lettere(carte, d);
	//stampo le carte
	//colonna parte da 0 e incrementa ogni volta che stampo il numero, quando raggiunge un multiplo del numero (dimensione) va a capo
	int colonna=0;
	for(int i=0; i<dimensione;i++){
	    
	    for(int j=0; j<dimensione; j++){
	        
	        tabella[i][j]=carte[colonna];
	        //cout<<tabella[i][j]<<"   ";
	        cout<<"*"<<"   ";
	        colonna++;
	        if(colonna%dimensione==0){
	        cout<<endl<<endl;
	        }
	    }
	}
	
	cout<<"\ninserisci le coordinate delle due carte che vuoi vedere\n\n";
	int riga1, colonna1, riga2, colonna2, tentativi=0, coppie=0;
	//array che mi serve per spostare il cursore correttamente sulla riga con massimo 7 righe (stessa cosa per le colonne)
	/*come funziona: ogni posizione contiene il valore da sommare al numero della riga inserito dall'utente
		esempio: inserisco 1; voglio girare una casella alla riga 1 del memory, che in realtà parte dalla riga 6 dello schermo
		allora quando vado ad indicare la posizione del cursore per visualizzare la casella, sommo al valore inserito il numero contenuto
		nella rispettiva posizione dell'array. esempio inserisco riga_carta=1 --> visualizzerò la riga che corrisponde a riga_carta+valori_riga[riga_carta]
		cioè 1+valori_riga[1], che è uguale a 1+5=6, cioè la prima riga da cui partono le caselle del memory
	*/
	int somma_riga[7]={0,5,6,7,8,9,10}, somma_colonna[7]={0,0,3,6,9,12,15};
	//50 tentativi al massimo
	for(int i=0; i<50; i++){
		tentativi++;
		cout<<"COPPIA "<<i+1<<endl;
		cout<<"riga della prima carta: ";
		cin>>riga1;
		cout<<"colonna della prima carta: ";
		cin>>colonna1;
		cout<<endl;
		//salvo la posizione del cursore in fondo allo schermo
		cout<<"\33[s";
		//metto il cursore nella posizione della casella che voglio visualizzare e faccio vedere la lettera nascosta
 		cout<<"\33["<<riga1+somma_riga[riga1]<<";"<<colonna1+somma_colonna[colonna1]<<"H";
		cout<<tabella[riga1-1][colonna1-1];
		cout<<"\33[u";
		//ripeto per due volte perchè devo girare due carte alla volta
		cout<<"riga della seconda carta: ";
		cin>>riga2;
		cout<<"colonna della seconda carta: ";
		cin>>colonna2;
		cout<<endl;
		//salvo la posizione del cursore in fondo allo schermo
		cout<<"\33[s";
		//metto il cursore nella posizione della casella che voglio visualizzare e faccio vedere la lettera nascosta
 		cout<<"\33["<<riga2+somma_riga[riga2]<<";"<<colonna2+somma_colonna[colonna2]<<"H";
		cout<<tabella[riga2-1][colonna2-1];
		
		//aspetto 5 sec
		sleep(5);
		//rimetto il cursore nella posizione della lettera e la nascondo di nuovo con un asterisco per entrambe le carte
		cout<<"\33["<<riga1+somma_riga[riga1]<<";"<<colonna1+somma_colonna[colonna1]<<"H";
		cout<<'*';
		cout<<"\33["<<riga2+somma_riga[riga2]<<";"<<colonna2+somma_colonna[colonna2]<<"H";
		cout<<'*';
		//riporto il cursore alla fine dello schermo
		cout<<"\33[u";	
		
		if(tabella[riga1-1][colonna1-1]==tabella[riga2-1][colonna2-1]){
			cout<<"indovinato!"<<endl<<endl;
			coppie++;
			
			if(coppie==dimensione*dimensione/2){
				cout<<"HAI VINTO! \nhai indovinato tutte le coppie in: "<<tentativi<<" tentativi";
			}
		}	
	}

	return 0;
}
