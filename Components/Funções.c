#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include "pdfgen.h"
#include <time.h>
#include <string.h>
#include <math.h>

void CHAR_SEMANA(char semana_1[][2], int idioma)
{
    if(idioma==1)
    {
        strcpy(semana_1[0], "D");
        strcpy(semana_1[1], "S");
        strcpy(semana_1[2], "T");
        strcpy(semana_1[3], "Q");
        strcpy(semana_1[4], "Q");
        strcpy(semana_1[5], "S");
        strcpy(semana_1[6], "S");
    }
    else
    {
        strcpy(semana_1[0], "S");
        strcpy(semana_1[1], "M");
        strcpy(semana_1[2], "T");
        strcpy(semana_1[3], "W");
        strcpy(semana_1[4], "T");
        strcpy(semana_1[5], "F");
        strcpy(semana_1[6], "S");
    }


}

void STRING_SEMANA(char semana_1[][19], int idioma)
{
    if(idioma==1)
    {
        strcpy(semana_1[0], "Domingo");
        strcpy(semana_1[1], "Segunda-Feira");
        strcpy(semana_1[2], "Terca-Feira");
        strcpy(semana_1[3], "Quarta-Feira");
        strcpy(semana_1[4], "Quinta-Feira");
        strcpy(semana_1[5], "Sexta-Feira");
        strcpy(semana_1[6], "Sabado");
    }
    else
    {
        strcpy(semana_1[0], "Sunday");
        strcpy(semana_1[1], "Monday");
        strcpy(semana_1[2], "Tuesday");
        strcpy(semana_1[3], "Wednesday");
        strcpy(semana_1[4], "Thursday");
        strcpy(semana_1[5], "Friday");
        strcpy(semana_1[6], "Saturday");
    }


}

int dia_semana(int ano, int mes, int dia)
{
    int a, y, m, q, d;
    a=(14-mes)/12;
    y=ano-a;
    m=mes+12*a-2;
    q=dia+(31*m/12)+y+(y/4)-(y/100)+y/400;
    d=(q%7)+1;
    return d;
}

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (Apontador)malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->prox = NULL;
}

int VerificaListaVazia(TipoLista lista)
{

    if(lista.Primeiro->prox == lista.Ultimo->prox)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Insere(Evento x, TipoLista *lista)
{
    lista->Ultimo->prox = (Apontador) malloc(sizeof(Celula));
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->e = x;
    lista->Ultimo->prox = NULL;

}

void preenche_semana(struct pdf_doc *pdf, int idioma, int fundo)
{
    if(idioma==1)
    {
        if(fundo==1)
        {
            pdf_add_text(pdf, NULL, "Domingo", 15, 73, 463, PDF_RGB(255, 0, 0));
            pdf_add_text(pdf, NULL, "Sabado", 15, 717, 463, PDF_RGB(255, 0, 0));
        }
        else
        {
            pdf_add_text(pdf, NULL, "Domingo", 15, 73, 463, PDF_BLACK);
            pdf_add_text(pdf, NULL, "Sabado", 15, 717, 463, PDF_BLACK);
        }
        pdf_add_text(pdf, NULL, "Segunda-Feira", 15, 158, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Terca-Feira", 15, 275, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Quarta-Feira", 15, 376, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Quinta-Feira", 15, 485, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Sexta-Feira", 15, 595, 463, PDF_BLACK);

    }
    else
    {
        if(fundo==1)
        {
            pdf_add_text(pdf, NULL, "Sunday", 15, 76, 463, PDF_RGB(255, 0, 0));
            pdf_add_text(pdf, NULL, "Saturday", 15, 710, 463, PDF_RGB(255, 0, 0));
        }
        else
        {
            pdf_add_text(pdf, NULL, "Sunday", 15, 76, 463, PDF_BLACK);
            pdf_add_text(pdf, NULL, "Saturday", 15, 710, 463, PDF_BLACK);
        }
        pdf_add_text(pdf, NULL, "Monday", 15, 182, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Tuesday", 15, 286, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Wednesday", 15, 383, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Thursday", 15, 496, 463, PDF_BLACK);
        pdf_add_text(pdf, NULL, "Friday", 15, 615, 463, PDF_BLACK);

    }

}

void imprime_img(struct pdf_doc *pdf, char t, int x, int y, uint32_t cor)
{
    int size=12;
    if(t=='A')
    {
        if(cor == PDF_RGB(255, 0, 0))
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./A2.jpg");
        }
        else
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./A.jpg");
        }
    }
    else if(t=='F')
    {
        if(cor == PDF_RGB(255, 0, 0))
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./F2.jpg");
        }
        else
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./F.jpg");
        }
    }
    else if(t=='V')
    {
        if(cor == PDF_RGB(255, 0, 0))
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./V2.jpg");
        }
        else
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./V.jpg");
        }
    }
    else if(t=='O')
    {
        if(cor == PDF_RGB(255, 0, 0))
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./O2.jpg");
        }
        else
        {
            pdf_add_jpeg(pdf, NULL, x, y, size, size, "./O.jpg");
        }
    }

}

void imprimir_eventos(struct pdf_doc *pdf, int day, int x, int y, TipoLista lista, uint32_t cor)
{
    int x_img=x-75, y_img=y-15, count=0, count_2=0, ultimo_dia;
    char aviso_eventos[5], auxiliar[4];
    Apontador aux;
    aux=lista.Primeiro->prox;
    while (aux != NULL)
    {
        if(aux->e.d == day || aux->e.d == 0)
        {
            count++;
        }
        ultimo_dia=aux->e.d;
        aux=aux->prox;
    }

    if(count != 0)
    {
        aux=lista.Primeiro->prox;
        while(aux->e.d == 0 && count_2<3)
        {
            imprime_img(pdf, aux->e.t, x_img, y_img, cor);
            pdf_add_text(pdf, NULL, aux->e.Desc, 8, x_img+13, y_img+3, cor);
            y_img=y_img-15;
            aux=aux->prox;
            count_2++;
        }
        while(aux->e.d < day)
        {
            aux=aux->prox;
            if(aux==NULL)
            {
                break;
            }
        }
        if(day<=ultimo_dia)
        {
            while(aux->e.d == day && count_2<3)
            {
                imprime_img(pdf, aux->e.t, x_img, y_img, cor);
                if(strlen(aux->e.Desc)>17)
                {
                    int tam=strlen(aux->e.Desc)-1;
                    char a_1[18];
                    strcpy(a_1, aux->e.Desc);
                    while(tam!=17)
                    {
                        a_1[tam]=' ';
                        tam--;
                    }
                    a_1[17]='\n';
                    a_1[16]='.';
                    a_1[15]='.';
                    a_1[14]='.';
                    pdf_add_text(pdf, NULL, a_1, 8, x_img+13, y_img+3, cor);
                }
                else
                {
                    pdf_add_text(pdf, NULL, aux->e.Desc, 8, x_img+13, y_img+3, cor);
                }
                y_img=y_img-15;
                aux=aux->prox;
                count_2++;
                if(aux==NULL)
                {
                    break;
                }
            }
        }
    }
    if(count_2==3 && count>3)
    {
        strcpy(aviso_eventos, "+");
        itoa(count-3, auxiliar, 10);
        strcat(aviso_eventos, auxiliar);
        pdf_add_text(pdf, NULL, aviso_eventos, 10, x+4, y-53, cor);
    }
}

