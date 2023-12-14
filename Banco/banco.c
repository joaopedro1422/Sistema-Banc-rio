#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_CYAN "\033[46m"
#define BG_GRAY "\033[47m"
#define NONE "\033[0m"
#define BOLD "\033[1m"
#define HALFBRIGHT "\033[2m"
#define UNDERSCORE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"
#define C_CYAN "\033[36m"
#define C_GRAY "\033[37m"
#define C_RED "\033[31m"
float saldo = 1000, valor_pix, capital,resultado; 
int opcao=0, valor_transf, valor_emprestimo, qntd_giftcard,valor_giftcard,total_giftcard,valorex,contex,valor_extrato[10];
char nome[30];
char cpf[12], senha_conta, senha_login, opcao_emprestimo, nome_dest[10],chave_pix[12], opcao_giftcard,opcao_chavepix,celular[12],opcao_pix,nomex,tipo_extrato[100], opcao_poupanca,tempo;

char extrato();
char extrato() {
  printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
  printf("\t\t\t\t\t\t\tEXTRATO:"UNDERSCORE"\n\n\t\t\t\t\tVALOR:\t\t\t\tTIPO:\n\n"NONE);
  for(int i=0;i<contex;i++)
    {
      if(tipo_extrato[i]=='E')
      {
        printf(BG_CYAN BOLD BLINK"\t\t-->\t\t\t+%d\t\t\t EMPRESTIMO\n",valor_extrato[i]);
      }
      if(tipo_extrato[i]=='T')
      {
        printf(BG_CYAN BOLD BLINK"\t\t-->\t\t\t-%d\t\t\t TRANSFERÊNCIA\n",valor_extrato[i]);
      }
      if(tipo_extrato[i]=='P')
      {
        printf(BG_CYAN BOLD BLINK"\t\t-->\t\t\t-%d\t\t\t PIX\n",valor_extrato[i]);
      }
       if(tipo_extrato[i]=='G')
      {
        printf(BG_CYAN BOLD BLINK"\t\t-->\t\t\t-%d\t\t\t    GIFT CARD\n",valor_extrato[i]);
      }
      if(tipo_extrato[i]=='L')
      {
        printf(BG_CYAN BOLD BLINK"\t\t-->\t\t\t+%d\t\t\t    POUPANÇA\n",valor_extrato[i]);
      }
    
    
    }
  

  
}

char inicio();
char inicio() {
  if (saldo<=0)
  {
    printf(BG_CYAN BOLD BLINK REVERSE C_GRAY
      "\n\t\t\a===================> J.B.A BANK <===================\n" NONE
          BG_CYAN BOLD BLINK
      "\n\t\t\t\t\t\t \t< OLÁ %s! > \n INFORME O NUMERO CORRESPONDENTE AO "
      "SERVIÇO DESEJADO:\n\n [1] EMPRESTIMO         [2] REALIZAR "
      "TRANFERÊNCIA\n [3] PIX                [4] POUPANÇA \n [5] GIFTCARD      "
      "     [6] EXTRATO \n [7] ENCERRAR \n\n\n\t\t\t\t\t\t\t\t\t\t" REVERSE
          C_RED " <SALDO:%.2fR$> ",
      nome, saldo, NONE BG_CYAN REVERSE "\n --->");
  printf(BG_CYAN REVERSE C_GRAY"\n INSIRA SUA OPÇÃO:");
  scanf("%d\a", &opcao);
  }
  else
  {
    printf(BG_CYAN BOLD BLINK REVERSE C_GRAY
      "\n\t\t===================> J.B.A BANK <===================\n" NONE
          BG_CYAN BOLD BLINK
      "\n\t\t\t\t\t\t \t< OLÁ %s! > \n INFORME O NUMERO CORRESPONDENTE AO "
      "SERVIÇO DESEJADO:\n\n [1] EMPRESTIMO         [2] REALIZAR "
      "TRANFERÊNCIA\n [3] PIX                [4] POUPANÇA \n [5] GIFTCARD      "
      "     [6] EXTRATO \n [7] ENCERRAR \n\n\n\t\t\t\t\t\t\t\t\t\t" REVERSE
          C_GRAY " <SALDO:%.2fR$> ",
      nome, saldo, NONE BG_CYAN "\n --->");
  printf("\n INSIRA SUA OPÇÃO:");
  scanf("%d", &opcao);
  }
  if (opcao == 7) {
    system("cls");
    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <===================\n"
           "\n\n\n\n\n\t\t\t  ---------   A T É  L O G O !  ---------   \n");
    exit(0);
  }
  if (opcao == 2) {
    system("cls");

    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\nINFORME O PRIMEIRO NOME DO DESTINATARIO E "
                                  "O VALOR A SER REPASSADO:\n\n");
    printf("--> NOME:");
    scanf("%s", &nome_dest);
    printf("\n\n--> VALOR:");
    scanf("%d", &valor_transf);
    printf(UNDERSCORE "\n\n\n\t\t\t\t\t\t*TRANSFERINDO*\n" NONE);
    Sleep(3);
    system("cls");
    printf(BG_CYAN BLINK BOLD REVERSE C_GRAY
           "\n\n\n\tVALOR DE %d REAIS TRANSFERIDO COM SUCESSO PARA %s !!\n",
           valor_transf, nome_dest);
    
    Sleep(4);
    system("cls");
    saldo = saldo - valor_transf;
    valor_extrato[contex] = valor_transf;
    tipo_extrato[contex] = 'T';
    contex++;
    
    inicio();
  }
  if (opcao == 1) {
    system("cls");
    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
    printf("\t\t\t\t\tPRECISANDO DE DINHEIRO?");
    Sleep(1);
    printf("\n\tENTÃO CONFERE AÍ AS OPÇÕES DE EMPRESTIMO DA J.B.A BANK!\n\n");
    Sleep(1);
    printf(
        UNDERSCORE
        "\tOPÇÃO\t\t\t\tDURAÇÃO(PARCELAS)\t\t\t\tJUROS" NONE BG_CYAN BLINK BOLD
        "\n\t  A \t\t\t\t   12 meses\t\t\t\t\t\t 15%\n\t  B \t\t\t\t   6 "
        "meses\t\t\t\t\t\t 11%\n\t  C \t\t\t\t   3 meses\t\t\t\t\t\t 8%\n\t  D "
        "\t\t\t\t   16 meses\t\t\t\t\t\t 20%");
    printf("\n\n\nINSIRA SUA OPÇÃO: ");
    scanf("%s", &opcao_emprestimo);
    printf("\nINFORME O VALOR DESEJADO:");
    scanf("%d", &valor_emprestimo);
    system("cls");
    float valor_acumulado = valor_emprestimo;
    switch (opcao_emprestimo) {
    case 'A':
      printf(REVERSE C_GRAY
             "\n\t\t===================> J.B.A BANK <==================\n" NONE
                 BG_CYAN BLINK BOLD "\n\n\n");

      printf("--> %d REAIS FORAM ADICIONADOS AO SEU SALDO!\n\n\n--> APÓS 12 "
             "MESES O VALOR ACUMULADO DO PAGAMENTO SERÁ DE " UNDERSCORE
             "R$ %d\n",
             valor_emprestimo, valor_emprestimo + (valor_emprestimo * 15) / 100,
             NONE);
      Sleep(6);
      system("cls");
      saldo += valor_emprestimo;
      break;
    case 'B':
      printf(REVERSE C_GRAY
             "\n\t\t===================> J.B.A BANK <==================\n" NONE
                 BG_CYAN BLINK BOLD "\n\n\n");
      printf("--> %d REAIS FORAM ADICIONADOS AO SEU SALDO!\n\n\n--> APÓS 6 "
             "MESES O VALOR ACUMULADO DO PAGAMENTO SERÁ DE " UNDERSCORE
             "R$ %d\n",
             valor_emprestimo, valor_emprestimo + (valor_emprestimo * 11) / 100,
             NONE);
      Sleep(6);
      system("cls");
      saldo += valor_emprestimo;
      break;;
    case 'C':
      printf(REVERSE C_GRAY
             "\n\t\t===================> J.B.A BANK <==================\n" NONE
                 BG_CYAN BLINK BOLD "\n\n\n");
      printf("--> %d REAIS FORAM ADICIONADOS AO SEU SALDO!\n\n\n--> APÓS 3 "
             "MESES O VALOR ACUMULADO DO PAGAMENTO SERÁ DE " UNDERSCORE
             "R$ %d\n",
             valor_emprestimo, valor_emprestimo + (valor_emprestimo * 8) / 100,
             NONE);
      Sleep(6);
      system("cls");
      saldo += valor_emprestimo;
      break;
    case 'D':
      printf(REVERSE C_GRAY
             "\n\t\t===================> J.B.A BANK <==================\n" NONE
                 BG_CYAN BLINK BOLD "\n\n\n");
      printf("--> %d REAIS FORAM ADICIONADOS AO SEU SALDO!\n\n\n--> APÓS 3 "
             "MESES O VALOR ACUMULADO DO PAGAMENTO SERÁ DE " UNDERSCORE
             "R$ %d\n",
             valor_emprestimo, valor_emprestimo + (valor_emprestimo * 8) / 100,
             NONE);
      Sleep(6);
      system("cls");
      saldo += valor_emprestimo;
      //inicio();
      break;
    }
    valor_extrato[contex] = valor_emprestimo;
    tipo_extrato[contex] ='E';
    contex++;
    inicio();
  }
  if (opcao == 3) {
    system("cls");

    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
    printf("\t\t\tQUAL OPERAÇÃO VOCÊ DESEJA REALIZAR? \n \n [1] PAGAR \n [2] "
           "RECEBER \n [3] DEFINIR MINHA CHAVE PIX \n\n");
    printf("\n\nINSIRA SUA OPÇÃO: \n");
    scanf("%s", &opcao_pix);
    if(opcao_pix=='1')
    {
        Sleep(1);
        system("cls");
        printf(REVERSE C_GRAY
               "\n\t\t===================> J.B.A BANK <==================\n" NONE
                   BG_CYAN BLINK BOLD "\n\n");
        printf(UNDERSCORE
               "\n\t\t\t\t SEJA BEM VINDO AO NOSSO SERVIÇO PIX!\n\n\n");
        Sleep(2);
        printf("\t->DIGITE A CHAVE CPF PIX DO DESTINATARIO: ");
        scanf("%s", chave_pix);
        
        if (strlen(chave_pix) != 11) {
          printf(" \n FORMATO INVÁLIDO, TENTE NOVAMENTE!");
          printf("\n\n->DIGITE A CHAVE PIX DO DESTINATARIO: ");
          scanf("%s", chave_pix);
        }
        if (strlen(cpf) == 11) {
          printf("\n\n\t->INFORME O VALOR A SER REPASSADO:");
          scanf("%f", &valor_pix);
          printf(NONE BG_CYAN BLINK BOLD "\n\n\t\t\t\t\t    *TRANSFERINDO*\n");
          Sleep(2);
          system("cls");
          printf(REVERSE C_GRAY "\n\t\t===================> J.B.A BANK "
                            "<==================\n\n\n\n-VALOR DE %.2f REAIS "
                            "TRANSFERIDO PARA A CHAVE %s VIA PIX!\n",
             valor_pix, chave_pix);
          saldo = saldo - valor_pix;
          valor_extrato[contex] = valor_pix;
          tipo_extrato[contex]='P';
          contex++;
          Sleep(4);
          system("cls");
          inicio();
        
        }
      }
      }
      
    if (opcao_pix=='3')
    {
        Sleep(1);
        system("cls");
        printf(REVERSE C_GRAY
               "\n\t\t===================> J.B.A BANK <==================\n" NONE
                   BG_CYAN BLINK BOLD "\n\n");
        printf("\t->DEFINA O TIPO DA SUA CHAVE PIX:"UNDERSCORE"\n\n\n\t CELULAR [A]\n\n\t CPF [B]"NONE);
        printf(BG_CYAN BLINK BOLD"\n\n\n\t->INSIRA SUA OPÇÃO:");
        scanf("%s",&opcao_chavepix);
        if(opcao_chavepix=='A')
        {
            Sleep(1);
            printf(UNDERSCORE"\n\t->INFORME O SEU NUMERO DE CELULAR COM DDD:");
            scanf("%s", celular);
            if (strlen(celular)!=11)
            {
                printf(" \n FORMATO INVÁLIDO, TENTE NOVAMENTE!");
              printf("\n\n\t->INFORME O SEU NUMERO DE CELULAR COM DDD: \n");
              scanf("%s", &celular);              
            }    
            if (strlen(celular) == 11) 
            {
            Sleep(1);
              system("cls");
              printf(REVERSE C_GRAY
               "\n\t\t===================> J.B.A BANK <==================\n\n\n");
              printf("\t\t-> CHAVE PIX DEFINIDA COMO (%s)!\n",celular);
              Sleep(4);
              system("clear||cls");
              inicio();
            
            }
        }
          
        
        if(opcao_chavepix=='B')
        {
            Sleep(2);
            system("cls");
            printf(REVERSE C_GRAY
               "\n\t\t===================> J.B.A BANK <==================\n\n\n");
            printf("\t\t-> CHAVE PIX DEFINIDA COMO (%c%c%c.%c%c%c.%c%c%c-%c%c)\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);
            Sleep(6);
            system("cls");
            inicio();
  
        }
    }
  if (opcao == 5) {
    system("cls");
    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
    Sleep(1);
    printf("\t\t\tSEJA BEM VINDO A NOSSA SESSÃO DE GIFT CARDS!\n\n");
    Sleep(1);
    printf("\t\t\n AQUI VOCE PODE COMPRAR CARTÕES PARA DAR DE PRESENTE OU USAR NOS LUGARES QUE CURTE!\n\n A SEGUIR ESTÃO OS GIFTCARDS:\n");
    Sleep(1);
    printf(UNDERSCORE
           "\t\n OPÇÃO\t\t\t\tEMPRESA\t\t\t CASHBACK" NONE BG_CYAN BLINK BOLD
           "\n\tA \t\t\t\tIFOOD\t\t\t\t6%\n\tB \t\t\t\tUBER\t\t\t\t8%\n\tC "
           "\t\t\t\tPLAYSTATION\t\t\t4%\n\tD \t\t\t\tGLOBOPLAY\t\t\t6%\n\tE "
           "\t\t\t\tNIKE\t\t\t\t2%");
    printf("\n\n\nINSIRA SUA OPÇÃO: ");
    scanf("%s", &opcao_giftcard);
    system("cls");
    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
    Sleep(1);
    printf("\n\nQUAL O VALOR DE GIFTCARD QUE VOCE DESEJA? E SERÃO QUANTAS "
           "QUANTIDADES?");
    printf("\n\nVALORES DISPONIVEIS(10,20,50,100,150,200): ");
    scanf("%d", &valor_giftcard);
    printf("\n\nQUANTIDADE: ");
    scanf("%d", &qntd_giftcard);
    int total_giftcard = valor_giftcard * qntd_giftcard;
    int a = total_giftcard * 0.06, b = total_giftcard * 0.08,
        c = total_giftcard * 0.04, d = total_giftcard * 0.06,
        e = total_giftcard * 0.02;
    if (opcao_giftcard == 'A') {
      printf("\n\n VALOR TOTAL: %d", total_giftcard);
      printf("\n\n O CASHBACK É DE %d REAIS QUANDO FOR UTILIZADO\n", a);
    } else if (opcao_giftcard == 'B') {
      printf("\n\n VALOR TOTAL: %d", total_giftcard);
      printf("\n\n O CASHBACK É DE %d REAIS QUANDO FOR UTILIZADO\n", b);
    }

    else if (opcao_giftcard == 'C') {
      printf("\n\n VALOR TOTAL: %d", total_giftcard);
      printf("\n\n O CASHBACK É DE %d REAIS QUANDO FOR UTILIZADO\n", c);
    } else if (opcao_giftcard == 'D') {
      printf("\n\n VALOR TOTAL: %d", total_giftcard);
      printf("\n\n O CASHBACK É DE %d REAIS QUANDO FOR UTILIZADO\n", d);
    } else if (opcao_giftcard == 'E') {
      printf("\n\n VALOR TOTAL: %d", total_giftcard);
      printf("O CASHBACK É DE %d REAIS QUANDO FOR UTILIZADO.\n", e);
    }
    
    Sleep(4); 
    system("cls");
    printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n\n\n\n- "
           "O VALOR DOS GIFTCARDS SERÁ DESCONTADO NO SEU SALDO!\n");
    saldo = saldo - total_giftcard;
    valor_extrato[contex] = total_giftcard;
    tipo_extrato[contex] = 'G';
    contex++;

    Sleep(3);
    system("cls");
    inicio();
  }
 if(opcao == 4){
  system("cls"); 
   printf(REVERSE C_GRAY
           "\n\t\t===================> J.B.A BANK <==================\n" NONE
               BG_CYAN BLINK BOLD "\n\n");
   printf("\t\t\tBEM VINDO A SUA POUPANÇA!\n\n");
   printf("\t\t\n INFORME O CAPITAL: ");
   scanf("%f", &capital);
   printf("\t\t\n QUAL O TEMPO QUE VOCÊ DESEJA: \t\n [A] MENSAL\n [B] TRIMESTRAL\n [C] SEMESTRAL\n");
   printf(REVERSE C_GRAY"\n\n\nINSIRA SUA OPÇÃO: \n"NONE);
   scanf("%c",&tempo);
   if(tempo=='A')
     {
     tempo= 1;
       resultado=capital*(pow(1.008,tempo));
       printf(BG_CYAN BLINK BOLD UNDERSCORE"\n\tO MONTANTE FINAL É DE: 2%f\n",resultado);
     }
   if(tempo=='B'){
     tempo= 3;
      resultado=capital*(pow(1.008,tempo));
     printf(BG_CYAN BLINK BOLD"\n\tO MONTANTE FINAL É DE: %.2f\n",resultado);
     
   }
   if(tempo=='C'){
      tempo= 6;
      resultado=capital*(pow(1.008,tempo));
     printf(BG_CYAN BLINK BOLD"\n\tO MONTANTE FINAL É DE: %.2f\n",resultado);
   }
   float lucro= resultado-capital;
    valor_extrato[contex] = lucro;
    tipo_extrato[contex] = 'L';
    contex++;
   saldo=1000+lucro;
   Sleep(6);
   system("cls");
   inicio();
   
   
     
     
 }
  if (opcao ==6) {
    Sleep(1);
    system("cls");
    extrato();
    Sleep(6);
    system("cls");
    inicio();
  }

}

