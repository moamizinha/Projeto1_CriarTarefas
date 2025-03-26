# Projeto1_CriarTarefas
Nome: Paulo César Fachetti Motta
RA: 242240125

Erros:

Projeto.c
1 - chamando o aruivo de projeto.h, no arquivo é maiusculo e nocodigo estava minusculo.
2 - chamando as bibliotecas com "", teria que chamar com <>.
8 - na linha 60, pois estava "int carregarTarefas(ListaDeTarefas *lt, char *nome){" mas foi mudado para "int carregarTarefas(ListaDeTarefas *lt, char *nome){" faltou o "*".
9 - na linha 71, faltou apenas colocar o ponto e virgula ";".

////////////////////////////////////////////////////////////////////////////
main.c
1 - chamando o aruivo de projeto.h, no arquivo é maiusculo e nocodigo estava minusculo.
2 - chamando as bibliotecas com "", teria que chamar com <>.
7 - na linha 10, pois estava "codigo=carregarTarefas(lt, arquivo);" foi mudado para "codigo=carregarTarefas(&lt, arquivo);" faltou o "&" para compilar.


////////////////////////////////////////////////////////////////////////////
Projeto.h
3 - pois está falando que são 100, mas o TOTAL_TAREFAS é 5.
4 - linha 12, na ListaDeTarefas pois estava escrito ListaDeTarefa no singular, enquanto as funcoes que estavam sendo chamadas estava ListaDeTarefas no plural.
5 - na linha 18, pois estava ", char *nomes" mudei para ", char *nome".
6 - na linha 21, pois estava "exibeMenu" foi mudado para "exibirMenu".