#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>


int unidadeToNum(char unidade); //Converte unidade de letra para expoente Ex: G para 30
char numToUnidade(int num); //Converte unidade de expoente para letra Ex 30 para G
void exercicio1(); //Executa funções do exercício 01

int main()
{
    exercicio01();

    return 0;

}


int unidadeToNum(char unidade)
{
    switch (unidade)
    {
    case 'K':
    case 'k':
        return 10;
        break;
    case 'M':
    case 'm':
        return 20;
        break;
    case 'G':
    case 'g':
        return 30;
        break;
    case 'T':
    case 't':
        return 40;
        break;
    case 'E':
    case 'e':
        return 50;
        break;
    case 'P':
    case 'p':
        return 60;
        break;
    case 'Z':
    case 'z':
        return 70;
        break;
    case 'Y':
    case 'y':
        return 80;
        break;
    default:
        return 0;
        break;
    }
}
char numToUnidade(int num)
{
    switch (num)
    {
    case 10:
        return 'K';
        break;
    case 20:
        return 'M';
        break;
    case 30:
        return 'G';
        break;
    case 40:
        return 'T';
        break;
    case 50:
        return 'P';
        break;
    case 60:
        return 'E';
        break;
    case 70:
        return 'Z';
        break;
    case 80:
        return 'Y';
        break; 
    default:
        return ' ';
        break;
    }
}

void exercicio01()
{
    /*Exercício 01 - solicita a quantidade de celulas da
    memória com unidade e o tamanho da célula em bits e retorna
    a capacidade total da memória
    */
    double qntdEnderecos, tamanhoEndereco;
    char unidadeEnderecos;
    int unidade=0;
    printf("\n---------- Exercício 01 ----------\n");

    printf("Digite a quantidade de endereços da memória (sem a unidade): \n");
    scanf("%lf", &qntdEnderecos);

    printf("Digite a unidade da quantidade de endereços da memória: ");
    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    scanf("%s", &unidadeEnderecos);

    printf("Digite o tamanho de cada endereco em bits: \n");
    scanf("%lf", &tamanhoEndereco);
    
    double totalQntdEnd = qntdEnderecos * pow(2, unidadeToNum(unidadeEnderecos));
    double tamanhoBytes = tamanhoEndereco / 8;
    double capacidadeBytes = totalQntdEnd * tamanhoBytes;
    if(capacidadeBytes >= 1024)
    {
        while(capacidadeBytes >= 1024)
        {
            capacidadeBytes = (capacidadeBytes/1024);
            unidade+=10;
        }
        printf("A capacidade em bytes é: %.2lf %c Bytes", capacidadeBytes, numToUnidade(unidade));
    }
    else{
        printf("A capacidade em bytes é: %.2lfBytes", capacidadeBytes);
    }
}