#include <stdio.h>

/*
 * Input formats must be 120 bit key as 30 hex values and 64 bit IV as 16 hex values.
 * The keystream output length can be chosen between 1 bit and 10000 bits.
 */
//key
u_int8_t K[30];
//iv
u_int8_t IV[16];
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
    //TODO
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