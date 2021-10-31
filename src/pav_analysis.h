#ifndef PAV_ANALYSIS_H
#define PAV_ANALYSIS_H

float compute_power(const float *x, unsigned int N);
float compute_am(const float *x, unsigned int N);
float compute_zcr(const float *x, unsigned int N, float fm);
float Ventana_Hamming (int n, int N);
float compute_power_ventanada(const float *x, unsigned int N, unsigned int fm);

#endif	/* PAV_ANALYSIS_H	*/
