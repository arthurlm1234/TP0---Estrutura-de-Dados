#include "Imagem.hpp"

int main(int argc, char* argv[]){

    Imagem* imagem = new Imagem(0,0);
    imagem->ler(argv[1]);
    imagem->converter();
    imagem->escrever(argv[2]);

    return 0;
}