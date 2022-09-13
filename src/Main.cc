#include "Imagem.hpp"
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char* argv[]){

    Imagem* imagem = new Imagem;
    int flag;
    std::string nome_PPM, nome_PGM;

    while((flag = getopt(argc, argv, "i:o:p:l")) != EOF){
        if (flag == 'i'){
            nome_PPM = optarg;
        }
        else if(flag == 'o'){
            nome_PGM = optarg;
        }
        else if(flag == 'p'){
            iniciaMemLog(optarg);
            ativaMemLog();
        }
    }

    int cont = 0;
    bool ativa = false;
    
    while(argv[++cont] != NULL){
        if(strcmp(argv[cont],"-l") == 0){
            ativa = true;
            break;
        }
    }

    if(!ativa){
        desativaMemLog();
    }

    imagem->ler(nome_PPM);
    imagem->converter();
    imagem->escrever(nome_PGM);

    
    finalizaMemLog();

    return 0;
}