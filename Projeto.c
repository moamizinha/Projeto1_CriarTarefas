#include "Projeto.h"
#include <stdio.h>
#include <string.h>

int criarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd >= TOTAL_TAREFAS)
        return 1;

    Tarefa *t = &lt->tarefas[lt->qtd];

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);
    getchar(); // limpa o buffer após leitura de número

    printf("Entre com a categoria da tarefa: ");
    fgets(t->categoria, sizeof(t->categoria), stdin);
    t->categoria[strcspn(t->categoria, "\n")] = '\0'; // remove o \n do fgets

    printf("Entre com a descricao da tarefa: ");
    fgets(t->descricao, sizeof(t->descricao), stdin);
    t->descricao[strcspn(t->descricao, "\n")] = '\0'; // remove o \n do fgets

    lt->qtd++;

    return 0;
}


int deletarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd == 0)
        return 1;

    int pos;
    printf("Entre com a posicao que deseja deletar: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= lt->qtd)
        return 2;

    for (int i = pos; i < lt->qtd - 1; i++) {
        lt->tarefas[i] = lt->tarefas[i + 1];
    }

    lt->qtd--;
    return 0;
}


int listarTarefas(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return 1;
    }

    for (int i = 0; i < lt->qtd; i++) {
        printf("Tarefa %d\n", i);
        printf("Prioridade: %d\n", lt->tarefas[i].prioridade);
        printf("Categoria: %s\n", lt->tarefas[i].categoria);
        printf("Descricao: %s\n", lt->tarefas[i].descricao);
        printf("-----------------------------\n");
    }

    printf("Fim da lista de tarefas.\n");
    return 0;
}


int carregarTarefas(ListaDeTarefas *lt, const char *nome){
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
       return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, const char *nome){
   FILE *fp=fopen(nome, "wb");
   if (fp == NULL)
       return 1;
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int editarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        printf("Nenhuma tarefa para editar.\n");
        return 1;
    }

    int pos;
    printf("Digite a posição da tarefa que deseja editar: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 0 || pos >= lt->qtd) {
        printf("Posição inválida!\n");
        return 2;
    }

    printf("Nova prioridade: ");
    scanf("%d", &lt->tarefas[pos].prioridade);
    getchar();

    printf("Nova categoria: ");
    fgets(lt->tarefas[pos].categoria, sizeof(lt->tarefas[pos].categoria), stdin);
    lt->tarefas[pos].categoria[strcspn(lt->tarefas[pos].categoria, "\n")] = '\0';

    printf("Nova descrição: ");
    fgets(lt->tarefas[pos].descricao, sizeof(lt->tarefas[pos].descricao), stdin);
    lt->tarefas[pos].descricao[strcspn(lt->tarefas[pos].descricao, "\n")] = '\0';

    printf("Tarefa atualizada com sucesso!\n");

    return 0;
}

int buscarTarefaPorCategoria(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return 1;
    }

    char categoriaBusca[100];
    printf("Digite a categoria que deseja buscar: ");
    getchar();
    fgets(categoriaBusca, sizeof(categoriaBusca), stdin);
    categoriaBusca[strcspn(categoriaBusca, "\n")] = '\0';

    int encontrou = 0;
    for (int i = 0; i < lt->qtd; i++) {
        if (strcmp(lt->tarefas[i].categoria, categoriaBusca) == 0) {
            printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i, 
                   lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
            printf("Descrição: %s\n", lt->tarefas[i].descricao);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada para essa categoria.\n");
    }

    return 0;
}

void exibeMenu(){
    printf("\n=== MENU ===\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
    printf("3. Listar tarefas\n");
    printf("4. Editar tarefa\n");
    printf("5. Buscar tarefa por categoria\n");
    printf("6. Carregar tarefas\n");
    printf("7. Salvar tarefas\n");
    printf("0. Sair\n");
    printf("=================\n");
    printf("Escolha uma opção: ");
}