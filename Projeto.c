#include "projeto.h"
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
        lt->tarefas[i].prioridade = lt->tarefas[i + 1].prioridade;
        strcpy(lt->tarefas[i].descricao, lt->tarefas[i + 1].descricao);
        strcpy(lt->tarefas[i].categoria, lt->tarefas[i + 1].categoria);
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

    return 0;
}


int carregarTarefas(ListaDeTarefas *lt, char nome){
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb")
   if (fp == NULL)
   return 1;
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

void exibeMenu(){
    printf("menu\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
    printf("3. Listar tarefa\n");
    printf("4. Carregar tarefas\n");
    printf("5. Salvar tarefas\n");
    printf("0. Sair\n");
}
