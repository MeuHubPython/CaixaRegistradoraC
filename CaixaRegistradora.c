/*
Criar um programa que simule uma caixa registradora.
Calculando o total de compras, troco, aplicando descontos e exibindo a nota de compra com todos os itens comprados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int main(void){

    struct produto{
    char nome[20];
    char marca[20];
    float preco;
    int qnt;
    };

    struct venda{
        char nome[20];
        char marca[20];
        float preco;
        int qnt;
    };

    struct venda Vendas[1000];
    struct produto Produtos[100];
    int tamanho_lista = 0, opcao, opcao_produtos, variavel, af_caixa = 0, codigo, opcao_venda, quantidade;
    char produto_alterado[20];
    float total_caixa, total_dinheiro, total_cartao, total_pix;
    
    while(1){
        printf("\n-------CAIXA REGISTRADORA-------\n\nDigite uma opcao:\n\n[1]- Abrir Venda\n[2]- Produtos\n[3]- Abrir/Fechar Caixa\n[4]- Sair\n");
        scanf("%d", &opcao);
        Sleep(500);
        if(opcao == 2){
            while(1){
                Sleep(2000);
                printf("\n\n------PRODUTOS------\n\nDigite uma opcao:\n\n[1]- Novo Produto\n[2]- Remover Produto\n[3]- Alterar Estoque de Produtos\n[4]- Lista de Produtos\n[5]- Voltar ao Menu Anterior\n\n");
                scanf("%d", &opcao_produtos);
                if(opcao_produtos == 1){
                    system("cls");
                    printf("\n\n------NOVO PRODUTO------\n\nDigite o nome do Produto:");
                    scanf("%s", &Produtos[tamanho_lista].nome);
                    printf("\nDigite a marca do produto:");
                    scanf("%s", &Produtos[tamanho_lista].marca);
                    printf("\nDigite o preco de venda do produto: R$");
                    scanf("%f", &Produtos[tamanho_lista].preco);
                    printf("\nDigite a quantidade inicial do produto:");
                    scanf("%d", &Produtos[tamanho_lista].qnt);
                    Sleep(600);
                    printf("\n\n--------PRODUTO REGISTRADO COM SUCESSO!!----------\n\n");
                    Sleep(600);
                    printf("\n---------RESUMO DO PRODUTO---------\n\nNome: %s\n\nMarca: %s\n\nR$%.2f\n\nEstoque: %d", Produtos[tamanho_lista].nome, Produtos[tamanho_lista].marca, Produtos[tamanho_lista].preco, Produtos[tamanho_lista].qnt);
                    tamanho_lista ++;
                    Sleep(600);
                }
                else if(opcao_produtos == 2){
                    system("cls");
                    printf("\n\n---------REMOCAO DE PRODUTOS--------\n\nDigite o nome do produto a ser removido: ");
                    scanf("%s", &produto_alterado);
                    variavel = -1;
                    for(int i = 0; i <= 100; i++){
                        variavel ++;
                        int comparacao = strcmp(Produtos[i].nome, produto_alterado);
                        if(comparacao == 0){
                            printf("\n\n---------INFORMACAO DO PRODUTO----------\n\nNome: %s\n\nMarca: %s\n\nR$%.2f\n\nEstoque Atual: %d", Produtos[i].nome, Produtos[i].marca, Produtos[i].preco, Produtos[i].qnt);
                            int remocao_produto = 0;
                            printf("\n\nDESEJA REALMENTE REMOVER ESSE PRODUTO?\n\n[1]SIM\n\n[0]NAO\n");
                            scanf("%d", &remocao_produto);
                            if(remocao_produto == 1){
                                for(int i = variavel; i <= 99; i++){
                                    Produtos[i] = Produtos[i + 1];
                                }
                                tamanho_lista --;
                                Sleep(600);
                                printf("\n\n-----------REMOCAO CONCLUIDA COM SUCESSO!!------------\n\n");
                            }else if(remocao_produto == 0){
                                break;
                            }else{
                                Sleep(600);
                                printf("\n\n---------OPCAO INVALIDA-------\n\n");
                            }
                        }
                    }
                }
                else if(opcao_produtos == 3){
                    system("cls");
                    printf("\n\n-------ALTERAR ESTOQUE-------\n\nDigite o nome do produto a ser alterado: ");
                    scanf("%s", &produto_alterado);
                    variavel = 0;
                    for(int i = 0; i <= 100; i++){
                        variavel ++;
                        int comparacao = strcmp(Produtos[i].nome, produto_alterado);
                        if(comparacao == 0){
                            printf("\n\n---------INFORMACAO DO PRODUTO----------\n\nNome: %s\n\nMarca: %s\n\nR$%.2f\n\nEstoque Atual: %d", Produtos[i].nome, Produtos[i].marca, Produtos[i].preco, Produtos[i].qnt);
                            int novo_estoque;
                            printf("\n\nDigite o valor do novo estoque: ");
                            scanf("%d", &novo_estoque);
                            Produtos[i].qnt = novo_estoque;
                            Sleep(600);
                            printf("\n\n----------ESTOQUE DE %s ALTERADO COM SUCESSO!!-----------\n\nEstoque Atual: %d", Produtos[i].nome, Produtos[i].qnt);
                            break;
                        }
                        else if(variavel == 101){
                            Sleep(600);
                            printf("\n\n------------PRODUTO NAO EXISTE NO ESTOQUE ATUAL------------\n\n");
                            break;
                        }     
                    }
                }
                else if(opcao_produtos == 4){
                    system("cls");
                    printf("\n\n------------LISTA DE PRODUTOS---------------\n\n");
                    for(int i = 0; i <= tamanho_lista - 1; i++){
                        Sleep(200);
                        printf("\n\n[%d] - Produto: |%s| Marca: |%s| Preco: |R$%.2f| Estoque: |%d|", i, Produtos[i].nome, Produtos[i].marca, Produtos[i].preco, Produtos[i].qnt);
                    }
                    Sleep(600);
                    printf("\n\nQuantidade Total de Produtos: %d produtos\n\n-----------------FIM DA LISTA---------------", tamanho_lista);
                }
                else if (opcao_produtos == 5){
                    break;
                }
                else{
                    Sleep(600);
                    printf("\n\n-----------------OPCAO INVALIDA--------------\n\n");
                }  
            }
        }
        if(opcao == 3){
            if(af_caixa == 0){
                Sleep(200);
                printf("\n\n------------------CAIXA ABERTO--------------------\n\n");
                af_caixa = 1;
            }else{
                printf("\n\nDeseja fechar o caixa?\n\n[1]Sim\n[2]Nao\n");
                int opcao_caixa;
                scanf("%d", &opcao_caixa);
                if(opcao_caixa == 1){
                    Sleep(200);
                    printf("\n\n----------------RESUMO DO DIA----------------\n\n"); 
                    total_caixa = total_cartao + total_dinheiro + total_pix;
                    Sleep(200);
                    printf("TOTAL EM DINHEIRO: R$%.2f\nTOTAL EM CARTAO: R$%.2f\nTOTAL EM PIX: %.2f\n\nTOTAL DO DIA: R$%.2f",total_dinheiro, total_cartao, total_pix, total_caixa);
                    Sleep(1000);
                    printf("\n\n---------------------CAIXA FECHADO-----------------\n\n");
                    af_caixa = 0;
                }
                else if(opcao_caixa == 2){
                    break;
                }
                else{
                    Sleep(600);
                    printf("\n\n-----------------OPCAO INVALIDA--------------\n\n");
                }
            }
        }
        if(opcao == 1){
            printf("\n\n----------------------NOVA VENDA------------------------\n\n");
            int tamanho_venda = 0;
            if(af_caixa == 0){
                printf("\n\nCAIXA FECHADO, POR FAVOR ABRA O CAIXA!!\n\n");
            }
            else{
                while(1){
                    printf("\n\n[1]Adicionar Produto\n[2]Finalizar Venda\n\n");
                    scanf("%d", &opcao_venda);
                    if(opcao_venda == 1){
                        printf("Digite o codigo do produto:");
                        scanf("%d", &codigo);
                        if(codigo > tamanho_lista){
                            printf("-----------------CODIGO INVALIDO---------------");
                        }
                        else{
                            printf("\n\nProduto: %s\nMarca: %s\nPreco: %.2f\n\nDigite a quantidade: ", Produtos[codigo].nome, Produtos[codigo].marca, Produtos[codigo].preco);
                            scanf("%d", &quantidade);
                            strcpy(Vendas[tamanho_venda].nome, Produtos[codigo].nome);
                            strcpy(Vendas[tamanho_venda].marca, Produtos[codigo].marca);
                            Vendas[tamanho_venda].preco = (Produtos[codigo].preco * quantidade);
                            Vendas[tamanho_venda].qnt = quantidade;
                            printf("\n%d - ++ %s, %s, %d, %.2f", tamanho_venda, Vendas[tamanho_venda].nome, Vendas[tamanho_venda].marca, Vendas[tamanho_venda].qnt, Vendas[tamanho_venda].preco);
                            Produtos[codigo].qnt -= quantidade;
                            tamanho_venda ++;
                        }
                    }
                    else if(opcao_venda == 2){
                        Sleep(600);
                        printf("\n\n-----------------NOTA FISCAL------------------\n");
                        float total = 0;
                        for(int itens = 0; itens <= tamanho_venda - 1; itens ++){
                            Sleep(400);
                            printf("%d - QTD: %d |%s %s R$%.2fun.| = R$%.2f\n", itens, Vendas[itens].qnt, Vendas[itens].nome, Vendas[itens].marca, Vendas[itens].preco / Vendas[itens].qnt, Vendas[itens].preco);
                            total += Vendas[itens].preco;
                        }
                        Sleep(400);
                        printf("\n\nTOTAL = R$%.2f", total);
                        Sleep(400);
                        printf("\n\n------------------------------------------------\nModo de Pagamento:\n[1] - Dinheiro\n[2] - Cartao\n[3] - PIX\n\n");
                        int opcao_pagamento;
                        scanf("%d", &opcao_pagamento);
                        if(opcao_pagamento == 1){
                            Sleep(400);
                            printf("\nDigite o valor recebido: R$");
                            float dinheiro;
                            scanf("%f", &dinheiro);
                            if(dinheiro > total){
                                float troco = dinheiro - total;
                                Sleep(200);
                                printf("TROCO: R$%.2f", troco);
                                Sleep(2000);
                                printf("\n\n--------------------VENDA FINALIZADA!----------------------\n\nOBRIGADO, VOLTE SEMPRE!!\n\n");
                                total_dinheiro += total;
                                break;
                            }else{
                                printf("\n\n--------------------VENDA FINALIZADA!----------------------\n\nOBRIGADO, VOLTE SEMPRE!!\n\n");
                                total_dinheiro += total;
                                break;
                            }
                        }
                        else if(opcao_pagamento == 2){
                            Sleep(400);
                            printf("\n\nInsira o cartao\n\n");
                            printf("Digite sua senha(4 digitos): ");
                            char senha[4];
                            int nsenha = 0;
                            char numero;
                            while(1){
                                numero = getch();
                                if(numero == 13){ //13 == Enter
                                    break;
                                }
                                else if(numero == 8){ //8 == Backspace
                                    if(nsenha > 0){
                                        printf("\b \b"); //apaga o número digitado
                                        nsenha --;
                                    }
                                }
                                else{
                                    senha[nsenha] = numero;
                                    printf("*");
                                    nsenha ++;
                                }
                            }
                            printf("\n\nProcessando...\n");
                            Sleep(2000);
                            printf("TRANSACAO APROVADA!\n\nRETIRE O CARTAO");
                            Sleep(600);
                            printf("\n\n--------------------VENDA FINALIZADA!----------------------\n\nOBRIGADO, VOLTE SEMPRE!!\n\n");
                            total_cartao += total;
                            break;
                        }
                        else if(opcao == 3){
                            printf("\n\nChave Pix: CNPJ 53.095.636/0001-20\n");
                            Sleep(10000);
                            printf("\n\nPIX RECEBIDO\n\n");
                            printf("\n\n--------------------VENDA FINALIZADA!----------------------\n\nOBRIGADO, VOLTE SEMPRE!!\n\n");
                            total_pix += total;
                            break;
                        }
                    }
                }
            }
        }
        if(opcao == 4){
            Sleep(1500);
            printf("\n\n-----------------SISTEMA FINALIZADO--------------------\n\n");
            return 0;
        }
    }
}