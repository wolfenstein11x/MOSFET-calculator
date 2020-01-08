#include "stdafx.h"
#include "MOSFET.h"

void Transistor::get_voltages()
{
	std::cout << "Enter the drain voltage: ";
	std::cin >> VD;
	std::cout << "Enter the gate voltage: ";
	std::cin >> VG;
	std::cout << "Enter the source voltage: ";
	std::cin >> VS;
}

double NMOS::calc_current_sat(double &current)
{
	current = 0.5*(kn_)*(W / L)*pow((VG - VS - Vtn), 2);
	return current;
}

double NMOS::calc_current_tri(double &current)
{
	current = (kn_)*(W / L)*((VG - VS - Vtn)*(VD - VS) - 0.5*pow((VD - VS), 2));
	return current;
}

void NMOS::present_answer()
{
	std::cout << "The DC current is " << IDS * 1000 << "mA\n";
}

int NMOS::sat_triode_cutoff()
{
	if (VG - VS <= Vtn) {
		return 0;
	}

	else if (VD <= VG - Vtn) {
		return 1;
	}
	
	else {
		return 2;
	}
}

double PMOS::calc_current_sat(double &current)
{
	current = 0.5*(kp_)*(W / L)*pow((VS - VG - abs(Vtp)), 2);
	return current;
}

double PMOS::calc_current_tri(double &current)
{
	current = (kp_)*(W / L)*((VS - VG - Vtp)*(VS - VD) - 0.5*pow((VS - VD), 2));
	return current;
}

void PMOS::present_answer()
{
	std::cout << "The DC current is " << ISD * 1000 << "mA\n";
}

int PMOS::sat_triode_cutoff()
{
	if (VG - VS > Vtp) {
		return 0;
	}

	else if (VS - VD <= VS - VG - abs(Vtp)) {
		return 1;
	}

	else {
		return 2;
	}
}

bool nmos_or_pmos()
{
	std::cout << "NMOS or PMOS?\n\n";
	std::cout << "[1] NMOS\n";
	std::cout << "[2] PMOS\n";

	int answer;
	std::cin >> answer;

	if (answer == 1) {
		return true;
	}

	else {
		return false;
	}
}