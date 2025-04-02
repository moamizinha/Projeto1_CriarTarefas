#ifndef PROJETO_H
#define PROJETO_H

#define TOTAL_TAREFAS 100

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[TOTAL_TAREFAS];
    int qtd;
} ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);
int carregarTarefas(ListaDeTarefas *lt, const char *nome);
int salvarTarefas(ListaDeTarefas *lt, const char *nome);
int editarTarefa(ListaDeTarefas *lt);
int buscarTarefaPorCategoria(ListaDeTarefas *lt);
void exibeMenu();

#endif // PROJETO_H
