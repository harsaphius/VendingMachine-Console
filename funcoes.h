#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

vector<Produto> maquina;

double xTotal;
int xCont;

void importar(){
    ifstream ficheiroEntrada ("maquina.txt");
    string linhaLida;

    while (getline(ficheiroEntrada, linhaLida)){
        string informacao;
        vector <string> dadosLidos;

        stringstream linhaQuebrar(linhaLida);

        while(getline(linhaQuebrar,informacao,'|')){
            dadosLidos.push_back(informacao);
        }

    string nome=dadosLidos.at(0);
    double preco=stod(dadosLidos.at(1));

    maquina.push_back(Produto(nome,preco));
    }

    ficheiroEntrada.close();
}

void exportar(){
    ofstream ficheiroSaida ("maquina.txt");

    for (int i=0; i<maquina.size(); i++)
    {
        ficheiroSaida << maquina.at(i).getNome() << "|";
        ficheiroSaida << maquina.at(i).getPreco() << endl;
    }

    ficheiroSaida.close();
}

int verMenuPrincipal(){
    system("cls");
    int opcao;

    cout << "MENU PRINCIPAL"<< endl;
    cout << "==============================="<< endl;
    cout << endl << "1 -> Comprar Produto";
    cout << endl << "2 -> Menu Fornecedores";
    cout << endl << "0 -> Sair";
    cout << endl << endl << "Introduza uma opção: ";

    cin >> opcao;
    return opcao;
    system("pause");
}

void MenuIntroducao(){

    string nomeLido, preco;
    double precoLido;
    cin.ignore(10000,'\n');

    if (maquina.size()<20)
    {
    cout << "INTRODUZIR PRODUTO"<< endl;
    cout << "==============================="<< endl;
    cout << endl << "> Introduza o Nome: " ;
    getline(cin, nomeLido);
    cout << endl << "Introduza  o Preço: ";
    getline(cin, preco);

    precoLido = stod(preco);

    maquina.push_back(Produto(nomeLido, precoLido));
    }

    else
    {
    cout << "A máquina está cheia!" << endl;
    }

    system("pause");
}

int MenuProduto(){

    string nomeLido;
    double precoLido;

    cout << "INTRODUZIR PRODUTO"<< endl;
    cout << "==============================="<< endl;
    cout << endl << "> Introduza o Nome: " ;
    cin >> nomeLido;
    cout << endl << "> Introduza o Preço: " ;
    cin >> precoLido;

}


int MenuFornecedores(){
    system("cls");
    int opcao;

    cout << "FORNECEDORES"<< endl;
    cout << "==============================="<< endl;
    cout << endl << "1 -> Introduzir Produto";
    cout << endl << "2 -> Consultar Totais";
    cout << endl << "0 -> Voltar ao menu anterior";
    cout << endl << endl << "Introduza uma opção: ";

    cin >> opcao;
    return opcao;

    system("pause");
}


void visualizarProdutos(){

    cout << "PRODUTOS DISPONÍVEIS"<< endl;
    cout << "==============================="<< endl;

    for(int i=0; i<maquina.size(); i++){
        cout << endl << (i+1) << "->" << maquina.at(i).getNome() << " (" << maquina.at(i).getPreco() << ")" << endl;
    }

    if(maquina.size()==0)
        cout << "Máquina indisponível! Necessário recarga!" << endl;

    for (int i=0;i<maquina.size(); i++){

    if (maquina.size()>i)
    {
    int opcao;
    cout << endl << "Introduza a opção pretendida: "  << endl;
    cin >> opcao;

    opcao=opcao-1;

    double quantia;

    cout << endl << "Introduza montante: " << endl;
    cin >> quantia;

    cout << endl;

    if (maquina.at(opcao).getPreco()==quantia)
            {cout << "Retirar: " << maquina.at(opcao).getNome() << endl;
            xCont++;
            xTotal+=maquina.at(opcao).getPreco();
            maquina.erase(maquina.begin() + opcao);
            break;
            }
    if (maquina.at(opcao).getPreco()<quantia)
            {cout << "Retirar: " << maquina.at(opcao).getNome()<< endl;
            cout << "Troco de " << (quantia-maquina.at(opcao).getPreco()) << " euros." << endl;
            xCont++;
            xTotal+=maquina.at(opcao).getPreco();
            maquina.erase(maquina.begin() + opcao);
            break;
            }
    if (maquina.at(opcao).getPreco()>quantia)
           {
            double quantiaTotal;
            quantiaTotal=quantia;

            while (quantiaTotal<maquina.at(opcao).getPreco()){
                cout << maquina.at(opcao).getNome() << ": Crédito insuficiente! Faltam " << ((maquina.at(opcao).getPreco()- quantiaTotal)) << " euros." << endl;
                cout << endl << "Introduza montante: " << endl;
                cin >> quantia;
                quantiaTotal+=quantia;
            }
            cout << "Retirar: " << maquina.at(opcao).getNome() << endl;
            xCont++;
            xTotal+=maquina.at(opcao).getPreco();
            maquina.erase(maquina.begin() + opcao);
            break;
           }
    }}
    exportar();

    system("pause");
}

void consultarTotais (){

   cout << "O número de produtos vendidos é: " << xCont << endl;
   cout << "O valor de vendas é: " << xTotal << endl;

   system("pause");
}


#endif // FUNCOES_H_INCLUDED
