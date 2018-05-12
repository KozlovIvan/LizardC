//
// Created by Ivan Kozlov on 12/05/2018.
//

#include <ntsid.h>

#ifndef LIZARD_LIZARD_H
#define LIZARD_LIZARD_H

void loadkey(u_int8_t *key);
void loadIV(u_int8_t *iv);
void initRegisters();
void mixing();
void keyadd();
void diffusion();
u_int8_t NFSR1();
u_int8_t NFSR2();


#endif //LIZARD_LIZARD_H
