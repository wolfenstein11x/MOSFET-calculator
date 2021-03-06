//TODO: handle invalid input

#include "stdafx.h"
#include "MOSFET.h"

int main()
{
	NMOS nmos;
	PMOS pmos;

	if (nmos_or_pmos()) {
		
		nmos.get_voltages();

		if (nmos.sat_triode_cutoff() == 0) {
			std::cout << "Transistor is in cutoff mode. Current is zero.\n";
		}

		else if (nmos.sat_triode_cutoff() == 1) {
			nmos.calc_current_tri(nmos.IDS);
			std::cout << "Triode region. ";
			nmos.present_answer();
		}

		else {
			nmos.calc_current_sat(nmos.IDS);
			std::cout << "Saturation region. ";
			nmos.present_answer();
		}
	}

	else {

		pmos.get_voltages();

		if (pmos.sat_triode_cutoff() == 0) {
			std::cout << "Transistor is in cutoff mode. Current is zero.\n";
		}

		else if (pmos.sat_triode_cutoff() == 1) {
			pmos.calc_current_tri(pmos.ISD);
			std::cout << "Triode region. ";
			pmos.present_answer();
		}

		else {
			pmos.calc_current_sat(pmos.ISD);
			std::cout << "Saturation region. ";
			pmos.present_answer();
		}
	}

	
	return 0;
}