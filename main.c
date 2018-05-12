#include <stdio.h>
#include "lizard.h"

/*
 * Input formats must be 120 bit key as 30 hex values and 64 bit IV as 16 hex values.
 * The keystream output length can be chosen between 1 bit and 10000 bits.
 */
//key bin
u_int8_t K[120];
//iv bin
u_int8_t IV[64];

//B
u_int8_t B[258][90];
//S
u_int8_t S[258][31];

// bool a257 = false;
u_int8_t a257 = 0;
int t = 0;




void _construct(/*key, IV, length*/){
    //TODO
}

void _initialization(u_int8_t *key, u_int8_t *iv){

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

void loadkey(u_int8_t *key){

    for (int i = 0; i < 119; ++i){
        K[i] = key[i];
    }
}

void loadIV(u_int8_t *iv){
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

   S[0][29] = K[119] ^ 1;
   S[0][30] = 1;
}

void mixing(){
    //TODO
}

void a(){
    //TODO
}

u_int8_t NFSR2(){

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

u_int8_t NFSR1(){

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
    S[t][21] * S[t][21] ^ \
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

void keysteamGeneration(/*length*/){
    //TODO
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