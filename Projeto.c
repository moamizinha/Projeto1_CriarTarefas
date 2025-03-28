#include "Projeto.h" //Erro 1
#include <stdio.h> // Erro 2
#include <string.h> //Erro 2

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;

	Tarefa *t=&lt->tarefas[lt->qtd];

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);

    printf("Entre com a categoria da tarefa: ");
    scanf("%s", t->categoria);

    printf("Entre com a descricao da tarefa: ");
    scanf("%s", t->descricao);

    lt->qtd++;

    return 0;
}

int deletarTarefa(ListaDeTarefas *lt){
   if (lt->qtd == 0)
   return 1;

   int pos;
   printf("Entre com a posicao que deseja deletar: ");
   scanf("%d", &pos);

   if (pos <0 || pos > lt->qtd - 1) //Erro 15
   return 2;

   for (; pos<lt->qtd-1; pos++){
   	lt->tarefas[pos].prioridade=lt->tarefas[pos+1].prioridade;
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao); //Erro 16
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

   }

    lt->qtd--;
	return 0;
}
int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0)
	return 1;


int i;
for(i=0; i< lt->qtd; i++){
	printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i,
	lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
	printf("Descricao: %s\n", lt->tarefas[i].descricao);
}
    return 0;
}

int carregarTarefas(ListaDeTarefas *lt, char *nome){ //Erro 8
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;

   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb"); //Erro 9
   if (fp == NULL)
   return 1;

   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

void exibirMenu(){ //Erro 10
    printf("\nmenu\n"); //ajuste 1
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
    printf("4. Editar tarefa\n");
    printf("5. Contar tarefas por prioridade\n");
	printf("0. Sair\n");
	}

//Adicionando novas funções para editar e salvar tarefas
    
// Função para editar uma tarefa
int editarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd == 0) {
        return 1; // Nenhuma tarefa para editar
    }

    int pos;
    printf("Digite a posição da tarefa que deseja editar: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= lt->qtd) {
        return 2; // Posição inválida
    }

    printf("Nova prioridade: ");
    scanf("%d", &lt->tarefas[pos].prioridade);

    printf("Nova categoria: ");
    scanf("%s", lt->tarefas[pos].categoria);

    printf("Nova descrição: ");
    scanf("%s", lt->tarefas[pos].descricao);

    return 0;
}

// Função para contar tarefas com determinada prioridade
int contarTarefas(ListaDeTarefas *lt, int prioridade) {
    int contador = 0;
    int i;
    for (i = 0; i < lt->qtd; i++) {
        if (lt->tarefas[i].prioridade == prioridade) {
            contador++;
        }
    }
    return contador;
}