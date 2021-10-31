#include <math.h>
#include "pav_analysis.h"

float PI = acos(-1);

float compute_power(const float *x, unsigned int N) {
    int i;
    float P=0;
    float sum=0;

    for(i=0; i<N; i++){
        sum = sum + x[i] * x[i];        
    }

    P=sum/N;
    return 10*log10(P);

}
float Ventana_Hamming (int n, int N){
    if( n>= 0 && n<N){
        return 0.54 -0.46 * cos ((2*PI*n)/(N-1));
    }
    return 0;

}

float compute_power_ventanada(const float *x, unsigned int N, unsigned int fm){
    float NTlong = fm * 0.02;
    float Tdesp = fm *0.01;
    float i = 0, w = 0;
    int cont = 0, inicio = 0, n=0;

    while(n<N){
        inicio = cont * Tdesp;

        for(n = inicio; n< (inicio + NTlong); n++){
            w = Ventana_Hamming(n-inicio, NTlong);
            if(w && n<N){
                i += (x[n]*w) * (x[n] * w) / (w*w);
            }
        }
        cont ++;
    }
    return 10 * log10 (i);

}

float compute_am(const float *x, unsigned int N) {
    int i;
    float res = 0;
    float sum =0;
    
    for(i=0; i<N; i++){     
        //sumx = sqrt(x[i] * x[i]); 
        //sum = sum + sumx;
        float a = x[i]; 
        if(x[i]<0){
            a = (-1) * a;
        }      
        sum = sum + a;
    }    
    res = sum/N;
    return res;

}

float compute_zcr(const float *x, unsigned int N, float fm) {
     float res;
     float sum = 0;
     int i;
     for(i=0; i<N; i++){     
        //sumx = sqrt(x[i] * x[i]); 
        //sum = sum + sumx; 
        if(x[i -1]* x[i] <0){
            sum = sum +1;
        }      
    }    
    res = (fm/(2*(N-1)))*sum;
   
    return res;
}
