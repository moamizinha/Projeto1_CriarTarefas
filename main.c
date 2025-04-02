#include "Projeto.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListaDeTarefas lt;
    char arquivo[] = "tarefas";
    int codigo, opcao;

    codigo = carregarTarefas(&lt, arquivo);

    if (codigo != 0) {
        printf("Lista de tarefas não carregada\n");
        lt.qtd = 0; // Ajustando para inicializar corretamente
    }

    do {
        exibeMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                codigo = criarTarefa(&lt);
            if (codigo == 1)
                printf("Erro ao criar tarefa: Sem espaço disponível\n");
            break;
            case 2:
                codigo = deletarTarefa(&lt);
            if (codigo == 1)
                printf("Erro ao deletar tarefa: Não existem tarefas para deletar\n");
            else if (codigo == 2)
                printf("Erro ao deletar tarefa: Posição inválida\n");
            break;
            case 3:
                codigo = listarTarefas(&lt);
            if (codigo == 1)
                printf("Erro ao listar tarefas: Não existem tarefas para serem listadas\n");
            break;
            default:
                printf("Opção inválida\n");
            break;
        }
    } while (opcao != 0);

    codigo = salvarTarefas(&lt, arquivo);
    if (codigo != 0)
        printf("Erro ao salvar tarefas em arquivo\n");

    system("pause");
    return 0;
}
