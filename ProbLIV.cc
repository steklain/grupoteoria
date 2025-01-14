#include <iostream>
#include <cmath>
#include <string.h>
#include<float.h>
#include<complex.h>
#include <vector>
#include<gsl/gsl_complex.h>
#include<gsl/gsl_complex_math.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include <globes/globes.h>
#include<fstream>

#include <algorithm>

extern "C"
{
	#include "bsm.h"
}

using namespace std;

char AEDLFILE[] = "DUNE_GLoBES.glb";

int main(int argc, char * argv[])
{

	glbInit(argv[0]);
	glbInitExperiment(AEDLFILE, &glb_experiment_list[0], &glb_num_of_exps);

	ofstream outmu,oute,outtau;

	outmu.open("livprob_mumu.dat");
	oute.open("livprob_mue.dat");
    outtau.open("livprob_mutau.dat");

	double dm21 = 0;
	double dm31 = 2*5.2e-3;// massa tandem
	double theta12 = 0;
	double theta23 = 0;
	double theta13 = 0;
	double deltacp = 0;

bsm_init_probability_engine_3();

	glbRegisterProbabilityEngine(8 * 9 - 3,
                               &bsm_probability_matrix,
							   &bsm_set_oscillation_parameters,
  							   &bsm_get_oscillation_parameters,
  							   NULL);
	/* Define "true" oscillation parameter vector */
	glb_params true_values = glbAllocParams();
  
	for(unsigned int i=0; i < 69; i++)
	{
	glbSetOscParams(true_values, 0.0, i);
	}

	glbDefineParams(true_values,theta12,theta13,theta23,deltacp,dm21,dm31);

    //parametros Tamdem
	double a = -0.85 * 2.4e-19 *1.0e9;
	double c =  1.80  * 3.4e-17;
    double arga = 0.1*M_PI/2;
    
	double abs_a_ee = 0;
	double abs_a_mue = a;
	double arg_a_mue = arga;
	double abs_a_etau = a;
	double arg_a_etau = arga;
	double abs_a_mumu = 0;
	double abs_a_mutau = a;
	double arg_a_mutau = arga;
	double abs_a_tautau = 0;

	double abs_c_ee = -3.0*c/4.0;
	double abs_c_mue = 0;
	double arg_c_mue = 0;
	double abs_c_etau = 0;
	double arg_c_etau = 0;
	double abs_c_mumu = 0;
	double abs_c_mutau = 0;
	double arg_c_mutau = 0;
	double abs_c_tautau = 0;

	//############ LIV Parameter #################################//
	glbSetOscParams(true_values, abs_a_ee, 51);  // a_ee 
	glbSetOscParams(true_values, abs_a_mue, 52);  // a_mue magnitude
    glbSetOscParams(true_values, arg_a_mue, 53);  // a_mue phase
    glbSetOscParams(true_values, abs_a_etau, 54);  // a_etau 
    glbSetOscParams(true_values, arg_a_etau, 55);  // a_etau phase
    glbSetOscParams(true_values, abs_a_mumu, 56);  // a_mumu
    glbSetOscParams(true_values, abs_a_mutau, 57);  // a_mutau
    glbSetOscParams(true_values, arg_a_mutau, 58);  // a_mutau phase
    glbSetOscParams(true_values, abs_a_tautau, 59);  // a_tautau

	glbSetOscParams(true_values, abs_c_ee, 60);  // c_ee 
	glbSetOscParams(true_values, abs_c_mue, 61);  // c_mue magnitude
    glbSetOscParams(true_values, arg_c_mue, 62);  // c_mue phase
    glbSetOscParams(true_values, abs_c_etau, 63);  // c_etau 
    glbSetOscParams(true_values, arg_c_etau, 64);  // c_etau phase
    glbSetOscParams(true_values, abs_c_mumu, 65);  // c_mumu
    glbSetOscParams(true_values, abs_c_mutau, 66);  // c_mutau
    glbSetOscParams(true_values, arg_c_mutau, 67);  // c_mutau phase
    glbSetOscParams(true_values, abs_c_tautau, 68);  // c_tautau

	glbSetDensityParams(true_values,0.0,GLB_ALL);

	glb_params input_errors = glbAllocParams();
  	
	glbSetDensityParams(input_errors, 0., GLB_ALL);
	glbSetInputErrors(input_errors);

	glbSetOscillationParameters(true_values);
	glbSetRates();

	double energy,prob_mumu,prob_mue,prob_mutau;
	double step= 30000;
	[[maybe_unused]] double L = 1300;// km
    glbSetBaselineInExperiment(0, L);
    double emin= 0.5;//L/1e4 ; //GeV
	double emax= 10; //L/1e1 ; //GeV
  
	//cout <<  glbGetNumberOfFluxes(0) << endl;

	for (energy=emin;energy<=emax;energy+=(emax-emin)/step)
	{
	prob_mumu=glbProfileProbability(0,2,2,+1,energy);
	prob_mue=glbProfileProbability(0,2,1,+1,energy);
	prob_mutau=glbProfileProbability(0,2,3,+1,energy);
	
	oute<<energy<<"  "<<prob_mue<<endl;
	outmu<<energy<<"  "<<prob_mumu<<endl;
    outtau<<energy<<"  "<<prob_mutau<<endl;
	}

	outmu.close();
	oute.close();
    outtau.close();

	glbFreeParams(true_values);
 	return 0;

}

//int p = find(bsm_param_strings[801].begin(),bsm_param_strings[801].end(),"ABS_A_V_MUE");
	//cout << p << endl;

//for (int p=0;p<69;p++){
	//	cout << p << " " <<  bsm_param_strings[p] << endl;
	//}
