# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para relembrar a sintaxe e estrutura de programas em código C.

Receber um programa que receba argumentos de entrada na execução do programa e exibir estes argumentos.

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
    ./arguments.out {parâmetros}

Para executar um exemplo de input deve-se utilizar
    
    make teste

# Instruções de uso

Não há telas de interação, portanto basta executar o programa enviando argumentos e ver o resultado.

# Limitações

É assumido que o sistema de arquivos trabalha com o direcionamento de diretórios o /. Caso contrário, o nome do programa pode retornar o nome do executável contendo todo o caminho.
Exemplo: 
    
    /home/usuario/fso/programa1.out
    > programa1.out

    C:\\user\programa1.out
    > C:\\user\programa1.out
