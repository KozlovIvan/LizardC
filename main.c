#include <stdio.h>
#include "lizard.h"
#include "stdint.h"
/*
 * Input formats must be 120 bit key as 30 hex values and 64 bit IV as 16 hex values.
 * The keystream output length can be chosen between 1 bit and 10000 bits.
 */

uint8_t K[120];
uint8_t IV[64];
uint8_t z[258];
uint8_t L[258];
uint8_t Q[258];
uint8_t T[258];
uint8_t Ttilde[258];
uint8_t B[258][90];
uint8_t S[258][31];
uint8_t a257 = 0;
int t = 0;
uint8_t keystream[258];




void _construct(uint8_t  *key, uint8_t *iv, int length){

    for(int i = 0; i < 259; ++i){
        z[i] = 0;
        L[i] = 0;
        Q[i] = 0;
        T[i] = 0;
        Ttilde[i] = 0;
        _initialization(key, iv);
    }
    if(length > 0){
        keysteamGeneration(length);
    }
}

void _initialization(uint8_t *key, uint8_t *iv){

    //Phase 1
    loadkey(key);
    loadIV(iv);
    initRegisters();

    //Phase 2
    for(;t<=127; ++t){
        mixing();
    }

    //Phase 3
    keyadd();

    //Phase 4
    t=129;
    for(; t<=256; ++t){
        diffusion();
    }

}

void loadkey(uint8_t *key){

    for (int i = 0; i < 119; ++i){
        K[i] = key[i];
    }
}

void loadIV(uint8_t *iv){
    for (int i = 0; i < 63; ++i){
        IV[i] = iv[i];
    }
}

void initRegisters(){

    for(int i = 0; i <=63; ++i){
       B[0][i] = K[i]^IV[i];
    }

    for(int i = 64; i<=89; ++i){
        B[0][i] = K[i];
    }

    for(int i = 0; i <=28; ++i){
       S[0][i] = K[i+90];
    }

   S[0][29] = K[119] ^ (uint8_t )1;
   S[0][30] = 1;
}

void mixing(){

    z[t] = a();
    for(int i = 0; i<=88; ++i) {
        B[t + 1][i] = B[t][i + 1];
    }

    B[t+1][89] = z[t] ^ NFSR2();

    for(int i = 0; i <= 29; ++i){
        S[t+1][i] = S[t][i+1];
    }
    S[t+1][30] = z[t] ^ NFSR1();
}

uint8_t a(){

    L[t] = B[t][7]  ^ B[t][11] ^ \
             B[t][30] ^ B[t][40] ^ \
             B[t][45] ^ B[t][54] ^ \
             B[t][71];

	Q[t] = B[t][4]  * B[t][21] ^ \
           B[t][9]  * B[t][52] ^ \
           B[t][18] * B[t][37] ^ \
           B[t][44] * B[t][76];

	T[t] = B[t][5]  ^ B[t][8]  * \
           B[t][82] ^ B[t][34] * \
           B[t][67] * B[t][73] ^ \
           B[t][2]  * B[t][28] * \
           B[t][41] * B[t][65] ^ \
           B[t][13] * B[t][29] * \
           B[t][50] * B[t][64] * \
           B[t][75] ^ B[t][6]  * \
           B[t][14] * B[t][26] * \
           B[t][32] * B[t][47] * \
           B[t][61] ^ B[t][1]  * \
           B[t][19] * B[t][27] * \
           B[t][43] * B[t][57] * \
           B[t][66] * B[t][78];

	Ttilde[t] = S[t][23] ^ S[t][3]  * \
                S[t][16] ^ S[t][9]  * \
                S[t][13] * B[t][48] ^ \
                S[t][1]  * S[t][24] * \
                B[t][38] * B[t][63];

		return L[t] ^ Q[t] ^ T[t] ^ Ttilde[t];
}

