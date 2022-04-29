/*agdd*/
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

float Delta(float a, float b, float c);
float function(float x, float a, float b, float c);
int menu();
int racional();
int polinomial();
int exponencial();

	float a, a2, b, b2, c, c2, x1, x2, media, var3, delta, fx1, fx2, fm, erro=1;
    int iter=1;
    
int main(){

    int opcao;
    

    cout<<"\n\n========== Metodo da Bisseccao ==========\n\n    Qual tipo de Funcao a ser usada:\n\n    | Para funcoes polinomiais | = | 1 |\n    | Para funcoes racionais   | = | 2 |\n    | Para funcoes exponenciais| = | 3 |\n\n        Opcao: ";cin>>opcao;

    switch(opcao){
        case 1:
            polinomial();
            break;

        case 2:
            racional();
            break;
        case 3:
        	exponencial();
        	break;
        default:
            cout<<"\n ****caractere nao valido****\n";
			main();
			break;
    }
   
    
}


int menu(){

    char op;

    cout<<"\n\n---Deseja fazer outro calculo---\n    (S-sim | N-nao): ";cin>>op;
    op = toupper(op);

    switch(op){
        case 'S':
            main();
            break;

        case 'N':
            return 0;
            break;
        
        default:
            cout<<"caractere nao valido\n";
			break;
    }
   menu();

}
float Delta(float a, float b, float c){

    return(pow(b,2) - 4*a*c);

}

float function(float x, float a, float b, float c){

    return(a * pow(x,2) + b * x + c);

}

int racional(){
	
	cout<<"\n\n |========= Metodo da Bisseccao =========|\n |para funcoes racionais ate segundo grau|\n |    para 1  grau  comece com  a = 0    |"<<endl<<endl;
// recebendo valores da funcao
	cout<<"\n    Dividendo:\n\n";
    cout<<"    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;
    
    if(a==0&&b==0&&c==0){
    	cout<<"    \n\nA funcao tem 0 como numerador e resulta em uma constante\n";
    	menu();
	}
	cout<<"\n\n    Divisor:\n\n";
    cout<<"    Digite valor de a: ";cin >> a2;
    cout<<"    Digite valor de b: ";cin >> b2;
    cout<<"    Digite valor de c: ";cin >> c2;
    
    if(a2==0&&b2==0&&c2==0){
    	cout<<"    \n\nA funcao tem 0 como denominador e resulta em uma indeterminacao matematica\n";
    	menu();
	}

// Passo 1

    cout<<"\n    Digite primeiro valor de x: ";cin >> x1;
    cout<<"    Digite segundo  valor de x: ";cin >> x2;

    var3 = ((function(x1, a, b, c))/(function(x1, a2, b2, c2)))*((function(x2, a, b, c))/(function(x2, a2, b2, c2)));

    while(var3>=0){
        cout<<"\n---- tente outros valores ----\n";
        cout<<"    Digite primeiro valor de x: ";cin >> x1;
        cout<<"    Digite segundo  valor de x: ";cin >> x2;
        
        var3 = ((function(x1, a, b, c))/(function(x1, a2, b2, c2)))*((function(x2, a, b, c))/(function(x2, a2, b2, c2)));
    }
// Passo 2
    while(erro > 0.001){
        
        media = (x1+x2)/2;
// Passo 3 
    fx1 = (function(x1, a, b, c))/(function(x1, a2, b2, c2));
    fx2 = (function(x2, a, b, c))/(function(x2, a2, b2, c2));
    fm = (function(media, a, b, c))/(function(media, a2, b2, c2));
    
    if((fx1*fm) > 0){
        
        x1 = media;
    }else if((fx2*fm)>0){
        x2 = media;
        
    }else{
    	if(iter==1){
    		erro=0;
		}
        cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
        return 0;
    }
    erro = media - ((x1+x2)/2);
    if(erro<0){
        erro=erro*(-1);
        
    }
	iter++;
    }

    cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
    
    menu();
}


