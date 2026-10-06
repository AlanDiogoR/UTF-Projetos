#include <stdio.h>
#include <conio.h>

class Pai{
	public:
		void impDados();
	};
	void Pai::impDados(){
		printf("\nimpDados() do Pai");
	}

//===========================================	

class Mae{
	public:
		void impDados();
	};
	void Mae::impDados(){
		printf("\nimpDados() do Mae");
	}
	
//===========================================	

class Filho: public Pai, public Mae{
	public:
		void impDados();
	};
	void Filho::impDados(){
		printf("\nimpDados() do Filho");
	}	
	
//===========================================

int main(){
	Filho f;
	
	//f.impDados();
//	f.Pai::impDados();
	f.Mae::impDados();
}
