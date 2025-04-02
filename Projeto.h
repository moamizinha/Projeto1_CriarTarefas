#define TOTAL_TAREFAS 5

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;  // Corrigido o nome aqui para 'ListaDeTarefas'

int criarTarefa(ListaDeTarefas *lt);  // Corrigido para 'ListaDeTarefas'
int deletarTarefa(ListaDeTarefas *lt);  // Corrigido para 'ListaDeTarefas'
int listarTarefas(ListaDeTarefas *lt);  // Corrigido para 'ListaDeTarefas'

int carregarTarefas(ListaDeTarefas *lt, char *nome);  // Corrigido para 'ListaDeTarefas'
int salvarTarefas(ListaDeTarefas *lt, char *nome);  // Corrigido para 'ListaDeTarefas'
void exibeMenu(); 
