#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Imagem{
    
private:
    int altura, largura, cor;
    std::string tipo;

public:
    
    Imagem(int altura, int largura);

    struct RGB{
        unsigned char r,g,b,cinza;
    };

    void ler(std::string nome_arquivo);
    void converter();
    void escrever(std::string nome_arquivo);
    RGB **imagem = nullptr;
};
