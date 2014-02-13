
#pragma once

#include <stdio.h>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas
#include <fstream>

using namespace std;


//========================================================================================
// Definición de tipos
//========================================================================================

/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef double 		matrix_item_t;	
/** Tipo de dato para índices de la matriz.                 */
typedef unsigned short int 	matrix_inx_t;	
/** Tipo de dato para índices del vector  .                 */
typedef unsigned short int 	vector_inx_t;	

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Clase que representa una matriz de mxn elementos. */

class matrix_t {

//========================================================================================
// Atributos privados.
//========================================================================================

private:

	matrix_item_t*	M_;	/**< Puntero que apunta al comienzo del vector conteniendo los elementos de la matriz. */

	matrix_inx_t  	m_;	/**< Número de filas.   */
	matrix_inx_t	n_;	/**< Número de columnas.*/
    bool            traspuesta_;



//========================================================================================
// Métodos públicos.
//========================================================================================

public:

/**	
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Constructor. Reserva memoria para una matriz de mxn elementos.

       * @param 	m número de filas del tipo matrix_inx_t.       
       * @param 	n número de columnas del tipo matrix_inx_t.       
       * @see 		matrix_inx_t.

*/

	matrix_t(matrix_inx_t m,matrix_inx_t n); 

/**	
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Constructor por defecto. Construye una matriz de dimensión 0x0.

*/

	matrix_t(void); 	

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Destructor. Libera la memoria de la matriz.
 */

	~matrix_t(void);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Muestra la matriz formateada.

 */

	void  mostrarMatriz(void);


/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve el elemento de la posición (i,j) de la matriz.

       * @param 	i fila del elemento.
       * @param 	j columna del elemento
       * @see 		matrix_inx_t.
       * @return 	el valor en la posición (i,j).
       * @see 		vector_inx_t.
 */

	matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j);


/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Asigna un valor al elemento (i,j) de la matriz.

       * @param 	it valor a asignar.
       * @param 	i fila del elemento.
       * @param 	j columna del elemento
       * @see 		matrix_inx_t.
  
 */

	void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve el número de filas.

       * @return 	el número de filas m_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_m(void);


/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve el número de columnas.

       * @return 	el número de columnas n_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_n(void);


/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Lee una matriz desde el flujo de entrada.El formato es el siguiente:
			m_ n_
			elemento(1,1) elemento (1,2) ... elemento(1,n_)
			elemento(2,1) elemento (2,2) ... elemento(2,n_)
			...
			elemento(m_,1) ...		 elemento(m_,n_)
 */

	istream& read(istream& is);


/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Escribe una matriz en el flujo de salida.El formato es el siguiente:
			m_ n_
			elemento(1,1) elemento (1,2) ... elemento(1,n_)
			elemento(2,1) elemento (2,2) ... elemento(2,n_)
			...
			elemento(m_,1) ...		 elemento(m_,n_)
 */

	ostream& write(ostream& os);
    
    
    
    
    
    
    bool igual(matrix_item_t a, matrix_item_t b, double precision); 
    bool mayor(matrix_item_t a, matrix_item_t b, double precision); 
    bool menor(matrix_item_t a, matrix_item_t b, double precision); 
    bool zero(matrix_item_t a, double precision);
    
    void filtra(matrix_t& M, matrix_item_t it, double precision);
    
    void resize(int m, int n);
    
    void trasponer();
    
    double signo(int i, int j);
    
    void menor(matrix_inx_t k, matrix_inx_t l, matrix_t& B);
    
    double determinante(void);
    
    void inversa(void);
    
    void menor_adjunto(matrix_inx_t k, matrix_inx_t l, matrix_t& B);

//========================================================================================
// Métodos privados.
//========================================================================================

private:

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve la posición k dentro del vector M_ del elemento (i,j) de la matriz.

       * @param  	i fila del elemento.
       * @param  	j columna del elemento.
       * @see 		matrix_inx_t.
       * @return 	el índice k.
       * @see 		vector_inx_t.
 */

	vector_inx_t pos(matrix_inx_t i,matrix_inx_t j);

/**	
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Reserva memoria para una matriz de mxn elementos.

       * @param 	m número de filas del tipo matrix_inx_t.       
       * @param 	n número de columnas del tipo matrix_inx_t.       
       * @see 		matrix_inx_t.
*/

	void crearMatriz(void); 
	

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Libera la memoria de la matriz.
 */

	void destruirMatriz(void);

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Redimensiona la matriz. Destruye la anterior, borrando su contenido, y construye una nueva matriz con la dimensión especificada.

       * @param  	m nuevo número de filas.
       * @param  	n nuevo número de columnas.
       * @see 		matrix_inx_t.   
 */

	void redimensiona(matrix_inx_t m,matrix_inx_t n);
    
    
};