void Ordena_Mes(TipoLista lista, int count)
{
    Apontador aux[count], ler, x, aux_2[4][count];
    int i=0, j=0, k, m[4]= {0};
    ler=lista.Primeiro->prox;
    while(i<count)
    {
        aux[i]=ler;
        ler=ler->prox;
        i++;
    }
    while(j<count)
    {
        k=j+1;
        while(k<count)
        {
            if(aux[k]->e.d < aux[j]->e.d)
            {
                x=aux[j];
                aux[j]=aux[k];
                aux[k]=x;
            }
            k++;
        }
        j++;
    }
    k=0;
    while(k<count)
    {
        if(aux[k]->e.t == 'A')
        {
            aux_2[0][m[0]]=aux[k];
            m[0]++;
        }
        else if(aux[k]->e.t == 'F')
        {
            aux_2[1][m[1]]=aux[k];
            m[1]++;
        }
        else if(aux[k]->e.t == 'V')
        {
            aux_2[2][m[2]]=aux[k];
            m[2]++;
        }
        else if(aux[k]->e.t == 'O')
        {
            aux_2[3][m[3]]=aux[k];
            m[3]++;
        }
        k++;
    }
    i=0;
    aux_2[0][m[0]]=NULL;
    aux_2[1][m[1]]=NULL;
    aux_2[2][m[2]]=NULL;
    aux_2[3][m[3]]=NULL;
    m[0]=0;
    m[1]=0;
    m[2]=0;
    m[3]=0;
    j=0;
    while(i<=31)
    {
        while(aux_2[0][m[0]]!=NULL && aux_2[0][m[0]]->e.d == i)
        {
            aux[j]=aux_2[0][m[0]];
            m[0]++;
            j++;
        }
        while(aux_2[1][m[1]]!= NULL && aux_2[1][m[1]]->e.d == i)
        {
            aux[j]=aux_2[1][m[1]];
            m[1]++;
            j++;
        }
        while(aux_2[2][m[2]]!= NULL && aux_2[2][m[2]]->e.d == i)
        {
            aux[j]=aux_2[2][m[2]];
            m[2]++;
            j++;
        }
        while(aux_2[3][m[3]]!= NULL && aux_2[3][m[3]]->e.d == i)
        {
            aux[j]=aux_2[3][m[3]];
            m[3]++;
            j++;
        }
        i++;
    }
    lista.Primeiro->prox=aux[0];
    for(i=0; i<count; i++)
    {
        if(i==count-1)
        {
            aux[i]->prox=NULL;
        }
        else
        {
            aux[i]->prox=aux[i+1];
        }
    }
    lista.Ultimo=aux[count-1];
}

void Ordena_Tipo(TipoLista lista, int count)
{
    Apontador aux[count], ler, aux_2[4][count];
    int i=0, j=0, k=0, m[4]= {0};
    ler=lista.Primeiro->prox;
    while(i<count)
    {
        aux[i]=ler;
        ler=ler->prox;
        i++;
    }
    while(k<count)
    {
        if(aux[k]->e.t == 'A')
        {
            aux_2[0][m[0]]=aux[k];
            m[0]++;
        }
        else if(aux[k]->e.t == 'F')
        {
            aux_2[1][m[1]]=aux[k];
            m[1]++;
        }
        else if(aux[k]->e.t == 'V')
        {
            aux_2[2][m[2]]=aux[k];
            m[2]++;
        }
        else if(aux[k]->e.t == 'O')
        {
            aux_2[3][m[3]]=aux[k];
            m[3]++;
        }
        k++;
    }
    k=0;
    while(k<m[0])
    {
        aux[k]=aux_2[0][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1])
    {
        aux[k]=aux_2[1][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1]+m[2])
    {
        aux[k]=aux_2[2][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1]+m[2]+m[3])
    {
        aux[k]=aux_2[3][j];
        k++;
        j++;
    }
    lista.Primeiro->prox=aux[0];
    for(i=0; i<count; i++)
    {
        if(i==count-1)
        {
            aux[i]->prox=NULL;
        }
        else
        {
            aux[i]->prox=aux[i+1];
        }
    }
    lista.Ultimo=aux[count-1];
}

void Ordena_Data(TipoLista lista, int count)
{

    Apontador aux[count], ler, x;
    int i=0, j=0, k;
    ler=lista.Primeiro->prox;
    while(i<count)
    {
        aux[i]=ler;
        ler=ler->prox;
        i++;
    }
    while(j<count)
    {
        k=j+1;
        while(k<count)
        {
            if(aux[k]->e.a < aux[j]->e.a)
            {
                x=aux[j];
                aux[j]=aux[k];
                aux[k]=x;
            }
            else if(aux[k]->e.a == aux[j]->e.a)
            {
                if(aux[k]->e.m < aux[j]->e.m)
                {
                    x=aux[j];
                    aux[j]=aux[k];
                    aux[k]=x;
                }
                else if(aux[k]->e.m == aux[j]->e.m)
                {
                    if(aux[k]->e.d < aux[j]->e.d)
                    {
                        x=aux[j];
                        aux[j]=aux[k];
                        aux[k]=x;
                    }
                }

            }
            k++;
        }
        j++;
    }
    lista.Primeiro->prox=aux[0];
    for(i=0; i<count; i++)
    {
        if(i==count-1)
        {
            aux[i]->prox=NULL;
        }
        else
        {
            aux[i]->prox=aux[i+1];
        }
    }
    lista.Ultimo=aux[count-1];
}

