#define TOTAL_TAREFAS 100 //Erro 18

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[TOTAL_TAREFAS]; //Erro 3
    int qtd;
} ListaDeTarefas; //Erro 4

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);

int carregarTarefas(ListaDeTarefas *lt, char *nome); //Erro 5
int salvarTarefas(ListaDeTarefas *lt, char *nome);

int editarTarefa(ListaDeTarefas *lt); //É a nova funcao que vai editar a tarefa
int contarTarefas(ListaDeTarefas *lt, int prioridade); //nova funcao que conta as tarefas com determinada prioridade
void buscarTarefasPorCategoria(ListaDeTarefas *lt, char *categoria);

void exibirMenu(); //Erro 6
