# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para relembrar a sintaxe e estrutura de programas em código C.

Receber conjuntos de 4 coordenadas (X,Y) de um quadrilátero e indicar se este é convexo, e caso seja, exibir sua área.

# Ambiente

As informações sobre o ambiente de compilação e construção estão citados abaixo

## Compilação

    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/6.3.1/lto-wrapper
    Target: x86_64-redhat-linux
    Thread model: posix
    gcc version 6.3.1 20161221 (Red Hat 6.3.1-1) (GCC)

## Construção

    Fedora release 25 (Twenty Five)
    NAME=Fedora
    VERSION="25 (Workstation Edition)"
    ID=fedora
    VERSION_ID=25
    PRETTY_NAME="Fedora 25 (Workstation Edition)"
    VARIANT="Workstation Edition"
    VARIANT_ID=workstation

    Linux version 4.9.14-200.fc25.x86_64 (mockbuild@bkernel01.phx2.fedoraproject.org) (gcc version 6.3.1 20161221 (Red Hat 6.3.1-1) (GCC) ) #1 SMP Mon Mar 13 19:26:40 UTC 2017

# Compilando e executando

Para compilar este projeto, basta executar o comando a seguir
  
    make
    make run

Para executar um exemplo de input deve-se utilizar
    
    make run < input.txt

# Instruções de uso

O primeiro conjunto de entrada no código são quatro pares de números com ponto flutuante ou não.

    0 0
    0 1
    1 1
    1 0

Em seguida, será perguntado se deseja adicionar um novo conjunto de pares.

    0 -> exit
    1 -> continue

Ao pressionar 0 e dar enter o programa encerrará.
Ao pressionar outra tecla, que seja lido como um valor diferente de 0, o programa continuará a executar

# Limitações

Só funciona para entradas de pontos no sentido horário.

Não processa área para poligonos convexos com quantidade de lados < 4

Os cálculos são feitos com pontos flutuantes, e isso diminui a precisão. A precisão exibida foi de ```1 x 10^-12```.
