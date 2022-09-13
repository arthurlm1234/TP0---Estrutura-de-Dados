#include "Imagem.hpp"

Imagem::Imagem(int altura, int largura){
    this->altura = altura;
    this->largura = largura;
}

void Imagem::ler(std::string nome_arquivo){

    std::ifstream entrada(nome_arquivo);

    entrada >> tipo;
    entrada >> largura;
    entrada >> altura;
    entrada >> cor;

    int aux;

    imagem = new RGB*[altura];

    for(int i = 0; i< altura; i++){
        imagem[i]= new RGB[largura];
    }

    for(int i = 0; i < altura;i++){
        for(int j = 0; j < largura;j++){
            entrada >> aux;
            imagem[i][j].r = aux;

            entrada >> aux;
            imagem[i][j].g = aux;

            entrada >> aux;
            imagem[i][j].b = aux;

            leMemLog((long int)(&(imagem[i][j].r)), sizeof(unsigned char),0);
            leMemLog((long int)(&(imagem[i][j].g)), sizeof(unsigned char),0);
            leMemLog((long int)(&(imagem[i][j].b)), sizeof(unsigned char),0);
        }
    }

    entrada.close();
}

void Imagem::converter(){

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            imagem[i][j].cinza = int((49.0/255.0)*(0.3*imagem[i][j].r + 0.59*(imagem[i][j].g) + 0.11*imagem[i][j].b));
            leMemLog((long int)(&(imagem[i][j].cinza)), sizeof(unsigned char),0);
        }
    }
}

void Imagem::escrever(std::string nome_arquivo){
    
    std::ofstream saida(nome_arquivo);

    saida<<"P2"<<std::endl;
    saida<<largura<<' ';
    saida<<altura<<std::endl;
    saida<<49<<std::endl;

    for(int i = 0; i < altura;i++){
        for(int j = 0; j < largura;j++){
            saida << (int) imagem[i][j].cinza;
            escreveMemLog((long int)(&(imagem[i][j].cinza)), sizeof(unsigned char),0);
            if(j != largura -1){
                saida << ' ';
            }
        }

        saida << '\n';
    }

    saida.close();
}