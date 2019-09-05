unidades = {
    'K':10,10:'K',
    'M':20,20:'M',
    'G':30,30:'G',
    'T':40,40:'T',
    'P':50,50:'P',
    'E':60,60:'E',
    'Z':70,70:'Z',
    'Y':80,80:'Y'

}
qntdEnderecos = float(input("Digite a quantidade de enderecos(sem a unidade): "));
print("K - Kilo\nM - Mega\nG - Giga\nT - Tera")
unidadeEnderecos = input("Digite a unidade da quantidade de endereços: ")
tamanhoEnderecos = float(input("Digite o tamanho dos enderecos em bits: "))
totalQntEnd = qntdEnderecos * (2**unidades.get(unidadeEnderecos))
tamanhoBytes = tamanhoEnderecos / 8
capacidadeBytes = totalQntEnd * tamanhoBytes
unit=0
while capacidadeBytes >= 1024:
    capacidadeBytes = capacidadeBytes/1024
    unit+=10
print("A capacidade total é de {} {} Bytes".format(capacidadeBytes,unidades.get(unit)))