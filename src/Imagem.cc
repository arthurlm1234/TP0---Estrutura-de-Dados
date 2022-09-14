#include "Imagem.hpp"

Imagem::Imagem(int altura, int largura){
    this->altura = altura;
    this->largura = largura;
}

void Imagem::ler(std::string nome_arquivo){

    std::ifstream entrada(nome_arquivo);

    entrada >> tipo;
    erroAssert(tipo == "P3", "Tipo de arquivo não suportado, deve ser do tipo P3");

    entrada >> largura;
    entrada >> altura;
    erroAssert(altura>0 && largura>0, "A altura e a largura devem ser positivas.");
    
    entrada >> cor;

    erroAssert(cor==255, "O atributo cor deve ser de 255");

    int aux;

    ppm = new RGB*[altura];

    for(int i = 0; i< altura; i++){
        ppm[i]= new RGB[largura];
    }

    for(int i = 0; i < altura;i++){
        for(int j = 0; j < largura;j++){
            entrada >> aux;
            ppm[i][j].r = aux;

            entrada >> aux;
            ppm[i][j].g = aux;

            entrada >> aux;
            ppm[i][j].b = aux;

            ESCREVEMEMLOG((long int)(&(ppm[i][j].r)), sizeof(unsigned char),0);
            ESCREVEMEMLOG((long int)(&(ppm[i][j].g)), sizeof(unsigned char),0);
            ESCREVEMEMLOG((long int)(&(ppm[i][j].b)), sizeof(unsigned char),0);
        }
    }

    entrada.close();
}

void Imagem::converter(){

    pgm = new unsigned char*[altura];

    for(int i = 0; i< altura; i++){
        pgm[i]= new unsigned char[largura];
    }

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            pgm[i][j] = int((49.0/255.0)*(0.3*ppm[i][j].r + 0.59*(ppm[i][j].g) + 0.11*ppm[i][j].b));
            ESCREVEMEMLOG((long int)(&(pgm[i][j])), sizeof(unsigned char),0);
            LEMEMLOG((long int)(&(ppm[i][j].r)), sizeof(unsigned char),1);
            LEMEMLOG((long int)(&(ppm[i][j].g)), sizeof(unsigned char),1);
            LEMEMLOG((long int)(&(ppm[i][j].b)), sizeof(unsigned char),1);
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
            saida << (int) pgm[i][j];
            LEMEMLOG((long int)(&(pgm[i][j])), sizeof(unsigned char),0);
            if(j != largura -1){
                saida << ' ';
            }
        }

        saida << '\n';
    }

    saida.close();
}