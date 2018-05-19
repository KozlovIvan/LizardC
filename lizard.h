//
// Created by Ivan Kozlov on 12/05/2018.
//
#include <stdint.h>

#ifndef LIZARD_LIZARD_H
#define LIZARD_LIZARD_H

#define KEYSTREAM_SIZE 258

void loadkey(uint8_t *key);
void loadIV(uint8_t *iv);
void initRegisters();
void mixing();
void keyadd();
void diffusion();
uint8_t NFSR1();
uint8_t NFSR2();
void _construct(uint8_t  *key, uint8_t *iv, int length);
void _initialization(uint8_t *key, uint8_t *iv);
void keysteamGeneration(int length);
uint8_t* keystreamGenerationSpecification(int length);
uint8_t a();
char* binArray2hex(uint8_t * bin, int size);
char* binArray2hex(uint8_t * bin, int size);
uint8_t hex2int(char ch);

#endif //LIZARD_LIZARD_H
