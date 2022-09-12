#include "Imagem.hpp"

int main(int argc, char* argv[]){

    Imagem* imagem = new Imagem;
    int cont = 0;
    
    while(argv[++cont] != NULL){
        if(strcmp(argv[cont],"-p")== 0){
            iniciaMemLog(argv[cont+1]);
            desativaMemLog();
            break;
        }
    }

    cont = 0;

    while(argv[++cont] != NULL){
        if(strcmp(argv[cont],"-l") == 0){
            ativaMemLog();
            break;
        }
    }

    cont = 0;
    //desativaMemLog();

    while(argv[++cont] != NULL){
        if(strcmp(argv[cont],"-i")==0){
            imagem->ler(argv[cont+1]);
        }
        else if(strcmp(argv[cont],"-o") == 0){
            imagem->converter();
            imagem->escrever(argv[cont+1]);
        }
    }
    
    
    desativaMemLog();
    
    
    

    finalizaMemLog();

    return 0;
}