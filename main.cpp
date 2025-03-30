#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;

#define MAX_LINHAS 16
#define MAX_COLUNAS 41

void exibir_matriz(bool **reservas, int opcao_selecionada){
    int escolha;
    int linha, coluna;
    
    if(opcao_selecionada == 1)
    {
        cout << endl << "Escolha a linha e a coluna para a reserva: " << endl;
        cin >> linha >> coluna;
        
        for(int i=1; i<MAX_LINHAS; ++i)
        {
            for(int j=1; j<MAX_COLUNAS; ++j)
            {
                if(i == linha && j == coluna)
                {
                    if(reservas[i][j] == false)
                    {
                        cout << endl << "A poltrona foi reservada com sucesso!" << endl;
                        reservas[i][j] = true;
                    }
                    else
                    {
                        cout << endl << "Este lugar já está ocupado!" << endl;
                    }
                }
            }
        }
        
        cout << endl << "Escolha uma nova opção: " << endl
             << "0. Sair" << endl
             << "1. Reservar poltrona" << endl
             << "2. Visualizar mapa de ocupação" << endl
             << "3. Relatório de faturamento" << endl;
        cin >> escolha;
        
        exibir_matriz(reservas, escolha);
        
    }
    else if(opcao_selecionada == 2)
    {
        for(int i=1; i<MAX_LINHAS; ++i)
        {
            for(int j=1; j<MAX_COLUNAS; ++j)
            {
                if(reservas[i][j] == true)
                {
                    cout << setw(2) << "#";
                }
                else
                {
                    cout << setw(2) << ".";
                }
            }
            cout << endl;
        }
        cout << endl << "Escolha uma nova opção: " << endl
             << "0. Sair" << endl
             << "1. Reservar poltrona" << endl
             << "2. Visualizar mapa de ocupação" << endl
             << "3. Relatório de faturamento" << endl;
        cin >> escolha;

        exibir_matriz(reservas, escolha);
    }
    else if(opcao_selecionada == 3)
    {
        int contagem = 0;
        int faturamento = 0;
        
        for(int i=1; i<MAX_LINHAS; ++i)
        {
            for(int j=1; j<MAX_COLUNAS; ++j)
            {
                if(reservas[i][j] == true)
                {
                    if(i <= 5)
                    {
                        faturamento += 50;
                        contagem++;
                    }
                    else if(i >= 6 && i <= 10)
                    {
                        faturamento += 30;
                        contagem++;
                    }
                    else if(i >= 11 && i <= 15)
                    {
                        faturamento += 15;
                        contagem++;
                    }
                }
            }
        }
        
        cout << endl << "Lugares ocupados: " << contagem << endl;
        cout << "Faturamento total: R$ " << faturamento << endl;
        
        cout << endl << "Escolha uma nova opção: " << endl
             << "0. Sair" << endl
             << "1. Reservar poltrona" << endl
             << "2. Visualizar mapa de ocupação" << endl
             << "3. Relatório de faturamento" << endl;
        cin >> escolha;
        
        exibir_matriz(reservas, escolha);
    }
    else
    {
        for(int i=1; i<MAX_LINHAS; ++i)
        {
            delete[] reservas[i];
        }
        delete[] reservas;
    }
}

int main()
{
    int escolha_inicial;
    
    bool **mapa_reservas;
    
    mapa_reservas = new bool*[MAX_LINHAS];
    
    for(int i=1; i<MAX_LINHAS; ++i)
    {
        mapa_reservas[i] = new bool[MAX_COLUNAS];
    }
    
    for(int i=1; i<MAX_LINHAS; ++i)
    {
        for(int j=1; j<MAX_COLUNAS; ++j)
        {
            mapa_reservas[i][j] = false; 
        }
    }
    
    cout << endl << "Selecione uma opção: " << endl
         << "0. Sair" << endl
         << "1. Reservar poltrona" << endl
         << "2. Visualizar mapa de ocupação" << endl
         << "3. Relatório de faturamento" << endl;
    
    cin >> escolha_inicial;
    
    switch(escolha_inicial)
    {
        case 1:
            exibir_matriz(mapa_reservas, escolha_inicial);
            break;
        case 2:
            exibir_matriz(mapa_reservas, escolha_inicial);
            break;
        case 3:
            exibir_matriz(mapa_reservas, escolha_inicial);
            break;
        default:
            for(int i=1; i<MAX_LINHAS; ++i)
            {
                delete[] mapa_reservas[i];
            }
            delete[] mapa_reservas;
            break; // Corrigido: adicionei o break aqui
    }
    
    return 0;
}