void Ordena_Tipo_Data(TipoLista lista, int count)
{
    Apontador aux[count], ler, x, aux_2[4][count];
    int i=0, j=0, k=0, m[4]= {0};
    ler=lista.Primeiro->prox;
    while(i<count)
    {
        aux[i]=ler;
        ler=ler->prox;
        i++;
    }
    while(k<count)
    {
        if(aux[k]->e.t == 'A')
        {
            aux_2[0][m[0]]=aux[k];
            m[0]++;
        }
        else if(aux[k]->e.t == 'F')
        {
            aux_2[1][m[1]]=aux[k];
            m[1]++;
        }
        else if(aux[k]->e.t == 'V')
        {
            aux_2[2][m[2]]=aux[k];
            m[2]++;
        }
        else if(aux[k]->e.t == 'O')
        {
            aux_2[3][m[3]]=aux[k];
            m[3]++;
        }
        k++;
    }
    k=0;
    j=0;
    while(k<m[0])
    {
        j=k+1;
        while(j<m[0])
        {
            if(aux_2[0][j]->e.a < aux_2[0][k]->e.a)
            {
                x=aux_2[0][j];
                aux_2[0][j]=aux_2[0][k];
                aux_2[0][k]=x;
            }
            else if(aux_2[0][j]->e.a == aux_2[0][k]->e.a)
            {
                if(aux_2[0][j]->e.m < aux_2[0][k]->e.m)
                {
                    x=aux_2[0][j];
                    aux_2[0][j]=aux_2[0][k];
                    aux_2[0][k]=x;
                }
                else if(aux_2[0][j]->e.m == aux_2[0][k]->e.m)
                {
                    if(aux_2[0][j]->e.d < aux_2[0][k]->e.d)
                    {
                        x=aux_2[0][j];
                        aux_2[0][j]=aux_2[0][k];
                        aux_2[0][k]=x;
                    }
                }
            }
            j++;
        }
        k++;
    }
    k=0;
    j=0;
    while(k<m[1])
    {
        j=k+1;
        while(j<m[1])
        {
            if(aux_2[1][j]->e.a < aux_2[1][k]->e.a)
            {
                x=aux_2[1][j];
                aux_2[1][j]=aux_2[1][k];
                aux_2[1][k]=x;
            }
            else if(aux_2[1][j]->e.a == aux_2[1][k]->e.a)
            {
                if(aux_2[1][j]->e.m < aux_2[1][k]->e.m)
                {
                    x=aux_2[1][j];
                    aux_2[1][j]=aux_2[1][k];
                    aux_2[1][k]=x;
                }
                else if(aux_2[1][j]->e.m == aux_2[1][k]->e.m)
                {
                    if(aux_2[1][j]->e.d < aux_2[1][k]->e.d)
                    {
                        x=aux_2[1][j];
                        aux_2[1][j]=aux_2[1][k];
                        aux_2[1][k]=x;
                    }
                }
            }
            j++;
        }
        k++;
    }
    k=0;
    j=0;
    while(k<m[2])
    {
        j=k+1;
        while(j<m[2])
        {
            if(aux_2[2][j]->e.a < aux_2[2][k]->e.a)
            {
                x=aux_2[2][j];
                aux_2[2][j]=aux_2[2][k];
                aux_2[2][k]=x;
            }
            else if(aux_2[2][j]->e.a == aux_2[2][k]->e.a)
            {
                if(aux_2[2][j]->e.m < aux_2[2][k]->e.m)
                {
                    x=aux_2[2][j];
                    aux_2[2][j]=aux_2[2][k];
                    aux_2[2][k]=x;
                }
                else if(aux_2[2][j]->e.m == aux_2[2][k]->e.m)
                {
                    if(aux_2[2][j]->e.d < aux_2[2][k]->e.d)
                    {
                        x=aux_2[2][j];
                        aux_2[2][j]=aux_2[2][k];
                        aux_2[2][k]=x;
                    }
                }
            }
            j++;
        }
        k++;
    }
    k=0;
    j=0;
    while(k<m[3])
    {
        j=k+1;
        while(j<m[3])
        {
            if(aux_2[3][j]->e.a < aux_2[3][k]->e.a)
            {
                x=aux_2[3][j];
                aux_2[3][j]=aux_2[3][k];
                aux_2[3][k]=x;
            }
            else if(aux_2[3][j]->e.a == aux_2[3][k]->e.a)
            {
                if(aux_2[3][j]->e.m < aux_2[3][k]->e.m)
                {
                    x=aux_2[3][j];
                    aux_2[3][j]=aux_2[3][k];
                    aux_2[3][k]=x;
                }
                else if(aux_2[3][j]->e.m == aux_2[3][k]->e.m)
                {
                    if(aux_2[3][j]->e.d < aux_2[3][k]->e.d)
                    {
                        x=aux_2[3][j];
                        aux_2[3][j]=aux_2[3][k];
                        aux_2[3][k]=x;
                    }
                }
            }
            j++;
        }
        k++;
    }
    k=0;
    j=0;
    while(k<m[0])
    {
        aux[k]=aux_2[0][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1])
    {
        aux[k]=aux_2[1][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1]+m[2])
    {
        aux[k]=aux_2[2][j];
        k++;
        j++;
    }
    j=0;
    while(k<m[0]+m[1]+m[2]+m[3])
    {
        aux[k]=aux_2[3][j];
        k++;
        j++;
    }
    lista.Primeiro->prox=aux[0];
    for(i=0; i<count; i++)
    {
        if(i==count-1)
        {
            aux[i]->prox=NULL;
        }
        else
        {
            aux[i]->prox=aux[i+1];
        }
    }
    lista.Ultimo=aux[count-1];


}

