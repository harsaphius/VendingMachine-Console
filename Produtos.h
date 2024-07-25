#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

class Produto{
private:
    string nome;
    double preco;
public:
    Produto (string xNome, double xPreco)
    {
        nome = xNome;
        preco = xPreco;
    }

    string getNome() {return nome;}
    double getPreco(){return preco;}

    void setNome(string xNome){nome = xNome;}
    void setPreco (double xPreco){preco = xPreco;}

};

#endif // PRODUTOS_H_INCLUDED