uint8_t NFSR2(){

    return \
    S[t][0]  ^ B[t][0]  ^ \
    B[t][24] ^ B[t][49] ^ \
    B[t][79] ^ B[t][84] ^ \
    B[t][3]  * B[t][59] ^ \
    B[t][10] * B[t][12] ^ \
    B[t][15] * B[t][16] ^ \
    B[t][25] * B[t][53] ^ \
    B[t][35] * B[t][42] ^ \
    B[t][55] * B[t][58] ^ \
    B[t][60] * B[t][74] ^ \
    B[t][20] * B[t][22] * \
    B[t][23] ^ B[t][62] * \
    B[t][68] * B[t][72] ^ \
    B[t][77] * B[t][80] * \
    B[t][81] * B[t][83];
}

uint8_t NFSR1(){

    return \
    S[t][0]  ^ S[t][2]  ^ \
    S[t][5]  ^ S[t][6]  ^ \
    S[t][15] ^ S[t][17] ^ \
    S[t][18] ^ S[t][20] ^ \
    S[t][25] ^ S[t][8]  * \
    S[t][18] ^ S[t][8]  * \
    S[t][20] ^ S[t][12] * \
    S[t][21] ^ S[t][14] * \
    S[t][19] ^ S[t][17] * \
    S[t][21] ^ S[t][20] * \
    S[t][22] ^ S[t][4]  * \
    S[t][12] * S[t][22] ^ \
    S[t][4]  * S[t][19] * \
    S[t][22] ^ S[t][7]  * \
    S[t][20] * S[t][21] ^ \
    S[t][8]  * S[t][18] * \
    S[t][22] ^ S[t][8]  * \
    S[t][20] * S[t][22] ^ \
    S[t][12] * S[t][19] * \
    S[t][22] ^ S[t][20] * \
    S[t][21] * S[t][22] ^ \
    S[t][4]  * S[t][7]  * \
    S[t][12] * S[t][21] ^ \
    S[t][4]  * S[t][7]  * \
    S[t][19] * S[t][21] ^ \
    S[t][4]  * S[t][12] * \
    S[t][21] * S[t][22] ^ \
    S[t][4]  * S[t][19] * \
    S[t][21] * S[t][22] ^ \
    S[t][7]  * S[t][8]  * \
    S[t][18] * S[t][21] ^ \
    S[t][7]  * S[t][8]  * \
    S[t][20] * S[t][21] ^ \
    S[t][7]  * S[t][12] * \
    S[t][19] * S[t][21] ^ \
    S[t][8]  * S[t][18] * \
    S[t][21] * S[t][22] ^ \
    S[t][8]  * S[t][20] * \
    S[t][21] * S[t][22] ^ \
    S[t][12] * S[t][19] * \
    S[t][21] * S[t][22];
}

void keyadd(){

    for(int i = 0; i <= 89; ++i){
        B[129][i] =  B[128][i] ^ K[i];
    }

    for(int i = 0; i <= 29; ++i){
        S[129][i] = S[128][i] ^ K[i+90];
    }

    S[129][30] = 1;
}

void diffusion(){

    for(int i = 0; i <= 88; ++i){
        B[t+1][i] = B[t][i+1];
    }

    B[t+1][89] = NFSR2();

    for(int i = 0; i <= 29; ++i){
        S[t+1][i] = S[t][i+1];
    }

    S[t+1][30] = NFSR1();

}

void keysteamGeneration(int length){

    for(int i = 0 ; i <=258; ++i){
        keystream[i] = 0;
    }

    for(int i = 0; i <= length; ++i){
        keystream[i] = a();
        diffusion();
        ++t;
    }


}

void keystreamGenerationSpecification(/*length*/){
    //TODO
}

void getKeystream(){
    //TODO
}

void binArray2hex(/*bin*/){
    //TODO
}

void hex2binArray(/*hex*/){
    //TODO
}


int main() {
    //TODO
    return 0;
}