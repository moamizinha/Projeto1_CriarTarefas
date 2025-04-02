# 🔨 Alterações Realizadas
# 1. Correção e Refatoração dos Métodos
Todos os métodos do projeto foram atualizados e refatorados para garantir um código mais limpo, eficiente e com melhores práticas de desenvolvimento. ✍️

# 2. Comentários no Código
O código foi amplamente comentado para fornecer explicações sobre as mudanças realizadas, permitindo que outros desenvolvedores compreendam facilmente a lógica implementada. 📝

# README - Correções no Código

## Introdução
Este documento explica as correções feitas no código original, destacando os problemas encontrados e as soluções aplicadas para melhorar a funcionalidade e a legibilidade.

---

## 1. Correção na Estrutura `ListaDeTarefas`
### Problema:
O código original declarava a estrutura como `ListaDeTarefa`, mas as funções estavam usando `ListaDeTarefas`, causando inconsistência.

### Solução:
O nome da struct foi padronizado para `ListaDeTarefas` para manter coerência.

---

## 2. Função `carregarTarefas`
### Problemas:
1. O parâmetro `char nome` deveria ser `const char *nome`, pois `nome` é uma string e não um caractere.
2. Falta de verificação do retorno da função `fread`.

### Solução:
- Alterado o tipo do parâmetro para `const char *nome`.
- Adicionada uma verificação para garantir que `fread` leu corretamente os dados.

```c
int carregarTarefas(ListaDeTarefas *lt, const char *nome) {
    FILE *fp = fopen(nome, "rb");
    if (fp == NULL) {
        return 1;
    }

    if (fread(lt, sizeof(ListaDeTarefas), 1, fp) != 1) {
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}
```

---

## 3. Função `salvarTarefas`
### Problemas:
1. Falta de ponto e vírgula (`;`) após `fopen(nome, "wb")`.
2. Não havia verificação se `fwrite` conseguiu salvar os dados corretamente.

### Solução:
- Corrigido o erro de sintaxe.
- Adicionada verificação para garantir que `fwrite` gravou os dados corretamente.

```c
int salvarTarefas(ListaDeTarefas *lt, const char *nome) {
    FILE *fp = fopen(nome, "wb");
    if (fp == NULL) {
        return 1;
    }

    if (fwrite(lt, sizeof(ListaDeTarefas), 1, fp) != 1) {
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}
```

---

## 4. Função `exibeMenu`
### Problemas:
1. O uso de `printf` para cada linha poderia ser otimizado.
2. A palavra "menu" deveria ter a primeira letra maiúscula.
3. "Listar tarefa" deveria ser "Listar tarefas" para manter concordância.

### Solução:
- Substituído `printf` por `puts`, que automaticamente adiciona `\n`.
- Corrigidos os textos para manter a consistência.

```c
void exibeMenu() {
    puts("Menu:");
    puts("1. Criar tarefa");
    puts("2. Deletar tarefa");
    puts("3. Listar tarefas");
    puts("0. Sair");
}
```

---

# Gerenciador de Tarefas

Este projeto implementa um gerenciador de tarefas simples em C. Ele permite criar, deletar, listar, salvar e carregar tarefas de um arquivo, além de oferecer novas funcionalidades para aprimorar sua experiência.

## Funcionalidades

- **Criar Tarefa**: Adiciona uma nova tarefa com prioridade, categoria e descrição.
- **Deletar Tarefa**: Remove uma tarefa informando sua posição na lista.
- **Listar Tarefas**: Exibe todas as tarefas cadastradas.
- **Salvar Tarefas**: Salva as tarefas em um arquivo binário.
- **Carregar Tarefas**: Carrega tarefas de um arquivo salvo.
- **(Nova) Editar Tarefa**: Permite modificar uma tarefa existente.
- **(Nova) Buscar Tarefa por Categoria**: Busca e exibe tarefas filtrando por categoria.

## Como Usar

1. Compile o código com:
   ```sh
   gcc -o gerenciador_tarefas main.c projeto.c
   ```
2. Execute o programa:
   ```sh
   ./gerenciador_tarefas
   ```
3. Navegue pelo menu e utilize as novas funções!

## Estrutura do Código

- `projeto.h`: Define as estruturas e assinaturas das funções.
- `projeto.c`: Implementação das funções do gerenciador de tarefas.
- `main.c`: Contém a função principal e o menu interativo.

## Melhorias Futuras
- Implementação de persistência em JSON para maior portabilidade.
- Interface gráfica simples para facilitar a interação do usuário.

Contribuições são bem-vindas! 😊

## Conclusão
As correções feitas melhoraram a segurança do código, corrigiram erros de sintaxe e tornaram a implementação mais consistente e legível.

# 👥 Membros do Projeto
Igor Marques Pieralini RA: 24224003-4
Victor Augusto Caramori André RA: 24.224.009-1

