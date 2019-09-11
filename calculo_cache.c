#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double bitsToBytes(double bits); //converte bits para Bytes
double BytesToBits(double Bytes); //Converte Bytes para bits
double ToLongNum(double num, char unidade); //numero com unidade para somente numero
char numToUnidade(int num); //expoente para unidade
int unidadeToNum(char unidade); //unidade para expoente



void main(){
    
}

double bitsToBytes(double bits){
    return (bits / 8);
    }
double BytesToBits(double Bytes){
    return (Bytes * 8);
    }
double ToLongNum(double num, char unidade){
    int expoente = unidadeToNum(unidade);
    return (num * pow(2, expoente));
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
double qntdBlocos(double N, double X){
    return N/X;
}
double tamanhoMemoria(double M, double N){
    return M * N;
}
double tamanhoCache(double L, double X){
    return L * X;
}
double larguraTag(double B, double L){
    return log2(B/L);
}
double bitsTag(double L, double Lct){
    return L * Lct;
}
double bitsDados(double Tc){
    return Tc * 8;
}
double bitsCache(double Td, double Tt){
    return Td + Tt;
}


