# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para relembrar a sintaxe e estrutura de programas em código C.

Receber um argumento para que um programa ordene uma lista de acordo com o argumento recebido na inicialização do programa, e caso não receba nenhum argumento seja ordenada de forma crescente (**-d** para crescente, **-r** para decrescente).

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
    ./sort.out {argumento}

Para executar um exemplo de input deve-se utilizar
    
    make test-increscent (argumento igual a -d)
    make test-decrease (argumento igual a -r)
    make test-default (sem argumento)    

# Instruções de uso

 O usuário deverá entrar com os valores que serão alocados na lista, até que o mesmo coloque o valor -1.

 20
 1
 13
 44
 47
 -1


# Limitações

A lista deverá ser de inteiros não negativos

O usuário devera inserir o número -1 para dizer que a lista ja possui todos os integrantes