int main() 
{
  printf(BG_CYAN BOLD BLINK"_");
  Sleep(1);
  system("cls");
   printf(BG_CYAN BOLD BLINK C_GRAY
         "\t  ===================> J.B.A BANK <=================== \n");
  Sleep(1);
  system("cls");

  printf(REVERSE C_GRAY
         "\n\t  ===================> J.B.A BANK <==================== " NONE);
  Sleep(1);

  printf(BG_CYAN BOLD BLINK "\n\n\t\t\t\t\t    SEJA BEM VINDO!");
  Sleep(1);
  printf(
      "\n\n\t----- PARA COMEÇAR, PRECISAMOS DE ALGUNS DADOS...----- \n" REVERSE
          C_GRAY
      "\n\n\n\t  ===================> J.B.A BANK <==================== \n ");
  Sleep(4);

  printf(REVERSE C_GRAY "\n\n\t\t\t\t\t   < C A D A S T R O >   " NONE);
  Sleep(2);
  system("cls");

  printf(BG_CYAN BOLD BLINK
         "\n------------------------------------\n \aINFORME SEU PRIMEIRO NOME:");

  // sleep(2);
  scanf("%s", nome);
  printf("\n------------------------------------\n \aINFORME O SEU CPF:");
  scanf("%s", cpf);
  while (1 > 0) {
    if (strlen(cpf) != 11) {
      printf(" FORMATO INVÁLIDO, TENTE NOVAMENTE!");
      printf(BG_CYAN BOLD BLINK
             "\n------------------------------------\n INFORME SEU CPF:");
      scanf("%s", cpf);
    }
    if (strlen(cpf) == 11) {
      break;
    }
  }

  // sleep(2);

  printf("\n------------------------------------\n \aESCOLHA UMA SENHA PARA A CONTA: ");
  scanf("%s", &senha_conta);
  Sleep(1);

  printf("\n\t\t\t\t\t\t *CONTA CRIADA*\n");
  Sleep(2);
  system("cls");

  printf(REVERSE C_GRAY "\n\t\t\t\t\t\t  < L O G I N >  " NONE);
  printf( BG_CYAN BOLD BLINK "\n\n\t\t\t\t\t\t\tOLÁ %s! "UNDERSCORE"\n\n\t\t---> SENHA:",nome);
  scanf("%s", &senha_login);

  while (1 > 0) {
    if (senha_login != senha_conta) {
      printf("\nSENHA INVALIDA!!\nDIGITE NOVAMENTE!\n");
      Sleep(1);
      system("cls");
      printf(REVERSE C_GRAY "\n\t\t\t\t\t\t < L O G I N > " NONE);
      printf(BG_CYAN BOLD BLINK "\n---> SENHA:");
      scanf("%s", &senha_login);
    }

    if (senha_login == senha_conta) {
      system("cls");
      break;
    }
  }
  inicio();
  // sleep(3);
  // system("clear||cls");
  // saldo += valor_emprestimo;
  //inicio();
  //
}