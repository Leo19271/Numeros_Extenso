#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//----------FUNCOES-------------
void MILHAR();//Função para escrever os milhares
void CENTENA();//Função para escrever as centenas
void DEZENA();//Função para escrever as dezenas
void UNIDADE();//Função para escrever as unidades
void PAR();//Função para escrever quando dezena for 10
void ALL_NUM();//Função para escrever todos os numeros
void NUMERO_EXT(float numero);//Função para transformar um numero em extenso

//-----------------PROGRAMA PRINCIPAL--------------------------------------------------
int main(){
    int escolha;
    float numero;
    do
    {
        printf("ESCOLHA: \n\t1 - ESCREVER NUMERO POR EXTENSO\n\t2 - IMPRIMIR TODOS OS NUMEROS NA TELA\n\t3 - SAIR\n");
        scanf("%d", &escolha);
        switch(escolha)
        {
            case 1:
                printf("Escreva um numero de 0 a 9999.99 para ser escrito por extenso\n");
                scanf("%f", &numero);
                FILE *numbers = fopen("num_ext.txt", "a");//Abre o arquivo para armazenar os numeros
                if(numero < 0 || numero >= 10000)
                {
                    printf("Valor acima do limite!!\n");
                    break;
                }
                fprintf(numbers, "\n%.2f", numero);//salva os numeros no arquivo em forma de float
                fclose(numbers);//fecha o arquivo
                NUMERO_EXT(numero);//chama a função para transformar o numero em extenso
                break;
            case 2:
                ALL_NUM();
                break;
            case 3:
                printf("Encerrando programa...\n");
                remove("num_ext.txt");//deleta o arquivo
                exit;
                break;
            default:
                printf("Opcao Invalida!\n");
        }
    }while(escolha != 3);//FaZ a repetição do menu até finalizar ele
    system("pause");
    return 0;
}
//--------------ESCREVER TODOS NUMEROS---------------------------------
void ALL_NUM()
{
    float numero;
    int i = 1;
    FILE *numbers = fopen("num_ext.txt", "r");
    while (fscanf(numbers, "%f", &numero) != EOF )//lê no arquivo o numero para transformar em extenso
    {
        printf("Numero %d: ", i);
        NUMERO_EXT(numero);//chama a função novamente pra pegar o numero por extenso
        i++;
    }
    fclose(numbers);
}
//-----------ESCREVER NUMERO POR EXTENSO-------------------------------------
void NUMERO_EXT(float numero)
{
    int cent, mil, cen, dez, un, par, cenun, cendez;
    //-------MATEMATICA----------------------------
    cent = round((numero - (int)numero) * 1000) / 10;
    mil = numero / 1000;
    cen = ((int)numero % 1000) / 100;
    dez = ((int)numero % 100) / 10;
    un = (int)numero % 10;
    //------Matematica-centavos-------------
    cendez = cent / 10;
    cenun = (int)cent % 10;
    //---------REAIS-------------------------
    MILHAR(mil);
    CENTENA(cen, dez, un);
    if(dez==1){
        par = dez + un;
        PAR(par);
    }
    else{
        DEZENA(dez);
        UNIDADE(un);
    }
    if((int)numero==0){
        printf("zero reais");
    }
    else{
        printf(" reais");
    }
//----------PARTE DOS CENTAVOS---------------------------
    dez = cendez;
    un = cenun;
    if(dez == 1){
        par = dez + un;
        PAR(par);//caso dezena for 1 não imprimir dez e um e sim onze.
    }
    else{
        DEZENA(dez);
        UNIDADE(un);
    }
    if(cent !=0 ){
        printf(" centavos\n");
    }
    else
        printf("\n");
}

//------------------MILHAR----------------------------------------
void MILHAR(int milhar){
    switch(milhar){
    case 1:
        printf("mil ");
        break;
    case 2:
        printf("dois mil ");
        break;
    case 3:
        printf("tres mil ");
        break;
    case 4:
        printf("quatro mil ");
        break;
    case 5:
        printf("cinco mil ");
        break;
    case 6:
        printf("seis mil ");
        break;
    case 7:
        printf("sete mil ");
        break;
    case 8:
        printf("oito mil ");
        break;
    case 9:
        printf("nove mil ");
        break;
    default:
        break;
    }
}
//------------------CENTENA--------------------------------------
void CENTENA(int centena, int unidade, int dezena){
    switch(centena){
    case 1:
        if(unidade + dezena == 0)
            printf("e cem");
        else
            printf("cento");
        break;
    case 2:
        printf("duzentos");
        break;
    case 3:
        printf("trezentos");
        break;
    case 4:
        printf("quatrocentos");
        break;
    case 5:
        printf("quinhentos");
        break;
    case 6:
        printf("seiscentos");
        break;
    case 7:
        printf("setecentos");
        break;
    case 8:
        printf("oitocentos");
        break;
    case 9:
        printf("novecentos");
        break;
    default:
        break;
    }
}
//--------------------DEZENA---------------------------------------
void DEZENA(int dezena){
    switch(dezena){
    case 1:
        break;
    case 2:
        printf(" e vinte");
        break;
    case 3:
        printf(" e trinta");
        break;
    case 4:
        printf(" e quarenta");
        break;
    case 5:
        printf(" e cinquenta");
        break;
    case 6:
        printf(" e sessenta");
        break;
    case 7:
        printf(" e setenta");
        break;
    case 8:
        printf(" e oitenta");
        break;
    case 9:
        printf(" e noventa");
        break;
    default:
        break;
    }
}
//---------------------UNIDADE-------------------------------------
void UNIDADE(int unidade){
    switch(unidade){
    case 1:
        printf(" e um");
        break;
    case 2:
        printf(" e dois");
        break;
    case 3:
        printf(" e tres");
        break;
    case 4:
        printf(" e quatro");
        break;
    case 5:
        printf(" e cinco");
        break;
    case 6:
        printf(" e seis");
        break;
    case 7:
        printf(" e sete");
        break;
    case 8:
        printf(" e oito");
        break;
    case 9:
        printf(" e nove");
        break;
    default:
        break;
    }
}
//--------------------------DEZENAS CASO 10-19---------------------------------
void PAR(int par){
    par = (par % 10);
    switch(par){
    case 1:
        printf(" e dez");
        break;
    case 2:
        printf(" e onze");
        break;
    case 3:
        printf(" e doze");
        break;
    case 4:
        printf(" e treze");
        break;
    case 5:
        printf(" e quatorze");
        break;
    case 6:
        printf(" e quinze");
        break;
    case 7:
        printf(" e dezesseis");
        break;
    case 8:
        printf(" e dezessete");
        break;
    case 9:
        printf(" e dezoito");
        break;
    case 10:
        printf(" e dezenove");
        break;
    default:
        break;
    }
}
