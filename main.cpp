//Bibliotecas necess�rias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>

using namespace std;

//Função principal para demonstrar o uso da Pilha
int main() {
    int correto = 1;
    char x[100]; //Vari�vel utilizada para receber o valor digitado do usu�rio e empilhar na Pilha
    //Tamb�m ser� utilizada para receber os valores dos m�todos Desempilhar e Topo

    Pilha_Construtor();  //para iniciar a Pilha

    cout << "\nDigite a expressao: "; //coleta a a expressão
    cin.getline(x, sizeof(x));

    for (int i = 0; x[i] != '\0'; ++i) { //abre um laço que só para quando chega no final da string

        if (x[i] == '[' || x[i] == '(') { //verifica se o caractere que esta lendo é [ ou (
            Pilha_Empilhar(x[i]);          //se a condição for verdadeira o caractere será empilhado
        }
        else if (Pilha_Vazia() == true) { // se a pilha estiver vazia, não há parenteses/colchetes
            correto = 0;                   // então não está correto
        }
        else {
            if (x[i] == ']' || x[i] == ')'){  //se o caractere atual for um fechamento iremos desempilhar
                Pilha_Desempilhar(x[i]);
            }
        }
    }
    if (Pilha_Vazia() == false){ //apos fecharmos o "for" verificamos se a pilha está vazia, ou seja, caso não haja nada na pilha quer dizer que todos pares
        correto = 0;            // foram encontrados. Caso contrario não há aberturas e fechamentos correspondentes.
    }
    if (correto == 1) {          //se correto permanecer atribuido a 1 será impresso "OK" pois a expressão está balanceada
        cout << "OK" << endl;
    } else {                     //caso seja diferente de 1 será impresso "Errado" pois a expressão não está balanceada
        cout << "Errado" << endl;
    }
    Pilha_Destrutor();           //destruimos o que restou da pilha
    system("pause");
    return 0;

}

