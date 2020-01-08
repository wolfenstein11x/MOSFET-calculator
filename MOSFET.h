#pragma once
#include "stdafx.h"
#include <iostream>

bool nmos_or_pmos();

class Transistor
{
public:
	const double W = 0.00001;
	const double L = 0.00000018;

	// these values will be input by user
	double VD;
	double VG;
	double VS;

	void get_voltages();
};

class NMOS: public Transistor
{
public:
	// adjust these constants as needed
	const double Vtn = 1.0;
	const double kn_ = 0.00008;
	
	// DC drain to source current is what you are solving for, initialize it to arbitrary value
	double IDS = 0;

	double calc_current_sat(double &current);
	double calc_current_tri(double &current);
	int sat_triode_cutoff();
	bool valid_input_check();
	void present_answer();

};

class PMOS : public Transistor
{
public:
	// adjust these constants as needed
	const double Vtp = -1.0;
	const double kp_ = 0.00002;
	
	// DC source to drain current is what you are solving for, initialize it to arbitrary value
	double ISD = 0;

	double calc_current_sat(double &current);
	double calc_current_tri(double &current);
	int sat_triode_cutoff();
	bool valid_input_check();
	void present_answer();
};

