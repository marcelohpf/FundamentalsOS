# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para implementar o problema de produtor e consumidor.

Tratar da criação de threads sendo 1 produtora e 2 consumidoras, na qual a thread produtora irá gerar números inteiros aleatórios. Tratamento de envio de sinais entre processos. Tratamento de seção critica para o correto funcionamento do programa.

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

Para compilar e limpar os dados antigos use

    make dist

Para limpar o ambiente use o comando a seguir

    make clean

# Instruções de uso

Após a compilação, será gerado um arquivo chamado de prod_cons no diretório bin do local de compilação. Como argumento de entrada, espera-se um único argumento que é o nome do arquivo onde serão escritas as mensagens de *logger*.

    ./bin/prod_cons logger.log

Para encessar a aplicação é necessário enviar um sinal de interrupção, **SIGINT** para o processo. Este sinal pode ser enviado utilizando o comando kill no terminal onde é necessário identificar o número do processo criado (PID) ou precionando as teclas CTRL+C no terminal.

    kill -2 PID

Após o recebimento da mensagem a aplicação irá sinalizar para as threads encerrarem suas atividades, e mostrará as informações de maior e menor números lidos e o maior espaço de buffer ocupado.

## Exemplo de execução
    
    ./bin/prod_cons logger.log 
    [aviso]: Termino solicitado. Aguardando threads...
    [aviso]: Maior numero gerado: 1073658792
    [aviso]: Menor numero gerado: -1073623444
    [aviso]: Maior ocupacao de buffer: 2
    [aviso]: Aplicacao encerrada.
    [1]+  Concluído              ./bin/prod_cons logger.log
    
# Limitações

* O buffer é limitado a 50 posições, e quando ele está cheio o número gerado é descartado.
* Foi utilizada variável global para o controle das threads.
* Se forem enviados mais sinais antes do encerramento adequado serão enviadas as mensagens de encerramento: "[aviso]: Termino solicitado. Aguardando threads...".

# Lista de bibliotecas

Foram usadas as bibliotecas padrão do c.

* stdio.h
* stdlib.h
* unistd.h
* time.h
* signal.h
* pthread.h
