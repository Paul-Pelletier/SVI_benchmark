#pragma once
#ifndef SVIMODEL_H
#define SVIMODEL_H

#include <vector>
#include <string>

class SVIModel {
public:
    SVIModel(); // Constructeur

    double svi(double k);  // Fonction de la surface SVI
    double loss_function(const std::vector<double>& strikes,
        const std::vector<double>& ivs);
    void save_volatility_curve(const std::vector<double>& strikes, const std::string& filename);

private:
    double a, b, rho, m, sigma; // Paramètres SVI
};

#endif // SVIMODEL_H