int polinomial(){
	
    
    cout<<"\n\n |======== Metodo da Bisseccao ========|\n |      para funcoes  polinomiais      |\n |    para 1 grau  comece com a = 0    |"<<endl<<endl;
// recebendo valores da funcao
    cout<<"    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;

// verificando se e quadratica e se ha raizes reais 
    if(a!=0){
	
		delta = Delta(a, b, c);

    	if(delta < 0){
        	cout<<"\n==A funcao nao tem raizes reais==\n\n";
        	menu();
    	}else if(delta == 0){
        	cout<<"\n|A funcao tem duas raizes reais iguais|\n|    e nao convege via esse metodo    | \n\n";
        	menu();
    	}
	}else if(a==0&&b==0){   /* verificando se afin e constante */
		if(c==0){
			cout<<"\n== A funcao e uma constante sobre o eixo x ==\n\n";
        	menu();
		}else{
			cout<<"\n== A funcao e uma constante e nao tem raizes reais ==\n\n";
        	menu();
		}
		
	}
// Passo 1
    cout<<"    Digite primeiro valor de x: ";cin >> x1;
    cout<<"    Digite segundo  valor de x: ";cin >> x2;

    var3 = (function(x1, a, b, c))*(function(x2, a, b, c));

    while(var3>=0){
        cout<<"\n---- tente outros valores ----\n";
        cout<<"    Digite primeiro valor de x: ";cin >> x1;
        cout<<"    Digite segundo  valor de x: ";cin >> x2;
        
        var3 = (function(x1, a, b, c))*(function(x2, a, b, c));
    }
// Passo 2
    while(erro > 0.001){
        
        media = (x1+x2)/2;
// Passo 3 
    fx1 = function(x1, a, b, c);
    fx2 = function(x2, a, b, c);
    fm = function(media, a, b, c);
    
    if((fx1*fm) > 0){
        
        x1 = media;
    }else if((fx2*fm)>0){
        x2 = media;
        
    }else{
        cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
        return 0;
    }
    erro = media - ((x1+x2)/2);
    if(erro<0){
        erro=erro*(-1);
        
    }
	iter++;
    }

    cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
    
    menu();
}

int exponencial(){
	
	cout<<"\n\n |======== Metodo da Bisseccao ========|\n";
	cout<<" |      para funcoes exponenciais      |\n\n    vamos usar:\n\n    f(x) = ('a' vezes 'e' elevado a ('b'vezes 'x')) mais 'c' "<<"\n    f(x) = (a*e^(bx))+c ";
	
	cout<<"\n\n    Digite valor de a: ";cin >> a;
    cout<<"    Digite valor de b: ";cin >> b;
    cout<<"    Digite valor de c: ";cin >> c;

 
    if(a==0&&b==0){   /* verificando se f(x) e constante */
		if(c==0){
			cout<<"\n== A funcao e uma constante sobre o eixo x ==\n\n";
        	menu();
		}else{
			cout<<"\n== A funcao e uma constante e nao tem raizes reais ==\n\n";
        	menu();
		}
		
	}
// Passo 1
    cout<<"    Digite primeiro valor de x: ";cin >> x1;
    cout<<"    Digite segundo  valor de x: ";cin >> x2;

    var3 = ((a*exp(b*x1))+c)*((a*exp(b*x2))+c);

    while(var3>=0){
        cout<<"\n---- tente outros valores ----\n";
        cout<<"    Digite primeiro valor de x: ";cin >> x1;
        cout<<"    Digite segundo  valor de x: ";cin >> x2;
        
        var3 = ((a*exp(b*x1))+c)*((a*exp(b*x2))+c);
    }
// Passo 2
    while(erro > 0.001){
        
        media = (x1+x2)/2;
// Passo 3 
    fx1 = (a*exp(b*x1))+c;
    fx2 = (a*exp(b*x2))+c;
    fm = (a*exp(b*media))+c;
    
    if((fx1*fm) > 0){
        
        x1 = media;
    }else if((fx2*fm)>0){
        x2 = media;
        
    }else{
        cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
        return 0;
    }
    erro = media - ((x1+x2)/2);
    if(erro<0){
        erro=erro*(-1);
        
    }
	iter++;
    }

    cout<<"\n A funcao converge em aproximadamente x = "<< media<<" depois de "<<iter<<" iteracoes"<<"\n com erro = "<<erro<<"\n\n";
    
    menu();
}



