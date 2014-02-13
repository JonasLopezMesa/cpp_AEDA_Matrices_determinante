//
//  main.cpp
//  Práctica_6
//
//  Created by Jonás López Mesa on 09/05/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#include "matrices_3.hpp"
#include <iostream>

int main ()
{
    matrix_t A;
    A.read(cin);
    cout << "---  MATRIZ ORIGINAL  ---" << endl;
    A.mostrarMatriz();
    cout << "---  DETERMINANTE DE LA MATRIZ ORIGINAL  ---" << endl;
    double det = A.determinante();
    cout << A.determinante() << endl;
    cout << "---  MATRIZ INVERSA  ---" << endl;
    
    A.inversa();

    
    
    return 0;
}

