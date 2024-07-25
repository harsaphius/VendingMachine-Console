#include <iostream>
#include <locale>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
#include "Produtos.h"
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    importar();

    int opcao, opcao2;


    do{
        opcao = verMenuPrincipal();

        switch(opcao){
            case 0:
                cout << "Obrigada pela sua preferência!";
                break;
            case 1:
                visualizarProdutos();
                break;
            case 2:
                do{
                   opcao2=MenuFornecedores();
                switch(opcao2){
                case 0:
                    break;
                case 1:
                    MenuIntroducao();
                    exportar();
                    break;
                case 2:
                    consultarTotais();
                    break;
                default:
                    cout << endl << "Opção inválida!";
                }}while(opcao2!=0);
                break;
            default:
                cout << endl << "Opção inválida!";
        }
    }while(opcao!=0);

    return 0;
}
