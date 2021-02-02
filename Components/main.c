#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Biblioteca.h"
#define tammax 300

int main()
{
    system("title Calendário/Calendar");
    int idioma;
    printf("Selecione a opção de idioma / Select the option for language:\n1: Portugues\n2: English\nOpcao/Option: ");
    scanf("%d", &idioma);
    if(idioma==1){
        //chama a função em portugês
        system("color E2");
        system("cls");
        char nome[tammax];
        printf("Digite o endereco do arquivo com os eventos:\n");
        scanf("%s", nome);
        int a=0, b;
        while(a!=1)
        {
            system("cls");
            printf("Digite o numero correspondente a acao:\n1:Imprimir calendario como lista.\n2:Imprimir calendario como pdf.\n3:Consultar eventos.\n4:Sair.\n");
            scanf("%d", &b);
            if(b==1)
            {
                int mes_LIST, ano_LIST;
                system("cls");
                printf("Digite o mes que deseja imprimir:\n");
                scanf("%d", &mes_LIST);
                system("cls");
                printf("Digite o ano que deseja imprimir:\n");
                scanf("%d", &ano_LIST);
                system("cls");
                cria_TAD_mensal(mes_LIST,ano_LIST,nome,b,idioma);
            }
            else if(b==2)
            {
                int mes_LIST, ano_LIST;
                system("cls");
                printf("Digite o mes que deseja imprimir:\n");
                scanf("%d", &mes_LIST);
                system("cls");
                printf("Digite o ano que deseja imprimir:\n");
                scanf("%d", &ano_LIST);
                system("cls");
                cria_TAD_mensal(mes_LIST,ano_LIST,nome,b,idioma);

            }
            else if(b==3)
            {
                system("cls");
                printf("Selecione a opcao:\n1:Ordenar e Imprimir\n2:Pesquisar\n");
                int opcao;
                scanf("%d", &opcao);
                system("cls");
                if(opcao==1){
                    Ordena_Imprime(idioma, nome);
                }
                else{
                    pesquisa_eventos(idioma, nome);
                }
            }
            else if(b==4)
            {
                a=1;
            }


        system("pause");
        }



        fflush(stdin);

    }
    else if(idioma==2){
        //chama a função em inglês
        system("color F4");
        system("cls");
        char nome[tammax];
        printf("Enter the address of the event's file:\n");
        scanf("%s", nome);
        system("cls");
        int a=0, b;
        while(a!=1)
        {
            system("cls");
            printf("Enter the number corresponding to the action:\n1:Print calendar as list.\n2:Print calendar as pdf.\n3:Consult events.\n4:Exit.\n");
            scanf("%d", &b);
            if(b==1)
            {
                int mes_LIST, ano_LIST;
                system("cls");
                printf("Enter the month you want to print:\n");
                scanf("%d", &mes_LIST);
                system("cls");
                printf("Enter the year you want to print:\n");
                scanf("%d", &ano_LIST);
                system("cls");
                cria_TAD_mensal(mes_LIST,ano_LIST,nome,b,idioma);
            }
            else if(b==2)
            {
                int mes_LIST, ano_LIST;
                system("cls");
                printf("Type the month you want to print:\n");
                scanf("%d", &mes_LIST);
                system("cls");
                printf("Type the year you want to print:\n");
                scanf("%d", &ano_LIST);
                system("cls");
                cria_TAD_mensal(mes_LIST,ano_LIST,nome,b,idioma);

            }
            else if(b==3)
            {
                system("cls");
                printf("Enter the option:\n1:Sort and Print\n2:Search\n");
                int opcao;
                scanf("%d", &opcao);
                system("cls");
                if(opcao==1){
                    Ordena_Imprime(idioma, nome);
                }
                else{
                    pesquisa_eventos(idioma, nome);
                }
            }
            else if(b==4)
            {
                a=1;
            }
            system("pause");
        }

    }
    return 0;
}
