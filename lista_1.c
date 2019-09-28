#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int unidadeToNum(char unidade); //Converte unidade de letra para expoente Ex: G para 30
char numToUnidade(int num); //Converte unidade de expoente para letra Ex 30 para G
void exercicio01();//Executa funções do exercício 01
void exercicio02();//Executa funções do exercício 02
void exercicio03();//Executa funções do exercício 03
void exercicio04();//Executa funções do exercício 04


int main()
{
    printf("\n##### EXERCICIO 01 #####\n");
    exercicio01();
    printf("\n##### EXERCICIO 02 #####\n");
    exercicio02();
    printf("\n##### EXERCICIO 03 #####\n");
    exercicio03();
    printf("\n##### EXERCICIO 04 #####\n");
    exercicio04();
    return 0;
}
void exercicio04(){
    double tamanho_MP;
    printf("Digite o tamanho da memoria principal em bytes e sem unidade: ");
    scanf("%lf", &tamanho_MP);

    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    printf("Digite a unidade do tamanho acima: ");
    char unidade_MP;
    scanf("%s", &unidade_MP);
    double total_MP = tamanho_MP * pow(2, unidadeToNum(unidade_MP));

    double tamanho_MC;
    printf("Digite o tamanho da memoria cache em bytes e sem unidade: ");
    scanf("%lf", &tamanho_MC);

    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    printf("Digite a unidade do tamanho acima: ");
    char unidade_cache;
    scanf("%s", &unidade_cache);
    double total_MC = tamanho_MC * pow(2, unidadeToNum(unidade_cache));

    printf("Digite a largura da linha da memoria cache em bytes: ");
    double largura_linha_cache;
    scanf("%lf", &largura_linha_cache);

    printf("Digite a quantidade de linhas por conjunto: ");
    int linhas_conjunto;
    scanf("%d",&linhas_conjunto);

    double total_linhas_cache = total_MC / largura_linha_cache;
    double total_conjuntos = total_linhas_cache / linhas_conjunto;
    double total_blocos = total_MP / largura_linha_cache;
    double tag = log2((total_blocos / total_conjuntos));
    double total_tag = tag * total_linhas_cache;
    double total_MC_b = total_MC * 8;
    double total_bits_cache = total_MC_b + total_tag;
    int unidade_total_cache = 0;
    if(total_bits_cache > 1024){
        while(total_bits_cache > 2048){
            total_bits_cache = total_bits_cache / 1024;
            unidade_total_cache += 10;
        }
    }
    printf("Total de bits para implementacao da cache eh: %.0lf %cbits", total_bits_cache, numToUnidade(unidade_total_cache));
}
void exercicio03(){
    double tamanho_MP;
    printf("Digite o tamanho da memoria principal em bytes e sem unidade: ");
    scanf("%lf", &tamanho_MP);

    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    printf("Digite a unidade do tamanho acima: ");
    char unidade_MP;
    scanf("%s", &unidade_MP);
    double total_MP = tamanho_MP * pow(2, unidadeToNum(unidade_MP));

    double tamanho_MC;
    printf("Digite o tamanho da memoria cache em bytes e sem unidade: ");
    scanf("%lf", &tamanho_MC);


    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    printf("Digite a unidade do tamanho acima: ");
    char unidade_cache;
    scanf("%s", &unidade_cache);
   
    double total_MC = tamanho_MC * pow(2, unidadeToNum(unidade_cache));

    printf("Digite a largura da linha da memoria cache em bytes: ");
    double largura_linha_cache;
    scanf("%lf", &largura_linha_cache);

    double palavra = log2(largura_linha_cache);
    double total_linhas_cache = total_MC / largura_linha_cache;
    double tag = log2(total_MP / largura_linha_cache);
    double total_tag = tag * total_linhas_cache;
    double total_MC_b = total_MC * 8;
    double total_bits_cache = total_MC_b + total_tag;
    int unidade_total_cache=0;
    if(total_bits_cache > 1024){
        while(total_bits_cache > 2048){
            total_bits_cache = total_bits_cache / 1024;
            unidade_total_cache += 10;
        }
    }
    printf("Total de bits para implementacao da cache eh: %.0lf %cbits", total_bits_cache, numToUnidade(unidade_total_cache));
}
void exercicio02(){
    /*Elabore  um  programa  para  calcular  e  mostrar  o  formato  de  endereço  de  um  
    computador  com memória cache utilizando o mapeamento direto.
    */
        printf("\n---------- Exercicio 02 ----------\n");

    //Ler tamanho da MP
    printf("Digite o tamanho da memoria principal sem a unidade: ");
    double Tamanho_Mp;
    scanf("%lf", &Tamanho_Mp);
    printf("\nAspas vazias ('') para sem unidade\nK para Kilo\nM para Mega\nG para Giga\nT para Tera\n");
    printf("Digite a unidade do tamanho acima: ");
    char Unidade;
    scanf("%s", &Unidade);
    //Qnt linhas da cache
    printf("Digite a quantidade de linhas da cache: ");
    double QntLinhas;
    scanf("%lf", &QntLinhas);
    //Largura da linha da cache em bytes
    printf("Digite a largura da linha da cache em BYTES: ");
    double LarguraLinhaCache;
    scanf("%lf", &LarguraLinhaCache);
    //Calculos
    double Total_MP = Tamanho_Mp * pow(2,unidadeToNum(Unidade));
    double EnderecoMPb = log2(Total_MP);
    double EnderecoPalavrab = log2(LarguraLinhaCache);
    double EnderecoLinha = log2(QntLinhas);
    double EnderecoTagb = EnderecoMPb - (EnderecoLinha + EnderecoPalavrab);

    printf("Endereco Total: %.0lf bits\n", EnderecoMPb);
    printf("Endereco Palavra: %.0lf bits\n", EnderecoPalavrab);
    printf("Endereco Linha: %.0lf bits\n", EnderecoLinha);
    printf("Endereco Tag: %.0lf bits\n", EnderecoTagb);
}
int unidadeToNum(char unidade){
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
char numToUnidade(int num){
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
void exercicio01(){
    /*Exercício 01 - solicita a quantidade de celulas da
    memória com unidade e o tamanho da célula em bits e retorna
    a capacidade total da memória
    */
    printf("\n---------- Exercício 01 ----------\n");
    double qntdEnderecos, tamanhoEndereco;
    char unidadeEnderecos;
    int unidade=0;

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
    if(capacidadeBytes >= 1024){
        while(capacidadeBytes >= 1024)
        {
            capacidadeBytes = (capacidadeBytes/1024);
            unidade+=10;
        }
        printf("A capacidade em bytes é: %.2lf %c Bytes\n", capacidadeBytes, numToUnidade(unidade));
        printf("O tamanho do REM eh: %lf bits\n", log2(totalQntdEnd));
        printf("O tamanho do RDM eh: %lf bits", log2(tamanhoEndereco));
    }
    else{
        printf("A capacidade em bytes é: %.2lfBytes\n", capacidadeBytes);
        printf("O tamanho do REM eh: %.2lf bits\n", log2(totalQntdEnd));
        printf("O tamanho do RDM eh: %.2lf bits\n", log2(tamanhoEndereco));
    }
}