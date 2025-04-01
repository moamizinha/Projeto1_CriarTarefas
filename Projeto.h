#define TOTAL_TAREFAS 5

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas; // Erro no nome da struct, deve ser ListaDeTarefas
 
int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);

int carregarTarefas(ListaDeTarefas *lt, char *nome); // Corrigido o nome do parâmetro para char *nome, ao invés de "nomes" 
int salvarTarefas(ListaDeTarefas *lt, char *nome);
void exibeMenu();
