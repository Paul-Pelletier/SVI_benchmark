#include "SVIModel.h"
#include <cmath>
#include <fstream>
#include <iostream>

SVIModel::SVIModel() : a(0.1), b(0.2), rho(0.0), m(0.0), sigma(0.1) {}

double SVIModel::svi(double k) {
    return a + b * (rho * (k - m) + sqrt((k - m) * (k - m) + sigma * sigma));
}

double SVIModel::loss_function(const std::vector<double>& strikes,
    const std::vector<double>& ivs) {
    double loss = 0.0;
    for (size_t i = 0; i < strikes.size(); ++i) {
        double error = svi(strikes[i]) - ivs[i];
        loss += error * error;
    }
    return loss;
}
void SVIModel::save_volatility_curve(const std::vector<double>& strikes, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    for (double k : strikes) {
        file << k << " " << svi(k) << "\n";
    }

    file.close();
    std::cout << "Données sauvegardées dans " << filename << std::endl;
}