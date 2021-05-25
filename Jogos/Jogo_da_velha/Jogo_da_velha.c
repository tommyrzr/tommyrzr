#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i,j,seguir = 1,linha,coluna,vez,verifica1,verifica2,ganhador1,ganhador2,empate,rodada=0,ganhou,dvelha=0,cont=0;
int vitoria1=0, vitoria2=0;
char velha[4][4],jog1,jog2;
char tabuleiro();
int jogador1();
int jogador2();
char ImprimeTabuleiro();
char tabu();
char tabuleiro();
int verificarlinha();
int verificacolunas();
int verificadiagonal();
int fimdojogo();
int trofeu();
int deuvelha();
int zerar();

int main() {
		
		setlocale(LC_ALL, "Portuguese");
   		tabu();
		printf("\n");
		tabuleiro();
		printf("_______________________Jogue em tela cheia!_______________________\n");

		 while(seguir==1 && rodada<2){
			if(vez%2==0){
				jogador1();
            	printf("\n");
				ImprimeTabuleiro();
            	printf("\n");
            	verificarlinha();
				verificacolunas();
				verificadiagonal();
				deuvelha();
				fimdojogo();
				if(ganhou==1){
					ganhou=0;
					tabuleiro();
					rodada=rodada+1;
					vez=0;
					}
				if (dvelha==1){
					tabuleiro();
					vez=0;}
				if(vitoria1==2){
					system("cls");
					printf("                 Parabéns jogador 1!!!                     \n");
					trofeu();
					printf("Deseja jogar novamente? Qualquer outra tecla - Não e 1 - Para Sim: ");
					scanf("%d", &seguir);
					if(seguir!=1){
						printf("Você escolheu sair! \n");
						break;
					}
					else{
						zerar();
						
					}
					}
				            
					}
			else{
				jogador2();
            	printf("\n");
				ImprimeTabuleiro();
            	printf("\n");
            	verificarlinha();
				verificacolunas();
				verificadiagonal();
				deuvelha();
				fimdojogo();
				if(ganhou==1){
					ganhou=0;
					tabuleiro();
					rodada=rodada+1;
					vez=0;
					}
				if (dvelha==1){
					printf("Deu Velha!. \n");
					zerar();
				}
				if(vitoria2==2){
					system("cls");
					printf("                 Parabéns jogador 2!!!                     \n");
					trofeu();
					if(seguir!=1){
						printf("Você escolheu sair! \n");
						break;
					}
					else{
						zerar();
					}
			}
		}

	}
	return 0;
}

char tabuleiro(){

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			velha[i][j]='-';
		}
	}
}
char ImprimeTabuleiro(){
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf(" %c |",velha[i][j]);
		}
		printf("\n");
	}
}

int jogador1(){

	printf("Jogador 1: digite a linha que deseja jogar: ");
	scanf("%d", &linha);
	printf("Jogador 1: digite a coluna que deseja jogar: ");
	scanf("%d", &coluna);

	if(linha>=0 && linha<4 && coluna>=0 && coluna<4){
		if(velha[linha][coluna]!='X' && velha[linha][coluna]!='O'){
			velha[linha][coluna]='X';
			vez=vez+1;
		}
		else{
			printf("A posição já foi jogada! \n");
		}

	}
	else{
		printf("Digite novamente. \n");
	}

}
int jogador2(){

	printf("Jogador 2: digite a linha que deseja jogar: ");
	scanf("%d", &linha);
	printf("Jogador 2: digite a coluna que deseja jogar: ");
	scanf("%d", &coluna);

	if(linha>=0 && linha<4 && coluna>=0 && coluna<4){
		if(velha[linha][coluna]!='X' && velha[linha][coluna]!='O'){
			velha[linha][coluna]='O';
			vez=vez+1;
		}
		else{
			printf("A posição já foi jogada! \n");
		}

	}
	else{
		printf("Digite novamente. \n");
	}
}
char tabu (){
    printf("< velha que o jogador pode escolher >\n");
    printf("linhas vai de de 0 a 3 e coluna vai de 0 a 3\n");
    printf("      coluna coluna coluna coluna\n");
    printf("              |     |     |    \n");
    printf("linha     0/0 | 0/1 | 0/2 | 0/3\n");
    printf("      --- --- | --- | --- | --- ---\n");
    printf("linha     1/0 | 1/1 | 1/2 | 1/3\n");
    printf("      --- --- | --- | --- | --- ---\n");
    printf("linha     2/0 | 2/1 | 2/2 | 2/3\n");
    printf("      --- --- | --- | --- | --- ---\n");
    printf("linha     3/0 | 3/1 | 3/2 | 3/3\n");
    printf("              |     |     |    \n");
}

