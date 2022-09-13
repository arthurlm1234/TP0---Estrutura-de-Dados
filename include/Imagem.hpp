#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "memlog.hpp"
#include "msgassert.hpp"

class Imagem{
    
private:
    int altura, largura, cor;
    std::string tipo;

public:
    
    Imagem(int altura=0, int largura=0);

    struct RGB{
        unsigned char r,g,b,cinza;
    };

    void ler(std::string nome_arquivo);
    void converter();
    void escrever(std::string nome_arquivo);
    RGB **imagem = nullptr;
};
