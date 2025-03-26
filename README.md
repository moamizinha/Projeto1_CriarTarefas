# Projeto1_CriarTarefas
Nome: Paulo César Fachetti Motta
RA: 242240125

Erros:

Projeto.c
1 - chamando o aruivo de projeto.h, no arquivo é maiusculo e no codigo estava minusculo.
2 - chamando as bibliotecas com "", teria que chamar com <>.
8 - na linha 60, pois estava "int carregarTarefas(ListaDeTarefas *lt, char *nome){" mas foi mudado para "int carregarTarefas(ListaDeTarefas *lt, char *nome){" faltou o "*".
9 - na linha 71, faltou apenas colocar o ponto e virgula ";".
10 - na linha 80 na funcao do menu, pois foi mudado o nome da funcao para exibirMenu, estava "void exibeMenu(){" foi mudado para "void exibirMenu(){".
15 - na funcao deletarTarefa da linha 33, pois no codigo esta como "if (pos <0 || pos < lt->qtd - 1)" foi mudado para "if (pos <0 || pos > lt->qtd - 1)".
16 - na funcao deletarTarefa da linha 38, pois no codigo esta como "strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].categoria);" mas esta fazendo da descricao nao da categoria esta diferente, foi mudado para "strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao);".

////////////////////////////////////////////////////////////////////////////
main.c
1 - chamando o aruivo de projeto.h, no arquivo é maiusculo e no codigo estava minusculo.
2 - chamando as bibliotecas com "", teria que chamar com <>.
7 - na linha 10, pois estava "codigo=carregarTarefas(lt, arquivo);" foi mudado para "codigo=carregarTarefas(&lt, arquivo);" faltou o "&" para compilar.
11 - na linha 18 na funcao do menu, pois foi mudado o nome da funcao para exibirMenu, estava "exibeMenu(); " foi mudado para "exibirMenu()".
12 - na linha 36 pois no codigo esta "if (codigo ==2)" mas daria outro tipo de erro, foi mudado para "if (codigo ==1)".
13 - na linha 45 pois no codigo esta como "if(codigo ==0)" mas tem que ser diferente, foi mudado para "if(codigo !=0)".
14 - na linha 50 pois faltou o "return 0;".
17 - na linha 14 poia no codigo esta commo "lt.qtd=2;" e o correto é "lt.qtd=0;".

////////////////////////////////////////////////////////////////////////////
Projeto.h
3 - pois está falando que são 100, mas o TOTAL_TAREFAS é 5.
4 - linha 12, na ListaDeTarefas pois estava escrito ListaDeTarefa no singular, enquanto as funcoes que estavam sendo chamadas estava ListaDeTarefas no plural.
5 - na linha 18, pois estava ", char *nomes" mudei para ", char *nome".
6 - na linha 21, pois estava "exibeMenu" foi mudado para "exibirMenu".