int verificarlinha(){
	//Linhas
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(velha[i][j]=='X'){
				verifica1=verifica1+1;	
			}
			if(velha[i][j]=='O'){
				verifica2=verifica2+1;
			}
		}
		if(verifica1==4){
			ganhador1=1;
		}
		else{
			verifica1=0;
		}
		if(verifica2==4){
			ganhador2=1;
		}
		else{
			verifica2=0;
		}
	}
}
int verificacolunas(){
		//Colunas
		
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			if(velha[i][j]=='X'){
				verifica1=verifica1+1;	
			}
			if(velha[i][j]=='O'){
				verifica2=verifica2+1;
			}
		}
		if(verifica1==4){
			ganhador1=1;
		}
		else{
			verifica1=0;
		}
		if(verifica2==4){
			ganhador2=1;
		}
		else{
			verifica2=0;
		}
	}
}
int verificadiagonal(){
	
    if(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X' && velha[3][3] == 'X' ){
    	ganhador1=1;
	}
    if(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O' && velha[3][3] == 'O' ){
    	ganhador2=1;
	}
       
    if(velha[0][3] == 'X' && velha[1][2] == 'X' && velha[2][1] == 'X' && velha[3][0] == 'X' ){
    	ganhador1=1;
	}
        
    if(velha[0][3] == 'O' && velha[1][2]  == 'O' && velha[2][1] == 'O' && velha[3][0]  == 'O'){
    	ganhador2=1;
	}
        
	
}
int deuvelha(){
	cont=0;
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(velha[i][j]!='-'){
				cont=cont+1;
			}
		}
	}

	if(cont==16 && ganhador1!=1 && ganhador2!=1 ){
		dvelha=1;
		cont=0;
	}

}
int fimdojogo(){
	
	if(ganhador1==1){
		printf("Jogador 1 venceu \n");
		ganhou=1;
		vitoria1=vitoria1+1;
		ganhador1=0;
		
	}
	if(ganhador2==1){
		printf("Jogador 2 venceu \n");
		ganhou=1;
		vitoria2=vitoria2+1;
		ganhador2=0;
	}
	if(rodada==2 && ganhador2==1 && ganhador1==1 ){
		printf("Empate \n");
		rodada=0;
		vez=0;
	}
	
}
int trofeu(){
	printf("                                                  riririririririririririririririririririririririi:i:iri                              \n");                  
	printf("                                                 .ri:i:::i:::i:i:i:::::i:i:::::::i:i:i:i:i:::i:::::::ii                              \n");                 
	printf("                                                 .i:::::::::::::::::::::::::::::::::::::::::::::..:.::i.                            \n");                   
	printf("                                                 :::::::.:.:.:.:::.:::.:::.:::::.:::.:.:.:.:.:.:.....::.                            \n");                   
	printf("                                                 ::.:::.:.:.:.:.:::.:.:::.:.:.:.:.:.:::.:.:.:.::......:.                            \n");                  
	printf("                                     r7LLL77ri::.:.:.:.:.:.:.:.:.:.:.:.:.:.....:.:.:.:.:.:.:.:.:.....:::.::ii77LvL7i                \n");                  
	printf("                                    rrr:::rr77vvr.....:.:.:.:...:.:...:.:..:i:..:.:.:.:.:.:.:.........:.7vv77rri::r7:               \n");                 
	printf("                                    :ii         .:...:.......:.:.:...:....:i:i:....:...:.....:.:.......:.        .ir:               \n");                   
	printf("                                    ::i          ::.:.................:..:i:::i...:.:...:.....:.......::         .ii.               \n");                   
	printf("                                    ::i          :::.....:.:.:...........i:::::i.............:.:.....:::         .:i.               \n");                   
	printf("                                   ::i          ::.:.:.:.:...:...:.:.::i:i:i:i::::::.....:.:.:.......::         .i:.                \n");                  
	printf("                                    :::          :::.:.:.:.:.:.:ii:iii:i:i:::::i:i:iii:ii:.:.:::.....:::         .::.               \n");                   
	printf("                                    .::.         .:.:.:.:.:.:.::iii:i:i:i:i:i:i:::i:i:iii.:.:.:.....::i.         .::.               \n");                   
	printf("                                    .i::         .::.:.:.:.:::.:.:iiii:i:i:i:i:i:i:i:i::.:::.::....::::          ::i                \n");                   
	printf("                                     :::          i::::::::::::.:.::i:i:iii:iii:i:iii::.:.:::::.:.:.:::         .:::                \n");                   
	printf("                                     .ii:         :i::::::::::::::.::i:i:iii:iiiiiii.:.:::::::.:.:.::i.         ::i                 \n");                   
	printf("                                      iii.        .i:::::::::::::::.:iiiiiiiiiiiiiri:.:::::::::.:.:::i         :ii:                 \n");                   
	printf("                                       rir.        :i::::::::::::::::riiiriririiirir::::::::::::::::i.        :ri:                  \n");                   
	printf("                                        irr:        r:::::::::::::::rrrirrriiirrrirri::::::::::::::ir        irri                   \n");                   
	printf("                                         :77r.      .r::::::::::::::r7rrii:::::iirr7r::::::::::::i:r       :r77:                    \n");                   
	printf("                                          .rL7r.     :r:::::::::::::rii:::::::::::irr:::::i:::::::r.     .rvLr.                     \n");                   
	printf("                                            :vYJ7i    :i:::i:i:i:i:i:::::::i:i:::::::i:i:i:::::i:i.   .i7jL7.                       \n");                   
	printf("                                              .rJ11vr.:ii:i:i:i:i:i:i:i:i:i:i:i:i:i:i:i:ii::::iiii..rv1uJi.                         \n");                   
	printf("                                                 :iYuUjYrriiii:iiiiiiiii:i:iii:iii:iiiiiii:::iirrYjIuYi:                            \n");                   
	printf("                                                     .:iii7iiiiiiii:iiiiiiiiiii:i:i:i:iii:i:ir7rri:.                                \n");                   
	printf("                                                          :Yrriiiriiiiiiiiiiiriiiririiii:iir7v.                                     \n");                   
	printf("                                                           .7v7iriririiiriiiririiiiiriiiii7Lr                                       \n");                   
	printf("                                                             :vY7rrrrriririrrririririiir7j7.                                        \n");                   
	printf("                                                               :vss77rrrrrrirrrrrrrirrsJ7.                                          \n");                   
	printf("                                                                 .iLsJLv77r7r7r77vvJsv:                                             \n");                   
	printf("                                                                     .irvvLvLvL77ri.                                                \n");                   
	printf("                                                                         :::.::.                                                    \n");                   
	printf("                                                                         :. ....                                                    \n");                   
	printf("                                                                        .:.....:                                                    \n");                   
	printf("                                                                        ::....::.                                                   \n");                   
	printf("                                                                       .::.:...::                                                   \n");                   
	printf("                                                                       ii::.:.::i:                                                  \n");                   
	printf("                                                                      :r:::::::::r.                                                 \n");                   
	printf("                                                                      7ii:::::::iir                                                 \n");                   
	printf("                                                                     v7rri:iii:irrvr                                                \n");                   
	printf("                                                                    i7rii:iiiiiiiir7:                                               \n");                   
	printf("                                                               ..:ii::...:.:.:.:...::ii...                                          \n");                   
	printf("                                                            ..:.......... . . . . . ........                                        \n");                   
	printf("                                                           .ri:::i:i:::i:i:i:i:i:i:::::::i:ir.                                      \n");                   
	printf("                                                    :BBBBBBQBRQgggQQBQBQBBBBBQBBBQBBBBBQBRQgRgRMBQBQ                                \n");                   
	printf("                                        7RdPKqXKXXS5KBgMDDdPqPXqXS2IUUJjYJYsLJYjsu1I25SqqdPbbEEMgQQBKqqPPdPEdZZB.                   \n");                   
	printf("                                        LBBBBQBBBQBBQqPEEPXSbPqqP5U2U1v7777rrrv777YJ1uqqdPbPdPMQQRBBBBBBBBBBBQBB.                   \n");                   
	printf("                         7Xsv777r7r7rri:SBggEZbdbR7 YBg  LgM  g. SP. rSuL  2r  u1I: 7Z.      gu      XQMDggMgRQBvirrr7r7r77vYPi     \n");                   
	printf("                         .BBBBBQBBBBBBBgRRDdEPbPPgX  BU   Bq  B  IZ   iqu  Xi   uE: 7g  SZdKqBr iBBd  QgDZgZggMQQMBBBBBBBBBBBB      \n");                   
	printf("                           BBQZDdEbdPPqXdMEEdEPbqdB  B  S 57 uB  KD  i :X  qi :  Sr vQ  ..  iBr  i:: iBMEgZggggQPXPdbZdZZggBQ       \n");                   
	printf("                          .BQgPdPdqPqq2dgDbZbbPbPQ1 . 7B    RQ  5g  gi .  Xi iK  . LQ  IKSUbB7 .U  iBBZZZgZgDMRPIqKPPdPEEQB.        \n");                  
	printf("                            .BDEbdPPqPS5bMEZPEPPqbdB   RBv  iQD  Id  Xqi   X: .KI   rR  :rii:Qr iBQi  QREDZgDgDQKSKPPbPdbgQ:        \n");                   
	printf("                            .BgbdPbqPKK2EgDddPdqPPEM2.JgPE:.Pqbi.SK..uJU7 :Jr ivjU: uX7.. . .PS UMMBr ggDEgEMgMRPIPqbqdPEZB         \n");                   
	printf("                           .QQEdPdPPKqK5bMZZPPXXXqgQQgPS1SPE521PPUY2Jvrrrvriiriii7Y1sJ2PPZEDZPPRdPPgBBBDbEdDDggQqSKPqdPdbDBB        \n");                   
	printf("                           QBggdEdEPPqP5dgQQBQQRBB. iQQggDDEEPbqPKqSKSK5KIX5X5KXqKPqPPEdZdDdEbZbZEgR. 7BQRQQBBBMPKPPdPdEDZRBB       \n");                   
	printf("                         BBBBBBBBBBQBQQggDQBBQBBB. :BQQgggMDgZgZggRMQQBBBBBBBQBQBQQMQgMDDEZdZdDEDgQ  rBBBBBQRggMQQBBBBBQBBBBB       \n");                  
	printf("                        LBPXI5U5U212uuJJYsv7777KgQQMXS2IIXSPqPPddDEZEZEDgDZZEEbEPdqPKKSSIS5KqPPddDMBQBBUr77vvJs1J112U2USISSdB7      \n");                  
	printf("                                                :BQQRRDgdgDRgRRQRBQBQBBBBBBBQBQBQQQQMRMMZgEggRMQQBBBBBQB                            \n");                   
	printf("                                                rBgZDEZPbdEEDDgDMggMQMRMQRQRQMRgRggDgZZddPdbDZgDMgQQBBBB.                           \n");
	
	
	
}
int zerar(){
	ganhou=0;
	tabuleiro();
	rodada=0;
	vez=0;
	vitoria1=0;
	vitoria2=0;
	cont=0;
	ganhador1=0;
	ganhador2=0;
	verifica1=0;
	verifica2=0;
	dvelha=0;
}
