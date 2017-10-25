#include <iostream>

using namespace std;
class Primero{
private:
    int privado;
protected:
    int protegido;
public:
    int publico;
    Primero(const int a,const int b,const int c):privado(a),protegido(b),publico(c){}
    virtual void imprimir(){
        cout << publico<<endl;
        cout << protegido<<endl;
        cout << privado<<endl;
    }
};
class Segundo:private Primero{ //Al acceder de esta manera todos los datos heredados se heredan como si fueran privados
public:
    Segundo(const int a,const int b,const int c):Primero(a,b,c){}
    virtual void imprimir(){
        cout << publico<<endl;
        cout << protegido<<endl;
        //No podemos haceder al dato privado ya que private solo es accesible por la clase
    }
};


class Tercero:protected Primero{ //Al acceder de esta manera todos los datos heredados se heredan como si fueran protected
public:                          //esto quiere decir que podra seguir siendo usado en las subclases
    Tercero(const int a,const int b,const int c):Primero(a,b,c){}
    virtual void imprimir(){
        cout << publico<<endl;
        cout << protegido<<endl;
        //No podemos haceder al dato privado ya que private solo es accesible por la clase
    }
};

class Cuarto:public Primero{  //Al acceder de esta manera todos los datos heredados se heredan como si fueran publicos
public:                       //esto quiere decir que podran ser accedidos publicamente
    Cuarto(const int a,const int b,const int c):Primero(a,b,c){}
    virtual void imprimir(){
        cout << publico<<endl;
        cout << protegido<<endl;
        //No podemos haceder al dato privado ya que private solo es accesible por la clase
    }
};
int main()
{
    cout << "Esta es la clase madre podra acceder a todos los datos siendo 8 privado,4 protegido y 2 publico" <<endl;
    Primero lala =Primero(8,4,2);
    lala.imprimir();
    cout << "Aca no podremos aceder al dato privado y los heredados seran privados en esta subclase" <<endl;
    Segundo lele =Segundo(8,4,2);
    lele.imprimir();
    cout << "Aca tampoco pero el resto de datos si podran ser heredados" <<endl;
    Tercero lili =Tercero(8,4,2);
    lili.imprimir();
    cout << "Aca tampoco pero los datos en esta subclase seran publicos" <<endl;
    Cuarto lolo =Cuarto(8,4,2);
    lolo.imprimir();
    return 0;
}
