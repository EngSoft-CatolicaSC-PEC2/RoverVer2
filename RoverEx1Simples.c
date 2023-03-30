
#include <stdio.h>
#include <string.h>

#define TAM_MATRIZ 8
#define DIREITA 'D'
#define ESQUERDA 'E'
#define CIMA 'C'
#define BAIXO 'B'
#define DESTINO 'D'
#define RASTRO 'R'
#define BLOQUEIO 'B'
#define TERRENO '*'
int roverLinha = 2;
int roverColuna = 2;
int destinoLinha = 2;
int destinoColuna = 4;
char matriz[TAM_MATRIZ][TAM_MATRIZ];
void matrizCarregar();
void matrizImprimir();
void matrizIniciar();
void roverMover(char);
void roverFazerRastro();
int ehLimiteDiretoMapa();
int ehLimiteEsquerdoMapa();
int ehLimiteSuperiorMapa();
int ehLimiteInferiorMapa();
int encontrouFinal();

int main()
{
    matrizCarregar();
    matrizIniciar();
    matrizImprimir();
    printf("\n *** ***\n");

    do
    {
        roverMover(DIREITA);
        matrizImprimir();
    } while (encontrouFinal() == 0);
}

void roverMover(char comando)
{
    if (comando == DIREITA && ehLimiteDiretoMapa() != 0)
    {
        roverColuna++;
        roverFazerRastro();
    }
    else if (comando == ESQUERDA && ehLimiteEsquerdoMapa() != 0)
    {
        roverColuna++;
        roverFazerRastro();
    }
}

int encontrouFinal()
{
    return roverColuna == destinoColuna && roverLinha == destinoLinha;
}

int ehLimiteDiretoMapa()
{
    return roverColuna < TAM_MATRIZ;
}

int ehLimiteEsquerdoMapa()
{
    return roverColuna > 0;
}

int ehLimiteSuperiorMapa()
{
    return roverLinha > 0;
}

int ehLimiteInferiorMapa()
{
    return roverLinha < TAM_MATRIZ;
}

void roverFazerRastro()
{
    matriz[roverLinha][roverColuna] = RASTRO;
}

void matrizIniciar()
{
    matriz[roverLinha][roverColuna] = RASTRO;
    matriz[destinoLinha][destinoColuna] = DESTINO;
}

void matrizCarregar()
{
    for (int linha = 0; linha < TAM_MATRIZ; linha++)
    {
        for (int coluna = 0; coluna < TAM_MATRIZ; coluna++)
        {
            matriz[linha][coluna] = TERRENO;
        }
    }
}

void matrizImprimir()
{

    printf("\n *** ***\n");
    for (int linha = 0; linha < TAM_MATRIZ; linha++)
    {
        for (int coluna = 0; coluna < TAM_MATRIZ; coluna++)
        {
            printf("%c ", matriz[linha][coluna]);
        }
        printf("\n"); // Quebra de linha
    }
}
