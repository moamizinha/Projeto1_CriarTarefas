# Projeto1_CriarTarefas

GRUPO:
Isabela Bonoto de Castro
,
Gustavo Runge Passarelli


PROBLEMAS CORRIGIDOS:
--Erros em 'Projeto.h':

++Linha 1 - Número máximo de tarefas é 100 e não 5;

++Linha 12 - "ListaDeTarefas" estava sem o "s" no final;

++Linha 18 - "nome" estava com "s" no final;
    -------------
   | typedef struct {
   |     Tarefa tarefas[100]; --------->  padronizando  o ListaDeTarefas em que ocorre que antes estava escrito no singular
   |     int qtd; 
   | } ListaDeTarefa; 
    ------------


--Erros em 'Projeto.c':

++Linha 1 - O nome do arquivo é 'Projeto.h' com p maiúsculo, e não 'projeto.h';

++Linhas 2 e 3 - Para incluir bibliotecas, utiliza-se <> e não aspas("");

++Linha 33 -  Utilizou-se o símbolo de menor(<), quando o certo era usar maior(>);

++Linha 38 - Essa linha deleta a 'descrição' e não a 'categoria';

++Linha 60 - Faltou o asterisco(*) antes de 'nome';

++Linha 71 - Faltou o ponto e vírgula(;) no final da linha;

mudado de posição < lt->qtd - 1, por >= para validar de forma correta o posição;
removido strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria); para poder copiar o campo que possui .descrição na pos+1;
adicionado * no char nome;
adicionado o ";" na linha do FILE *fp=fopen(nome, "wb");



--Erros em 'main.c':

++Linha 1 - O nome do arquivo é 'Projeto.h' com p maiúsculo, e não 'projeto.h';

++Linha 2 - Para incluir bibliotecas, utiliza-se <> e não aspas("");

++Linha 10 - Faltou o '&' antes de 'lt';

++Linha 14 - O valor a ser atribuído nesse caso, é '0' e não '2';

++Linha 36 - O código de erro na função 'listarTarefas' é 1 e não 2;

++Linha 45 - O certo é '!=0' e não '==0', pois 0 é o código de retorno caso não tenha erros, então só se for diferente(!=) de 0, que avisamos ao usuário que tem erros;

Adicionado as chaves {} que estava faltando na estrutura do if;


FUNÇÕES IMPLEMENTADAS:



FORMA DE COMPILAÇÃO E EXECUÇÃO DO CÓDIGO:

