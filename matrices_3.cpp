#include "matrices_3.hpp"

#define MAX_MATRIX_ITEM 100

//========================================================================================
// Métodos privados.
//========================================================================================



vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }

	return (i-1)*n_+j-1;


}

void matrix_t::resize(int m, int n){
    m_ = m;
    n_ = n;
}

void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		



void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}




void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}




//========================================================================================
// Métodos públicos.
//========================================================================================

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n), 
traspuesta_(false)
{
	crearMatriz();
}	




matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0),
traspuesta_(false)
{}		



matrix_t::~matrix_t(void)
{
	destruirMatriz();
}



void  matrix_t::mostrarMatriz(void)
{

	char aux[80];
    if (traspuesta_ == false) {
        for(int i=1;i<=m_;i++){
            
            std::cout << "|";	
            for(int j=1;j<=n_;j++){
                sprintf(aux," %10.6lf ",get_matrix_item(i,j));
                cout << aux;
            }
            std::cout << " |";
            cout << endl;
        }
        
        cout << endl;
    } else {
        for(int i=1;i<=n_;i++){
	
            std::cout << "|";	
            for(int j=1;j<=m_;j++){
                sprintf(aux," %10.6lf ",get_matrix_item(i,j));
                cout << aux;
            }
            std::cout << " |";
            cout << endl;
        }

        cout << endl;
    }
}



matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
    if (traspuesta_ == true) {
        return M_[pos(j,i)];
    } else {
        return M_[pos(i,j)];
    }
}


void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}




matrix_inx_t matrix_t::get_m(void)
{
    if (traspuesta_ == true) {
        return n_;
    } else {
        return m_;
    }
}




matrix_inx_t matrix_t::get_n(void)
{
    if (traspuesta_ == true) {
        return m_;
    } else {
        return n_;
    }
}




istream& matrix_t::read(istream& is)
{
	int m,n;
	is >> m >> n;
    cout << "Introduce ahora cada uno de los datos de la matriz" << endl;

	redimensiona(m,n);
	const int sz=m*n;
    
	for(int i=0;i<sz;i++) {
		is >> M_[i];
	}
}


ostream& matrix_t::write(ostream& os)
{
	char aux[80];

	sprintf(aux, " %10d  %10d ",m_,n_);
	os << aux<<endl;
    if (traspuesta_ == false) {
        for(int i=1;i<=m_;i++){
            for(int j=1;j<=n_;j++){
                sprintf(aux," %10.6lf ",get_matrix_item(i,j));
                os << aux;
            }
            os << endl;
        }
    } else {
        for(int i=1;i<=n_;i++){
            for(int j=1;j<=m_;j++){
                sprintf(aux," %10.6lf ",get_matrix_item(i,j));
                os << aux;
            }
            os << endl;
        }
    }
}

bool matrix_t::igual(matrix_item_t a, matrix_item_t b, double precision){
    if (fabs(a-b) < precision) {
        return true;
    } else
    {
        return false;
    }
    
}
bool matrix_t::mayor(matrix_item_t a, matrix_item_t b, double precision){
    if ((a-b) > precision) {
        return true;
    } else
    {
        return false;
    }
}
bool matrix_t::menor(matrix_item_t a, matrix_item_t b, double precision){
    if ((a-b) < precision*-1) {
        return true;
    } else
    {
        return false;
    }
}
bool matrix_t::zero(matrix_item_t a, double precision){
    if (fabs(a) < precision) {
        return true;
    } else
    {
        return false;
    }
}

void matrix_t::filtra(matrix_t& M, matrix_item_t it, double precision){
    matrix_inx_t m = get_m();
    matrix_inx_t n = get_n();
    M.redimensiona(m, n);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n ; j++) {
            if (M.igual(get_matrix_item(i, j),it,precision) == true) {
                M.set_matrix_item(i, j, get_matrix_item(i, j));
            } else {
                matrix_item_t x = 0.00000;
                M.set_matrix_item(i, j, x);
            }
        }
    }
}


void matrix_t::trasponer() {
    traspuesta_ = true;
}

double matrix_t::signo(int i, int j){
    if ((i+j)%2 == 0) {
        return 1.0;
    } else {
        return -1.0;
    }
}

void matrix_t::menor(matrix_inx_t k, matrix_inx_t l, matrix_t& B){
    B.redimensiona(get_m()-1,get_n()-1);
    matrix_inx_t ii=0;
    for (matrix_inx_t i = 1; i <= B.get_m(); i++) {
        if (i == k) {
            ii= 1;
        }
        matrix_inx_t jj = 0;
        for (matrix_inx_t j = 1; j <= B.get_n(); j++) {
            if (j == l) {
                jj=1;
            }
            B.set_matrix_item(i, j, get_matrix_item(i+ii, j+jj));
        }
    }
}

double matrix_t::determinante(void){
    if (get_m() == 1) {
        return get_matrix_item(1, 1);
    } else {
        double Det = 0.0;
        for (matrix_inx_t i = 1; i <= get_m(); i++) {
            matrix_t B;
            menor(1, i, B);
            Det = Det + get_matrix_item(1, i) * signo(1, i) * B.determinante();
        }
        return Det;
    }
}


void matrix_t::inversa(void){
    cout << "Matriz Inversa = (1/Determinante)*[Traspuesta de la matriz adjunta]" << endl;
    matrix_t INV;
    INV.redimensiona(get_m(),get_n());
    matrix_t A;
    for (matrix_inx_t i = 1; i <= get_n(); i++) {
        for (matrix_inx_t j = 1; j <= get_m(); j++) {
            menor_adjunto(i,j,A);
            INV.set_matrix_item(i,j,A.determinante());
        }
    }
    cout << "1 / " << determinante() <<endl;
    INV.trasponer();
    INV.mostrarMatriz();
}

void matrix_t::menor_adjunto(matrix_inx_t k, matrix_inx_t l, matrix_t& B){
    int m = 1;
    int x = 1;
    matrix_inx_t a = 1;
    matrix_inx_t b = 1;
    int control = 0;
    B.redimensiona(get_m()-1,get_n()-1);
    m=1;
    for (matrix_inx_t i = 1; i <= get_n(); i++) {
        if (i == k) {
            m = 0;
        } else {
            m = 1;
        }
        for (matrix_inx_t j = 1; j <= get_m(); j++) {
            if (j == l) {
                x = 0;
            } else {
                x = 1;
            }
            if (m != 0 && x != 0) {
                if (control == 0) {
                    a=1;
                    b=1;
                }
                if (control == 1) {
                    a=1;
                    b=2;
                }
                if (control == 2) {
                    a=2;
                    b=1;
                }
                if (control == 3) {
                    a=2;
                    b=2;
                }
                B.set_matrix_item(a, b, get_matrix_item(i, j));
                control++;
            }
        }
    }
}



