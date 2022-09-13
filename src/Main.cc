#include "Imagem.hpp"
#include <getopt.h>

bool possui_argumento(char** vetor_argumentos, std::string argumento){
    bool possui = false;
    int cont = 0;
    
    while(vetor_argumentos[++cont] != NULL){
        if(vetor_argumentos[cont] == argumento){
            possui = true;
            break;
        }
    }

    return possui;
}

int main(int argc, char* argv[]){

    Imagem* imagem = new Imagem;
    int flag;
    std::string nome_PPM, nome_PGM;
    bool iniciado = false;

    erroAssert(possui_argumento(argv, "-i"), "O programa precisa da flag '-i' para saber o arquivo de entrada.");
    erroAssert(possui_argumento(argv, "-o"), "O programa precisa da flag '-o' para saber o arquivo de saída.");

    while((flag = getopt(argc, argv, "i:o:p:l")) != EOF){
        if (flag == 'i'){
            nome_PPM = optarg;
        }
        else if(flag == 'o'){
            nome_PGM = optarg;
        }
        else if(flag == 'p'){
            iniciaMemLog(optarg);
            iniciado = true;
            ativaMemLog();
        }
    }

    if(!possui_argumento(argv,"-l") && iniciado)
        desativaMemLog();
    
    erroAssert(possui_argumento(argv, "-l") && iniciado, "Você não ativar o memlog sem tê-lo iniciado.");
    
    imagem->ler(nome_PPM);
    imagem->converter();
    imagem->escrever(nome_PGM);
   
    if(iniciado)
        finalizaMemLog();

    return 0;
}