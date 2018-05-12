#include <stdio.h>

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




void _construct(/*key, IV, length*/){
    //TODO
}

void _initialization(/* key, IV */){
    //TODO
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

void NFSR1(){
    //TODO
}

void keyadd(){
    //TODO
}

void diffusion(){
    //TODO
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