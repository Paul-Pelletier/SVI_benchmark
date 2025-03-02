// SVI_benchmark.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "SVIModel.h"
#include <vector>
#include <cstdlib>

int main()
{
    SVIModel model;

    // Générer des strikes de -1 à 1
    std::vector<double> strikes;
    for (double k = -1.0; k <= 1.0; k += 0.1) {
        strikes.push_back(k);
    }
    // Sauvegarder les valeurs dans un fichier
    std::string filename = "volatility_data.txt";
    model.save_volatility_curve(strikes, filename);

    // Exécuter Gnuplot pour afficher la courbe
    std::string gnuplot_cmd = "gnuplot -p -e \"plot '" + filename + "' using 1:2 with lines title 'SVI Volatility Smile'\"";
    system(gnuplot_cmd.c_str());

    std::cout <<"Hello, C++ for financial modeling" << std::endl;
	return 0;
}