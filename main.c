#include "Projeto.h" //Erro 1
#include <stdio.h> //Erro 2

int main(){
ListaDeTarefas lt;

char arquivo[] = "tarefas";
int codigo, opcao;

codigo=carregarTarefas(&lt, arquivo); //Erro 7

if (codigo !=0){
printf("Lista de tarefas nao carregada");
lt.qtd=0; //Erro 17
}

do{
exibirMenu(); //Erro 11
scanf("%d", &opcao);

if(opcao == 0){}
else if(opcao == 1){
    codigo=criarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao criar tarefa: Sem espacao disponivel\n");
    }
else if(opcao == 2){
    codigo=deletarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao deletar tarefa: nao existem tarefas para deletar\n");
else if(codigo ==2)
    printf("erro ao deletar tarefa: posicao invalida\n");
}
else if(opcao == 3){
    codigo=listarTarefas(&lt);
   if (codigo ==1) //Erro 12
   printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
}
else if(opcao == 4){ //É a nova funcao de editarTarefa
	codigo=editarTarefa(&lt);
	if(codigo == 1)
	printf("Erro ao editar tarefa: nao existe tarefa para ser editada.\n");
	else if(codigo == 2)
	printf("erro ao editar a tarefa: posicao invalida\n");
}
else if(opcao == 5){ //É a nova funcao de editarTarefa
	int prioridade;
	printf("Digite a prioridade para contar as tarefas: ");
    scanf("%d", &prioridade);
	int total = contarTarefas(&lt, prioridade);
    printf("Total de tarefas com prioridade %d: %d\n", prioridade, total);
}
else {
	printf("opcao invalida\n");
}
}while (opcao != 0);

codigo=salvarTarefas(&lt,arquivo);
if(codigo !=0) //Erro 13
printf("Erro ao salvar tarefas em arquivo");


system ("pause");
return 0; //Erro 14
}
