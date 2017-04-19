# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para implementar a comunicação entre 3 pocessos.

Tratar do gerenciamento de processos criando, enviando sinal de término e troca de mensagens entre processos distintos.

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

# Instruções de uso

Para utilizar o software, basta executar o arquivo pg.out.
Em seguida, é necessário apenas digitar na entrada de dados padrão **STDIN** do terminal. As mensagens só são consideradas completas quando o usuário pressiona a tecla **RETURN** inserindo uma quebra de linha.

Após a execução do programa será apresentada a mensagem: Exiting... e então é possível ver o resultado no arquivo chamado output.txt

Exemplos de entradas (envie uma a cada segundo aproximadamente):
Olá, processo

Estou testando a entrada

Pode aceitar pontuações?

Mas é claro que sim!

# Limitações

O buffer de envio de mensagens é limitado em apenas 499 caracteres mais 1 caractere para o \0.

Atualmente não é possível o processo pai enviar sinais para os filhos de forma a determinar qual é sua função.

Para obter o timestamp foi utilizado a função clock_gettime, portanto a precisão do tempo medido se sujeita a função.

O tempo de execução do programa está limitado por uma macro chamada **TIME_EXECUTION**.

# Lista de bibliotecas

Foram usadas as bibliotecas padrão do c, uni e sys.

* stdio.h
* stdlib.h
* string.h
* unistd.h
* time.h
* sys/wait.h
* sys/time.h
* sys/select.h
* signal.h