void Ordena_Data_Tipo(TipoLista lista, int count)
{
    Apontador aux[count], ler, x;
    int i=0, j=0, k, m, n, o;
    ler=lista.Primeiro->prox;
    while(i<count)
    {
        aux[i]=ler;
        ler=ler->prox;
        i++;
    }
    while(j<count)
    {
        k=j+1;
        while(k<count)
        {
            if(aux[k]->e.a < aux[j]->e.a)
            {
                x=aux[j];
                aux[j]=aux[k];
                aux[k]=x;
            }
            else if(aux[k]->e.a == aux[j]->e.a)
            {
                if(aux[k]->e.m < aux[j]->e.m)
                {
                    x=aux[j];
                    aux[j]=aux[k];
                    aux[k]=x;
                }
                else if(aux[k]->e.m == aux[j]->e.m)
                {
                    if(aux[k]->e.d < aux[j]->e.d)
                    {
                        x=aux[j];
                        aux[j]=aux[k];
                        aux[k]=x;
                    }
                }

            }
            k++;
        }
        j++;
    }
    n=0;
    m=0;
    o=0;
    while(n<count)
    {
        n=m;
        while(m<count && (aux[m]->e.a == aux[n]->e.a) && (aux[m]->e.m == aux[n]->e.m) && (aux[m]->e.d == aux[n]->e.d))
        {
            m++;
        }
        if((m-n)!= 1)
        {
            while(n<m-1)
            {
                o=n;
                while(o<m)
                {
                    if((aux[n]->e.t!='V') && (aux[o]->e.t < aux[n]->e.t))
                    {
                        x=aux[o];
                        aux[o]=aux[n];
                        aux[n]=x;
                    }
                    else if((aux[n]->e.t == 'V') && (aux[o]->e.t == 'A' || aux[o]->e.t == 'F'))
                    {
                        x=aux[o];
                        aux[o]=aux[n];
                        aux[n]=x;
                    }
                    o++;
                }
                n++;
            }
        }
    }

    lista.Primeiro->prox=aux[0];
    for(i=0; i<count; i++)
    {
        if(i==count-1)
        {
            aux[i]->prox=NULL;
        }
        else
        {
            aux[i]->prox=aux[i+1];
        }
    }
    lista.Ultimo=aux[count-1];
}

