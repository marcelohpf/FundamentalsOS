# Alunos
* Marcelo Herton Pereira Ferreira - 14/0056688
* João Paulo Busche - 14/0023348

# Objetivo

Elaborar um programa utilizando código C para implementar o carremantento de bibliotecas de 3 maneiras diferentes.

Criar uma biblioteca de cálculo das funções seno e arco seno, que receba o ângulo em Radianos. Em seguida, essa biblioteca deve ser utilizada de 3 formas diferentes:

- Utilizar como biblioteca estática
- Utilizar como bilioteca dinâmica
- Realizar o carregamento da biblioteca sob demanda, durante a execução do programa.

# Ambiente

As informações sobre o ambiente de compilação e construção estão citados abaixo

## Compilação

### GCC

    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/6.3.1/lto-wrapper
    Target: x86_64-redhat-linux
    Thread model: posix
    gcc version 6.3.1 20161221 (Red Hat 6.3.1-1) (GCC)


    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/7/lto-wrapper
    OFFLOAD_TARGET_NAMES=nvptx-none
    OFFLOAD_TARGET_DEFAULT=1
    Target: x86_64-redhat-linux
    Configured with: ../configure --enable-bootstrap --enable-languages=c,c++,objc,obj-c++,fortran,ada,go,lto --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-gcc-major-version-only --with-linker-hash-style=gnu --enable-plugin --enable-initfini-array --with-isl --enable-libmpx --enable-offload-targets=nvptx-none --without-cuda-driver --enable-gnu-indirect-function --with-tune=generic --with-arch_32=i686 --build=x86_64-redhat-linux
    Thread model: posix
    gcc version 7.1.1 20170503 (Red Hat 7.1.1-1) (GCC)

### AR

    GNU ar version 2.27-21.fc26
    Copyright (C) 2016 Free Software Foundation, Inc.
    This program is free software; you may redistribute it under the terms of
    the GNU General Public License version 3 or (at your option) any later version.
    This program has absolutely no warranty.

## Construção

    Fedora release 25 (Twenty Five)
    NAME=Fedora
    VERSION="25 (Workstation Edition)"
    ID=fedora
    VERSION_ID=25
    PRETTY_NAME="Fedora 25 (Workstation Edition)"

    Linux version 4.9.14-200.fc25.x86_64 (mockbuild@bkernel01.phx2.fedoraproject.org) (gcc version 6.3.1 20161221 (Red Hat 6.3.1-1) (GCC) ) #1 SMP Mon Mar 13 19:26:40 UTC 2017

    Fedora release 26 (Twenty Six)
    NAME=Fedora
    VERSION="26 (Workstation Edition)"
    ID=fedora
    VERSION_ID=26
    PRETTY_NAME="Fedora 26 (Workstation Edition)"

    Linux version 4.11.0-2.fc26.x86_64 (mockbuild@bkernel01.phx2.fedoraproject.org) (gcc version 7.1.1 20170503 (Red Hat 7.1.1-1) (GCC) ) #1 SMP Tue May 9 15:24:49 UTC 2017


# Compilando e executando

Para compilar este projeto, basta executar o comando a seguir

    make

Para limpar o ambiente use o comando a seguir

    make fullclean

# Instruções de uso

Após a compilação, gerão geradas 2 pastas chamadas ./bin e ./lib. Na pasta bin estarão 3 executáveis chamados de:

- trigonometry_a: Compilação com a biblioteca estática
- trigonometry_d: Compilação com a carga sobre demanda
- trigonometry_dl: Compilação com a biblioteca dinâmica

Na pasta ./lib terão 2 pastas: dynamic e static, onde terão as respectivas bibliotecas libseno.so e libseno.a.

Antes da execução das bibliotecas dinâmicas é necessário adicionar o caminho da biblioteca para o systema identificar onde buscar a biblioteca. `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:caminho_para_a_pasta_bin_do_trabalho`.
Nota-se que não é necessário adicionar o caminho para a execução da biblioteca estática trigonometry_a
    Exemplo:
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/mferreira/UnB/fso/schoolworkFour/lib/dynamic

Após adicionar esse caminho a biblioteca, basta executar qualquer um dos binários. Executando com _a, _dl ou _d:
    ./bin/trigonometry_a [-s|-a] [Value]
Em que -s é para seno e o -a é para o arcoseno, em seguida deve ser adicionado o valor do ângulo, ou seno em rads.

# Limitações

* As limitações identificadas estão relacionadas a quantidade de casas decimais das contas.
* O programa precisa da variável de ambiente LD_LIBRARY_PATH, pois é exigido o sudo para adicionar a biblioteca no caminho do sistema para carregar automaticamente.

# Questões

1. Para a resolução dos itens A e B do enunciado do trabalho, não foram necessárias nenhuma modificação no código. Mudou-se apenas a maneira de gerar as bibliotecas e a maneira de realizar a compilação de cada item, adicionando a biblioteca estática ou dinâmica.
1. A criação de um link estático com a biblioteca impossibilita que esta seja trocada, ou seja, uma vez compilado o código, não há como alterar o comportamento da biblioteca utilizada. Diferentemente da utilização do link dinâmico, que possibilita que a biblioteca seja carregada em pelo loader. Isso indica que, é possível realizar a troca da biblioteca original, por uma customizada. Também é notável que, por ser carregada dinâmicamente, vários programas podem ter acesso a essa mesma biblioteca e reduzir a quantidade de código fonte carregado na memória, pois ela é carregada quando vai ser utilizada e esta mesma biblioteca pode ser compartilhada por vários programas.
1. Relação das dependências:
    1. Estática
        1. Na compilação da aplicação com biblioteca estática é necessário apenas a utilização da libc e libseno. Para a execução não é necessária dependência nenhuma.
        1. A posição desta biblioteca fica na área de texto (código fonte) do processo.
    1. Dinâmica
        1. Para a compilação da biblioteca dinâmica, é necessário também, somente a libc e a libseno. Para a execução, é exigido que exista a biblioteca nos caminhos que o Sistema Operacional busca as bibliotecas, não é necessária nenhuma outra dependência.
        1. Fica como armazenado em área de referência de memória do processo.
    1. Sob demanda
        1. Para a compilação da aplicação, é exigido as bibliotecas libc e libdl, para que seja possível fazer uso da dlfcn.h. Para a execução é preciso também adicionar o caminho para encontrar a biblioteca.
        1. Fica na área de heap do processo
