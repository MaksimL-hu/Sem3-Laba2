#include <cstdio>
#include <iostream>
#include <string>

#include "DynamicArray.h"


void PlotGraph(DynamicArray<double>& x, DynamicArray<double>& y, std::string name) {
    FILE* gnuplotPipe = _popen("gnuplot -persistent", "w");  // ��������� ����� ����� � Gnuplot
    if (!gnuplotPipe) {
        std::cerr << "Failed to launch Gnuplot." << std::endl;
        return;
    }

    std::string title = "set title '" + name + "'\n";

    // ������������� ��������� ��� �������
    fprintf(gnuplotPipe, "%s", title.c_str());
    fprintf(gnuplotPipe, "set xlabel 'capacity'\n");
    fprintf(gnuplotPipe, "set ylabel 'time'\n");
    fprintf(gnuplotPipe, "plot '-' with lines title 'Data'\n");

    // �������� ������ ��� �������
    for (size_t i = 0; i < x.GetLength(); i++) {
        fprintf(gnuplotPipe, "%f %f\n", x[i], y[i]);
    }

    // ��������� �������� ������
    fprintf(gnuplotPipe, "e\n");
    fflush(gnuplotPipe); // ��������, ��� ������ �������� � Gnuplot
    _pclose(gnuplotPipe); // ��������� �����
}