int verifica_bissexto(int ano)
{
    if(ano%4==0 && ano%100!=0)
    {
        return 1;
    }
    else if(ano%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mes(int mes, char nome[], int *d, int a, int idioma)
{
    if(mes==1)
    {
        if(idioma==1)
        {
            strcpy(nome, "Janeiro");
        }
        else
        {
            strcpy(nome, "January");
        }
        *d=31;
    }
    else if(mes==2)
    {
        if(idioma==1)
        {
            strcpy(nome, "Fevereiro");
        }
        else
        {
            strcpy(nome, "February");
        }

        if(verifica_bissexto(a)==1)
        {
            *d=29;
        }
        else if(verifica_bissexto(a)==0)
        {
            *d=28;
        }
    }
    else if(mes==3)
    {
        if(idioma==1)
        {
            strcpy(nome, "Marco");
        }
        else
        {
            strcpy(nome, "March");
        }

        *d=31;
    }
    else if(mes==4)
    {
        if(idioma==1)
        {
            strcpy(nome, "Abril");
        }
        else
        {
            strcpy(nome, "April");
        }

        *d=30;
    }
    else if(mes==5)
    {
        if(idioma==1)
        {
            strcpy(nome, "Maio");
        }
        else
        {
            strcpy(nome, "May");
        }

        *d=31;
    }
    else if(mes==6)
    {
        if(idioma==1)
        {
            strcpy(nome, "Junho");
        }
        else
        {
            strcpy(nome, "June");
        }

        *d=30;
    }
    else if(mes==7)
    {
        if(idioma==1)
        {
            strcpy(nome, "Julho");
        }
        else
        {
            strcpy(nome, "July");
        }

        *d=31;
    }
    else if(mes==8)
    {
        if(idioma==1)
        {
            strcpy(nome, "Agosto");
        }
        else
        {
            strcpy(nome, "August");
        }

        *d=31;
    }
    else if(mes==9)
    {
        if(idioma==1)
        {
            strcpy(nome, "Setembro");
        }
        else
        {
            strcpy(nome, "September");
        }

        *d=30;
    }
    else if(mes==10)
    {
        if(idioma==1)
        {
            strcpy(nome, "Outubro");
        }
        else
        {
            strcpy(nome, "October");
        }

        *d=31;
    }
    else if(mes==11)
    {
        if(idioma==1)
        {
            strcpy(nome, "Novembro");
        }
        else
        {
            strcpy(nome, "November");
        }

        *d=30;
    }
    else if (mes==12)
    {
        if(idioma==1)
        {
            strcpy(nome, "Dezembro");
        }
        else
        {
            strcpy(nome, "December");
        }

        *d=31;
    }
}

void GeraPDF(int m, int ano, TipoLista L, int idioma)
{
    int titulo, x_titulo, x_ant, x_prox, dias_anterior, mes_anterior, semana_anterior, anterior, proximo, d, b, c, aux, semana,j=0, a[42],i=1, fundo;
    char dia[42][3], a_1[2], week_1[7][2];
    char nome_mes[18], nome_mes_anterior[18], string_ano[5];
    CHAR_SEMANA(week_1, idioma);
    if(idioma==1)
    {
        printf("Deseja posicionar o titulo do calendario a:\n1:Esquerda\n2:Centro\n3:Direita\n");
    }
    else
    {
        printf("Do you want the title of the calendar at:\n1:Left\n2:Center\n3:Right\n");
    }
    scanf("%d", &titulo);
    system("cls");
    if(idioma==1)
    {
        printf("Deseja adicionar a visualizacao do mes anterior?\n1:Sim\n2:Nao\n");
    }
    else
    {
        printf("Do you want to add the view of the previous month?\n1:Yes\n2:No\n");
    }
    scanf("%d", &anterior);
    system("cls");
    if(idioma==1)
    {
        printf("Deseja adicionar a visualizacao do proximo mes?\n1:Sim\n2:Nao\n");
    }
    else
    {
        printf("Do you want to add the view of the next month?\n1:Yes\n2:No\n");
    }
    scanf("%d", &proximo);
    system("cls");
    if(idioma==1)
    {
        printf("Deseja adicionar um fundo nos finais de semana?\n1:Sim\n2:Nao\n");
    }
    else
    {
        printf("Do you want to add a background at the weekends?\n1:Yes\n2:No\n");
    }
    scanf("%d", &fundo);
    system("cls");
    if(titulo==1)
    {
        if(idioma==1)
        {
            x_titulo=85;
        }
        else
        {
            x_titulo=85;
        }
        x_ant=480;
        x_prox=650;
    }
    else if(titulo==2)
    {
        x_ant = 52;
        x_prox=650;
        if(m==1)
        {
            if(idioma==1)
            {
                x_titulo=297;
            }
            else
            {
                x_titulo=290;
            }

        }
        else if(m==2)
        {
            if(idioma==1)
            {
                x_titulo=272;
            }
            else
            {
                x_titulo=274;
            }

        }
        else if(m==3)
        {
            if(idioma==1)
            {
                x_titulo=300;
            }
            else
            {
                x_titulo=300;
            }

        }
        else if(m==4)
        {
            if(idioma==1)
            {
                x_titulo=320;
            }
            else
            {
                x_titulo=320;
            }

        }
        else if(m==5)
        {
            if(idioma==1)
            {
                x_titulo=310;
            }
            else
            {
                x_titulo=315;
            }

        }
        else if(m==6)
        {
            if(idioma==1)
            {
                x_titulo=300;
            }
            else
            {
                x_titulo=307;
            }

        }
        else if(m==7)
        {
            if(idioma==1)
            {
                x_titulo=307;
            }
            else
            {
                x_titulo=312;
            }

        }
        else if(m==8)
        {
            if(idioma==1)
            {
                x_titulo=300;
            }
            else
            {
                x_titulo=300;
            }

        }
        else if(m==9)
        {
            if(idioma==1)
            {
                x_titulo=268;
            }
            else
            {
                x_titulo=259;
            }

        }
        else if(m==10)
        {
            if(idioma==1)
            {
                x_titulo=285;
            }
            else
            {
                x_titulo=285;
            }

        }
        else if(m==11)
        {
            if(idioma==1)
            {
                x_titulo=268;
            }
            else
            {
                x_titulo=265;
            }

        }
        else if (m==12)
        {
            if(idioma==1)
            {
                x_titulo=268;
            }
            else
            {
                x_titulo=265;
            }

        }
    }
    else if(titulo==3)
    {
        x_ant=52;
        x_prox=222;
        if(m==1)
        {
            if(idioma==1)
            {
                x_titulo=530;
            }
            else
            {
                x_titulo=527;
            }

        }
        else if(m==2)
        {
            if(idioma==1)
            {
                x_titulo=495;
            }
            else
            {
                x_titulo=495;
            }

        }
        else if(m==3)
        {
            if(idioma==1)
            {
                x_titulo=540;
            }
            else
            {
                x_titulo=540;
            }

        }
        else if(m==4)
        {
            if(idioma==1)
            {
                x_titulo=575;
            }
            else
            {
                x_titulo=575;
            }

        }
        else if(m==5)
        {
            if(idioma==1)
            {
                x_titulo=575;
            }
            else
            {
                x_titulo=575;
            }

        }
        else if(m==6)
        {
            if(idioma==1)
            {
                x_titulo=560;
            }
            else
            {
                x_titulo=560;
            }
        }
        else if(m==7)
        {
            if(idioma==1)
            {
                x_titulo=560;
            }
            else
            {
                x_titulo=560;
            }

        }
        else if(m==8)
        {
            if(idioma==1)
            {
                x_titulo=530;
            }
            else
            {
                x_titulo=530;
            }

        }
        else if(m==9)
        {
            if(idioma==1)
            {
                x_titulo=485;
            }
            else
            {
                x_titulo=485;
            }

        }
        else if(m==10)
        {
            if(idioma==1)
            {
                x_titulo=520;
            }
            else
            {
                x_titulo=520;
            }

        }
        else if(m==11)
        {
            if(idioma==1)
            {
                x_titulo=485;
            }
            else
            {
                x_titulo=485;
            }

        }
        else if (m==12)
        {
            if(idioma==1)
            {
                x_titulo=485;
            }
            else
            {
                x_titulo=485;
            }

        }

    }
    mes(m, nome_mes, &d, ano, idioma);
    itoa(ano,string_ano,10);
    strcat(nome_mes, " ");
    strcat(nome_mes, string_ano);
    semana=dia_semana(ano,m,1);
    mes_anterior=m-1; // CONFERE O MES ANTERIOR AQUI
    if(mes_anterior==0)
    {
        mes_anterior=12;
        ano--;
    }
    mes(mes_anterior, nome_mes_anterior, &dias_anterior, ano, idioma); //Pegamos a string com o nome do mes anterior e mudamos o conteudo de dias do mes anterior para o valor correto
    itoa(ano, string_ano, 10);
    strcat(nome_mes_anterior, " ");
    strcat(nome_mes_anterior, string_ano);
    if(anterior==1)
    {
        semana_anterior=dia_semana(ano, mes_anterior, 1);
    }
    if(mes_anterior==12)
    {
        ano++;
    }
    while(j<semana-1)  //PREENCHE O VETOR COM OS NUMEROS DOS DIAS -> ULTIMA SEMANA DO MES ANTERIOR
    {
        a[j]=dias_anterior-(7-(9-semana))+j;
        itoa(a[j], dia[j], 10);
        j++;
    }
    while(i<=d)  //PREENCHE O VETOR COM OS NUMEROS DOS DIAS -> MES PRINCIPAL
    {
        a[j]=i;
        if(a[j]<10)
        {
            strcpy(dia[j], "0");
            itoa(a[j], a_1, 10);
            strcat(dia[j], a_1);
        }
        else
        {
            itoa(a[j], dia[j], 10);
        }
        j++;
        i++;
    }
    i=1;
    while(j<42)  //PREENCHE O VETOR COM OS DIAS DA PRIMEIRA SEMANA DO PROXIMO MES
    {
        a[j]=i;
        if(a[j]<10)
        {
            strcpy(dia[j], "0");
            itoa(a[j], a_1, 10);
            strcat(dia[j], a_1);
        }
        else
        {
            itoa(a[j], dia[j], 10);
        }
        i++;
        j++;
    }

    struct pdf_info info = //Necessário para a confecção do PDF
    {
        .creator = "Calendário.c",
        .producer = "Calendário.c",
        .title = "Calendario.c",
        .author = "Daniel e Frederico",
        .subject = nome_mes,
        .date = "Hoje"
    };
    struct pdf_doc *pdf = pdf_create(PDF_A4_HEIGHT, PDF_A4_WIDTH, &info);
    pdf_set_font(pdf, "Times_Roman");
    pdf_append_page(pdf);
    if(fundo==1)
    {
        pdf_add_jpeg(pdf, NULL, 0, 0, 842, 595, "./fundo_cor.jpg");
    }
    else
    {
        pdf_add_jpeg(pdf, NULL, 0, 0, 842, 595, "./fundo.jpg");
    }

    j=0;
    b=135;
    c=440;
    for(aux=0, c=440; aux<42; aux=aux+7, c=c-71)
    {
        for(j=aux, b=135; j<aux+7; j++, b=b+106)
        {
            if((a[j]>7 && c==440) || (a[j]<=14 && c<=440-4*(71)))
            {
                pdf_add_text(pdf, NULL, dia[j], 15, b, c, PDF_RGB(169, 169, 169));
            }
            else if(((b==135 || b==135+6*(106)) || ((b==135 || b==135+6*(106))&&((a[j]=1 && c==440)||(a[j]>14 && c<=440-4*(71)))))&&fundo==1)
            {
                pdf_add_text(pdf, NULL, dia[j], 15, b, c, PDF_RGB(255, 0, 0));
                if(VerificaListaVazia(L)==0)
                {
                    imprimir_eventos(pdf, atoi(dia[j]), b, c, L, PDF_RGB(255, 0, 0));
                }
            }
            else
            {
                pdf_add_text(pdf, NULL, dia[j], 15, b, c, PDF_BLACK);
                if(VerificaListaVazia(L)==0)
                {
                    imprimir_eventos(pdf, atoi(dia[j]), b, c, L, PDF_BLACK);
                }
            }
        }
    }
    pdf_add_text(pdf, NULL, nome_mes, 40, x_titulo, 510, PDF_BLACK);
    if(anterior==1)
    {
        if(proximo==2 && titulo==1)
        {
            x_ant=x_prox;
        }
        int k[dias_anterior];
        char str_ant[42][3], auxiliar[3];
        for(j=0; j<dias_anterior; j++)
        {
            k[j]=j+1;
        }
        j=0;
        int p[7], x_1, n_1;
        char n[10];
        if(mes_anterior==0)
        {
            mes_anterior=11;
        }
        else
        {
            mes_anterior--;
        }
        mes(mes_anterior, n, &n_1, x_1, idioma);
        while(j<semana_anterior-1)
        {
            p[j]=n_1-(7-(9-semana_anterior))+j;
            itoa(p[j], str_ant[j], 10);
            j++;
        }
        int q=j;
        i=0;
        while(j<q+dias_anterior)
        {
            if(k[i]<10)
            {
                strcpy(str_ant[j], "0");
                itoa(k[i], auxiliar, 10);
                strcat(str_ant[j], auxiliar);
            }
            else
            {
                itoa(k[i], str_ant[j], 10);
            }
            i++;
            j++;
        }
        int f[12];
        i=1;
        while(j<42)
        {
            if(i<10)
            {
                strcpy(str_ant[j], "0");
                f[i-1]=i;
                itoa(f[i-1], auxiliar, 10);
                strcat(str_ant[j], auxiliar);
            }
            else
            {
                f[i-1]=i;
                itoa(f[i-1], str_ant[j], 10);
            }
            i++;
            j++;
        }
        if(semana_anterior+dias_anterior==36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior1.jpg");
        }
        else if(semana_anterior==1 && dias_anterior>=29 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior2.jpg");
        }
        else if(semana_anterior+dias_anterior>36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior3.jpg");
        }
        else if(semana_anterior==1 && dias_anterior==28 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior4.jpg");
        }
        else if(semana_anterior+dias_anterior<36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior5.jpg");
        }
        else if(fundo==2)
        {
            pdf_add_jpeg(pdf, NULL, x_ant, 485, 143, 92, "./Superior6.jpg");
        }

        for(aux=0, c=557; aux<42; aux=aux+7, c=c-12)
        {
            for(j=aux, b=x_ant+12; j<aux+7; j++, b=b+18)
            {
                if((atoi(str_ant[j])>20 && c==557)||(atoi(str_ant[j])<13 && c<557-3*(12)))
                {
                    pdf_add_text(pdf, NULL, str_ant[j], 8, b, c, PDF_RGB(169, 169, 169));
                }
                else
                {
                    pdf_add_text(pdf, NULL, str_ant[j], 8, b, c, PDF_BLACK);
                }

            }
        }
        pdf_add_text(pdf, NULL, nome_mes_anterior, 10, x_ant+8, 582, PDF_BLACK);
        b=x_ant+14;
        c=569;
        j=0;
        while(j<7)
        {
            pdf_add_text(pdf, NULL, week_1[j], 8, b, c, PDF_BLACK);
            j++;
            b=b+18;
        }
    }
    if(proximo==1)
    {
        if(anterior==2 && titulo==3)
        {
            x_prox=x_ant;
        }
        int dias_proximo, proximo_mes, semana_proximo;
        char nome_proximo_mes[18];
        proximo_mes=m+1;
        if(proximo_mes==13)
        {
            proximo_mes=1;
            ano++;
        }
        mes(proximo_mes, nome_proximo_mes, &dias_proximo, ano, idioma);
        semana_proximo=dia_semana(ano, proximo_mes, 1);
        strcat(nome_proximo_mes, " ");
        itoa(ano, string_ano, 10);
        strcat(nome_proximo_mes, string_ano);
        int k[dias_proximo];
        char str_prox[42][3], auxiliar[3];
        for(j=0; j<dias_proximo; j++)
        {
            k[j]=j+1;
        }
        j=0;
        int p[7];
        while(j<semana_proximo-1)
        {
            p[j]=d-(7-(9-semana_proximo))+j;
            itoa(p[j], str_prox[j], 10);
            j++;
        }
        int q=j;
        i=0;
        while(j<q+dias_proximo)
        {
            if(k[i]<10)
            {
                strcpy(str_prox[j], "0");
                itoa(k[i], auxiliar, 10);
                strcat(str_prox[j], auxiliar);
            }
            else
            {
                itoa(k[i], str_prox[j], 10);
            }
            i++;
            j++;
        }
        int f[12];
        i=1;
        while(j<42)
        {
            if(i<10)
            {
                strcpy(str_prox[j], "0");
                f[i-1]=i;
                itoa(f[i-1], auxiliar, 10);
                strcat(str_prox[j], auxiliar);
            }
            else
            {
                f[i-1]=i;
                itoa(f[i-1], str_prox[j], 10);
            }
            i++;
            j++;
        }

        if(semana_proximo+dias_proximo==36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior1.jpg");
        }
        else if(semana_proximo==1 && dias_proximo>=29 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior2.jpg");
        }
        else if(semana_proximo+dias_proximo>36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior3.jpg");
        }
        else if(semana_proximo==1 && dias_proximo==28 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior4.jpg");
        }
        else if(semana_proximo+dias_proximo<36 && fundo!=2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior5.jpg");
        }
        else if(fundo==2)
        {
            pdf_add_jpeg(pdf, NULL, x_prox, 485, 143, 92, "./Superior6.jpg");
        }
        for(aux=0, c=557; aux<42; aux=aux+7, c=c-12)
        {
            for(j=aux, b=x_prox+12; j<aux+7; j++, b=b+18)
            {
                if((atoi(str_prox[j])>20 && c==557)||(atoi(str_prox[j])<13 && c<557-3*(12)))
                {
                    pdf_add_text(pdf, NULL, str_prox[j], 8, b, c, PDF_RGB(169, 169, 169));
                }
                else
                {
                    pdf_add_text(pdf, NULL, str_prox[j], 8, b, c, PDF_BLACK);
                }

            }
        }
        pdf_add_text(pdf, NULL, nome_proximo_mes, 10, x_prox+8, 582, PDF_BLACK);
        b=x_prox+14;
        c=569;
        j=0;
        while(j<7)
        {
            pdf_add_text(pdf, NULL, week_1[j], 8, b, c, PDF_BLACK);
            j++;
            b=b+18;
        }

    }
    preenche_semana(pdf, idioma, fundo);
    pdf_save(pdf, "Calendario.pdf");
    pdf_destroy(pdf);

    system("Calendario.pdf");
}

void Imprime(TipoLista lista)
{
    Apontador aux;
    aux=lista.Primeiro->prox;
    while (aux != NULL)
    {
        printf("%c %d %d %d %s", aux->e.t, aux->e.d, aux->e.m, aux->e.a, aux->e.Desc);
        aux=aux->prox;
    }
    printf("\n \n");
}

void Imprime_Mes(TipoLista lista, int idioma, int ano, int m_1)
{
    Apontador aux;
    aux=lista.Primeiro->prox;
    int month=m_1, days, i=1, str_ano[5],k;
    char nome[18], week[7][19];
    STRING_SEMANA(week, idioma);
    mes(month, nome, &days, ano, idioma);
    printf("%s %d\n", nome, ano);
    if(idioma==1)
    {
        if(aux->e.d==0)
        {
            printf("Os eventos a seguir ocorrem todos os dias do mes:\n");
            while(aux!=NULL && aux->e.d==0)
            {
                if(aux->e.t=='O')
                {
                printf("\t%s", aux->e.Desc);
                }
                else
                {
                    printf("\t%c %s", aux->e.t, aux->e.Desc);
                }
                aux=aux->prox;
            }
        }
        printf("\nDia\tEventos\n\n");
        while(i<=days)
        {
            k=dia_semana(ano, month, i);
            if(i<10)
            {
                printf("0%d %s\n", i, week[k-1]);
            }
            else
            {
                printf("%d %s\n", i, week[k-1]);
            }
            if(aux!=NULL && aux->e.d==i)
            {
                while(aux!=NULL && aux->e.d==i)
                {
                    if(aux->e.t!='O')
                    {
                        printf("\t%c %s", aux->e.t, aux->e.Desc);
                    }
                    else
                    {
                        printf("\t%s", aux->e.Desc);
                    }
                    aux=aux->prox;
                }
            }
            i++;
        }
    }
    else
    {
        if(aux->e.d==0)
        {
            printf("The following events happens every day in the month:\n");
            while(aux->e.d==0)
            {
                printf("\t%c %s", aux->e.t, aux->e.Desc);
                aux=aux->prox;
            }
        }
        printf("\nDay\tEvents\n\n");
        while(i<=days)
        {
            k=dia_semana(ano, month, i);
            if(i<10)
            {
                printf("0%d %s\n", i, week[k-1]);
            }
            else
            {
                printf("%d %s\n", i, week[k-1]);
            }
            if(aux!=NULL && aux->e.d==i)
            {
                while(aux!=NULL && aux->e.d==i)
                {
                    if(aux->e.t!='O')
                    {
                        printf("\t%c %s", aux->e.t, aux->e.Desc);
                    }
                    else
                    {
                        printf("\t%s", aux->e.Desc);
                    }
                    aux=aux->prox;
                }
            }
            i++;
        }

    }
    printf("\n \n");
}

void Imprime_Tipo(TipoLista lista, char c, int idioma)
{
    Apontador aux;
    aux=lista.Primeiro->prox;
    if(idioma==1)
    {
        printf("Os eventos do tipo %c existentes sao:\n", c);
    }
    else
    {
        printf("The events of the category %c are:\n", c);
    }
    while (aux != NULL)
    {
        printf("%d %d %d %s", aux->e.d, aux->e.m, aux->e.a, aux->e.Desc);
        aux=aux->prox;
    }
    printf("\n \n");
}

void Imprime_Data(TipoLista lista, int dia, int mes, int ano, int idioma)
{
    Apontador aux;
    aux=lista.Primeiro->prox;
    if(idioma==1)
    {
        printf("Os eventos do dia %d/%d/%d sao:\n", dia, mes, ano);
    }
    else
    {
        printf("The events of the day %d/%d/%d are:\n", dia, mes, ano);
    }
    if(VerificaListaVazia(lista)==1){
    while (aux != NULL)
    {
        printf("%c %s", aux->e.t, aux->e.Desc);
        aux=aux->prox;
    }
    }
    printf("\n \n");
}

void cria_TAD_mensal(Mes mes, Ano ano, char aux[], int b, int idioma)
{
    int p[4], w;
    if(idioma==1)
    {
        printf("Deseja imprimir os eventos do tipo A?\n1:Sim\n2:Nao\n");
        scanf("%d", &p[0]);
        system("cls");
        printf("Deseja imprimir os eventos do tipo F?\n1:Sim\n2:Nao\n");
        scanf("%d", &p[1]);
        system("cls");
        printf("Deseja imprimir os eventos do tipo V?\n1:Sim\n2:Nao\n");
        scanf("%d", &p[2]);
        system("cls");
        printf("Deseja imprimir os eventos do tipo O?\n1:Sim\n2:Nao\n");
        scanf("%d", &p[3]);
        system("cls");
    }
    else
    {
        printf("Do you want to print the A events?\n1:Yes\n2:No\n");
        scanf("%d", &p[0]);
        system("cls");
        printf("Do you want to print the F events?\n1:Yes\n2:No\n");
        scanf("%d", &p[1]);
        system("cls");
        printf("Do you want to print the V events?\n1:Yes\n2:No\n");
        scanf("%d", &p[2]);
        system("cls");
        printf("Do you want to print the O events?\n1:Yes\n2:No\n");
        scanf("%d", &p[3]);
        system("cls");

    }
    FILE *pfile = fopen(aux,"r");
    char tipof, descf[MAX_DESC];
    int df, mf, af, count=0;
    Evento x;
    TipoLista L;
    FLVazia(&L);
    while(!feof(pfile))
    {
        fscanf(pfile,"%c %d %d %d ", &tipof, &df, &mf, &af);
        w=0;
        if(tipof=='A' && p[0]==1)
        {
            w=1;
        }
        else if(tipof=='F' && p[1]==1)
        {
            w=1;
        }
        else if(tipof=='V' && p[2]==1)
        {
            w=1;
        }
        else if(tipof=='O' && p[3]==1)
        {
            w=1;
        }
        fgets(descf,MAX_DESC,pfile);
        if((mf==mes || mf==0)&&(af==ano || af==0) && w==1)
        {
            x.a=af;
            x.m=mf;
            x.d=df;
            x.t=tipof;
            strcpy(x.Desc, descf);
            Insere(x,&L);
            count++;
        }

    }
    fclose(pfile);
    if((mf==mes || mf==0) && w==1)
    {
        count--;
    }
    if(count!=0){
    Ordena_Mes(L,count);
    }
    if(b==1)
    {
        Imprime_Mes(L, idioma, ano, mes);
    }
    else if(b==2)
    {
        GeraPDF(mes, ano, L, idioma);
    }
}

void Ordena_Imprime(int idioma, char aux[])
{
    FILE *pfile = fopen(aux, "r");
    char tipof, descf[MAX_DESC];
    int df, mf, af, count=0, ordenar;
    Evento x;
    TipoLista L;
    FLVazia(&L);
    while(!feof(pfile))
    {
        fscanf(pfile,"%c %d %d %d ", &tipof, &df, &mf, &af);
        fgets(descf,MAX_DESC,pfile);
        x.a=af;
        x.m=mf;
        x.d=df;
        x.t=tipof;
        strcpy(x.Desc, descf);
        Insere(x,&L);
        count++;
    }
    count--;
    if(idioma==1)
    {
        printf("Deseja ordenar por:\n1:Tipo\n2:Data\n");
    }
    else
    {
        printf("Do you want to sort by:\n1:Type\n2:Date\n");
    }
    scanf("%d", &ordenar);
    system("cls");
    if(ordenar==1)
    {
        if(count!=0){
        Ordena_Tipo_Data(L, count);
        }
        Imprime(L);
    }
    else
    {   if(count!=0){
        Ordena_Data_Tipo(L, count);
        }
        Imprime(L);
    }
}

void pesquisa_eventos(int idioma, char aux[])
{
    int pesquisa, df, af, mf, count=0;
    char tipof, descf[MAX_DESC];
    FILE *pfile = fopen(aux, "r");
    TipoLista L;
    FLVazia(&L);
    Evento x;
    if(idioma==1)
    {
        printf("Desja pesquisar os eventos por:\n1:Data\n2:Tipo\n");
    }
    else
    {
        printf("Do you want to research the events by:\n1:Date\n2:Type\n");
    }
    scanf("%d", &pesquisa);
    system("cls");
    if(pesquisa==1)
    {
        int dia, mes, ano;
        if(idioma==1)
        {
            printf("Insira o dia:\n");
            scanf("%d", &dia);
            system("cls");
            printf("Insira o mes:\n");
            scanf("%d", &mes);
            system("cls");
            printf("Insira o ano:\n");
            scanf("%d", &ano);
            system("cls");
        }
        else
        {
            printf("Enter the day:\n");
            scanf("%d", &dia);
            fflush(stdin);
            system("cls");
            printf("Enter the month:\n");
            scanf("%d", &mes);
            fflush(stdin);
            system("cls");
            printf("Enter the year:\n");
            fflush(stdin);
            scanf("%d", &ano);
            system("cls");
        }
        while(!feof(pfile))
        {
            fscanf(pfile,"%c %d %d %d ", &tipof, &df, &mf, &af);
            fgets(descf,MAX_DESC,pfile);
            if((mf==mes || mf==0)&&(af==ano || af==0)&&(df==dia || df==0))
            {
                x.a=af;
                x.m=mf;
                x.d=df;
                x.t=tipof;
                strcpy(x.Desc, descf);
                Insere(x,&L);
                count++;
            }

        }
        if((af==ano || af==0) && (df==dia || df==0) && (mf==mes || mf==0))
        {
            count--;
        }
        fclose(pfile);
        if(count!=0){
        Ordena_Tipo(L, count);
        }
        Imprime_Data(L, dia, mes, ano, idioma);

    }
    else
    {
        char c;
        if(idioma==1)
        {
            printf("Insira o tipo de evento que deseja pesquisar (A, F, V ou O)\n");
        }
        else
        {
            printf("Enter the type of event you want to research (A, F, V ou O)\n");
        }
        fflush(stdin);
        scanf("%c", &c);
        system("cls");
        while(!feof(pfile))
        {
            fscanf(pfile,"%c %d %d %d ", &tipof, &df, &mf, &af);
            fgets(descf,MAX_DESC,pfile);
            if(c==tipof)
            {
                x.a=af;
                x.m=mf;
                x.d=df;
                x.t=tipof;
                strcpy(x.Desc, descf);
                Insere(x,&L);
                count++;
            }

        }
        fclose(pfile);
        if(tipof==c)
        {
            count--;
        }
        if(count!=0){
        Ordena_Data(L, count);
        }
        Imprime_Tipo(L, c, idioma);
    }
}
